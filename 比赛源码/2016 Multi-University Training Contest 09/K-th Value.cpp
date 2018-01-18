#include <bits/stdc++.h>
using namespace std;

const int MX = 200005;
const int MR = 55;
const int INF = 100000000;

#define fi first
#define se second

typedef pair<int, int> PII;
typedef vector<int> VI;
VI con[MX], cst[MX];
PII p[MX];

namespace IO {
	const int MX = 4096;
	char buf[MX], str[50];
	int bi = MX, bn = MX;
	
	int read(char *s) {
		while (bn) {
			for (; bi < bn && buf[bi] <= ' '; bi++);
			if (bi < bn) break;
			bn = fread(buf, 1, MX, stdin);
			bi = 0;
		}
		int sn = 0;
		while (bn) {
			for (; bi < bn && buf[bi] > ' '; bi++) s[sn++] = buf[bi];
			if (bi < bn) break;
			bn = fread(buf, 1, MX, stdin);
			bi = 0;
		}
		s[sn] = 0;
		return sn;
	}
	
	bool read(int& x) {
		if (!read(str)) return 0;
		x = atoi(str);
		return 1;
	}
}

inline void chkmax(int &u, int v) {
	if (u < v) u = v;
}

int val[MX], vcn;
int G[MX][MR], H[MX][MR];
int n, K, L, R, LIM;

void calc(int u, int pr) {
	if (u > 1) G[u][1] = (p[u].se <= LIM);
	
	for (int i = con[u].size() - 1; i >= 0; i--) {
		int v = con[u][i];
		if (v == pr) continue;
		p[v] = PII(u, cst[u][i]);
		calc(v, u);
		
		for (int k = 1; k < R; k++) {
			if (u > 1) chkmax(G[u][k + 1], G[v][k] + (p[u].se <= LIM));
		}
	}
}

int mx[MX];
int q[MX], qst, qen;

bool can_merge() {
	int u, v, k, i;
	
	for (u = 1; u <= n; u++) {
		for (k = 1; k <= R; k++) mx[k] = -INF;
		
		for (i = 0; i < con[u].size(); i++) {
			v = con[u][i];
			if (v == p[u].fi) continue;
			
			int st = 0, en = 0;
			qst = 0, qen = 0;
			for (k = R; k >= 1; k--) {
				while (en < R - k) {
					en++;
					while (qst < qen && mx[en] >= mx[q[qen - 1]]) qen--;
					q[qen++] = en;
				}
				
				while (st + 1 < L - k) {
					st++;
					while (qst < qen && q[qst] <= st) qst++;
				}
				
				if (qst < qen && mx[q[qst]] + H[v][k] > 0) return 1;
			}
			
			for (k = 1; k <= R; k++) chkmax(mx[k], H[v][k]);
		}
	}
	return 0;
}

bool can(int lim) {
	LIM = lim;
	int u, i, k;
	for (u = 1; u <= n; u++) {
		for (k = 1; k <= R; k++) H[u][k] = G[u][k] = -INF;
	}
	
	p[1].se = -INF;
	calc(1, 0);
	
	for (u = 2; u <= n; u++) {
		for (k = 1; k <= R; k++) {
			chkmax(H[u][k], K * G[u][k] - k);
			if (k >= L && H[u][k] > 0) return 1;
		}
	}
	
	return can_merge();
}

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	
	int Tc;
	int i, u, v, w;
	for (IO::read(Tc); Tc--; ) {
		IO::read(n);
		for (i = 1; i <= n; i++) {
			con[i].clear();
			cst[i].clear();
		}
		vcn = 0;
		
		for (i = 1; i < n; i++) {
			IO::read(u), IO::read(v), IO::read(w);
			con[u].push_back(v);
			cst[u].push_back(w);
			con[v].push_back(u);
			cst[v].push_back(w);
			val[vcn++] = w; 
		}
		
		sort(val, val + vcn);
		vcn = unique(val, val + vcn) - val;
		IO::read(K), IO::read(L), IO::read(R);
		int st = -1, en = vcn - 1;
		if (!can(val[en])) {
			puts("-1");
			continue;
		}
		
		while (st < en - 1) {
			int md = (st + en) >> 1;
			if (can(val[md])) en = md;
			else st = md;
		}
		
		printf("%d\n", val[en]);
	}
	
	return 0;
}
