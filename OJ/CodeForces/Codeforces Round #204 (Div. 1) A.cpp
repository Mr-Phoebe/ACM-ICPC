#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;
int main ()
{
    int n,s1,s2,i;
    while(scanf("%d",&n)!=EOF)
	{
        double sum,x;
        for(i=0,s1=0,s2=0,sum=0;i<n+n;i++)
		{
            scanf("%lf",&x);
            int temp=(int)x;
            x=x-(double)temp;
            if(x!=0)
            sum+=x,s1++;
            else s2++;
        }
        int k=min(s1,n);
        double ans=100000000.0;
        for(i=0;i<=k;i++)
		{
            if(i+s2>=n)
            	ans=min(ans,fabs(sum-i*1.0));
        }
        printf("%.3f\n",ans);
    }
    return 0;
}
