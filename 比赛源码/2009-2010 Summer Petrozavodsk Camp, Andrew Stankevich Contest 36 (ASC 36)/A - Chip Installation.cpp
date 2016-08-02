
//      whn6325689
//      Mr.Phoebe
//      http://blog.csdn.net/u013007900
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

#define eps 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LLINF 1LL<<62
#define speed std::ios::sync_with_stdio(false);

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;

#define CLR(x,y) memset(x,y,sizeof(x))
#define CPY(x,y) memcpy(x,y,sizeof(x))
#define clr(a,x,size) memset(a,x,sizeof(a[0])*(size))
#define cpy(a,x,size) memcpy(a,x,sizeof(a[0])*(size))
#define debug(a) cout << #a" = " << (a) << endl;
#define debugarry(a, n) for (int i = 0; i < (n); i++) { cout << #a"[" << i << "] = " << (a)[i] << endl; }

#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define lowbit(x) (x&(-x))

#define MID(x,y) (x+((y-x)>>1))
#define getidx(l,r) (l+r | l!=r)
#define ls getidx(l,mid)
#define rs getidx(mid+1,r)
#define lson l,mid
#define rson mid+1,r

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


const int N = 100010;
const int M = 400010;

struct Vertex
{
    int head;
} V[N],VV[N];

struct Edge
{
    int v,next;
} E[M],EE[M];

int top,topp,scc,idx,dfn[N],low[N],ind[N],belong[N],opp[N];

bool in[N],vis[N],color[N];

stack<int> S;

void init()
{
    top = topp = 0;
    memset(V,-1,sizeof(V));
    memset(VV,-1,sizeof(VV));
}

void add_edge(int u,int v)
{
    E[top].v = v;
    E[top].next = V[u].head;
    V[u].head = top++;
}

void add_edge2(int u,int v)
{
    EE[topp].v = v;
    EE[topp].next = VV[u].head;
    VV[u].head = topp++;
}

void tarjan(int u)
{
    dfn[u] = low[u] = ++idx;
    S.push(u);
    in[u] = true;
    for(int i=V[u].head; ~i; i=E[i].next)
    {
        int v = E[i].v;
        if(!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u],low[v]);
        }
        else if(in[v])
            low[u] = min(low[u],dfn[v]);
    }
    if(dfn[u] == low[u])
    {
        int v;
        do
        {
            v = S.top();
            S.pop();
            in[v] = false;
            belong[v] = scc;
        }
        while(u != v);
        scc++;
    }
}

void get_scc(int n)
{
    scc = idx = 0;
    memset(dfn,0,sizeof(dfn));
    memset(in,false,sizeof(in));
    for(int i=0; i<n; i++)
        if(!dfn[i])
            tarjan(i);
}

bool conflict(int n)
{
    for(int i=0; i<n; i++)
        if(belong[i<<1] == belong[i<<1|1])
            return true;
        else
        {
            opp[ belong[i<<1] ] = belong[i<<1|1];
            opp[ belong[i<<1|1] ] = belong[i<<1];
        }
    return false;
}

void rebuild(int n)
{
    memset(ind,0,sizeof(ind));
    for(int u=0; u<n; u++)
    {
        for(int j=V[u].head; ~j; j=E[j].next)
        {
            int v = E[j].v;
            if(belong[u] == belong[v])
                continue;
            ind[belong[u]]++;                   //ni'tu
            add_edge2(belong[v],belong[u]);
        }
    }
}

void paint(int u)
{
    for(int i=VV[u].head; ~i; i=EE[i].next)
    {
        int v = EE[i].v;
        if(!vis[v])
        {
            vis[v] = true;
            paint(v);
        }
    }
}

void topSort()
{
    memset(vis,false,sizeof(vis));
    memset(color,false,sizeof(color));
    queue<int> q;
    for(int i=0; i<scc; i++)
        if(!ind[i])
            q.push(i);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        if(vis[u])
            continue;
        vis[u] = true;
        color[u] = true;
        int v = opp[u];
        if(!vis[v])
        {
            vis[v] = true;
            paint(v);
        }
        for(int i=VV[u].head; ~i; i=EE[i].next)
        {
            int v = EE[i].v;
            if(--ind[v] == 0)
                q.push(v);
        }
    }
}

int num[N];
int ty[N];
int pos1[N],pos2[N];

int main()
{
    freopen("chip.in","r",stdin);
    freopen("chip.out","w",stdout);
    int n,m;
    while(~scanf("%d",&n))
    {
        init();
        for(int i=0; i<n; i++)
            scanf("%d",&num[i]);
        for(int i=0; i<2*n; i++)
        {
            scanf("%d",&ty[i]);ty[i]--;
            if(pos1[ty[i]]) pos2[ty[i]]=i;
            else    pos1[ty[i]]=i;
        }

        for(int i=0; i<2*n; i++)
        {
            int next=(i+1)%(2*n);
            if(num[ty[next]]==num[ty[i]] && ty[next]!=ty[i])
            {
                if(pos1[ty[i]]==i)
                {
                    if(pos1[ty[next]]==(next))
                    {
                        add_edge(ty[i]<<1,(ty[next])<<1|1);
                        add_edge((ty[next])<<1,ty[i]<<1|1);
                    }
                    else
                    {
                        add_edge(ty[i]<<1,(ty[next])<<1);
                        add_edge((ty[next])<<1|1,ty[i]<<1|1);
                    }
                }
                else
                {
                    if(pos1[ty[next]]==(next))
                    {
                        add_edge(ty[i]<<1|1,(ty[next])<<1|1);
                        add_edge((ty[next])<<1,ty[i]<<1);
                    }
                    else
                    {
                        add_edge(ty[i]<<1|1,(ty[next])<<1);
                        add_edge((ty[next])<<1|1,ty[i]<<1);
                    }
                }
            }
            next=(i-1+2*n)%(2*n);
            if(num[ty[next]]==num[ty[i]] && ty[next]!=ty[i])
            {
                if(pos1[ty[i]]==i)
                {
                    if(pos1[ty[next]]==(next))
                    {
                        add_edge(ty[i]<<1,(ty[next])<<1|1);
                        add_edge((ty[next])<<1,ty[i]<<1|1);
                    }
                    else
                    {
                        add_edge(ty[i]<<1,(ty[next])<<1);
                        add_edge((ty[next])<<1|1,ty[i]<<1|1);
                    }
                }
                else
                {
                    if(pos1[ty[next]]==(next))
                    {
                        add_edge(ty[i]<<1|1,(ty[next])<<1|1);
                        add_edge((ty[next])<<1,ty[i]<<1);
                    }
                    else
                    {
                        add_edge(ty[i]<<1|1,(ty[next])<<1);
                        add_edge((ty[next])<<1|1,ty[i]<<1);
                    }
                }
            }
        }
        get_scc(n<<1);
        if(conflict(n))
            puts("NO");
        else
        {
            rebuild(n<<1);
            topSort();
            puts("YES");
            for(int i=0; i<n; i++)
                printf("%d ",color[ belong[i<<1] ] ? pos1[i]+1 : pos2[i]+1);
            puts("");
        }
    }
    return 0;
}
