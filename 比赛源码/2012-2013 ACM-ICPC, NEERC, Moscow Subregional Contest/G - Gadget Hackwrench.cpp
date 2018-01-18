#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 100005

using namespace std;

int fa1[MAXN],fa2[MAXN];

int n,m;
int depth[MAXN];

int Index;
int head[MAXN],nxt[2*MAXN],node[2*MAXN];

int from[MAXN],to[MAXN];

int p[MAXN][20];
int deep[MAXN];

void init()
{
    Index = 0;
    memset(head,0,sizeof(head));
    memset(nxt,0,sizeof(nxt));

    deep[1] = 0;
    p[1][0] = 1;

    for(int i=1;i<=n;i++)
    {
        fa1[i] = i;
        fa2[i] = i;
    }
}

void addedge(int u,int v)
{
    Index++;
    nxt[Index] = head[u];
    node[Index] = v;
    head[u] = Index;
}

void dfs(int ret,int fa=-1)
{
    for(int j=1;j<20;j++)
        p[ret][j] = p[p[ret][j-1]][j-1];

    for(int o=head[ret];o;o=nxt[o])
        if(node[o] != fa)
        {
            p[node[o]][0] = ret;
            deep[node[o]] = deep[ret] + 1;
            dfs(node[o],ret);
        }
}

int getLca(int u,int v)
{
    if(deep[u] > deep[v])
        swap(u,v);

    for(int delta = deep[v]-deep[u],i=0;delta!=0;delta>>=1,++i)
        if(delta & 1) v = p[v][i];

    if(u == v) return u;

    for(int i=19;i>=0;i--)
    {
        if(p[u][i] == p[v][i]) continue;
        u = p[u][i],v = p[v][i];
    }
    return p[u][0];
}

int getfather1(int x)
{
    if(fa1[x] == x) return x;
    else return fa1[x] = getfather1(fa1[x]);
}

int getfather2(int x)
{
    if(fa2[x] == x) return x;
    else return fa2[x] = getfather2(fa2[x]);
}

int main()
{
    scanf("%d",&n);
    init();

    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&from[i],&to[i]);
        addedge(from[i],to[i]);
        addedge(to[i],from[i]);
    }

    dfs(1);

    for(int i=1;i<n;i++)
    {
        if(deep[from[i]] > deep[to[i]]) fa1[getfather1(from[i])] = getfather1(to[i]);
        else fa2[getfather2(from[i])] = getfather2(to[i]);
    }

    scanf("%d",&m);

    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        int shit = getLca(x,y);
        //cout<<shit<<endl;
        if(getfather1(x) == getfather1(shit) && getfather2(y) == getfather2(shit)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
