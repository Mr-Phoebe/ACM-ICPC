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


const int MAXN=100010;

struct Edge
{
    int to,next;
} e[MAXN*2];

int head[MAXN],tot;
int top[MAXN],fa[MAXN];
int dep[MAXN],num[MAXN];
int p[MAXN],fp[MAXN];
int son[MAXN],pos;
bool vis[MAXN];

void init()
{
    tot=0;
    CLR(head,-1);
    pos=1;
    CLR(son,-1);
    CLR(vis,0);
}

void addedge(int u,int v)
{
    e[tot].to=v;
    e[tot].next=head[u];
    head[u]=tot++;
}

void dfs1(int u,int pre,int d)
{
    dep[u]=d;
    fa[u]=pre;
    num[u]=1;
    for(int i=head[u]; ~i; i=e[i].next)
    {
        int v=e[i].to;
        if(v!=pre)
        {
            dfs1(v,u,d+1);
            num[u]+=num[v];
            if(son[u]==-1 || num[v] > num[son[u]])
                son[u]=v;
        }
    }
}

void getpos(int u,int sp)
{
    top[u]=sp;
    p[u]=pos++;
    fp[p[u]]=u;
    if(son[u]==-1)
        return;
    getpos(son[u],sp);
    for(int i=head[u]; ~i; i=e[i].next)
    {
        int v=e[i].to;
        if(v!=son[u] && v!=fa[u])
            getpos(v,v);
    }
}

int LCA(int u,int v)
{
    int f1=top[u],f2=top[v];
    while(f1 != f2)
    {
        if(dep[f1] < dep[f2])
        {
            swap(f1,f2);
            swap(u,v);
        }
        u=fa[f1];
        f1=top[u];
    }
    return dep[u]<dep[v] ? u:v;
}

struct Node
{
    int l,r,fa,d;
    void insert(int a, int b, int c, int d)
    {
        this->l=a;
        this->r=b;
        this->fa=c;
        this->d=d;
    }
} q[MAXN];

bool cmp(Node a,Node b)
{
    return a.d > b.d;
}

void dfs(int u)
{
    vis[u]=1;
    for(int i=head[u]; ~i; i=e[i].next)
    {
        int v=e[i].to;
        if(!vis[v] && fa[u]!=v)
            dfs(v);
    }
}

int main()
{
//    freopen("data.txt","r",stdin);
    int n,m;
    while(read(n)&&read(m))
    {
        int u,v;
        init();
        for(int i=1; i<n; i++)
        {
            read(u),read(v);
            addedge(u,v);
            addedge(v,u);
        }
        dfs1(1,0,0);
        getpos(1,1);
        for(int i=0; i<m; i++)
        {
            read(u),read(v);
            int rot=LCA(u,v);
            q[i].insert(u,v,rot,dep[rot]);
        }
        sort(q,q+m,cmp);
        int ans=0;
        for(int i=0; i<m; i++)
        {
            if(vis[q[i].l] || vis[q[i].r])
                continue;
            ans++;
            dfs(q[i].fa);
        }
        write(ans),putchar('\n');
    }
    return 0;
}
