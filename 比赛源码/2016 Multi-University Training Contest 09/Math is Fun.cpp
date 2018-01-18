#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;

typedef long long LL;
const int MX = 1005;
const int MP = 15;
const int M = 1000000009;
int d[MX];
LL pw[MX][MP];

void init() {
	int i, j;
	
	for (i = 2; i < MX; i++) d[i] = i;
	for (i = 2; i < MX; i++) {
		if (d[i] < i) continue;
		for (j = i * 2; j < MX; j += i) d[j] = i;
		
		pw[i][0] = 1;
		for (j = 1; j < MP; j++) pw[i][j] = pw[i][j - 1] * i % M;
	}
}

struct Num {
	int prm[MP], exp[MP];
	int pn;
	
	bool operator<(const Num& num) const {
		if (pn != num.pn) return pn > num.pn;
		for (int i = 0; i < pn; i++) {
			if (prm[i] != num.prm[i]) return prm[i] < num.prm[i];
			if (exp[i] != num.exp[i]) return exp[i] < num.exp[i];
		}
		return 0;
	}
	
	void push(int p, int e) {
		prm[pn] = p;
		exp[pn++] = e;
	}
	
	int go(int p) {
		return find(prm, prm + pn, p) - prm;
	}
	
	void set(int m) {
		int p, e;
		
		pn = 0;
		while (m > 1) {
			p = d[m];
			for (e = 0; m % p == 0; e++) m /= p;
			push(p, e);
		}
		reverse(prm, prm + pn);
		reverse(exp, exp + pn);
	}
};

int x[MX], m;
int n;
Num a[MX], emp;
bool pchk[MX][MX];
map<Num, int> H[2];
LL val[MX];

void preprocess() {
	int i, j, k, u, mc, c;
	
	sort(a, a + n);
	for (j = 0; j < MX; j++) pchk[n - 1][j] = 0;
	for (k = n - 1; k >= 0; k--) {
		mc = MX;
		for (i = 0; i <= k; i++) {
			for (c = j = 0; j < a[i].pn; j++) {
				if (!pchk[k][a[i].prm[j]]) c++;
			}
			if (mc > c) mc = c, u = i;
		}
		swap(a[u], a[k]);
		if (!k) break;
		for (j = 0; j < MX; j++) pchk[k - 1][j] = pchk[k][j];
		for (j = 0; j < a[k].pn; j++) pchk[k - 1][a[k].prm[j]]++;
	}
}

inline void add(int& x, int y) {
	x += y;
	if (x >= M) x -= M;
}

inline LL sqr(LL x) {
	return x * x % M;
}

LL calc() {
	int i, j, k, p, e, ce, id, sum;
	LL val;
	Num cur, nxt;
	
	if (!n) return 0;
	preprocess();
	H[id = 0].clear();
	H[id][emp] = 1;
	for (i = 0; i < n; i++) {
		H[!id].clear();
		for (map<Num, int>::iterator it = H[id].begin(); it != H[id].end(); it++) {
			cur = it->first, sum = it->second;
			val = 1;
			for (j = 0; j < a[i].pn; j++) {
				p = a[i].prm[j], e = a[i].exp[j];
				k = cur.go(p);
				ce = (k == cur.pn) ? 0 : cur.exp[k];
				if (e > ce) val = val * pw[p][e - ce] % M;
			}
			nxt.pn = 0;
			for (j = 0; j < cur.pn; j++) {
				p = cur.prm[j], e = cur.exp[j];
				if (pchk[i][p]) nxt.push(p, e);
			}
			add(H[!id][nxt], sum);
			for (j = 0; j < a[i].pn; j++) {
				p = a[i].prm[j], e = a[i].exp[j];
				if (!pchk[i][p]) continue;
				k = nxt.go(p);
				if (k == nxt.pn) {
					nxt.push(p, 0);
					for (k = nxt.pn - 1; k; k--) {
						if (nxt.prm[k - 1] < nxt.prm[k]) break;
						swap(nxt.prm[k - 1], nxt.prm[k]);
						swap(nxt.exp[k - 1], nxt.exp[k]);
					}
				}
				nxt.exp[k] = max(nxt.exp[k], e);
			}
			add(H[!id][nxt], sum * val % M * val % M);
		}
		id = !id;
	}
	return (H[id][emp] % M + M - 1) % M;
}

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	
	int tc, i, g, h, tp, ans;
	
	init();
	for (scanf("%d", &tc); tc--; ) {
		scanf("%d", &m);
		for (i = 0; i < m; i++) scanf("%d", &x[i]);
		ans = 0;
		for (g = MX - 1; g > 0; g--) {
			n = 0;
			for (i = 0; i < m; i++) {
				if (x[i] % g == 0) a[n++].set(x[i] / g);
			}
			tp = calc() * g * g % M;
			for (h = g * 2; h < MX; h += g) add(tp, M - val[h]);
			val[g] = tp;
			add(ans, g * val[g] % M);
		}
		printf("%d\n", ans);
	}
	return 0;
}
