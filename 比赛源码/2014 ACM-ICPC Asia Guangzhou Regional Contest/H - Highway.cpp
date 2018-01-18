#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define eps 1e-8
#define N 550

using namespace std;

const double PI = acos(-1.0);

struct Point
{
    double x,y;

    Point(){}
    Point(double xx,double yy):x(xx),y(yy){}
};

Point pt[N];
int n;

int dlcmp(double x)
{
    return x<-eps?-1:x>eps;
}

double sqr(double x)
{
    return x*x;
}

double dis(Point a,Point b)
{
    return sqrt(sqr(a.x-b.x) + sqr(a.y-b.y));
}

double outer(Point a,Point b,Point c)
{
    return (a.x-c.x)*(b.y-c.y) - (a.y-c.y)*(b.x-c.x);
}

double inner(Point a,Point b,Point c)
{
    return (a.x-c.x)*(b.x-c.x) + (a.y-c.y)*(b.y-c.y);
}

double calc_area(Point a,Point b,Point c,double r)
{
    double A,B,C,x,y,tS;

    A = dis(b,c);
    B = dis(a,c);
    C = dis(b,a);

    if(A < r && B < r)
        return outer(a,b,c)/2;
    else if(A < r && B >= r)
    {
        x = (inner(a,c,b) + sqrt(sqr(r)*sqr(C) - sqr(outer(a,c,b))))/C;
        tS = outer(a,b,c)/2;

        return asin(tS*(1-x/C)*2/r/B)*sqr(r)/2+tS*x/C;
    }
    else if(A >= r && B < r)
    {
        y = (inner(b,c,a)+sqrt(sqr(r)*sqr(C)-sqr(outer(b,c,a))))/C;
        tS = outer(a,b,c)/2;

        return asin(tS*(1-y/C)*2/r/A)*sqr(r)/2+tS*y/C;
    }
    else if(fabs(outer(a,b,c)) >= r*C || inner(b,c,a)<=0 || inner(a,c,b)<=0)
    {
        if(inner(a,b,c)<0)
        {
            if(outer(a,b,c)<0)
                return (-PI-asin(outer(a,b,c)/A/B))*sqr(r)/2;
            else
                return (PI-asin(outer(a,b,c)/A/B))*sqr(r)/2;
        }
        else
            return asin(outer(a,b,c)/A/B)*sqr(r)/2;
    }
    else
    {
        x = (inner(a,c,b)+sqrt(sqr(r)*sqr(C) - sqr(outer(a,c,b))))/C;
        y = (inner(b,c,a)+sqrt(sqr(r)*sqr(C) - sqr(outer(b,c,a))))/C;
        tS = outer(a,b,c)/2;

        return (asin(tS*(1-x/C)*2/r/B) + asin(tS*(1-y/C)*2/r/A))*sqr(r)/2 + tS*((y+x)/C-1);
    }
}

double solve(Point o,double r)
{
    int i,j;
    double res,sum;
    Point tri[3];

    res = 0;
    for(i=1;i<n-1;i++)
    {
        tri[0] = pt[0];
        tri[1] = pt[i];
        tri[2] = pt[i+1];
        sum = 0;

        for(j=0;j<3;j++)
            sum += calc_area(tri[j],tri[(j+1)%3],o,r);
        res += sum;
    }
    return fabs(res);
}


double v0,v1,D,T;
int cas = 0;

int main()
{
    while(~scanf("%lf%lf%lf%lf",&v0,&v1,&D,&T))
    {
        double x1;
        double x2;
        double xie;

        int j;
        double sum;
        double left = D/v0, right = T;
        for (int i = 0; i <= 100; i++)
        {
            double lmid = (left+right)/2, rmid = (lmid+right)/2;
            double d1 = (sqrt(v0*lmid*v0*lmid-D*D)+v1*(T-lmid));
            double d2 = (sqrt(v0*rmid*v0*rmid-D*D)+v1*(T-rmid));
            if (d1 > d2) right = rmid;
            else left = lmid;
        }
        double t = (left+right)/2;
        x2 = sqrt(v0*t*v0*t-D*D)+v1*(T-t);
        x1 = sqrt(v0*t*v0*t-D*D);
        xie = sqrt(x1*x1 + D*D);
        Point o = Point(0,-D);
        double r = T*v0;
        double ans;
        if (r <= D ) ans = PI*r*r;
        else
        {
            n = 3;
            pt[0] = Point(r/xie*x1 , r/xie*D - D);
            pt[1] = Point(x2,0);
            pt[2] = Point(r/xie*x1 , -(r/xie*D - D));
            sum = solve(o,r);
            ans = PI*r*r - 2*fabs(sum) + 2*(r/xie*D - D)*(x2-r/xie*x1);
        }
        cas++;
        printf("Case %d: %.8lf\n",cas,ans);
    }
    return 0;
}
