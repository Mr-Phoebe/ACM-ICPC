#include <iostream>
#include <cstdio>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

typedef long long s64;

template <class T>
inline int size(const T &a)
{
	return (int)a.size();
}

inline int intcmp(int a, int b)
{
	if (a < b)
		return -1;
	else if (a > b)
		return 1;
	else
		return 0;
}

template <class T>
struct divRes
{
	T q, r;
	divRes(){}
	divRes(const T &_q, const T &_r)
		: q(_q), r(_r){}
};

class ulint
{
private:
	static const int AL = 8;
	void clearLeading0()
	{
		while (l > 0 && a[l - 1] == 0)
			l--;
	}

	int l;
	int a[AL];

	void resize(int _l)
	{
		assert(_l <= AL);
		assert(_l >= l);
		fill(a + l, a + _l, 0);
		l = _l;
	}

public:
	static const int B = 1000000000;
	static const int BL = 9;

	ulint()
	{
		l = 0;
	}
	ulint(s64 x)
	{
		l = 0;
		while (x > 0)
			a[l++] = x % B, x /= B;
	}

	inline divRes<ulint> div(const ulint &rhs) const
	{
		divRes<ulint> res;
		res.q.resize(l);

		ulint cur;
		for (int i = l - 1; i >= 0; i--)
		{
			cur.l++;
			for (int k = cur.l - 1; k > 0; k--)
				cur.a[k] = cur.a[k - 1];
			cur.a[0] = a[i];

			int le = 0, ri = B;
			if (cur.cmpTo(rhs) >= 0)
			{
				while (le != ri)
				{
					int mid = (le + ri) >> 1;
					if ((mid * rhs).cmpTo(cur) <= 0)
						le = mid + 1;
					else
						ri = mid;
				}
				le--;
			}
			res.q.a[i] = le;
			cur -= le * rhs;
		}
		res.q.clearLeading0();
		res.r = cur;
		return res;
	}

	inline ulint &operator+=(const ulint &rhs)
	{
		resize(max(l, rhs.l) + 1);
		int t = 0;
		int i;
		for (i = 0; i < rhs.l; i++)
		{
			a[i] += rhs.a[i] + t;
			t = a[i] / B;
			a[i] %= B;
		}
		while (t > 0)
		{
			a[i] += t;
			t = a[i] / B;
			a[i] %= B;
			i++;
		}
		clearLeading0();
		return *this;
	}
	inline ulint &operator-=(const ulint &rhs)
	{
		assert(this->cmpTo(rhs) >= 0);
		int t = 0;
		int i;
		for (i = 0; i < rhs.l; i++)
		{
			a[i] -= t + rhs.a[i];
			t = 0;
			if (a[i] < 0)
				a[i] += B, t++;
		}
		while (t > 0)
		{
			a[i] -= t;
			t = 0;
			if (a[i] < 0)
				a[i] += B, t++;
			i++;
		}
		clearLeading0();
		return *this;
	}
	inline ulint &operator*=(const ulint &rhs)
	{
		return *this = *this * rhs;
	}

	friend inline ulint operator+(const ulint &lhs, const ulint &rhs)
	{
		ulint res = lhs;
		res += rhs;
		return res;
	}
	friend inline ulint operator-(const ulint &lhs, const ulint &rhs)
	{
		ulint res = lhs;
		res -= rhs;
		return res;
	}
	friend inline ulint operator*(const ulint &lhs, const ulint &rhs)
	{
		ulint res;
		res.resize(lhs.l + rhs.l);

		for (int i = 0; i < lhs.l; i++)
		{
			s64 t = 0;
			int j;
			for (j = 0; j < rhs.l; j++)
			{
				t += res.a[i + j] + (s64)lhs.a[i] * rhs.a[j];
				res.a[i + j] = t % B;
				t /= B;
			}
			while (t > 0)
			{
				t += res.a[i + j];
				res.a[i + j] = t % B;
				t /= B;
				j++;
			}
		}
		res.clearLeading0();
		return res;
	}
	friend inline ulint operator/(const ulint &lhs, const ulint &rhs)
	{
		return lhs.div(rhs).q;
	}
	friend inline ulint operator%(const ulint &lhs, const ulint &rhs)
	{
		return lhs.div(rhs).r;
	}

	inline int cmpTo(const ulint &rhs) const
	{
		if (l != rhs.l)
			return intcmp(l, rhs.l);
		for (int i = l - 1; i >= 0; i--)
			if (a[i] != rhs.a[i])
				return intcmp(a[i], rhs.a[i]);
		return 0;
	}

