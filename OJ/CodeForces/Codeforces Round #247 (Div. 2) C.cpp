#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <cmath>

using namespace std;
typedef long long ll;

const ll mod=1000000007;
int n,k,d,now;
ll dp[2][111][111];//DP表示方案总数，就不用考虑儿子了 
ll ans=0;

int main()
{
	scanf("%d %d %d",&n,&k,&d);
	for(int i=1;i<=k;i++)      //从根节点出发的第二层初始化 
		dp[now][i][i]=1;
	for(int i=d;i<=n;i++)      //更新ans 
		ans=(ans+dp[now][n][i])%mod;
	for(int i=0;i<n;i++)
	{
		now=!now;memset(dp[now],0,sizeof(dp[now]));//下一层的只和上一层的有关 
		for(int j=1;j<=n;j++)
			for(int z=1;z<=k;z++)
			{
				if(dp[!now][j][z])
				{
					for(int m=1;m<=z;m++)//最大值为z 
						if(j+m<=n)
							dp[now][j+m][z]=(dp[!now][j][z]+dp[now][j+m][z])%mod;
					for(int m=z+1;m<=k;m++)//最大值比z大 
						if(j+m<=n)
							dp[now][j+m][m]=(dp[!now][j][z]+dp[now][j+m][m])%mod;
				}	
			}
		for(int j=d;j<=k;j++)//每一层的ans更新 
			ans=(ans+dp[now][n][j])%mod;
	}
	printf("%I64d\n",ans);
	return 0;
} 