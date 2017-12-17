#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<time.h>
#include<string>
#define cl(a,b)	memset(a,b,sizeof(a))
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define REP2(i,a,b) for(int i=a;i>=b;--i)
#define MP make_pair
#define LL long long
#define ULL unsigned long long
#define X first
#define Y second
#define MAXN 100050
using namespace std;
vector<int> e[MAXN], c[MAXN];
set<int> st;
int fa[MAXN][20];
int p[MAXN];
int dfn[MAXN];
int dis[MAXN];
int cid;
int d[MAXN];
void dfs(int cur, int f) {
	dfn[++cid] = cur;
	p[cur] = cid;
	for (int i = 1; i < 20; ++i)
		fa[cur][i] = fa[fa[cur][i - 1]][i - 1];

	for (int i = 0; i < e[cur].size(); ++i) {
		int u = e[cur][i];
		if (u == f)
			continue;
		d[u] = d[cur] + 1;
		dis[u] = dis[cur] + c[cur][i];
		fa[u][0] = cur;
		dfs(u, cur);
	}
}

int lca(int u, int v) {
	if (d[u] < d[v])
		swap(u, v);
	for (int i = 19; i >= 0; --i) {
		if (d[fa[u][i]] >= d[v])
			u = fa[u][i];
		if (u == v)
			return u;
	}
	for (int i = 19; i >= 0; --i) {
		if (fa[u][i] != fa[v][i]) {
			u = fa[u][i];
			v = fa[v][i];
		}
	}
	return fa[u][0];
}
int add(int u) {
	if (st.empty())
		return 0;
	int x, y;
	set<int>::iterator it = st.lower_bound(p[u]), itx = it;
	itx--;
	if (it == st.end() || it == st.begin()) {
		it = st.begin();
		itx = st.end();
		itx--;
	}
	y = (*it);
	x = (*itx);
	y = dfn[y];
	x = dfn[x];
	return dis[u] - dis[lca(x, u)] - dis[lca(y, u)] + dis[lca(x, y)];
}
bool bo[MAXN];
int main() {
	//freopen("data.in", "r", stdin);
	//freopen("data.out", "w", stdout);
	int tt, ri = 0;
	scanf("%d", &tt);
	while (tt--) {
		int n, q;
		st.clear();
		cid=0;
		scanf("%d%d", &n, &q);
		for (int i = 0; i <= n; ++i)
		{
			bo[i] = false;
			e[i].clear();
			c[i].clear();
		}
		for (int i = 1; i < n; ++i) {
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			e[x].push_back(y);
			c[x].push_back(z);
			e[y].push_back(x);
			c[y].push_back(z);
		}
		for (int i = 0; i < 20; ++i)
			fa[1][0] = 1;
		d[1] = 1;
		dis[1] = 0;
		dfs(1, -1);
		int sum = 0;
		printf("Case #%d:\n", ++ri);
		for (int i = 1; i <= q; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			int tmp;
			if (x == 1) {
				if (!bo[y]){
					bo[y]=true;
					if (st.size() == 0) {
						st.insert(p[y]);
					} else {
						tmp = add(y);
						st.insert(p[y]);
						sum += tmp;
					}
				}
			} else {
				if (bo[y]){
					bo[y] = false;
					st.erase(p[y]);
					if (!st.empty()) {
						sum -= add(y);

					}
				}
			}

			printf("%d\n", sum);
//		printf("%d %d %d %d\n",now,i,sum,add(i));
		}
	}
	return 0;
}

/*
 6 5
 1 2 2
 1 5 2
 5 6 2
 2 4 2
 2 3 2
 1 5
 1 3
 1 4
 1 2
 2 5

 */
