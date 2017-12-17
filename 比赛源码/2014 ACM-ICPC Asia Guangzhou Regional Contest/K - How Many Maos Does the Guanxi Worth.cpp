#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <climits>
#include <cstring>
#define MAXN 35
#define MAXM 2005

using namespace std;

const int INF = INT_MAX / 2;

int head[MAXN],nxt[MAXM],node[MAXM],val[MAXM];
int n,m;
int Index = 0;

void addedge(int a,int b,int v)
{
    Index++;
    nxt[Index] = head[a];
    node[Index] = b;
    val[Index] = v;
    head[a] = Index;
}

void init()
{
    Index = 0;
    memset(head,0,sizeof(head));
    memset(nxt,0,sizeof(nxt));
}

struct Node
{
    int x;
    int d;

    Node(){}
    Node(int a,int b):x(a),d(b){}

    bool operator < (const Node &o) const
    {
        return d > o.d;
    }
};

priority_queue<Node> Q;

int d[MAXN];
int vis[MAXN];

void dij(int x)
{
    while(!Q.empty()) Q.pop();
    for(int i=1;i<=n;i++)
        d[i] = INF;

    memset(vis,false,sizeof(vis));
    d[1] = 0;
    Q.push(Node(1,0));

    while(!Q.empty())
    {
        Node tmp = Q.top();
        Q.pop();
        int xx = tmp.x;
        vis[xx] = true;

        for(int p=head[xx];p;p=nxt[p])
        if(node[p] != x && !vis[node[p]])
        {
            if(d[node[p]] > d[xx] + val[p])
            {
                d[node[p]] = d[xx] + val[p];
                Q.push(Node(node[p],d[node[p]]));
            }
        }
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        if(n == 0 && m == 0) break;

        init();

        for(int i=1;i<=m;i++)
        {
            int a,b,v;
            scanf("%d%d%d",&a,&b,&v);
            addedge(a,b,v);
            addedge(b,a,v);
        }

        int ans = 0;

        for(int i=2;i<n;i++)
        {
            dij(i);
            ans = max(ans,d[n]);
        }

        if(ans == INF) printf("Inf\n");
        else printf("%d\n",ans);
    }
    return 0;
}
