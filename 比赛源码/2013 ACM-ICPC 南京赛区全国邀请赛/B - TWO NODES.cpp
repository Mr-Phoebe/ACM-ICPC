#include <iostream>
#include <cstdio>
#include <cstring>
#define MAXN 5005
#define MAXM 10005

using namespace std;

int n,m;

int head[MAXN],node[MAXM],nxt[MAXM];
int Index;
int dfs_clock;

int ans;

int pre[MAXN],iscut[MAXN],low[MAXN];

void init()
{
    Index = 0;
    memset(head,0,sizeof(head));
    memset(nxt,0,sizeof(nxt));
    ans = -100000;
}

void addedge(int u,int v)
{
    Index++;
    nxt[Index] = head[u];
    node[Index] = v;
    head[u] = Index;
}

int dfs(int u,int fa,int x)
{
    int lowu = pre[u] = ++dfs_clock;
    int child = 0;
    for(int p=head[u];p;p=nxt[p])
    if(node[p] != x)
    {
        int v = node[p];
        if(!pre[v])
        {
            child++;
            int lowv = dfs(v,u,x);
            lowu = min(lowu,lowv);
            if(lowv >= pre[u])
            {//cout<<u<<' '<<v<<endl;
                iscut[u]++;
            }
        }
        else if(pre[v] < pre[u] && v != fa)
        {
            lowu = min(lowu,pre[v]);
        }
    }
    if(fa < 0 && child == 1) iscut[u] = 0;
    low[u] = lowu;
    return lowu;
}

void work(int x)
{
    memset(pre,0,sizeof(pre));
    memset(low,0,sizeof(low));
    memset(iscut,0,sizeof(iscut));
    dfs_clock = 0;

    int ret1 = 0;
    for(int i=0;i<n;i++)
    if(i != x)
    {
        if(!pre[i])
        {
            ret1++;
            dfs(i,-1,x);
            iscut[i]--;
        }
    }

    //cout<<x<<endl;
    //for(int i=0;i<n;i++) cout<<iscut[i]<<' ';
    //cout<<endl;

    int ret2 = -100000;
    for(int i=0;i<n;i++)
    if(i != x)
        ret2 = max(ret2,iscut[i]);
    //cout<<ret1<<' '<<ret2<<endl;
    ans = max(ans,ret1 + ret2);
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        init();

        for(int i=1;i<=m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            addedge(a,b);
            addedge(b,a);
        }

        for(int i=0;i<n;i++)
            work(i);

        printf("%d\n",ans);
    }
    return 0;
}