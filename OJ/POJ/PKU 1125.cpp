#include<iostream>
#include<cstdio>

using namespace std;

const int len=111,maxx = 10000000;
int dp[len][len];

void flody(int n)
{
	for(int k=1;k<=n;k++)
		for( int i=1;i<=n;i++)
			for( int j=1;j<=n;j++)
				if(dp[i][j]>dp[i][k]+dp[k][j])
					dp[i][j]=dp[i][k]+dp[k][j];
}

void init(int n)
{
	for( int i=1;i<=n;i++)
	{
		for( int j=1;j<=n;j++)
			dp[i][j]=maxx;
		dp[i][i]=0;
	}
} 

int main()
{
	int n;
//	freopen("data.txt","r",stdin);
	while(~scanf("%d",&n),n)
	{
		init(n);
		for(int i=1;i<=n;i++)
		{
			int m,temp;
			scanf("%d",&m);
			for(int j=0;j<m;j++)
			{
				scanf("%d",&temp);
				scanf("%d",&dp[i][temp]);
			}
		}
		flody(n);
		int p=0,ans=maxx;
		for( int i=1;i<=n;i++)
		{
			int tmaxx=0;
			for(int j=1;j<=n;j++)
				if(tmaxx<dp[i][j])
					tmaxx=dp[i][j];
			if(ans>tmaxx)
			{
				ans=tmaxx;
				p=i;
			}
		}
		if(ans==maxx)
			printf("disjoint\n");
		printf("%d %d\n",p,ans);
	}
	return 0;
}
