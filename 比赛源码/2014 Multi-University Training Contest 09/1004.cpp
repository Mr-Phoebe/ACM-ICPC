#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 20;
const int inf = 1000000000;

char S[N*2+1], HS[N];
int W[N*2], HW[N];
char T1[N], T2[N];
vector<int> V[2][1<<(N+1)];
int pow[N+1];
int n;

inline int abs(int x)
{
	return x < 0 ? -x : x;
}

void search(int k, int type, int k1, int k2, int w1, int w2)
{
	int v, i;
	if (k1 + n - k < k2) return;
	if (k == n)
	{
		assert(k1 >= k2);
		v = 0;
		if (!type) 
		{
			for (i=k2; i<k1; i++) v = v * 2 + T1[i];
			V[0][v+pow[k1-k2]].push_back(w1);
		}
		else 
		{
			for (i=k1-1; i>=k2; i--) v = v * 2 + T1[i];
			V[1][v+pow[k1-k2]].push_back(w2);
		}
		return;
	}
	//put into T1
	if (k1 >= k2 || HS[k] == T2[k1])
	{
		T1[k1] = HS[k];
		search(k + 1, type, k1 + 1, k2, w1 + HW[k], w2);
	}
	//put into T2
	if (k2 >= k1 || HS[k] == T1[k2])
	{
		T2[k2] = HS[k];
		search(k + 1, type, k1, k2 + 1, w1, w2 + HW[k]);
	}
}

int main()
{
	int res, sum, x, ta, tb, k1, k2, i;
	for (i=0; i<=N; i++) pow[i] = (1<<i) - 1;
	while (scanf("%d", &n), n > 0)
	{
		scanf("%s", S);
		assert(1 <= n && n <= 20 && strlen(S) == n * 2);
		sum = 0;
		for (i=0; i<n*2; i++) 
		{
			scanf("%d", &W[i]);
			assert(W[i] > 0 && W[i] <= 1000000);
			sum += W[i];
		}
		ta = tb = 0;
		for (i=0; i<n*2; i++) 
		{
			if (S[i] == 'a') ta ++; else tb ++;
			S[i] -= 'a';
		}
		if (ta % 2 || tb % 2)
		{
			printf("-1\n");
			continue;
		}
		for (i=0; i<n; i++) 
		{
			HS[i] = S[i];
			HW[i] = W[i];
		}
		search(0, 0, 0, 0, 0, 0);
		for (i=0; i<n; i++)
		{
			HS[i] = S[2*n-i-1];
			HW[i] = W[2*n-i-1];
		}
		search(0, 1, 0, 0, 0, 0);
		res = inf;
		for (i=0; i<(1<<(n+1))-1; i++)
		{
			if (V[0][i].size() && V[1][i].size())
			{
				sort(V[0][i].begin(), V[0][i].end());
				sort(V[1][i].begin(), V[1][i].end());
				for (k1=0,k2=V[1][i].size()-1; k1<V[0][i].size(); k1++)
					for (; k2>=0; k2--)
					{
						x = V[0][i][k1] + V[1][i][k2];
						res = min(res, abs(sum - x * 2));
						if (x * 2 <= sum) break;
					}
			}
			V[0][i].clear();
			V[1][i].clear();
		}
		printf("%d\n", res == inf ? -1 : res);
	}
	return 0;
}
