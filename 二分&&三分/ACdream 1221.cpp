//      whn6325689
//		Mr.Phoebe
//		http://blog.csdn.net/u013007900
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
#include <functional>
#include <numeric>
#pragma comment(linker, "/STACK:1024000000,1024000000")


using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;

#define CLR(x,y) memset(x,y,sizeof(x))
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define lowbit(x) (x&(-x))
#define MID(x,y) (x+((y-x)>>1))
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LLINF 1LL<<62

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
//-----------------------------------


#define double long double
const double inf=1.0e40;
const double eps=1.0e-14;
const double zero=0.0;
const double one=1.0;
const double two=2.0;
const double three=3.0;

double b1,t1,b2,t2,l,ds,dt,g;

double calc(double d, double s, double b, double t)
{
    double c=d*(one-d/s);
    b=b/c;
    t=t/c; //cout<<b<<" "<<c<<endl;
    if(b>one)
        return g*s*(b+one/b)/two;
    else if(t<one)
        return g*s*(t+one/t)/two;
    else
        return g*s;
}

double getsp(double s)
{
    return max(calc(ds,ds+s,b1,t1),calc(dt,dt+l-s,b2,t2));
}

int main()
{
    while(cin>>b1>>t1>>b2>>t2>>l>>ds>>dt>>g)
    {
        double Left=zero, Right=l;
        for(int i=0; i<100; i++)
        {
            double mid=(Left*two+Right)/three;
            double midd=(Left+Right*two)/three;
            if(getsp(mid)<getsp(midd))
            {
                Right=midd;
            }
            else
            {
                Left=mid;
            }
        }
        cout<<setiosflags(ios::fixed);
        cout<<setprecision(8)<<sqrtl(getsp(Left))<<endl;
    }
    return 0;
}
