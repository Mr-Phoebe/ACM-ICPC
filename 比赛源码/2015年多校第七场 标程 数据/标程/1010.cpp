#include<cstdio>
#include<iostream>
#include<sstream>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<cctype>
#include<ctime>
#include<stack>
#include<queue>
#include<vector>
#include<bitset>
#include<set>
#include<map>
#define maxn 1009
using namespace std;
const int MOD=1e9+7;
vector<int>G[maxn];
int n,m,sz[maxn];
long long dp[maxn][maxn],inv[maxn],fact[maxn];
void dfs(int u,int fa)
{
	sz[u]=1;
	for(int i=0;i<(int)G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa) continue;
		dfs(v,u);
		sz[u]+=sz[v];
	}
}
long long Exp(long long a,int b)
{
	long long res=1;
	while(b)
	{
		if(b&1)res=res*a%MOD;
		a=a*a%MOD;
		b>>=1;
	}
	return res;
}
int main()
{
	int tt,cot=1;
	scanf("%d",&tt);
	fact[0]=1;
	for(int i=1;i<maxn;i++) fact[i]=fact[i-1]*i%MOD;
	for(int i=1;i<maxn;i++) inv[i]=Exp(i,MOD-2);
	while(tt--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) G[i].clear();
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1,-1);
		dp[0][0]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=i;j++)
			{
				dp[i][j]=0;
				if(j)
					dp[i][j]+=dp[i-1][j-1]*inv[sz[i]]%MOD;
				dp[i][j]+=dp[i-1][j]*(sz[i]-1)%MOD*inv[sz[i]]%MOD;
				dp[i][j]%=MOD;
			}
		}
		dp[n][m]%=MOD;dp[n][m]+=MOD;dp[n][m]%=MOD;
		printf("Case #%d: %I64d\n",cot++,dp[n][m]*fact[n]%MOD);
	}
	//system("pause");
	return 0;
}