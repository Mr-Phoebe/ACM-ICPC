#include<stdio.h>
#include<string.h>
#define MAXN 1005
#define MAXM 100005
int amount[MAXN],value[MAXN];
int dp[MAXM];
int n,cash;
int max(int a,int b)
{
        return a>b ? a : b;
}
void CompletePack(int cost)//完全背包
{
    for(int v=cost;v<=cash;v++)
		dp[v]=max(dp[v],dp[v-cost]+cost);
}

void OneZeroPack(int cost)//01背包
{
        for(int v=cash;v>=cost;v--)
			dp[v]=max(dp[v],dp[v-cost]+cost);
}

void MultiplePack(int id)//多重背包
{
   if(value[id]*amount[id]>cash)
   {
        CompletePack(value[id]);
		return ;
   }
   int k=1;
   while(k<amount[id])
   {
		OneZeroPack(k*value[id]);
   		amount[id] -= k;
   		k *= 2;
   }
   OneZeroPack(amount[id]*value[id]);
}
int main()
{
        int i;
        int ans;
		while(scanf("%d%d",&cash,&n)!=EOF)
        {
                for(i=0;i<n;i++)
					scanf("%d%d",&amount[i],&value[i]);
                memset(dp,0,sizeof(dp));
                for(i=0;i<n;i++)
					MultiplePack(i);
                ans = 0;
                for(i=0;i<=cash;i++)
					if(dp[i]>ans)
						ans = dp[i];
                printf("%d\n",ans);
        }
        return 0;
}