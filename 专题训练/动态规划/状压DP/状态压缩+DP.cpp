#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

struct pe
{
	int l;
	int hour;
}a[111];
int dp[1<<16+1];
int m,ans=0;

int main()
{
//	freopen("data.txt","r",stdin);
	int n;
	while(scanf("%d",&n)&&n)
	{
		ans=0;
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++)
		{
			scanf("%d %d",&m,&a[i].l);
			int be,en;
			a[i].hour=0;
			for(int j=0;j<m;j++)
			{
				scanf("%d %d",&be,&en);
				
				for(int k=be-6;k<en-6;k++)
					a[i].hour|=1<<k;
			}
			for(int j=0;j<1<<16;j++)
			{
				if(!(j&a[i].hour))
				{
	   				int tmp=j|a[i].hour;
	                dp[tmp]=max(dp[tmp],dp[j]+a[i].l);
	                ans=max(ans,dp[tmp]);
	            }
	         }
		 }
         printf("%d\n",ans);
	}
	return 0;
}