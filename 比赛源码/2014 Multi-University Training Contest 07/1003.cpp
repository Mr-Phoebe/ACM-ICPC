#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
long long n,lim;
bool can2(int a1,int a2)
{
    long long w,k;
    w=n-a2;
    if (w%a1==0) k=w/a1;
    else return 0;
    if (k>a1&&k>a2)
    {
        lim=min(lim,k);
        return 1;
    }
    return 0;
}
bool can3(int a1,int a2,int a3)
{
    long long a,b,c;
    a=a1;
    b=a2;
    c=a3-n;
    long long deta;
    deta=b*b-4*a*c;
    if (deta>0)
    {
        long long now;
        now=sqrt(deta);
        if (now*now==deta)
        {
            long long q,k;
            q=-b+now;
            if (q%(2*a)==0)
            {
                k=q/(2*a);
                if (k>a1&&k>a2&&k>a3)
                {
                    lim=min(lim,k);
                    return 1;
                }
            }
        }
    }
    return 0;
}
bool can(int w)
{
    long long now=n;
    while (now)
    {
        long long k=now%w;
        if (k!=3&&k!=4&&k!=5&&k!=6) return 0;
        now/=w;
    }
    return 1;
}
int main()
{
    int t;
    scanf("%d",&t);
    for (int cas=1;cas<=t;cas++)
    {
        scanf("%I64d",&n);
        lim=n;
        if (n==3||n==4||n==5||n==6)
        {
            printf("Case #%d: -1\n",cas);
            continue;
        }
        long long ans=0;
        for (int i=3;i<=6;i++)
            for (int j=3;j<=6;j++)
                if (can2(i,j))
                {
                    ans++;
                   // printf("i=%d j=%d\n",i,j);
                }
        for (int i=3;i<=6;i++)
            for (int j=3;j<=6;j++)
                for (int k=3;k<=6;k++)
                    if (can3(i,j,k))
                    {
                       // printf("i=%d j=%d k=%d\n",i,j,k);
                        ans++;
                    }
        for (int i=4;i<min(10000LL,lim);i++)
        {
            if (can(i))
            {
                ans++;
                //printf("www=%d\n",i);
            }
        }
        printf("Case #%d: %I64d\n",cas,ans);
    }
    return 0;
}

