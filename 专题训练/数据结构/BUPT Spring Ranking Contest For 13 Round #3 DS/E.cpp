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
#include <cmath>

using namespace std;

const int N=1008;
int vis[N],val[N],p[N];
int first[N*2],node[N*2],dep[N*2],dp[N*2][25];
int mi[25];//移位运算
vector<int>t[N];//邻接表
int lc[N],in[N],n;

void dfs(int &index,int u,int d)
{
    index++;//时间搓,全部遍历一次并记录所有节点的父亲，为查找公共祖先做准备
    node[index]=u;
    dep[index]=d;
    vis[u]=1;
    first[u]=index;
    for(int i=0;i<t[u].size();i++)
    {
        if(!vis[t[u][i]])
        {
            dfs(index,t[u][i],d+1);
            index++;
            node[index]=u;
            dep[index]=d;
        }
    }
}

void rmq_init(int n)//RMQ预处理
{
    int K=(int)(log((double)n)/log(2.0));
    for(int i=1;i<=n;i++)
        dp[i][0]=i;
    for(int j=1;j<=K;j++)
        for(int i=1; i-1+mi[j]<=n;i++)
        {
            int a=dp[i][j-1];
            int b=dp[i+mi[j-1]][j-1];
            if(dep[a]<dep[b])
                dp[i][j] = a;
            else
                dp[i][j] = b;
        }
}

int rmq(int x,int y)
{
    int k=(int)(log((double)(y-x+1))/log(2.0));
    int a=dp[x][k];
    int b=dp[y+1-mi[k]][k];
    if(dep[a]<dep[b])//最近公共祖先的深度
        return a;
    else
        return b;
}

int lca(int a,int b)
{
    int x=first[a];
    int y=first[b];
    int k;
    if(x>y)//可用swap，但是我以前用了超时，所以再也不敢用了。
    {
        k=rmq(y,x);
        return node[k];
    }
    else
    {
        k=rmq(x,y);
        return node[k];
    }
}

int main()
{
    for(int i=0;i<20;i++)
        mi[i]=1<<i;
//    freopen("data.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        memset(in,0,sizeof(in));
        for(int i=0;i<=n;i++)
            t[i].clear();
        for(int i=0;i<n;i++)
        {
            int a,b,m;
            scanf("%d:(%d)",&a,&m);
            for(int j=0;j<m;j++)
            {
                scanf("%d",&b);
                t[a].push_back(b);
                t[b].push_back(a);
                in[b]++;
            }

        }
        memset(vis,0,sizeof(vis));
        int tot=0,m;
        for(int i=1;i<=n;i++)
            if(!in[i])
                dfs(tot,i,1);
        rmq_init(tot);
        scanf("%d",&m);
        getchar();
        memset(lc,0,sizeof(lc));
        for(int i=0;i<m;i++)
        {
            int a,b;
            scanf(" (%d %d)",&a,&b);
            lc[lca(a,b)]++;
        }
        for(int i=1;i<=n;i++)
            if(lc[i])
                printf("%d:%d\n",i,lc[i]);
    }
    return 0;
}
