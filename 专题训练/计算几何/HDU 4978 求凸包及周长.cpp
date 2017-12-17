/*author: birdstorm*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <complex>
#include <set>
#include <algorithm>
#include <climits>

#define MAXN 105
//#define N 105
#define inf 1.0e20
#define eps 1.0e-14
#define MOD 1000000007

#define next(i) (i+1)%sz

#define For(i,m,n) for(int i=(m);i<(n);i++)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define rep(i,m,n) for(int i=(m);i<=(n);i++)
#define repd(i,m,n) for(int i=(m);i>=(n);i--)
#define LL long long
#define test

using namespace std;
const double pi=acos(-1.0);
template<class T>
inline bool read(T &n)
{
    T x = 0, tmp = 1;
    char c = getchar();
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

struct point
{
    double x,y;
    point():x(0),y(0) {}
    point(double x,double y):x(x),y(y) {}
    point operator + (const point &a) const
    {
        return point(x+a.x,y+a.y);
    }
    point operator - (const point &a) const
    {
        return point(x-a.x,y-a.y);
    }
    bool operator < (const point &a) const
    {
        return x+eps<a.x || abs(x-a.x)<eps && y+eps<a.y;
    }
    bool operator == (const point &a) const
    {
        return abs(x-a.x)<eps && abs(y-a.y)<eps;
    }
    point operator * (double c) const
    {
        return point(c*x,c*y);
    }
    point operator / (double c) const
    {
        return point(x/c,y/c);
    }
};
double det(const point &a, const point &b)
{
    return a.x*b.y-a.y*b.x;
}
point zero(0,0);
int dlcmp(double x)
{
    return x<-eps?-1:x>eps;
}
double cross(point a, point b)
{
    return a.x*b.y-b.x*a.y;
}
double dist(point a, point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

struct Polygon_convex
{
    vector<point> P;
    Polygon_convex(int Size=0)
    {
        P.resize(Size);
    }
    double calc()
    {
        double ans=0;
        int sz=P.size();
        P.push_back(P[0]);
        For(i,0,sz)
            ans+=dist(P[i],P[i+1]);
        P.pop_back();
        P.resize(sz);
        return ans;
    }
};

bool cmp_less(const point &a, const point &b)
{
    return dlcmp(a.x-b.x)<0||dlcmp(a.x-b.x)==0&&dlcmp(a.y-b.y)<0;
}

Polygon_convex convex_hull(vector<point> a)
{
    Polygon_convex res(2*a.size()+5);
    sort(a.begin(),a.end(),cmp_less);
    a.erase(unique(a.begin(),a.end()),a.end());
    int m=0;
    for(int i=0; i<a.size(); ++i)
    {
        while(m>1&&dlcmp(det(res.P[m-1]-res.P[m-2],a[i]-res.P[m-2]))<=0)
            m--;
        res.P[m++]=a[i];
    }
    int k=m;
    for(int i=(int)(a.size())-2; i>=0; i--)
    {
        while(m>k&&dlcmp(det(res.P[m-1]-res.P[m-2],a[i]-res.P[m-2]))<=0)
            m--;
        res.P[m++]=a[i];
    }
    res.P.resize(m);
    if(a.size()>1) res.P.resize(m-1);
    return res;
}


int main()
{
    Polygon_convex A;
    point a;
    vector<point> S;
    int t, cs=1;
    int n;
    double d;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        cin>>d;
        S.clear();
        For(i,0,n)
        {
            cin>>a.x>>a.y;
            S.push_back(a);
        }
        A=convex_hull(S);
        printf("Case #%d: %.4f\n",cs++,A.calc()/pi/d);
    }
    return 0;
}
