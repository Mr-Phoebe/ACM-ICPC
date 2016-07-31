#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define sz 1000
#define inf 0x3fffffff
using namespace std;
int n,m;
int a[sz],b[sz];
vector <int> p[sz];
vector <int> g[sz],ng[sz];
int low[sz],dfn[sz],stack[sz],instack[sz],belong[sz],cost[sz];
int deep,top,kinds;
void tarjan(int s)
{
    low[s] = dfn[s] = deep++;
    stack[++top] = s;
    instack[s]=1;
    for(int i=0; i<g[s].size(); i++)
    {
        int t = g[s][i];
        if(dfn[t] == -1)
        {
            tarjan(t);
            low[s] = min(low[t],low[s]);
        }
        else if(instack[t])
        {
            low[s] = min(dfn[t],low[s]);
        }
    }
    if(low[s] == dfn[s])
    {
        int t;
        int ct=0;
        do
        {
            t = stack[top--];
            belong[t] = kinds;
            instack[t] = 0;
            ct+=b[t];
        }
        while(t!=s);
        cost[kinds]=ct;
        kinds++;
    }
}

struct node{int s,t,v,nxt;}e[sz*10];
int hd[sz],dis[sz],cur[sz],que[sz],cnt,S,T;
void insert(int s,int t,int v){
    //printf("%d %d %d\n",s,t,v);
    e[cnt].s=s,e[cnt].t=t,e[cnt].v=v,e[cnt].nxt=hd[s],hd[s]=cnt++;
    e[cnt].s=t,e[cnt].t=s,e[cnt].v=0,e[cnt].nxt=hd[t],hd[t]=cnt++;
}
bool bfs(int s,int t,int n){
    int head=0,tail=0,i;
    memset(dis,-1,sizeof(dis[0])*(n+1)),dis[s]=0;
    que[tail++]=s;
    while(head<tail){
        for(i=hd[que[head++]];i!=-1;i=e[i].nxt)
            if(e[i].v>0&&dis[e[i].t]==-1){
                dis[e[i].t]=dis[e[i].s]+1;
                if(e[i].t==t)return 1;
                que[tail++]=e[i].t;
            }
    }
    return 0;
}
int dinic(int s,int t,int n){
    int i,mf=0,tp;
    while(bfs(s,t,n)){
        for(i=0;i<n;i++)cur[i]=hd[i];
        int u=s,tail=0;
        while(cur[s]!=-1){
            if(u!=t&&cur[u]!=-1&&e[cur[u]].v>0&&dis[u]+1==dis[e[cur[u]].t]){
                que[tail++]=cur[u];u=e[cur[u]].t;
            }
            else if(u==t){
                for(tp=inf,i=tail-1;i>=0;i--)tp=min(tp,e[que[i]].v);
                for(mf+=tp,i=tail-1;i>=0;i--){
                    e[que[i]].v-=tp;e[que[i]^1].v+=tp;
                    if(e[que[i]].v==0)tail=i;
                }
                u=e[que[tail]].s;
            }
            else {
                while(u!=s&&cur[u]==-1)u=e[que[--tail]].s;
                cur[u]=e[cur[u]].nxt;
            }
        }
    }
    return mf;
}
void make_map()
{
    for(int i=0; i<kinds + n; i++)
        ng[i].clear();
    for(int i=0; i<m; i++)
        for(int j=0; j<g[i].size(); j++)
        {
            int t = g[i][j];
            if(belong[i] != belong[t])
            {
                ng[belong[i]].push_back(belong[t]);
            }
        }
    for(int i=0;i<n;i++)
    {
        int id = i + kinds;
        for(int j=0;j<p[i].size();j++)
            ng[id].push_back(belong[p[i][j]]);
    }
    for(int i=0; i<kinds + n; i++)
    {
        sort(ng[i].begin(),ng[i].end());
        ng[i].resize( unique(ng[i].begin(),ng[i].end()) - ng[i].begin());
    }
    memset(hd,-1,sizeof(hd));
    cnt = 0;
    S = kinds + n;
    T = S + 1;
    for(int i=0;i<n;i++)
        insert(S,i+kinds,a[i]);
    for(int i=0;i<n+kinds;i++)
        for(int j=0;j<ng[i].size();j++)
            insert(i,ng[i][j],inf);
    for(int i=0;i<kinds;i++)
        insert(i,T,cost[i]);
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int cs;
    scanf("%d",&cs);
    for(int cas=1; cas<=cs; cas++)
    {
        scanf("%d%d",&n,&m);
        int sum = 0;
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]),sum+=a[i];
        for(int i=0; i<m; i++)
            scanf("%d",&b[i]);
        int num,c;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&num);
            p[i].clear();
            for(int j=0; j<num; j++)
            {
                scanf("%d",&c);
                p[i].push_back(c);
            }
        }
        for(int i=0; i<m; i++)
        {
            g[i].clear();
            for(int j=0; j<m; j++)
            {
                scanf("%d",&c);
                if(c)
                    g[i].push_back(j);
            }
        }
        memset(dfn,-1,sizeof(dfn));
        top = deep = kinds = 0;
        for(int i=0; i<m; i++)
            if(dfn[i]==-1)
                tarjan(i);
        make_map();
        int ret = sum - dinic(S,T,T+1);
        printf("Case #%d: %d\n",cas,ret);
    }
}
/*
2
2 3
10 10
6 6 6
2 0 1
2 1 2
0 0 0
0 0 0
0 0 0
2 3
10 10
6 10 6
2 0 1
2 1 2
0 0 0
0 0 0
0 0 0
*/





