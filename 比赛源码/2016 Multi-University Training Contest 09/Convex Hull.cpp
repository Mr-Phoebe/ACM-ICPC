#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <cctype>
#include <utility>
#include <queue>
#include <cmath>
#include <complex>
#include <bitset>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef double DB;

#define pb push_back
#define mset(a, b) memset(a, b, sizeof a)
#define all(x) (x).begin(), (x).end()
#define bit(x) (1 << (x))
#define bitl(x) (1LL << (x))
#define sqr(x) ((x) * (x))
#define sz(x) ((int)(x.size()))
#define cnti(x) (__builtin_popcount(x))
#define cntl(x) (__builtin_popcountll(x))
#define clzi(x) (__builtin_clz(x))
#define clzl(x) (__builtin_clzll(x))
#define ctzi(x) (__builtin_ctz(x))
#define ctzl(x) (__builtin_ctzll(x))

#define X first
#define Y second

#define Error(x) cout << #x << " = " << x << endl

template <typename T, typename U> 
inline void chkmax(T& x, U y) {
	if (x < y) x = y;
}

template <typename T, typename U>
inline void chkmin(T& x, U y) {
	if (y < x) x = y;
}

const int MN = 1111;
const DB EPS = 1e-8;

int n, m;

struct PT {
	DB x[3];
	PT() { x[0] = x[1] = x[2] = 0; }
	PT(DB xx, DB yy, DB zz) {
		x[0] = xx, x[1] = yy, x[2] = zz;
	}
	PT operator*(const PT& v) const {
		return PT(x[1] * v.x[2] - x[2] * v.x[1],
							x[2] * v.x[0] - x[0] * v.x[2],
							x[0] * v.x[1] - x[1] * v.x[0]);
	}
	PT operator-(const PT& v) const {
		return PT(x[0] - v.x[0], x[1] - v.x[1], x[2] - v.x[2]);
	}
	PT operator-() const {
		return PT(-x[0], -x[1], -x[2]);
	}
	DB dot(const PT& v) const {
		return x[0] * v.x[0] + x[1] * v.x[1] + x[2] * v.x[2];
	}
	bool operator<(const PT& v) const {
		if (fabs(x[0] - v.x[0]) > EPS) return x[0] < v.x[0];
		return x[1] < v.x[1];
	}
	void input() { scanf("%lf%lf%lf", x, x + 1, x + 2); }
} A[MN], p[6 * MN], q[6 * MN], pp[6 * MN];

struct Twoset {
	void insert(int x) { (a == -1 ? a : b) = x; }
	bool contains(int x) { return a == x || b == x; }
	void erase(int x) { (a == x ? a : b) = -1; }
	int size() { return (a != -1) + (b != -1); }
	int a, b;
} E[MN][MN];

struct Face {
	PT norm;
	DB disc;
	int I[3];
};
 
vector<Face> F;
 
Face make_face(int i, int j, int k, int inside_i) {
	E[i][j].insert(k); E[i][k].insert(j); E[j][k].insert(i);
	Face f;
	f.I[0] = i; f.I[1] = j; f.I[2] = k;
	f.norm = (A[j] - A[i]) * (A[k] - A[i]);
	f.disc = f.norm.dot(A[i]);
	if (f.norm.dot(A[inside_i]) > f.disc) {
		f.norm = -f.norm;
		f.disc = -f.disc;
	}
	return f;
}
 
int id[4];
 
bool collinear(PT A, PT B, PT C) {
	PT D = (B - A) * (C - A);
	return fabs(D.dot(D)) < EPS;
}
 
bool is_valid(PT A, PT B, PT C, PT D) {
	PT E = (B - A) * (C - A);
	return fabs(E.dot(D - A)) > EPS;
}
 
int init() {
	memset(E, -1, sizeof E);
	F.clear();
	id[0] = 0, id[1] = 1;
	int i;
	for (i = 2; i < n; i++) if (!collinear(A[0], A[1], A[i])) break;
	if (i == n) return 0;
	id[2] = i;
	for (; i < n; i++) if (is_valid(A[0], A[1], A[id[2]], A[i])) break;
	if (i == n) return 0;
	id[3] = i;  
 
	for (int i = 0; i < 4; i++)
		for (int j = i + 1; j < 4; j++)
			for (int k = j + 1; k < 4; k++)
				F.push_back(make_face(id[i], id[j], id[k], id[6 - i - j - k]));
	return 1;
}
 
