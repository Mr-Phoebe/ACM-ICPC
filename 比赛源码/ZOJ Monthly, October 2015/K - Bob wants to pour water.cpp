#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define MAXN 100005
#define PI acos(-1.0)
#define eps 1e-8

using namespace std;

int dlcmp(double x)
{
    if(x < -eps) return -1;
    if(x > eps) return 1;
    return 0;
}

int t;
int m,n;

double w,l,v;

double z1[MAXN],z2[MAXN],a[MAXN],b[MAXN],c[MAXN],r[MAXN];

double cal(double h)
{
    double ret = 0;
    for(int i=1;i<=m;i++)
    {
        if(h < z1[i] - c[i]/2.0) {}
        else if(h > z1[i] + c[i]/2) ret += a[i]*b[i]*c[i];
        else ret += a[i]*b[i]*(h - (z1[i] - c[i]/2.0));
    }

    for(int i=1;i<=n;i++)
    {
        if(h < z2[i] - r[i]) {}
        else if(h > z2[i] + r[i]) ret += 4.0 * PI * r[i] * r[i] * r[i] / 3.0;
        else
        {
            double hh = h - (z2[i] - r[i]);
            ret += 1.0 * PI * (3*r[i] - hh) * hh * hh / 3.0;
        }
    }
    return ret;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf",&w,&l,&v);

        scanf("%d%d",&m,&n);

        for(int i=1;i<=m;i++)
            scanf("%lf%lf%lf%lf",&z1[i],&a[i],&b[i],&c[i]);

        for(int i=1;i<=n;i++)
            scanf("%lf%lf",&z2[i],&r[i]);

        double L = 0.0 , R = 1000000000000000.0;

        int t = 0;
        while(t <= 100)
        {
            t++;
            double mid = (R+L)/2.0;
            //cout<<mid<<' '<<cal(mid)<<endl;
            if(mid * w * l - cal(mid) <= v + eps)
                L = mid;
            else R = mid;
        }
        printf("%.6lf\n",L);
    }
}
