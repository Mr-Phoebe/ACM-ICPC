#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;

typedef long long i64;
const double inf = 1e100;
const int MAXN = 520 * 2;
int n, k;
int x[MAXN], y[MAXN];
int wx[MAXN], wy[MAXN], totx, toty;
int segx[MAXN], segy[MAXN], cntx, cnty;
int c[MAXN], tot;
double g[MAXN][MAXN], d[MAXN];

void init()
{
	totx = toty = cntx = cnty = 0;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n + n + 2; ++i) {
		scanf("%d%d", &x[i], &y[i]);
		wx[totx++] = x[i], wy[toty++] = y[i];
	}
	for (int i = 0; i < n; ++i) {
		int a = i<<1, b = a^1;
		if (x[a] > x[b]) swap(x[a], x[b]); // L: a, R: b
		if (y[a] < y[b]) swap(y[a], y[b]); // U: a, D: b
		if (x[a] == x[b]) segx[cntx++] = i; else segy[cnty++] = i;
	}
	n += n + 2;
	sort(wx, wx + totx);
	sort(wy, wy + toty);
	totx = unique(wx, wx + totx) - wx;
	toty = unique(wy, wy + toty) - wy;
	tot = max(totx, toty);
	for (int i = 0; i < n; ++i) {
		x[i] = lower_bound(wx, wx + totx, x[i]) - wx;
		y[i] = lower_bound(wy, wy + toty, y[i]) - wy;
	}
}

void add(int i, int x)
{
	for (i = tot - i; i <= tot; i += i & -i) c[i] += x;
}

int sum(int i)
{
	int s = 0;
	for (i = tot - i; i; i -= i & -i) s += c[i];
	return s;
}

struct event {
	int i, t;
	event() {}
	event(int i, int t): i(i), t(t) {}
};

struct cmp {
	int o;
	cmp(int o): o(o) {}
	bool operator()(const event &ea, const event &eb)
	{
		int a = ea.i, b = eb.i;
		int dx1 = wx[x[a]] - wx[x[o]], dy1 = wy[y[a]] - wy[y[o]];
		int dx2 = wx[x[b]] - wx[x[o]], dy2 = wy[y[b]] - wy[y[o]];
		i64 s = (i64)dx1 * dy2 - (i64)dx2 * dy1;
		return s ? s > 0 : ea.t < eb.t;
	}
};

void build(int u, int x[], int seg[], int cnt)
{
	static event p[MAXN * 2];
	int m = 0;
	for (int i = 0; i < n; ++i) {
		if (x[i] < x[u]) p[m++] = event(i, 0);
	}
	for (int i = 0; i < cnt; ++i) {
		int a = seg[i]<<1, b = a^1;
		if (x[a] < x[u]) p[m++] = event(a, 1), p[m++] = event(b, -1);
	}
	sort(p, p + m, cmp(u));
	for (int i = 0; i < m; ++i) {
		int v = p[i].i;
		if (p[i].t) {
			add(x[v], p[i].t);
		} else {
			g[u][v] += (double)sum(x[v]) * k;
			g[v][u] = g[u][v];
		}
	}
}

void build()
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			g[i][j] = g[j][i] =
				hypot(wx[x[i]] - wx[x[j]], wy[y[i]] - wy[y[j]]);
		}
	}
	for (int i = 0; i < n; ++i) {
		build(i, x, segx, cntx);
		build(i, y, segy, cnty);
	}
}

void dijkstra(int s)
{
	static bool vis[MAXN];
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; ++i) d[i] = inf;
	d[s] = 0;
	for (int i = 0; i < n; ++i) {
		int u = -1, v;
		for (v = 0; v < n; ++v) {
			if (!vis[v] && (u < 0 || d[v] < d[u])) u = v;
		}
		vis[u] = true;
		for (v = 0; v < n; ++v) {
			d[v] = min(d[v], d[u] + g[u][v]);
		}
	}
}

int main()
{
	int dat;
	scanf("%d", &dat);
	while (dat--) {
		init();
		build();
		dijkstra(n - 2);
		printf("%.8lf\n", d[n - 1]);
	}
}
