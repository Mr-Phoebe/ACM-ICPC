#include <cstdio>
#include <cassert>
#include <algorithm>

using namespace std;

const int N = 1000 + 10;

int G[N][N];
int T1[N], T2[N];
int type[N];
int seq[N], tmp[N], f[N];
char line[2*N];
int n, m, s;

bool dfs(int Q[], int u, int t)
{
	int i;
	type[u] = -t;
	for (i=1; i<=n; i++)
		if (G[u][i])
		{
			if (type[i] == -t) return false;
			if (type[i] == t && !dfs(Q, i, t)) return false;
		}
	type[u] = 0;	
	Q[s++] = u;
	return true;	
}

bool valid(int Q[], int t)
{
	int i;
	s = 0;
	for (i=1; i<=n; i++) if (type[i] == t && !dfs(Q, i, t)) return false;
	return true;
}

int check(int x)
{
	int s, i;
	for (i=0; i<m; i++) if (G[T1[i]][x]) break;
	s = i;
	for (; i<m; i++) if (!G[T1[i]][x]) return -1;
	return s;
}

int main()
{
	int u, x, i, j, k;
	while (scanf("%d %d\n", &n, &m), n > 0)
	{
		for (i=1; i<=n; i++)
		{
			gets(line);
			for (j=1; j<=n; j++) G[i][j] = line[(j-1)*2] - '0';
		}
		for (i=1; i<=n; i++) type[i] = 2;
		for (i=0; i<m; i++)
		{
			scanf("%d", &x);
			type[x] = 1;
		}
		if (valid(T1, 1) && valid(T2, 2))
		{
			printf("YES ");
			for (i=j=0; i<n-m; i++)
			{
				x = check(T2[i]);
				if (x != -1) seq[j++] = x;
			}
			if (!j) printf("0\n");
			else
			{
				x = f[0] = 1;
				tmp[0] = seq[0];
				u = 1;
				for (i=1; i<j; i++)
				{
					x = upper_bound(tmp, tmp + u, seq[i]) - tmp;
					tmp[x] = seq[i];
					if (x == u) u ++;
				}
				printf("%d\n", u);
			}
		}
		else printf("NO\n");
	}
	return 0;
}