int convex_hull_3d() {
	if (!init()) return 0;
	for (int i = 0; i < n; i++) {
		int k;
		for (k = 0; k < 4; k++) if (i == id[k]) break;
		if (k < 4) continue;
		for (int j = 0; j < F.size(); j++) {
			Face f = F[j];
			if (f.norm.dot(A[i]) >= f.disc) {
				for (int a = 0; a < 3; a++) for (int b = a + 1; b < 3; b++) {
					int c = 3 - a - b;
					E[f.I[a]][f.I[b]].erase(f.I[c]);
				}
				F[j--] = F.back();
				F.resize(F.size() - 1);
			}
		}
		int sz = F.size();
		for (int j = 0; j < sz; j++) {
			Face f = F[j];
			for (int a = 0; a < 3; a++) for (int b = a + 1; b < 3; b++) {
				int c = 3 - a - b;
				if (E[f.I[a]][f.I[b]].size() == 2) continue;
				F.push_back(make_face(f.I[a], f.I[b], i, f.I[c]));
			}
		}
	}
	return 1;
}

struct Mat {
	DB A[4][4];
	inline void init() {
		memset(A, 0, sizeof A);
		for (int i = 0; i < 4; i++) A[i][i] = 1.0;
	}
	inline Mat operator*(const Mat &M) const {
		Mat C;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				C.A[i][j] = 0;
				for (int k = 0; k < 4; k++) C.A[i][j] += A[i][k] * M.A[k][j];
			}
		}
		return C;
	}
};

Mat get_rotate(DB a, DB b, DB c) {
	Mat RX, RY;
	DB d = sqrt(a * a + b * b + c * c);
	a /= d, b /= d, c /= d;
	d = sqrt(sqr(b) + sqr(c));
	RX.init(); RY.init();
	if (fabs(d) > EPS) {
		RX.A[1][1] = c / d, RX.A[1][2] = -b / d;
		RX.A[2][1] = b / d, RX.A[2][2] = c / d;
	}
	RY.A[0][0] = d, RY.A[0][2] = -a;
	RY.A[2][0] = a, RY.A[2][2] = d;
	return RY * RX;
}

inline PT convert(Mat &M, PT P) {
	PT ret;
	for (int i = 0; i < 3; i++) {
		ret.x[i] = M.A[i][3];
		for (int j = 0; j < 3; j++) {
			ret.x[i] += M.A[i][j] * P.x[j];
		}
	}
	return ret;
}

DB vect_2d(PT p, PT p1, PT p2) {
	return (p1.x[0] - p.x[0]) * (p2.x[1] - p.x[1]) - (p2.x[0] - p.x[0]) * (p1.x[1] - p.x[1]);
}

bool inter(int id1, int id2, DB z, PT &ret) {
	DB mi = min(p[id1].x[2], p[id2].x[2]);
	DB ma = max(p[id1].x[2], p[id2].x[2]);
	if (!(mi - EPS < z && z < ma + EPS)) return 0;
	DB dx[3], t;
	for (int i = 0; i < 3; i++) dx[i] = p[id2].x[i] - p[id1].x[i];
	if (fabs(dx[2]) < EPS) {
		ret = p[id1];
		return 1;
	}
	t = (z - p[id1].x[2]) / dx[2];
	for (int i = 0; i < 3; i++) ret.x[i] = p[id1].x[i] + dx[i] * t;
	return 1;
}

int convex_hull_2d(PT *p, int n, PT *q) {
	int i, k, m;
	sort(p, p + n);
	m = 0;
	for (i = 0; i < n; i++) {
		while (m > 1 && vect_2d(q[m - 2], q[m - 1], p[i]) < EPS) m--;
		q[m++] = p[i];
	}
	k = m;
	for (i = n - 2; i >= 0; i--) {
		while (m > k && vect_2d(q[m - 2], q[m - 1], p[i]) < EPS) m--;
		q[m++] = p[i];
	}
	return --m;
}

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	int ncase, tc(0), Q;
	for (scanf("%d", &ncase); ncase--; ) {
		printf("Case #%d:\n", ++tc);
		scanf("%d%d", &n, &Q);
		for (int i = 0; i < n; i++) A[i].input();
		bool bf = convex_hull_3d();
		while (Q--) {
			DB A, B, C, D;
			PT P;
			scanf("%lf%lf%lf%lf", &A, &B, &C, &D);
			if (bf == 0) {
				puts("0.000");
				continue;
			}
			if (A != 0) {
				P = PT(-D / A, 0, 0);
			} else if (B != 0) {
				P = PT(0, -D / B, 0);
			} else {
				P = PT(0, 0, -D / C);
			}
			Mat M = get_rotate(A, B, C);
			P = convert(M, P);
			for (int i = 0; i < n; i++) p[i] = convert(M, ::A[i]);
			int pn = 0;
			for (int i = 0; i < F.size(); i++) {
				for (int j = 0; j < 3; j++) {
					bool b = inter(F[i].I[j], F[i].I[(j + 1) % 3], P.x[2], pp[pn]);
					if (b) {
						pn++;	
					}
				}
			}
			if (pn <= 2) {
				puts("0.000");
				continue;
			}
			m = convex_hull_2d(pp, pn, q);
			DB ans = 0;
			for (int i = 0; i < m; i++) {
				ans += vect_2d(q[0], q[i], q[i + 1]);
			}
			printf("%.3lf\n", 0.5 * fabs(ans));
		}
	}
	return 0;
}

