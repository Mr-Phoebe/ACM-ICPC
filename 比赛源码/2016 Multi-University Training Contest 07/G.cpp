#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long lli;

const int N = 1000 + 10;
const int M = 1000 + 10;

lli f[N][M];
int cnt[N][M], bst[N][M];
vector<int> V[N], E[N], T[N];
int A[N], ans[N];
lli res;
int n, m, s;

void dfs1(int u, int p)
{
	int v, i, j;
	for (i=0; i<V[u].size(); i++)
	{
		v = V[u][i];
		if (v == p) continue;
		dfs1(v, u);
		for (j=0; j<s; j++) f[u][j] += f[v][j]; 
	}
	if (u == 1) res = f[u][0];
	bst[u][s-1] = s - 1;
	for (i=s-2; i>=0; i--) 
		if (f[u][i] < f[u][i+1])
		{
			f[u][i] = f[u][i+1];
			bst[u][i] = bst[u][i+1];
		}
		else bst[u][i] = i;
}

void dfs2(int u, int k, int p)
{
	int v, i;
	for (i=0; i<V[u].size(); i++)
	{
		v = V[u][i];
		if (v == p) continue;
		ans[E[u][i]] = A[bst[v][k]] - A[k];
		dfs2(v, bst[v][k], u);
	}
}

int main()
{
	int t, u, v, x, i, j;
	scanf("%d", &t);
	while (t --)
	{
		scanf("%d %d", &n, &m);
		for (i=0; i<n-1; i++)
		{
			scanf("%d %d", &u, &v);
			V[u].push_back(v);
			V[v].push_back(u);
			E[u].push_back(i);
			E[v].push_back(i);
		}
		for (i=1; i<=m; i++)
		{
			scanf("%d %d", &u, &A[i]);
			T[u].push_back(A[i]);
		}
		m ++;
		sort(A, A + m);
		s = unique(A, A + m) - A;
		for (i=1; i<=n; i++)
		{
			for (j=0; j<s; j++) f[i][j] = cnt[i][j] = 0; 
			for (j=0; j<T[i].size(); j++) 
			{
				T[i][j] = lower_bound(A, A + s, T[i][j]) - A;
				cnt[i][T[i][j]] ++;
			}
			x = 0;
			for (j=s-1; j>=0; j--)
			{
				x += cnt[i][j];
				f[i][j] += (lli)A[j] * (lli)x;
			}
		}
		dfs1(1, -1);
		printf("%I64d\n", res);
		dfs2(1, 0, -1);
		for (i=0; i<n-2; i++) printf("%d ", ans[i]);
		printf("%d\n", ans[n-2]);
		for (i=1; i<=n; i++)
		{
			V[i].clear();
			E[i].clear();
			T[i].clear();
		}
	}
	return 0;
}