	friend inline istream& operator>>(istream &in, ulint &rhs)
	{
		string s;
		in >> s;
		reverse(s.begin(), s.end());
		for (int i = 0; i < size(s); i += BL)
		{
			int cur = 0;
			for (int j = min(i + BL, size(s)); j > i; j--)
				cur = cur * 10 + s[j - 1] - '0';
			rhs.a[rhs.l++] = cur;
		}
		rhs.clearLeading0();
		return in;
	}
	friend inline ostream& operator<<(ostream &out, const ulint &rhs)
	{
		if (rhs.l == 0)
			out << 0;
		else
		{
			out << rhs.a[rhs.l - 1];
			for (int i = rhs.l - 1; i > 0; i--)
				out << setw(BL) << setfill('0') << rhs.a[i - 1];
		}
		return out;
	}
};

class lint
{
private:
	int s;
	ulint ul;
public:
	static const int B = 1000000000;
	static const int BL = 9;

	lint()
	{
		s = 0;
	}
	lint(s64 x)
	{
		s = x > 0 ? 1 : (x < 0 ? -1 : 0);
		ul = abs(x);
	}
	lint(const ulint &_ul)
	{
		ul = _ul;
		s = ul.cmpTo(0);
	}

	inline divRes<lint> div(const lint &rhs) const
	{
		divRes<ulint> ures = ul.div(rhs.ul);
		divRes<lint> res(ures.q, ures.r);
		res.q.s = ures.q.cmpTo(0) * s * rhs.s;
		res.r.s = ures.r.cmpTo(0) * s * rhs.s;
		if (res.r.s < 0)
			res.r += rhs.ul, res.q -= 1;
		return res;
	}

	inline lint operator-() const
	{
		lint res = *this;
		res.s = -res.s;
		return res;
	}

	inline lint &operator+=(const lint &rhs)
	{
		if (s == 0)
			return *this = rhs;
		else if (rhs.s == 0)
			return *this;

		if (s == rhs.s)
			ul += rhs.ul;
		else
		{
			int c = ul.cmpTo(rhs.ul);
			if (c == 0)
				s = 0;
			else if (c > 0)
				ul -= rhs.ul;
			else
			{
				ul = rhs.ul - ul;
				s = -s;
			}
		}
		return *this;
	}
	inline lint &operator-=(const lint &rhs)
	{
		return *this += -rhs;
	}
	inline lint &operator*=(const lint &rhs)
	{
		return *this = *this * rhs;
	}
	inline lint &operator/=(const lint &rhs)
	{
		return *this = *this / rhs;
	}
	inline lint &operator%=(const lint &rhs)
	{
		return *this = *this % rhs;
	}

	friend inline lint operator+(const lint &lhs, const lint &rhs)
	{
		lint res = lhs;
		res += rhs;
		return res;
	}
	friend inline lint operator-(const lint &lhs, const lint &rhs)
	{
		lint res = lhs;
		res -= rhs;
		return res;
	}
	friend inline lint operator*(const lint &lhs, const lint &rhs)
	{
		lint res;
		res.ul = lhs.ul * rhs.ul;
		res.s = lhs.s * rhs.s;
		return res;
	}
	friend inline lint operator/(const lint &lhs, const lint &rhs)
	{
		return lhs.div(rhs).q;
	}
	friend inline lint operator%(const lint &lhs, const lint &rhs)
	{
		return lhs.div(rhs).r;
	}

	inline int cmpTo(const lint &rhs) const
	{
		if (s != rhs.s)
			return intcmp(s, rhs.s);
		return s * ul.cmpTo(rhs.ul);
	}

	friend inline bool operator<(const lint &lhs, const lint &rhs)
	{
		return lhs.cmpTo(rhs) < 0;
	}
	friend inline bool operator>(const lint &lhs, const lint &rhs)
	{
		return lhs.cmpTo(rhs) > 0;
	}
	friend inline bool operator<=(const lint &lhs, const lint &rhs)
	{
		return lhs.cmpTo(rhs) <= 0;
	}
	friend inline bool operator>=(const lint &lhs, const lint &rhs)
	{
		return lhs.cmpTo(rhs) >= 0;
	}
	friend inline bool operator==(const lint &lhs, const lint &rhs)
	{
		return lhs.cmpTo(rhs) == 0;
	}
	friend inline bool operator!=(const lint &lhs, const lint &rhs)
	{
		return lhs.cmpTo(rhs) != 0;
	}

	friend inline istream& operator>>(istream &in, lint &rhs)
	{
		char c;
		while (c = in.peek(), ('0' > c || c > '9') && c != '-')
			in.get();

		if (in.peek() != '-')
			rhs.s = 1;
		else
		{
			rhs.s = -1;
			in.get();
		}
		cin >> rhs.ul;
		if (rhs.ul.cmpTo(0) == 0)
			rhs.s = 0;
		return in;
	}
	friend inline ostream& operator<<(ostream &out, const lint &rhs)
	{
		if (rhs.s == -1)
			out << '-';
		out << rhs.ul;
		return out;
	}
};

