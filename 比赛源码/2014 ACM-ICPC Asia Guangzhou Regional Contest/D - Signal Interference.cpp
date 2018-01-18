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

double k;
int cas = 0;
int main()
{
    while(~scanf("%d%lf",&n,&k))
    {
        for(int i=0;i<n;i++) scanf("%lf%lf",&pt[i].x,&pt[i].y);

        Point A,B;
        scanf("%lf%lf%lf%lf",&A.x,&A.y,&B.x,&B.y);
        Point P1,P2;

        double r;

        P1 = Point(B.x+(B.x-A.x)/(1.0-k)*k , B.y+(B.y-A.y)/(1.0-k)*k);
        P2 = Point(B.x-(B.x-A.x)/(1.0+k)*k , B.y-(B.y-A.y)/(1.0+k)*k);
        //cout<<P1.x<<' '<<P1.y<<endl;
        //cout<<P2.x<<' '<<P2.y<<endl;
        r = dis(P1,P2)/2;

        //cout<<r<<endl;
        cas++;
        printf("Case %d: %.10lf\n",cas,solve(Point((P1.x+P2.x)/2 , (P1.y+P2.y)/2) , r));
    }
    return 0;
}
