#include<stdio.h>
#include<string.h>

int cash,n,v[10100],dp[101000];//数组要开的足够大
int main()
{
	while(scanf("%d",&cash) != EOF)
	{
		memset(dp,0,sizeof(dp));
		memset(v,0,sizeof(v));
		scanf("%d",&n);
		int cnt = 0;
		for(int i = 1; i <= n ; i ++)
		{
			int a,b,t = 1;
			scanf("%d%d",&b,&a);
			if(b != 0)
			{
				while(t < b)//此处是把b按照二进制分开
				{
					b = b - t;
					v[cnt++] = a * t;
					t *= 2;
				}
				v[cnt++] = b*a;
			}
		}
		if(n == 0 || cash == 0)
		{
			printf("0\n");
			continue;
		}

		dp[0] = 1;
		for(int i = 0 ; i < cnt ; i ++)
			for(int j = cash ; j >= v[i] ; j --)
				dp[j-v[i]] == 1?dp[j] = 1:0;
		
		for(int i = cash; i >= 0;i--)
		{
			if(dp[i] == 1)
			{
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}