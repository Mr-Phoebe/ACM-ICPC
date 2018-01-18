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
#define eps 1e-9
#define INF 0x3f3f3f3f
#define LLINF 1LL<<62

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


struct node{int x,y;}num[50055];
node operator-(const node &a,const node &b)
{node r;r.x=a.x-b.x;r.y=a.y-b.y;return r;}
int operator*(const node &a,const node &b)
{return a.x*b.y-a.y*b.x;}
int operator==(node a,node b)
{return a.x==b.x&&a.y==b.y;}
bool cmp(node a,node b){if(a.y==b.y) return a.x<b.x;return a.y<b.y;}
int i,l,r,n,c;node q[50055];
double minn,maxx;
void check(node a,node b)
{
   if(a.x>b.x)swap(a,b);
   if(a.x<=c&&b.x>=c)
   {
       if(a.x==c&&b.x==c)
       {
           maxx=max(maxx,(double)max(a.y,b.y));
           minn=min(minn,(double)min(a.y,b.y));
       } 
       else
       {
           double k=((double)c-a.x)/(b.x-a.x)*(b.y-a.y)+a.y;
           maxx=max(maxx,k);
           minn=min(minn,k);
       }
   }
   return;
}
int main()
{
   while(~scanf("%d%d",&n,&c))
   {
       minn=1e8,maxx=-1e8;
       for(i=1;i<=n;i++)scanf("%d",&num[i].x);
       for(i=1;i<=n;i++)scanf("%d",&num[i].y);
       if(n==1)
       printf("%.3f %.3f\n",(double)num[1].y,(double)num[1].y);
       else
       {
           sort(num+1,num+n+1,cmp);
           int offset=1;
           r=0;
           for(i=1;i;i+=offset)
           {
               if(i==n)offset=-1;
               while(r>1&&(num[i]-q[r])*(q[r]-q[r-1])>0)r--;
               if(!(num[i]==q[r]))q[++r]=num[i];
           }
           for(i=1;i<r;i++)check(q[i],q[i+1]);
       printf("%.3f %.3f\n",minn,maxx);
       }
   }
     return 0
}