#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define F first
#define S second
#define mp make_pair
#define LL long long
#define pb push_back
using namespace std;
#define sz 300005
#define inf 0x7fffffff

struct node
{
    int s,t,v,flag,nxt;
} e[sz*20];
int hd[sz],dis[sz],cur[sz],que[sz],cnt;
void insert(int s,int t,int v)
{
    //cout << s << " " << t << " " << v << endl;
    e[cnt].s=s,e[cnt].t=t,e[cnt].v=v,e[cnt].flag=0,e[cnt].nxt=hd[s],hd[s]=cnt++;
    e[cnt].s=t,e[cnt].t=s,e[cnt].v=0,e[cnt].flag=0,e[cnt].nxt=hd[t],hd[t]=cnt++;
}
bool bfs(int s,int t,int n)
{
    int head=0,tail=0,i;
    memset(dis,-1,sizeof(dis[0])*(n+1)),dis[s]=0;
    que[tail++]=s;
    while(head<tail)
    {
        for(i=hd[que[head++]]; i!=-1; i=e[i].nxt)
            if(e[i].v>0&&dis[e[i].t]==-1)
            {
                dis[e[i].t]=dis[e[i].s]+1;
                if(e[i].t==t)return 1;
                que[tail++]=e[i].t;
            }
    }
    return 0;
}
int dinic(int s,int t,int n)
{
    int i,mf=0,tp;
    while(bfs(s,t,n))
    {
        for(i=0; i<n; i++)cur[i]=hd[i];
        int u=s,tail=0;
        while(cur[s]!=-1)
        {
            if(u!=t&&cur[u]!=-1&&e[cur[u]].v>0&&dis[u]+1==dis[e[cur[u]].t])
            {
                que[tail++]=cur[u];
                u=e[cur[u]].t;
            }
            else if(u==t)
            {
                for(tp=inf,i=tail-1; i>=0; i--)tp=min(tp,e[que[i]].v);
                for(mf+=tp,i=tail-1; i>=0; i--)
                {
                    e[que[i]].v-=tp;
                    e[que[i]^1].v+=tp;
                    if(e[que[i]].v==0)tail=i;
                }
                u=e[que[tail]].s;
            }
            else
            {
                while(u!=s&&cur[u]==-1)u=e[que[--tail]].s;
                cur[u]=e[cur[u]].nxt;
            }
        }
    }
    return mf;
}
int v[sz],flag;
void dfs(int s,int cc)
{
    if(flag)return ;
    if(v[s]==1)
    {
        flag = 1;
        return ;
    }
    if(v[s]==2)return ;
    v[s]=1;
    for(int i=hd[s]; i!=-1; i=e[i].nxt)
    {
        if(e[i].v>0 && e[i].flag==0 && e[i^1].flag==0)
        {
            e[i].flag = 1;
            e[i^1].flag = 1;
            dfs(e[i].t,cc+1);
            e[i].flag = 0;
            e[i^1].flag = 0;
        }
    }
    v[s]=2;
}
int b[1005] , c[1005];
int main()
{
    int T;
    int n,m;
    scanf("%d",&T);
    int cas=1;
    while(~scanf("%d%d",&n,&m))
    {
        int S = n + m;
        int T = S + 1;
        memset(hd,-1,sizeof(hd));
        cnt = 0;
        int sum = 0;
        int a;
        rep(i,n)
        {
            scanf("%d",&a);
            b[i] = a;
            insert(S, i, a);
            sum += a;
        }
        int sum1 = 0;
        rep(i,m)
        {
            scanf("%d",&a);
            c[i] = a;
            insert(n+i, T, a);
            sum1 += a;
        }
        rep(i,n)
        rep(j,m)
        insert(i, n+j, 9);
        printf("Case #%d: ",cas++);
        if(sum == sum1 && sum==dinic(S,T,T+1))
        {
            memset(v,0,sizeof(v));
            flag = 0;
            rep(i,n+m)
            if(!flag && !v[i])
                dfs(i,0);
            if(flag)puts("So young!");
            else puts("So simple!");
        }
        else
            puts("So naive!");
    }
}