const lint Mod = 1000000007;

inline lint modpow(lint a, lint b, lint m)
{
	lint res = 1;
	lint t = a % m;
	for (lint i = b; i > 0; i /= 2)
	{
		if (i % 2 == 1)
			res = res * t % m;
		t = t * t % m;
	}
	return res;
}

inline pair<lint, lint> modrecmul(const pair<lint, lint> &a, const pair<lint, lint> &b, lint m)
{
	return make_pair(a.first * b.first % m, (b.second * a.first + a.second) % m);
}

// x_n = a * x_{n - 1} + b
inline lint modrec(lint x0, pair<lint, lint> a, lint n, lint m)
{
	pair<lint, lint> res = make_pair(1ll, 0ll);
	pair<lint, lint> t = a;
	for (lint i = n; i > 0; i /= 2)
	{
		if (i % 2 == 1)
			res = modrecmul(res, t, m);
		t = modrecmul(t, t, m);
	}
	return (res.first * x0 + res.second) % m;
}

lint countL(lint k, lint b, lint n, lint d)
{
	lint res = 0;
	res += (k / d) * (n * (n - 1) / 2), k %= d;
	res += (b / d) * n, b %= d;

	if (k == 0)
		return res;

	lint ym = (n * k + b - 1) / d;
	res += n * ym;
	res -= countL(d, d - b + k - 1, ym, k);
	return res;
}

lint countLSol(lint k, lint b, lint n, lint m, lint p)
{
	if (n == 0)
		return 0;
	if (k == 0)
		return b < m ? n : 0;

	lint res = 0;
	if (m - b > 0)
		res += (m - b + k - 1) / k;

	lint sm = ((n - 1) * k + b) / p;
	if (sm >= 1)
	{
		res += countL(p, p + m - b + k - 1, sm - 1, k);
		res -= countL(p, p - b + k - 1, sm - 1, k);

		lint sml = (p * sm - b + k - 1) / k;
		lint smr = (p * sm + m - b + k - 1) / k;
		if (smr > n)
			smr = n;
		res += smr - sml;
	}
	else
		res = min(res, n);
	/*
	for (int i = 0; i < n; i++)
		if (modadd(modmul(k, i, p), b, p) < m)
			res++;*/
	return res;
}

lint countSol(lint a, lint b, lint c, lint n, lint m, lint p)
{
	if (a == 0)
	{
		if (b == 0)
			return c == 0 ? n * m : 0;
		else
			return c * modpow(b, p - 2, p) % p < m ? n : 0;
	}

	lint ra = modpow(a, p - 2, p);
	return countLSol(-b * ra % p, c * ra % p, m, n, p);
}

lint getAns(lint p, lint c, lint qL, lint tL)
{
	lint nZ = qL / tL, rL = qL % tL;

	lint cZ = modrec(0, make_pair(modpow(2, tL, p), 1ll), nZ, p) * modpow(2, rL, p) % p;

	lint a = (modpow(2, tL - rL, p) * cZ + 1) % p;
	lint b = cZ;

	lint rA = modpow(2, rL, p);
	lint rB = modpow(2, tL - rL, p);

	lint qA, qB;
	if (p != Mod)
	{
		qA = (modpow(2, rL, Mod) - rA) * modpow(p, Mod - 2, Mod) % Mod;
		qB = (modpow(2, tL - rL, Mod) - rB) * modpow(p, Mod - 2, Mod) % Mod;
	}
	else
	{
		lint M2 = Mod * Mod;
		qA = modpow(2, rL, M2) / Mod;
		qB = modpow(2, tL - rL, M2) / Mod;
	}

	lint res = 0;
	res += countSol(a, b, c, p , p , p) * qA * qB;
	res += countSol(a, b, c, rA, p , p) * 1  * qB;
	res += countSol(a, b, c, p , rB, p) * qA * 1 ;
	res += countSol(a, b, c, rA, rB, p) * 1  * 1 ;
	res %= Mod;
	return res;
}

int main()
{
	int nT = 0;
	while (true)
	{
		nT++;

		lint p, x, l, r, tL;
		cin >> p >> x >> l >> r >> tL;
		if (p == 0 && x == 0 && l == 0 && r == 0 && tL == 0)
			break;
		cout << "Case #" << nT << ": " << getAns(p, x, r - l + 1, tL) << endl;
	}

	return 0;
}
