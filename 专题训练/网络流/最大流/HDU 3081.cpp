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
//----------------------------------------------

const int M=10100;const int N=300;

struct ISAP
{
    struct nedge
    {
        int u,v,next;
        ll c;
    } e[M*2];
    int head[N],tot,n;
    int ss,tt;

    void resize(int n)
    {
        this->n=n;
    }

    void clear()
    {
        tot=1;
        CLR(head,0);
    }

    void Addedge(int u,int v,ll w)
    {
        e[++tot].v=v;
        e[tot].u=u;
        e[tot].c=w;
        e[tot].next=head[u];
        head[u]=tot;
        e[++tot].v=u;
        e[tot].u=v;
        e[tot].c=0;
        e[tot].next=head[v];
        head[v]=tot;
    }

    int dep[N],gap[N];

    void bfs()
    {
        CLR(dep,-1);
        CLR(gap,0);
        queue<int> que;
        gap[0]=1;
        dep[tt]=0;
        que.push(tt);
        while(!que.empty())
        {
            int u=que.front();
            que.pop();
            for(int i=head[u]; i; i=e[i].next)
                if(dep[e[i].v]==-1)
                {
                    que.push(e[i].v);
                    dep[e[i].v]=dep[u]+1;
                    ++gap[dep[e[i].v]];
                }
        }
    }

    int res,cur[N],num[N];
    int top;
    int MaxFlow(int s,int t)
    {
        this->ss=s;
        this->tt=t;
        bfs();
        top=res=0;
        memcpy(cur,head,sizeof(head));
        int u=ss,i;
        while(dep[ss]<n)
        {
            if(u==tt)
            {
                int temp=INF;
                int inser;
                for(i=0; i<top; i++)
                    if(temp>e[num[i]].c)
                    {
                        temp=e[num[i]].c;
                        inser=i;
                    }
                for(i=0; i<top; i++)
                {
                    e[num[i]].c-=temp;
                    e[num[i]^1].c+=temp;
                }
                res+=temp;
                top=inser;
                u=e[num[top]].u;
            }
            if(u!=tt && gap[dep[u]-1]==0)
                break;
            for(i=cur[u]; i; i=e[i].next)
                if(e[i].c != 0 && dep[u]==dep[e[i].v]+1)
                    break;
            if(i)
            {
                cur[u]=i;
                num[top++]=i;
                u=e[i].v;
            }
            else
            {
                int mi=n;
                for(i=head[u]; i; i=e[i].next)
                    if(e[i].c>0 && mi>dep[e[i].v])
                    {
                        mi=dep[e[i].v];
                        cur[u]=i;
                    }
                --gap[dep[u]];
                dep[u]=mi+1;
                ++gap[dep[u]];
                if(u!=ss)
                    u=e[num[--top]].u;
            }
        }
        return res;
    }

    void print()
    {
        puts("GRAPH:");
        for(int i=0; i<=n; i++)
        {
            if(!head[i])
                continue;
            printf("%d ->",i);
            for(int j=head[i]; j; j=e[j].next)
                printf("%d(%I64d) ",e[j].v,e[j].c);
            putchar('\n');
        }
    }
};

struct DisjointSet
{
    vector<int> father,rank;
    DisjointSet() {}
    DisjointSet(int n):father(n+1),rank(n+1)
    {
        for(int i=1;i<=n;i++)
            father[i]=i;
    }
    void clear(int n)
    {
        father.resize(n+1);rank.resize(n+1);
        for(int i=1;i<=n;i++)
            father[i]=i, rank[i]=0;
    }
    int find(int v)
    {
        return father[v]=father[v]==v? v:find(father[v]);
    }
    void merge(int x,int y)
    {
        int a=find(x),b=find(y);
        if(a==b)
            return;
        if(rank[a]<rank[b])
        {
            father[a]=b;
        }
        else
        {
            father[b]=a;
            if(rank[b]==rank[a])
                ++rank[a];
        }
    }

};

ISAP g;
DisjointSet d;
vector<pii> match;
int G[N][N];

void build_graph(int cap,int n,int m)
{
    g.clear();
    CLR(G,0);
    for(int i=1; i<=n; i++)
    {
        g.Addedge(0,i,cap);
        g.Addedge(i+n,2*n+1,cap);
    }
    for(int i=0; i<m; i++)
    {
        int u=match[i].first,v=match[i].second;
        for(int j=1; j<=n; j++)
            if(d.find(u)==d.find(j)&&!G[j][v])
            {
                G[j][v]=1;
                g.Addedge(j, v+n, 1);
            }
    }
    g.resize(2*n+2);
}

int main()
{
//    freopen("data.txt","r",stdin);
	int n,m,f,T,a,b;
	read(T);
	while(T--)
    {
        read(n),read(m),read(f);
        d.clear(n);
        match.clear();
        for(int i=0;i<m;i++)
        {
            read(a),read(b);
            match.push_back(make_pair(a,b));
        }
        for(int i=0;i<f;i++)
        {
            read(a),read(b);
            d.merge(a,b);
        }
        int l=0,r=101,mid,ans=0;
        while(l<=r)
        {
            mid=(r+l)>>1;
            build_graph(mid,n,m);
            //g.print();
            if(g.MaxFlow(0,2*n+1)==mid*n)
            {
                ans=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        write(ans);putchar('\n');
    }
    return 0;
}
