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
#define idx(x,y) (x-1)*n+y
#define eps 1e-9
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

const int MAXN=3000;

struct Node
{
    int v , w , s ;
    int next ;
} e[8*MAXN];
int a[33][33],head[MAXN],tot ;
int pre[MAXN],vis[MAXN],dis[MAXN] ;
int cost,flow;
queue <int> Q ;

void init()
{
	CLR(head,-1);
 	tot=0 ;
}

void addedge(int u,int v,int w,int s)
{
    e[tot].v = v ; e[tot].w = w ; e[tot].s = s ;
    e[tot].next = head[u] ; head[u] = tot++ ;
    e[tot].v = u ; e[tot].w = 0 ; e[tot].s = -s ;
    e[tot].next = head[v] ; head[v] = tot++ ;
}
int spfa(int s,int t)
{
    int u , v , i ;
    CLR(dis,INF);
    dis[s] = 0 ; vis[s] = 1 ;
    pre[s] = pre[t] = -1 ;
    while( !Q.empty() )
        Q.pop();
    Q.push(s) ;
    while( !Q.empty() )
    {
        u = Q.front();
        Q.pop();
        vis[u] = 0 ;
        for(i = head[u] ; i != -1 ; i = e[i].next)
        {
            v = e[i].v ;
            if( e[i].w && dis[v] > dis[u] + e[i].s )
            {
                dis[v] = dis[u] + e[i].s ;
                pre[v] = i ;
                if( !vis[v] )
                {
                    vis[v] = 1 ;
                    Q.push(v) ;
                }
            }
        }
    }
    if( pre[t] == -1 )
        return 0 ;
    return 1 ;
}
int f(int s,int t)
{
    CLR(pre,-1);
    CLR(vis,0);
    int i,mi ;
    cost=flow=0;
    while(spfa(s,t))
    {
        mi=INF ;
        for(i=pre[t]; ~i ;i=pre[e[i^1].v])
            if(e[i].w < mi)
                mi = e[i].w ;
        flow+=mi;
    	cost+=dis[t]*mi;
        for(i=pre[t]; ~i ;i=pre[e[i^1].v])
        {
            e[i].w-=mi;
            e[i^1].w+=mi;
        }
    }
    return -cost;
}
int main()
{
    int i , j , n , b , base;
    while(read(n))
    {
    	init();
    	base = n*n ;
        for(i = 1 ; i <= n ; i++)
            for(j = 1 ; j <= n ; j++)
            {
                read(a[i][j]);
                addedge(idx(i,j),idx(i,j)+base,1,-a[i][j]);
            }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                if(j+1<=n)
                    addedge(idx(i,j)+base,idx(i,j+1),1,0);
                if(i+1<=n)
                    addedge(idx(i,j)+base,idx(i+1,j),1,0);
            }
        addedge(1,1+base,1,0);addedge(base,2*base,1,0);
        addedge(0,1,2,0);addedge(2*n*n,2*n*n+1,2,0);
        write(f(0,2*n*n+1)),putchar('\n');
    }
    return 0;
}