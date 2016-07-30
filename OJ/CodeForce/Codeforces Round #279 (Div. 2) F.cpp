//      whn6325689
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

const int MAXN=6010;

struct Egde
{
    int next,to;
}e[MAXN<<1];

int g[MAXN],val[MAXN],head[MAXN],cnt,n,ans,top;

void add_edge(int u,int v)
{
    e[cnt].to=v;
    e[cnt].next=head[u];
    head[u]=cnt++;
    e[cnt].to=u;
    e[cnt].next=head[v];
    head[v]=cnt++;
}

void dfs(int u,int top,int fa)
{
     int tmp,pos;
     if(top==0||val[u]>g[top])
     {
         pos=++top;
         tmp=g[top];
         g[top]=val[u];
         ans=max(ans,top);
     }
     else
     {
         pos=lower_bound(g+1,g+1+top,val[u])-g;
         tmp=g[pos];
         g[pos]=val[u];
     }
     for(int i=head[u];~i;i=e[i].next)
     {
         int v=e[i].to;
         if(v!=fa)
            dfs(v,top,u);
     }
     g[pos]=tmp;
}

int main()
{
    int x,y;
    while(read(n))
    {
        ans=cnt=0;
        CLR(head,-1);CLR(g,-1);
        for(int i=1;i<=n;i++)
            read(val[i]);
        for(int i=1;i<n;i++)
        {
            read(x),read(y);
            add_edge(x,y);
        }
        for(int i=1;i<=n;i++)
            dfs(i,0,-1);
        write(ans);
    }
    return 0;
}
