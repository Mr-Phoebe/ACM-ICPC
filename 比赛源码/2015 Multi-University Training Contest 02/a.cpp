#include <cstdio>
#include <algorithm>
#include <ctime>
using namespace std;


int n, m, len, LEN, x, y, a, b;
int next11[210000], go[210000], till[210000];
int NEXT[210000], GO[210000], TILL[210000], f1[210000], f2[210000];
int leno, nexto[410000], tillo[410000], lo[410000], t1o[410000];
int Time, Time1, TT[110000], L[110000], R[110000], mi[150001][21], dep[210000], Log[150001], fa[71000][21];
int len1, next1[210000], go1[210000], till1[210000], ff1[210000];
int node[210000], node1[210000];

char *ch, buf[35*2024000+5];

struct T {
	long long v, s;
	T() {
	}
	T(long long _v, long long _s) {
		v = _v;
		s = _s;
	}
	void update(T a) {
		if (a.v > v) v = a.v, s = 0;
		if (a.v == v) s += a.s;
	}
} down[210000], up[210000], ans, Down[210000], DD[210000], ma1[110000], ma2[110000], ma3[110000], fo[410000];


T operator + (T a, long long b) {
	a.v += b;
	return a;
}

T operator * (T a, long long b) {
	return T(a.v * b, a.s);
}

T operator * (T a, T b) {
	return T(a.v + b.v, a.s * b.s);
}

T operator + (T a, T b) {
	a.update(b);
	return a;
}

bool operator == (T a, T b) {
	return a.s == b.s && a.v == b.v;
}


void read(int &x) {
	for (++ch; *ch <= 32; ++ch);
	for (x = 0; '0' <= *ch; ch++)	x = x * 10 + *ch - '0';
}

struct SegmentTree {
	T ma[410000];
	SegmentTree() {
		for (int i = 0; i < 410000; i++)
			ma[i] = T(-1e18, 0);
	}
	void modify(int k, int q, int h, int x, T a) {
		if (q == h) ma[k] = a;
		else {
			if (x <= (q + h) / 2) modify(k * 2, q, (q + h) / 2, x, a);
			else modify(k * 2 + 1, (q + h) / 2 + 1, h, x, a);
			ma[k] = ma[k * 2] + ma[k * 2 + 1];
		}
	}
	T query(int k, int q, int h, int l, int r) {
		if (l <= q && h <= r) return ma[k];
		else if (r <= (q + h) / 2) return query(k * 2, q, (q + h) / 2, l, r);
		else if ((q + h) / 2 < l) return query(k * 2 + 1, (q + h) / 2 + 1, h, l, r);
		else return query(k * 2, q, (q + h) / 2, l, r) + query(k * 2 + 1, (q + h) / 2 + 1, h, l, r);
	}
} Tree[5];


bool cmp(int x, int y) {
	return L[x] < L[y];
}

void add(int x, int y) {
	next11[++len] = till[x];
	till[x] = len;
	go[len] = y;
}

void add(int x, int y, int a, int b) {
	NEXT[++LEN] = TILL[x];
	TILL[x] = LEN;
	GO[LEN] = y;
	f1[LEN] = a;
	f2[LEN] = b;
}

void add1(int a, int b, int c) {
	next1[++len1] = till1[a];
	till1[a] = len1;
	go1[len1] = b;
	ff1[len1] = c;
}

int lca(int a, int b) {
	a = TT[a]; b = TT[b];
	if (a > b) swap(a, b);
	int x = Log[b - a + 1];
	if (dep[mi[a][x]] < dep[mi[b - (1 << x) + 1][x]])
		return mi[a][x];
	else
		return mi[b - (1 << x) + 1][x];
}

int dist(int a, int b) {
	int x = lca(a, b);
	return dep[a] + dep[b] - 2 * dep[x];
}

void dfs1(int k, int fa) {
	down[k] = T(0, 1);
	for (int i = till[k]; i; i = next11[i])
		if (go[i] != fa) {
			dfs1(go[i], k);
			down[k].update(down[go[i]] + 1);
		}
}

void dfs2(int k, int fa) {
	ma1[k] = T(-1e18, 0);
	ma2[k] = T(-1e18, 0);
	ma3[k] = T(-1e18, 0);
	for (int i = till[k]; i; i = next11[i])
		if (go[i] != fa) {
			ans.update(ma1[k] * ((down[go[i]] + 1) * 2));
			ans.update((ma1[k] * 2) * (down[go[i]] + 1));
			ans.update((down[go[i]] + 1) * 2);
			if (down[go[i]].v + 1 > ma1[k].v) {
				ma3[k] = ma2[k];
				ma2[k] = ma1[k];
				ma1[k] = down[go[i]] + 1;
			}else if (down[go[i]].v + 1 == ma1[k].v) {
				ma1[k].update(down[go[i]] + 1);
			}else	if (down[go[i]].v + 1 > ma2[k].v) {
				ma3[k] = ma2[k];
				ma2[k].update(down[go[i]] + 1);
			}else if (down[go[i]].v + 1 == ma2[k].v) {
				ma2[k].update(down[go[i]] + 1);
			}else ma3[k].update(down[go[i]] + 1);
		}
	for (int i = till[k]; i; i = next11[i])
		if (go[i] != fa) {
			up[go[i]] = up[k] + 1;
			up[go[i]].update(T(1, 1));
			if (down[go[i]].v + 1 == ma1[k].v) {
				if (down[go[i]].s == ma1[k].s) up[go[i]].update(ma2[k] + 1);
				else up[go[i]].update(T(ma1[k].v + 1, ma1[k].s - down[go[i]].s));
			}else up[go[i]].update(ma1[k] + 1);
		}
	for (int i = till[k]; i; i = next11[i])
		if (go[i] != fa) dfs2(go[i], k);
}

