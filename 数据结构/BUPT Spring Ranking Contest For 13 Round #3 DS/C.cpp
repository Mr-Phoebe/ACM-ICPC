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
#include <cmath>

using namespace std;

int  dp1[1010],dp2[1010];
float num[1010];

int main()
{
	int i,j,n,max;
	while(scanf("%d",&n)!=EOF)
	{
		memset(dp1,0,sizeof(dp1));
		memset(dp2,0,sizeof(dp2));
		memset(num,0,sizeof(num));
		max=0;
		for(i=1;i<=n;i++)
			scanf("%f",&num[i]);
		for(i=1;i<=n;i++)
		{
			dp1[i]=1;
			for(j=i-1;j>=1;j--)
				if(num[i]>num[j]&& dp1[i]<dp1[j]+1)
					dp1[i]=dp1[j]+1;
		}
		for(i=n;i>=1;i--)
		{
			dp2[i]=1;
			for(j=i+1;j<=n;j++)
				if(num[i]>num[j]&& dp2[i]<dp2[j]+1)
					dp2[i]=dp2[j]+1;
		}
		for(i=1;i<=n;i++)
			for(j=i+1;j<=n;j++)
                if(dp1[i]+dp2[j]>=max)
                    max=dp1[i]+dp2[j];
		printf("%d\n",n-max);
	}
	return 0;

}
