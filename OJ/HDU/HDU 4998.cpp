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
#define pi acos(-1.0)
#define eps 1e-10
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
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
    if(fabs(x) < eps)
        return 0;
    else
        return x<0? -1:1;
}

struct Point
{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
}a[11];

double p[11];

typedef Point Vector;

Vector operator + (Vector A,Vector B)
{
    return Vector(A.x+B.x,A.y+B.y);
}

Vector operator - (Vector A,Vector B)
{
    return Vector(A.x-B.x,A.y-B.y);
}

Vector operator * (Vector A,double p)
{
    return Vector(A.x*p,A.y*p);
}

double Dot(Vector A,Vector B)
{
    return A.x*B.x + A.y*B.y;
}

double Length(Vector A)
{
    return sqrt(Dot(A,A));
}

double Cross(Vector A,Vector B)
{
    return A.x*B.y - A.y*B.x;
}

Vector Rotate(Vector A,double rad)
{
    return Vector(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));
}

Vector Normal(Vector A)
{
    double L=Length(A);
    return Vector(-A.y/L,A.x/L);
}

bool noparallel(Vector A,Vector B)
{
    return Cross(A,B);
}

Point GetlineIntersection(Point P,Vector v,Point Q,Vector w)
{
    Vector u = P - Q;
    double t = Cross(w,u)/Cross(v,w);
    return P+v*t;
}


int main()
{
	int T,n;
	scanf("%d",&T);
	while(T--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%lf %lf %lf",&a[i].x,&a[i].y,&p[i]);
        Point b1(a[0].x-1,a[0].y-1),b2(a[0].x+1,a[0].y);
        Point t1(a[0].x-1,a[0].y-1),t2(a[0].x+1,a[0].y);
        for(int i=0;i<n;i++)
        {
            Vector t=t1-a[i];
            t1=a[i]+Rotate(t,p[i]);
            t=t2-a[i];
            t2=a[i]+Rotate(t,p[i]);
        }
        Point z1((t1.x+b1.x)/2,(t1.y+b1.y)/2);
        Point z2((t2.x+b2.x)/2,(t2.y+b2.y)/2);
        Point c=GetlineIntersection(z1,Normal(t1-b1),z2,Normal(t2-b2));
        Vector t3=b1-c,t4=t1-c;
        double ans=atan2(t4.y,t4.x)-atan2(t3.y,t3.x);
        if(ans<eps)
            ans+=2*pi;
        printf("%.10f %.10f %.10f\n",c.x,c.y,ans);
    }
    return 0;
}
