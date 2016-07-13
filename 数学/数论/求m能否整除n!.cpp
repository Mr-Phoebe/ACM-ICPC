#include <stdio.h>
#include <iostream>
using namespace std;
long long num[100000],Prime[100000],res[100000];
int main (void)
{
    long long  i,j,k,count,h,temp,t;
    long long  m,n;
   
    while((scanf("%lld%lld",&n,&m))==2)
    {
        if(n==0&&m==1)
            {printf("1 divides 0!\n"); continue;}
        if(n==0&&m!=1)
            {printf("%lld does not divide 0!\n",m);continue;}
        if(m==0)
            {printf("0 does not divide %lld!\n",n);continue;}
        temp=m;
        count=0;
        memset(num,0,sizeof(num));
        memset(Prime,0,sizeof(Prime));
        memset(res,0,sizeof(res));
        h=0;
        for(i=2;i*i<=m;i++)
        {
            if(m%i==0)
            {
                while(m%i==0)
                {
                    Prime[h]=i;    //质因子 
                    num[h]++;      //个数 
                    m/=i;
                }
                h++;
            }   
        }
         
        Prime[h]=m;
        num[h]++;
        t=0;
        for(j=0;j<=h;j++)
        {
            if(Prime[j]!=1)
            {
                t++;
                for(k=Prime[j];k<=n;k*=Prime[j])
                    res[j]+=n/k;
                if(res[j]>=num[j])
                    count++;
            }
        }
        if(count==t)
            printf("%lld divides %lld!\n",temp,n);
        else
            printf("%lld does not divide %lld!\n",temp,n);
    }
    return 0;
}