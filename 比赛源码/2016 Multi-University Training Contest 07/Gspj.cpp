#include <cstdio>
#include <vector>

using namespace std;

typedef long long lli;

const int N = 1000 + 10;

const lli A[] = {34, 40, 42, 47, 31, 22, 32, 38, 37, 44, 257487333899, 259949435314, 420192460228, 390819139760, 382404151310, 402322413932, 391904479455, 396168818917, 407825482583, 397753540187, 389333704072, 400876859707, 389649874400, 203558994991, 215481581172, 291173145822, 204412824412, 43956071085, 190397079130, 67931397483, 124270972634, 114226528172, 178534686859, 190950840720, 284155838874, 155154418816, 82481256099, 333134985718, 53709214710, 152758124379, 227787534248, 50091761685, 82458966945, 307848827360, 190259056075, 148209349775, 129777103773, 254465892315, 126148170612, 87231001225};

vector<int> V[N], W[N], T[N];
lli dst[N];
lli tot;

void dfs(int u, int p)
{
	int v, i, j;
	for (i=0; i<V[u].size(); i++)
	{
		v = V[u][i];
		if (v == p) continue;
		dst[v] = dst[u] + W[u][i];
		for (j=0; j<T[v].size(); j++) if (dst[v] <= T[v][j]) tot += dst[v];
		dfs(v, u);
	}
}

int main(int argc, char* argv[])
{
	lli res;
	int n, m, t, cn, u, v, w, i;
	FILE *in;
	in = fopen(argv[1], "r");
//	freopen(argv[2], "r", stdin);
	fscanf(in, "%d", &t);
	for (cn=0; cn<t; cn++)
	{
		fscanf(in, "%d %d", &n, &m);
		scanf("%lld", &res);
		if (res != A[cn])
		{
			printf("WA\n");
			return 0;
		}
		for (i=0; i<n-1; i++)
		{
			fscanf(in, "%d %d", &u, &v);
			scanf("%d", &w);
			if (w < 0 || w > 1000000000)
			{
				printf("WA\n", i, w);
				return 0;
			}
			V[u].push_back(v);
			V[v].push_back(u);
			W[u].push_back(w);
			W[v].push_back(w);
		}
		for (i=1; i<=m; i++)
		{
			fscanf(in, "%d %d", &u, &v);
			T[u].push_back(v);
		}
		for (i=1; i<=n; i++) dst[i] = 0;
		tot = 0;
		dst[1] = 0;
		dfs(1, -1);
		if (tot != res)
		{
			printf("WA\n", tot);
			return 0;
		}
		for (i=1; i<=n; i++)
		{
			V[i].clear();
			W[i].clear();
			T[i].clear();
		}
	}
	printf("AC!\n");
	return 0;
}