void dfs3(int k, int ff) {
	TT[k] = ++Time;
	L[k] = ++Time1;
	mi[Time][0] = k;
	dep[k] = dep[ff] + 1;
	fa[k][0] = ff;
	for (int i = 1; i <= 20; i++)
		fa[k][i] = fa[fa[k][i - 1]][i - 1];
	for (int i = till[k]; i; i = next11[i])
		if (go[i] != ff) {
			dfs3(go[i], k);
			mi[++Time][0] = k;
		}
	R[k] = Time1;
}

int near(int a, int b) {
	for (int i = 20; i >= 0; i--)
		if (dep[fa[a][i]] > dep[b]) a = fa[a][i];
	return a;
}

void ins(int t1, int x, int l, T o) {
	leno++;
	nexto[leno] = tillo[x];
	tillo[x] = leno;
	lo[leno] = l;
	fo[leno] = o;
	t1o[leno] = t1;
}

void Find(int root, int t, T d) {
	int x = lca(root, t);
	if (x == t) {
		ans.update(d * (up[x] * 2));
		ans.update((d * 2) * up[x]);
		ans.update(((d + (dep[root] - dep[x])) * 2) * down[root]);
		ans.update((d + (dep[root] - dep[x])) * (down[root] * 2));
		if (root != t) {
			ins(1, root, dep[t], d + (dep[root] - dep[t]));
			ins(2, root, dep[t], d * 2 + (dep[root] - dep[t]) * 2);
		}
	}else if (x == root) {
		ans.update((d + (dep[x] - dep[root])) * (up[root] * 2));
		ans.update(((d + (dep[x] - dep[root])) * 2) * up[root]);
		ans.update((d * 2) * down[t]);
		ans.update(d * (down[t] * 2));
		ins(-1, t, dep[root], d);
		ins(-2, t, dep[root], d * 2);
	}else {
		ans.update((d * 2) * down[x]);
		ans.update(d * (down[x] * 2));
		ans.update(((d + (dep[root] + dep[t] - 2 * dep[x])) * 2) * down[root]);
		ans.update((d + (dep[root] + dep[t] - 2 * dep[x])) * (down[root] * 2));
		ans.update(((d + (dep[t] - dep[x])) * 2) * up[x]);
		ans.update((d + (dep[t] - dep[x])) * (up[x] * 2));
		T a = ma1[x], b = ma2[x], c = ma3[x];
		int x1 = near(root, x), x2 = near(t, x);
		if (down[x1].v + 1 == a.v) a.s -= down[x1].s;
		else if (down[x1].v + 1 == b.v) b.s -= down[x1].s;
		else if (down[x1].v + 1 == c.v) c.s -= down[x1].s;
		if (down[x2].v + 1 == a.v) a.s -= down[x2].s;
		else if (down[x2].v + 1 == b.v) b.s -= down[x2].s;
		else if (down[x2].v + 1 == c.v) c.s -= down[x2].s;
		if (a.s) a = a;
		else if (b.s) a = b;
		else a = c;
		a.update(T(1, 0));
		ans.update(((d + (dep[t] - dep[x])) * 2) * a);
		ans.update((d + (dep[t] - dep[x])) * (a * 2));
		if (dep[t] > dep[x] + 1) {
			ins(-1, t, dep[x] - 1, d);
			ins(-2, t, dep[x] - 1, d * 2);
		}
		if (dep[root] > dep[x] + 1) {
			ins(1, root, dep[x] - 1, d + (dep[t] + dep[root] - 2 * dep[x]));
			ins(2, root, dep[x] - 1, d * 2 + (dep[t] + dep[root] - 2 * dep[x]) * 2);
		}
	}
}

void dfs4_s(int k, int fa) {
	for (int i = till1[k]; i; i = next1[i])
		if (go1[i] != fa) {
			dfs4_s(go1[i], k);
			ans.update((DD[go1[i]] * 2 + 2 * ff1[i]) * DD[k]);
			ans.update((DD[go1[i]] + ff1[i]) * (DD[k] * 2));
			DD[k].update(DD[go1[i]] + ff1[i]);
		}
}

