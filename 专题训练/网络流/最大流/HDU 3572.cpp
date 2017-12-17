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
//-----------------------------------

const int maxn = 2010;

struct Edge
{
    int from, to, cap, flow;
};

bool operator < (const Edge& a, const Edge& b)
{
    return a.from < b.from || (a.from == b.from && a.to < b.to);
}

struct ISAP
{
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[maxn];   // 邻接表，G[i][j]表示结点i的第j条边在e数组中的序号
    bool vis[maxn];        // BFS使用
    int d[maxn];           // 从起点到i的距离
    int cur[maxn];        // 当前弧指针
    int p[maxn];          // 可增广路上的上一条弧
    int num[maxn];        // 距离标号计数

    void AddEdge(int from, int to, int cap)
    {
        edges.push_back((Edge){from, to, cap, 0});
        edges.push_back((Edge){to, from, 0, 0});
        m = edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }

    bool BFS()
    {
        memset(vis, 0, sizeof(vis));
        queue<int> Q;
        Q.push(t);
        vis[t] = 1;
        d[t] = 0;
        while(!Q.empty())
        {
            int x = Q.front();
            Q.pop();
            for(int i = 0; i < G[x].size(); i++)
            {
                Edge& e = edges[G[x][i]^1];
                if(!vis[e.from] && e.cap > e.flow)
                {
                    vis[e.from] = 1;
                    d[e.from] = d[x] + 1;
                    Q.push(e.from);
                }
            }
        }
        return vis[s];
    }

    void Resize(int n)
    {
        this->n = n;
    }

    void ClearAll()
    {
        for(int i = 0; i < maxn; i++) G[i].clear();
        edges.clear();
    }

    void ClearFlow()
    {
        for(int i = 0; i < edges.size(); i++) edges[i].flow = 0;
    }

    int Augment()
    {
        int x = t, a = INF;
        while(x != s)
        {
            Edge& e = edges[p[x]];
            a = min(a, e.cap-e.flow);
            x = edges[p[x]].from;
        }
        x = t;
        while(x != s)
        {
            edges[p[x]].flow += a;
            edges[p[x]^1].flow -= a;
            x = edges[p[x]].from;
        }
        return a;
    }

    int Maxflow(int s, int t, int need)
    {
        this->s = s;
        this->t = t;
        int flow = 0;
        BFS();
        memset(num, 0, sizeof(num));
        for(int i = 0; i < n; i++) num[d[i]]++;
        int x = s;
        memset(cur, 0, sizeof(cur));
        while(d[s] < n)
        {
            if(x == t)
            {
                flow += Augment();
                if(flow >= need) return flow;
                x = s;
            }
            int ok = 0;
            for(int i = cur[x]; i < G[x].size(); i++)
            {
                Edge& e = edges[G[x][i]];
                if(e.cap > e.flow && d[x] == d[e.to] + 1)   // Advance
                {
                    ok = 1;
                    p[e.to] = G[x][i];
                    cur[x] = i; // 注意
                    x = e.to;
                    break;
                }
            }
            if(!ok)   // Retreat
            {
                int m = n-1; // 初值注意
                for(int i = 0; i < G[x].size(); i++)
                {
                    Edge& e = edges[G[x][i]];
                    if(e.cap > e.flow) m = min(m, d[e.to]);
                }
                if(--num[d[x]] == 0) break;
                num[d[x] = m+1]++;
                cur[x] = 0; // 注意
                if(x != s) x = edges[p[x]].from;
            }
        }
        return flow;
    }

    vector<int> Mincut()   // call this after maxflow
    {
        BFS();
        vector<int> ans;
        for(int i = 0; i < edges.size(); i++)
        {
            Edge& e = edges[i];
            if(!vis[e.from] && vis[e.to] && e.cap > 0) ans.push_back(i);
        }
        return ans;
    }

    void Reduce()
    {
        for(int i = 0; i < edges.size(); i++) edges[i].cap -= edges[i].flow;
    }

    void print()
    {
        printf("Graph:\n");
        for(int i = 0; i < edges.size(); i++)
            printf("%d->%d, %d, %d\n", edges[i].from, edges[i].to , edges[i].cap, edges[i].flow);
    }
};


ISAP g;

int main()
{
    int T,n,m,sou,sink,t,Cas=1,sum;
    read(T);
    while(T--)
    {
        read(n);read(m);
        g.ClearAll();
        sou=0;
        t=sink=sum=0;
        int st,p,e;
        for(int i=1;i<=n;i++)
        {
            read(p),read(st),read(e);
            t=max(t,e);sum+=p;
            g.AddEdge(sou,i,p);
            for(int j=st;j<=e;j++)
                g.AddEdge(i,j+n,1);
        }
        sink=t+n+1;
        for(int i=1;i<=t;i++)
            g.AddEdge(i+n,sink,m);
        g.Resize(sink);
        int flow=g.Maxflow(sou,sink,INF);
        printf("Case %d: ",Cas++);
        if(flow==sum)
            puts("Yes");
        else
            puts("No");
        puts("");
    }
    return 0;
}
