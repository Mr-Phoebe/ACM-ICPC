#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<cctype>

using namespace std;


#define MAX 50010
struct Node
{
    int v;
    int next;
} E[2*MAX];

int head[MAX];
int dp[MAX][510];
bool vis[MAX];
int num,n,k,ans;


void init()
{
    memset(head,-1,sizeof(head));
    memset(dp,0,sizeof(dp));
    memset(vis,0,sizeof(vis));
    num=0;
    ans=0;
}
void add(int s,int t)
{
    E[num].v=t;
    E[num].next=head[s];
    head[s]=num++;
}
void dfs(int cur)
{
    vis[cur]=1;
    dp[cur][0]=1;
    int i,j;
    for(i=head[cur];i!=-1;i=E[i].next)
    {
        int v=E[i].v;
        if(!vis[v])
        {
            dfs(v);
            for(j=0;j<k;j++)//另一棵子树
                ans+=dp[cur][j]*dp[v][k-j-1];
            for(j=1;j<=k;j++)//回到父节点
                dp[cur][j]+=dp[v][j-1];
        }
    }
}

int main()
{
//    freopen("data.txt","r",stdin);
    while(scanf("%d %d",&n,&k) != EOF)
    {
        init();
        int s,t;
        for(int i=0;i<n-1;i++)
        {
            scanf("%d %d",&s,&t);
            add(s,t);
            add(t,s);
        }
        dfs(1);
        printf("%d\n",ans);
    }
}