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
#include <map>
#include <cmath>
#define CLR(x,y) memset(x,y,sizeof(x))
#define mp(x,y) make_pair(x,y)
#define eps 1e-9
#define INF 0x3f3f3f3f
#define LLINF 1LL<<62

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

template<class T>
inline bool read(T &n)
{
    T x = 0, tmp = 1; char c = getchar();
    while((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();
    if(c == EOF) return false;
    if(c == '-') c = getchar(), tmp = -1;
    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c = getchar();
    n = x*tmp;
    return true;
}
template <class T>
inline void write(T n)
{
    if(n < 0)
    {
        putchar('-');
        n = -n;
    }
    int len = 0,data[20];
    while(n)
    {
        data[len++] = n%10;
        n /= 10;
    }
    if(!len) data[len++] = 0;
    while(len--) putchar(data[len]+48);
}
//-----------------------------------

int dcmp(double x)
{
    if(fabs(x)<eps) return 0;
    return x<0?-1:1;
}

struct point
{
    double x,y;
    point (double x=0,double y=0):x(x),y(y){}
};
typedef point Vector;
Vector operator + (Vector a,Vector b){return Vector(a.x+b.x,a.y+b.y);}
Vector operator - (Vector a,Vector b){return Vector(a.x-b.x,a.y-b.y);}
Vector operator * (Vector a,double b){return Vector(a.x*b,a.y*b);}

double det(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
double dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
double lenth(Vector a){return sqrt(dot(a,a));}

struct line
{
    point p;
    Vector v;
    double angle;
    line(){}
    line(point p,Vector v):p(p),v(v){}
    bool operator <(const line &rht)const
    {
        return angle<rht.angle;
    }
};

struct circle
{
    point c;
    double r;
    circle(){c=point(0.0,0.0);}
    circle(point c,double r):c(c),r(r){}
    point Point(double rad)
    {
        return point(c.x+cos(rad)*r,c.y+sin(rad)*r);
    }
};

int get_circle_intersection(line L,circle C,double &t1,double &t2)
{
    t1=t2=0;
    double a=L.v.x, b=L.p.x-C.c.x,c=L.v.y,d=L.p.y-C.c.y;

    double e=a*a+c*c,f=2*(a*b+c*d),g=b*b+d*d-C.r*C.r;

    double detle = f*f-4*e*g;

    if(dcmp(detle)<0) return 0;
    if(dcmp(detle)==0) {t1=t2=-f/(2*e);return 1;}
    t1=(-f-sqrt(detle)) /(2*e);
    t2=(-f+sqrt(detle)) /(2*e);
    if(dcmp(t1)<0 || dcmp(t2)<0) return 0;//按照速度的反方向才可以和圆相交
    return 2;
}

int main()
{
    double t1,t2;
    double x1,x2;
    line tmp;
    circle tmp1;
    circle tmp2;
    double Rm, R, r;
    while(scanf("%lf %lf %lf %lf %lf %lf %lf",&Rm,&R,&r,&tmp.p.x,&tmp.p.y,&tmp.v.x,&tmp.v.y)!=EOF)
    {
        Rm+=r;R+=r;			//把这个小圆看成质点，并把固定园的半径加上小圆的半径。
        tmp1.r=Rm;
        tmp2.r=R;
        int count1=get_circle_intersection(tmp,tmp1,t1,t2);
        int count2=get_circle_intersection(tmp,tmp2,x1,x2);
        if(count2==0)
			printf("0.00\n");
        else
            printf("%.3lf\n",fabs(x2-x1)-fabs(t1-t2));
    }
    return 0;
}