void dfs4(int k, int fa, int root) {

	Down[k] = down[root];
	Down[k].update(up[root]);

	for (int i = TILL[k]; i; i = NEXT[i])
		if (GO[i] != fa) {
			dfs4(GO[i], k, f2[i]);
			Down[k].update(Down[GO[i]] + (1 + dist(root, f1[i])));
			Find(root, f1[i], Down[GO[i]] + 1);
		}


	int tot = 0;
	for (int i = TILL[k]; i; i = NEXT[i])
		if (GO[i] != fa) {
			ans.update((DD[f1[i]] * 2) * (Down[GO[i]] + 1));
			ans.update(DD[f1[i]] * ((Down[GO[i]] + 1) * 2));
			DD[f1[i]].update(Down[GO[i]] + 1);
			node[++tot] = f1[i];
		}
	node[++tot] = root;
	sort(node + 1, node + tot + 1, cmp);
	for (int i = tot; i > 1; i--)
		node[++tot] = lca(node[i], node[i - 1]);
	sort(node + 1, node + tot + 1, cmp);
	
	int tot1 = 0;
	for (int i = 1; i <= tot; i++)
		if (i == 1 || node[i] != node[i - 1])
			node1[++tot1] = node[i];
	tot = tot1;
	for (int i = 1; i <= tot; i++)
		node[i] = node1[i];

	for (int i = 1; i <= tot; i++)
		till1[node[i]] = 0;
	len1 = 0;

	node1[tot1 = 1] = node[1];

	for (int i = 2; i <= tot; i++) {
		while (L[node[i]] > R[node1[tot1]]) tot1--;
		add1(node[i], node1[tot1], dep[node[i]] - dep[node1[tot1]]);
		add1(node1[tot1], node[i], dep[node[i]] - dep[node1[tot1]]);
		node1[++tot1] = node[i];
	}

	dfs4_s(root, 0);

	for (int i = 1; i <= tot; i++)
		DD[node[i]] = T(-1e18, 0);
}

void dfs5(int k, int fa) {
	for (int i = tillo[k]; i; i = nexto[i]) {
		T a = Tree[t1o[i] + 2].query(1, 1, n, lo[i] + 1, dep[k]) + (-t1o[i] * dep[k]);
		ans.update(a * fo[i]);
	}

	for (int i = till[k]; i; i = next11[i])
		if (go[i] != fa) {
			T a;
			if ((down[go[i]] + 1) == ma1[k]) a = ma2[k];
			else if (down[go[i]].v + 1 == ma1[k].v) a = T(ma1[k].v, ma1[k].s - down[go[i]].s);
			else a = ma1[k];
			a.update(T(0, 1));
			for (int j = -2; j <= 2; j++)
				if (j)
					Tree[j + 2].modify(1, 1, n, dep[k] + 1, a * abs(2 / j) + (dep[k] * j));
			dfs5(go[i], k);
		}
}

int main() { 
	// freopen("a.in", "r", stdin);
	// freopen("tree.out", "w", stdout); 
// 	int size = 256 << 20; // 256MB  
// char *p = (char*)malloc(size) + size;  
// __asm__("movl %0, %%esp\n" :: "r"(p));  
	ch = buf - 1;
	fread(buf, 1, 35 * 2000000, stdin);
	int Case;
	read(Case);
	// if (Case == 1111)
	// 	while (1);
	for (int i = 0; i <= 20; i++)
		if ((1 << i) <= 150000) Log[1 << i] = i;
	for (int i = 2; i <= 150000; i++)
		if (!Log[i]) Log[i] = Log[i - 1];
	int ssss = 0;
	while (Case--) {
		ans = T(0, 0);
		read(n); read(m);
		ssss += n + m;
		if (n == 1 && m == 1) {
			printf("0 1\n");
			continue;
		}
		for (int i = 1; i <= n; i++)
			till[i] = tillo[i] = 0;
		len = leno = LEN = Time = 0;
		for (int i = 1; i <= m; i++)
			TILL[i] = 0;
		for (int i = 0; i < 5; i++)
			for (int j = 1; j <= 4 * n; j++)
				Tree[i].ma[j] = T(-1e18, 0);
		for (int i = 1; i < n; i++) {
			read(x); read(y);
			add(x, y);
			add(y, x);
		}
		for (int i = 1; i < m; i++) {
			read(x); read(a); read(y); read(b);
			add(x, y, a, b);
			add(y, x, b, a);
		}
		dfs1(1, 0);
		up[1] = T(0, 0);
		dfs2(1, 0);

		dfs3(1, 0);

		for (int i = 1; i <= 20; i++)
			for (int j = 1; j <= Time - (1 << i) + 1; j++)
				if (dep[mi[j][i - 1]] < dep[mi[j + (1 << (i - 1))][i - 1]])
					mi[j][i] = mi[j][i - 1];
				else
					mi[j][i] = mi[j + (1 << (i - 1))][i - 1];

		for (int i = 1; i <= n; i++)
			DD[i] = T(-1e18, 0);
		dfs4(1, 0, 1);

		
		dfs5(1, 0);

		printf("%lld %lld\n", ans.v, ans.s);
	}
	printf("%d\n", ssss);
	// fclose(stdin);
	// fclose(stdout);
	// printf("%d\n", clock());
}
