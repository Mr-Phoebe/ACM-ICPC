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

using namespace std;

const int N=10002;
const int M=50002;
typedef struct node
{
    int v;
    int next;
};
node edge[M];
int head[N];
int n,m;
int scc;//强连通分量
int index;//每个节点的访问次序编号  时间戳
int cnt;//边的数量
int vis[N];//标记结点i的时间戳
int low[N];//记录节点u或u的子树中的所有节点的最小标号
int belong[N];//属于哪个分支
bool instack[N];//是否在栈中
int num[N];//记录一个强连通分量中结点的个数
int sstack[N];
int top;
int out[N];//出度
void addedge(int u,int v)
{
    edge[cnt].v=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
void tarjan(int u)
{
    vis[u]=low[u]=++index;
    sstack[++top]=u;
    instack[u]=true;
    for (int j=head[u];j!=-1;j=edge[j].next)
    {
        int v=edge[j].v;
        if(vis[v]==0)//未曾访问过
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(instack[v])
            low[u]=min(low[u],vis[v]);
    }
    if(vis[u]==low[u])
    {
        scc++;
        while(1)
        {
            int tmp=sstack[top--];
            instack[tmp]=0;
            belong[tmp]=scc;
            num[scc]++;
            if(tmp==u)
                break;
        }
    }
}
void solve()
{
    scc=top=index=0;
    int outnum;
    memset(num,0,sizeof(num));
    memset(vis,0,sizeof(vis));
    for (int i=1;i<=n;i++)
        if (!vis[i])
            tarjan(i);
    memset(out,0,sizeof(out));
    for (int i=1;i<=n;i++)
        for(int j=head[i];j!=-1;j=edge[j].next)
        {
            int u=belong[i];
            int v=belong[edge[j].v];
            if(u!=v)
                out[u]=1;
        }
    outnum=0;
    int aug;
    for(int i=1;i<=scc;i++)
    {
        if(!out[i])
        {
            outnum++;
            aug=i;
        }
    }
    if(outnum==1)
        printf("%d\n",num[aug]);
    else
         puts("0");
}
int main()
{
    while (scanf("%d%d",&n,&m)!=EOF)
 {
        cnt=0;
        memset(head,-1,sizeof(head));
        for (int i=1;i<=m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            addedge(a,b);
        }
        solve();
    }
}