#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define maxn 1000000000
#define eps 1e-6
using namespace std;

int v1,v2,r,d;
double fabs(double x)
{
    if(x<0) return -x;
    return x;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t --)
    {
        scanf("%d%d%d%d",&v1,&v2,&r,&d);
        double V1,V2,R;
        V1=v1,V2=v2,R=r;
        double t=R*asin(V1/V2)/V1;
        double ans=V2*t;
        double D=d;
        if(fabs(D-ans)<eps || d>ans) printf("Wake up to code\n");
        else printf("Why give up treatment\n");
    }
    return 0;
}