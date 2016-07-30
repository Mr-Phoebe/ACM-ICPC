#include <string>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cmath>
#define eps 1e-8
using namespace std;

const double PI=acos(-1.0);

double X0,Y0,v0,theta,t,g,R;

int n;


struct Point
{
    double x,y;
    Point(){}
    Point(double xx,double yy):x(xx),y(yy){}
};
Point pt[105];
Point o;

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
    return (a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x);
}

double inner(Point a,Point b,Point c)
{
    return (a.x-c.x)*(b.x-c.x)+(a.y-c.y)*(b.y-c.y);
}

double calc_area(Point a,Point b,Point c,double r)
{
    double A,B,C,x,y,tS;

    A=dis(b,c);
    B=dis(a,c);
    C=dis(b,a);

    if(A<r&&B<r)
        return outer(a,b,c)/2;
    else if(A<r&&B>=r)
    {
        x=(inner(a,c,b)+sqrt(sqr(r)*sqr(C)-sqr(outer(a,c,b))))/C;
        tS=outer(a,b,c)/2;

        return asin(tS*(1-x/C)*2/r/B)*sqr(r)/2+tS*x/C;
    }
    else if(A>=r&&B<r)
    {
        y=(inner(b,c,a)+sqrt(sqr(r)*sqr(C)-sqr(outer(b,c,a))))/C;
        tS=outer(a,b,c)/2;

        return asin(tS*(1-y/C)*2/r/A)*sqr(r)/2+tS*y/C;
    }
    else if(fabs(outer(a,b,c))>=r*C || inner(b,c,a)<=0 || inner(a,c,b)<=0)
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
        x=(inner(a,c,b)+sqrt(sqr(r)*sqr(C)-sqr(outer(a,c,b))))/C;
        y=(inner(b,c,a)+sqrt(sqr(r)*sqr(C)-sqr(outer(b,c,a))))/C;
        tS=outer(a,b,c)/2;

        return (asin(tS*(1-x/C)*2/r/B)+asin(tS*(1-y/C)*2/r/A))*sqr(r)/2+tS*((y+x)/C-1);
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
        //cout<<sum<<endl;
    }
    return fabs(res);
}

int main()
{
    while(~scanf("%lf%lf%lf%lf%lf%lf%lf",&X0,&Y0,&v0,&theta,&t,&g,&R))
    {
        if(dlcmp(X0) == 0 && dlcmp(Y0) == 0 && dlcmp(v0) == 0 && dlcmp(theta) == 0 && dlcmp(t) == 0 && dlcmp(g) == 0 && dlcmp(R) == 0)
            break;
        double xx,yy;
        xx = X0 + v0*cos(theta/180.0*PI)*t;
        yy = Y0 + v0*sin(theta/180.0*PI)*t - 0.5*g*t*t;
//cout<<xx<<' '<<yy<<endl;
        o = Point(xx,yy);

        scanf("%d",&n);

        for(int i=0;i<n;i++)
            scanf("%lf%lf",&pt[i].x,&pt[i].y);

        printf("%.2lf\n",fabs(solve(o,R)) );
    }
    return 0;
}
