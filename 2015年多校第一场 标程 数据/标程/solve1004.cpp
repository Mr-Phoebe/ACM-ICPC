#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
#define mod 1000000007
typedef long long lld;
int s[2010];
lld a[400010];
lld dp[2][400010];
void odd(int st,int num,lld add)
{
	a[st]+=add;
	a[st+num*2]-=add*2;
	a[st+(num+num)*2]+=add;
}
void even(int st,int num,lld add)
{
	a[st]+=add;
	a[st+num*2]-=add;
	a[st+(num+1)*2]-=add;
	a[st+(num+num+1)*2]+=add;
}
#define base 40005
int main()
{
	int cas;
	scanf("%d",&cas);
	for(int cc=1;cc<=cas;cc++)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&s[i]);
		int T=0;
		memset(dp,0,sizeof(dp));
		int now=0;
		int pre=1;
		dp[now][base]=1;
		for(int t=0;t<n;t++)
		{
			if(s[t] == 0)
				continue;
			int val=s[t];
			T+=val;
			now^=1;
			pre^=1;
			for(int i=base-T-4;i<=base+T+4;i++)
				dp[now][i]=a[i]=0;
			for(int i=base-T-4;i<=base+T+4;i++)
			{
				if(dp[pre][i] == 0)
					continue;
				int num;
				num=val/2+1;
				odd(i-num*2,num,dp[pre][i]);
				num=(val+1)/2;
				even(i-num*2-1,num,dp[pre][i]);
			}
			lld tot,v;
			tot=v=0;
			for(int i=base-T-4;i<=base+T+4;i+=2)
			{
				a[i]=(a[i]%mod+mod)%mod;
				tot=(tot+v)%mod;
				dp[now][i]=tot;
				v=(v+a[i])%mod;
			}
			tot=v=0;
			for(int i=base-T-4+1;i<=base+T+4;i+=2)
			{
				a[i]=(a[i]%mod+mod)%mod;
				tot=(tot+v)%mod;
				dp[now][i]=tot;
				v=(v+a[i])%mod;
			}
		}
		printf("%d\n",(int)dp[now][base]);
	}
	return 0;
}
/*
1
2
2 2

 */
