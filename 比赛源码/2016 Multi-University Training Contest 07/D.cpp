#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>

using namespace std;

const int N = 100000 + 10;
const int M = 1000000;
const int inf = 1000000000;

vector<int> V[M+1];
vector< pair<int, int> > F[M+1];
int cnt[M+1], sf[M+1], tb[(1<<21)+1], tmp[M+1], fresh[M+1];
bool flag[M+1];
int D[M+1];
int C[M+1][21];

void init()
{
	int i, j;
	for (i=1; i<=M; i++) sf[i] = i;
	for (i=2; i*i<=M; i++) if (sf[i] == i) for (j=i*i; j<=M; j+=i) if (sf[j] == j) sf[j] = i;
}

int decomp(int x)
{
	int s, y, f, i;
	if (cnt[x] != -1) return cnt[x];
	y = x;
	cnt[y] = 0;
	while (x > 1)
	{
		f = sf[x];
		s = 0;
		do
		{
			x /= sf[x];
			s ++;
		}while (x > 1 && sf[x] == f);
		F[y].push_back(make_pair(f, s));
		cnt[y] += s;
	}
	return cnt[y];
}

void search(int x, int k, int f)
{
	if (k == F[x].size()) V[x].push_back(f);
	else
	{
		search(x, k + 1, f);
		for (int i=1; i<=F[x][k].second; i++)
		{
			f *= F[x][k].first;
			search(x, k + 1, f);
		}
	}
}

void cal(int x)
{
	if (V[x].size()) return;
	decomp(x);
	search(x, 0, 1);
}

int main()
{
	int res, q, cn, x, y, z, top, i;
	char cmd;
	memset(cnt, -1, sizeof(cnt));
	init();
	for (i=0; i<21; i++) tb[1<<i] = i;
	cn = 0;
	while (scanf("%d\n", &q), q > 0)
	{
		printf("Case #%d:\n", ++ cn);
		memset(flag, false, sizeof(flag));
		top = 0;
		while (q --)
		{
			scanf("%c %d\n", &cmd, &x);
			if (cmd == 'I')
			{
				if (!flag[x])
				{
					flag[x] = true;
					cal(x);
					for (i=0; i<V[x].size(); i++)
					{
						y = V[x][i];
						if (fresh[y] != cn)
						{
							tmp[top++] = y;
							fresh[y] = cn;
						}
						int s = decomp(x / y);
						C[y][s] ++;
						if (C[y][s] == 1) D[y] ^= (1<<s);
					}
				}
			}
			else if (cmd == 'D')
			{
				if (flag[x])
				{
					flag[x] = false;
					for (i=0; i<V[x].size(); i++)
					{
						y = V[x][i];
						int s = decomp(x / y);
						C[y][s] --;
						if (C[y][s] == 0) D[y] ^= (1<<s);
					}
				}
			}
			else
			{
				cal(x);
				res = inf;
				for (i=0; i<V[x].size(); i++)
				{
					y = V[x][i];
					if (!D[y]) continue;
					z = tb[D[y]&(-D[y])] + decomp(x / y);
					if (z < res) res = z;
				}
				if (res == inf) printf("-1\n"); else printf("%d\n", res);
			}
		}
		for (i=0; i<top; i++) 
		{
			D[tmp[i]] = 0;
			memset(C[tmp[i]], 0, sizeof(C[tmp[i]]));
		}
	}
	return 0;
}
