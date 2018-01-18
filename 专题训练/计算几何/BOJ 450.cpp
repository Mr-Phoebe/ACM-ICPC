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

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
const int maxn = 3 * 1e5;

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
//---------------------------

const double eps = 1e-6;
const double INF = 1e50;
const double PI=acos(-1.0);
double L,lx,ly;

struct Point
{
    int x,y;
};

double dist(double a,double b,double x,double y)
{
    return (a-x)*(a-x)+(b-y)*(b-y);
}

Point locate(double x,double y)
{
    int a=floor((x-y/sqrt(3))/lx+eps);
    int b=floor(y/ly+eps);
    Point res;
    double mm=INF;
    for(int i=a-1;i<=a+1;i++)
    {
        for(int j=b-1;j<=b+1;j++)
        {
            double a,b;
            b=(double)j*ly;
            a=(double)i*lx+(double)b/sqrt(3.0);
            if(mm>dist(a,b,x,y))
            {
                mm=dist(a,b,x,y);
                res.x=i;
                res.y=j;
            }
        }
    }
    return res;
}

int main()
{

    int T;
    read(T);
    while(T--)
    {
        scanf("%lf",&L);
        ly=1.5*L;
        lx=sqrt(3.0)*L;
        double x,y;
        scanf("%lf %lf",&x,&y);
        Point s=locate(x,y);
        scanf("%lf %lf",&x,&y);
        Point e=locate(x,y);
//        printf("%d %d ==\n",s.x,s.y);
//        printf("%d %d ==\n",e.x,e.y);
        if((s.x<e.x&&s.y<e.y)||(s.x>e.x&&s.y>e.y))
            printf("%d\n",abs(s.x-e.x)+abs(s.y-e.y));
        else
            printf("%d\n",max(abs(s.x-e.x),abs(s.y-e.y)));
    }
    return 0;
}
