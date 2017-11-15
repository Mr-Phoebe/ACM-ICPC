#include <bits/stdc++.h>

using namespace std;

const int MAXM = 1550;
const int MAXN = 1050;


int p[MAXM], num[MAXM];
int idx[MAXM];
bool dessert[MAXN][MAXM];
vector<int> edge[MAXM];


bool cmp(int i, int j)
{
	if(num[i] != num[j])	
		return num[i] < num[j];
	return p[i] < p [j];
}

void init(const int& n, const int& m)
{
	memset(dessert, 0, sizeof(dessert));
	for(int i = 0; i < m+3; i++)
	{
		edge[i].clear();
		idx[i] = i;
	}
}

int dp(int i)
{
	int sum = 0;
	for(auto v : edge[i])
		sum += num[v];
	if(sum < num[i])
		return p[i];
	
	int ans = 0;
	for(auto v : edge[i])
		ans += dp(v);
	return min(p[i], ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int n,m;
		scanf("%d %d", &n, &m);
		init(n, m);
		for(int i = 0; i < m; i++)
		{
			scanf("%d %d", &p[i], &num[i]);
			for(int j = 0, k; j < num[i]; j++)
			{
				scanf("%d", &k);
				dessert[i][k] = true;
			}
		}
		p[m] = 9999999;
		for(int i = 1; i <= n; i++)
			dessert[m][i] = true;
		num[m] = n;
		m++;
		sort(idx, idx+m, cmp);

		for(int i = 0; i < m; i++)
		{
			for(int j = i + 1; j < m; j++)
			{
				bool flag = true;
				for(int k = 1; k <= n; k++)
				{
					if(dessert[idx[i]][k] && !dessert[idx[j]][k])
					{
						flag = false;
						break;
					}
				}
				if(flag)
				{
					edge[idx[j]].push_back(idx[i]);
					break;
				}
			}
		}
		cout<<dp(m-1)<<endl;
	}
	return 0;
}
