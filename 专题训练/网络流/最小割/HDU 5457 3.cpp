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
#define ls (idx<<1)
#define rs (idx<<1|1)
#define lson ls,l,mid
#define rson rs,mid+1,r

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

const int MAXN=10240;
const int MAXM=40000;


struct Node
{
    Node *ln[2];
    int cost;
    bool f;

    void init()
    {
        f=0;
        cost=INF;
        memset(ln,0,sizeof ln);
    }
};

struct Trie
{
    Node T[MAXN];
    int cnt,pos[MAXN];
    Node *rt;

    Node* get()
    {
        T[cnt].init();
        return &T[cnt++];
    }

    void init()
    {
        cnt=0;
        rt=get();
    }

    void insert(int *s,int j)
    {
        Node *p=rt;
        for(int i=0; i<8; i++)
        {
            int v=s[i];
            if(p->ln[v]==NULL)  p->ln[v]=get();
            p=p->ln[v];
        }
        p->f=1;
        pos[j]=p-rt;
    }

    void find(char *s,int cost)
    {
        Node *p=rt;
        for(int i=0; s[i]; i++)
        {
            int v=s[i]-'0';
            if(p->ln[v]==NULL)  return;
            p=p->ln[v];
        }
        p->cost=min(p->cost,cost);
    }

} pre,su;

struct Dinic
{
    struct Edge
    {
        int to,next;
        ll f;
    } e[MAXM];
    int n,src,sink;
    int head[MAXN];
    int tot;

    void addedge(int u,int v,ll c)
    {
        e[++tot].to=v;
        e[tot].f=c;
        e[tot].next=head[u];
        head[u]=tot;
        e[++tot].to=u;
        e[tot].f=0;
        e[tot].next=head[v];
        head[v]=tot;
    }

    void Resize(int n)
    {
        this->n=n;
    }

    void Clear()
    {
        CLR(head,-1);
        tot=1;
    }

    bool vis[MAXN];
    int dist[MAXN];

    void bfs()
    {
        CLR(dist,0);
        queue<int> que;
        vis[src]=true;
        que.push(src);
        while(!que.empty())
        {
            int u=que.front();
            que.pop();
            for(int i=head[u]; ~i; i=e[i].next)
            {
                if(e[i].f>0 && !vis[e[i].to])
                {
                    que.push(e[i].to);
                    dist[e[i].to]=dist[u]+1;
                    vis[e[i].to]=true;
                }
            }
        }
    }

    ll dfs(int u,ll delta)
    {
        if(u==sink || delta==0)
            return delta;
        else
        {
            ll ret=0;
            for(int i=head[u]; ~i; i=e[i].next)
                if(e[i].f && dist[e[i].to]==dist[u]+1)
                {
                    ll dd=dfs(e[i].to,min(e[i].f,delta));
                    e[i].f-=dd;
                    e[i^1].f+=dd;
                    delta-=dd;
                    ret+=dd;
                }
            return ret;
        }
    }

    ll MaxFlow(int s,int t)
    {
        ll ret=0;
        this->src=s;
        this->sink=t;
        while(1)
        {
            CLR(vis,0);
            bfs();
            if(!vis[sink])
                return ret;
            ret+=dfs(src,LLINF);
        }
    }

    void print()
    {
        puts("GRAPH:");
        for(int i=0; i<n; i++)
        {
            if(head[i]==-1)    continue;
            printf("%d ->",i);
            for(int j=head[i]; ~j; j=e[j].next)
                printf("%d(%lld) ",e[j].to,e[j].f);
            putchar('\n');
        }
    }

};

Dinic g;

int n,m,ss,tt;
int a[9];
char str[9],x[9];

void dfs(Node *p,int flag)
{
    if(flag)
    {
        if(p->ln[0])
        {
            g.addedge(p->ln[0]-su.rt+pre.cnt,p-su.rt+pre.cnt,p->ln[0]->cost);
            dfs(p->ln[0],1);
        }
        if(p->ln[1])
        {
            g.addedge(p->ln[1]-su.rt+pre.cnt,p-su.rt+pre.cnt,p->ln[1]->cost);
            dfs(p->ln[1],1);
        }
    }
    else
    {
        if(p->ln[0])
        {
            g.addedge(p-pre.rt,p->ln[0]-pre.rt,p->ln[0]->cost);
            dfs(p->ln[0],0);
        }
        if(p->ln[1])
        {
            g.addedge(p-pre.rt,p->ln[1]-pre.rt,p->ln[1]->cost);
            dfs(p->ln[1],0);
        }
    }
}

void build()
{
    for(int i=1; i<=n; i++)
        g.addedge(pre.pos[i],su.pos[i]+pre.cnt,INF);
    dfs(pre.rt,0);
    dfs(su.rt ,1);
}

int main()
{
    //freopen("data.txt","r",stdin);
    int T,cas=1;
    read(T);
    while(T--)
    {
        read(n),read(m);
        pre.init();su.init();g.Clear();
        for(int i=1,x; i<=n; i++)
        {
            read(x);
            for(int j=0; j<8; j++)
                if(x&(1<<7-j))  a[j]=1;
                else    a[j]=0;
            pre.insert(a,i);
            for(int j=0; j<8; j++)
                if(x&(1<<j))    a[j]=1;
                else    a[j]=0;
            su.insert(a,i);
        }
        g.Resize(pre.cnt+su.cnt);
        ss=0;
        tt=pre.cnt;
        for(int i=1,cost; i<=m; i++)
        {
            scanf("%s %s %d",str,x,&cost);
            if(str[0]=='P') pre.find(x,cost);
            else
            {
                int len=strlen(x);
                reverse(x,x+len);
                su.find(x,cost);
            }
        }
        build();
        //g.print();
        ll ans=g.MaxFlow(ss,tt);
        printf("Case #%d: %lld\n",cas++,ans>=INF?-1:ans);
    }
    return 0;
}
