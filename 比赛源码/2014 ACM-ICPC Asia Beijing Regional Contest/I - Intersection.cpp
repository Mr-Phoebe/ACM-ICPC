#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#define eps 1e-8
#define maxn 1010
#define PI (acos(-1))
using namespace std;

int dlcmp(double x)
{
    return x<-eps?-1:x>eps;
}

double sqr(double x)
{
    return x*x;
}
struct Point
{
    double x,y;
    Point(){};
    Point(double xx,double yy):x(xx),y(yy){};
    Point operator - (const Point &a) const {return Point(x-a.x,y-a.y);}
    Point operator + (const Point &a) const {return Point(x+a.x,y+a.y);}
    //double operator * (const Point &a) const {return x*a.x+y*a.y;}

    Point trunc(double d)
    {
        double dis(Point,Point);
        double len = dis(*this,Point(0,0));
        return Point(x*d/len,y*d/len);
    }
    Point rotate(double a)
    {
        return Point( x*cos(a)-y*sin(a),y*cos(a)+x*sin(a) );
    }


};

double dot(Point a,Point b)
{
    return a.x*b.x+a.y*b.y;
}

struct Segment
{
    Point s,e;
    Segment(){}
    Segment(Point ss,Point ee):s(ss),e(ee){}
};

struct Rectangle
{
    Point lt;
    Point rb;
};

struct Circle
{
    Point o;
    double r;

    Circle(){}
    Circle(Point a,double l):o(a),r(l){}

    double area(){return sqr(r)*PI;}
};
double cross(double x1,double y1,double x2,double y2)
{
    return x1*y2-x2*y1;
}

double cross(Point a,Point b)
{
    return a.x*b.y-b.x*a.y;
}

double cross(Point a,Point b,Point s)
{
    double x1=a.x-s.x,y1=a.y-s.y;
    double x2=b.x-s.x,y2=b.y-s.y;

    return x1*y2-x2*y1;
}
double dis(Point a,Point b)
{
    return sqrt( (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y) );
}

int inter_circle(Circle c1,Circle c2,Point &p1,Point &p2)
{
    double len=dis(c1.o,c2.o);

    if( dlcmp(len - c1.r - c2.r)>0 ) return 0;
    double s = ( sqr(c1.r)-sqr(c2.r)+sqr(len) )/len/2;
    double h = sqrt( sqr(c1.r) - sqr(s) );
    Point vec=c2.o-c1.o;
    Point p0 = c1.o+vec.trunc(s);

    p1 = p0+vec.rotate(PI/2).trunc(h);
    p2 = p0-vec.rotate(PI/2).trunc(h);
    return 1;
}

double vec_angle(Point a,Point b)
{
    double tmp=dot(a,b)/(dis( a,Point(0,0) )*dis( b,Point(0,0) ));

    if(dlcmp(tmp-1)>=0) tmp = 1;
    if(dlcmp(tmp+1)<=0) tmp = -1;
    return acos(tmp);
}
double arc_area(Point a,Point b,Circle c)
{
    double theta = vec_angle(a-c.o,b-c.o);
    double sf = sqr(c.r)*theta/2.0;
    double st = sqr(c.r)*sin(theta)/2.0;
    if(dlcmp(cross(a,b,c.o))>0)
        return sf-st;
    else
        return c.area()-sf+st;
}

double circle_and(Circle a,Circle b)
{
    if( dlcmp(dis(a.o,b.o) - a.r - b.r) >=0 ) return 0;

    if(a.r>b.r) swap(a,b);
    if(dlcmp(b.r - dis(a.o,b.o) - a.r)>=0) return a.area();

    Point p1,p2;

    inter_circle(a,b,p1,p2);
    return abs( arc_area(p2,p1,a) + arc_area(p1,p2,b) );
}
int t,cas;
double R,r;

int main()
{
    scanf("%d",&t);
    for(int cas = 1;cas <= t;cas++)
    {
        Circle a1,a2,b1,b2;

        scanf("%lf%lf",&r,&R);
        scanf("%lf%lf",&a1.o.x,&a1.o.y);
        scanf("%lf%lf",&b1.o.x,&b1.o.y);
        a2.o = a1.o;
        b2.o = b1.o;
        a1.r = r;
        a2.r = R;
        b1.r = r;
        b2.r = R;
        //cout<<circle_and(a2,b2)<<endl;
        double ans = circle_and(a2,b2) - circle_and(a2,b1) - ( circle_and(a1,b2) - circle_and(a1,b1) );

        printf("Case #%d: %.6lf\n",cas,ans);
    }
    return 0;
}
