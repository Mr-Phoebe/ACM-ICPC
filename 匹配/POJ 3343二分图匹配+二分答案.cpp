#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <cmath>
#include <bitset>
#include <queue>
#include <vector>
using namespace std;

const int BORDER = (1<<26)-1;
const int MAXSIZE = 37;
const int MAXN = 300;
const int INF = 0x6ffffff;
#define CLR(x,y) memset(x,y,sizeof(x))
#define ADD(x) x=((x+1)&BORDER)
#define IN(x) scanf("%d",&x)
#define OUT(x) printf("%d\n",x)
#define MIN(m,v) (m)<(v)?(m):(v)
#define MAX(m,v) (m)>(v)?(m):(v)
#define ABS(x) ((x)>0?(x):-(x))

typedef struct
{
    int v,next;
    int val;
} Edge;
typedef struct
{
    int sh;
    int p;
} Node;
int n,m,ans,index;
int dist[MAXN][MAXN],net[MAXN],pre[MAXN];
bool visit[MAXN];
Edge edge[MAXN*MAXN];
Node hum[MAXN],mam[MAXN];

void add_edge(const int& u,const int& v)
{
    edge[index].v = v;
    edge[index].next = net[u];
    net[u] = index;
    ++index;
}
bool _check(const Node& a,const Node& b,const int& dis,const int& limit)
{
    if(limit < dis)
        return false;
    if(a.sh >= b.sh+(__int64)dis*b.p)
        return true;
    if(a.sh+(__int64)(limit-dis)*a.p >= b.sh+(__int64)limit*b.p)
        return true;
    return false;
}
int init()
{
    index = 0;
    ans = -1;
    CLR(net,-1);
    CLR(pre,-1);
    return 0;
}
int input()
{
    int i,j,a,b,val;
    for(i = 0; i < n; ++i)
        scanf("%d%d",&hum[i].sh,&hum[i].p);
    for(i = 0; i < m; ++i)
        scanf("%d%d",&mam[i].sh,&mam[i].p);
    for(i = 0; i < n; ++i)
        for(j = 0; j < m; ++j)
        {
            scanf("%d",&dist[i][j]);
        }
    return 0;
}
bool dfs(const int& u)
{
    int i,v;
    for(i = net[u]; i != -1; i = edge[i].next)
    {
        v = edge[i].v;
        if(!visit[v])
        {
            visit[v] = true;
            if(pre[v] == -1 || dfs(pre[v]))
            {
                pre[v] = u;
                return true;
            }
        }
    }
    return false;
}
int make_graph(const __int64& limit)
{
    int i,j,val,u,v,tmp;
    index = 0;
    CLR(net,-1);
    CLR(pre,-1);
    for(i = 0; i < n; ++i)
        for(j = 0; j < m; ++j)
        {
            if(_check(hum[i],mam[j],dist[i][j],limit))
                add_edge(i,j);
        }
    return 0;
}
int work()
{
    int i,j,tmp;
    __int64 b_low = 0;
    __int64 b_high = (1<<31)-1;
    __int64 b_mid;
    while(b_low <= b_high)
    {
        b_mid = (__int64)(b_low+b_high)>>1;
        make_graph(b_mid);
        tmp = 0;
        for(i = 0; i < n; ++i)
        {
            CLR(visit,0);
            if(dfs(i))
                ++tmp;
        }
        if(tmp == m)
        {
            ans = b_mid;
            b_high = b_mid - 1;
        }
        else
            b_low = b_mid + 1;
    }
    if(ans == -1)
        printf("IMPOSSIBLE\n");
    else
        OUT(ans);
    return 0;
}
int main()
{
    while(scanf("%d%d",&n,&m))
    {
        if(!n && !m)
            break;
        init();
        input();
        work();
    }
    return 0;
}
