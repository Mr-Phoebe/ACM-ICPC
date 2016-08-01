#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<set>
using namespace std;
typedef long long lld;
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define maxn 100010
lld a[200010];

lld prefixSuma(int x) {
    lld ans = 0;
    for (int i = x; i; i -= (i & -i))
        ans += a[i];
    return ans;
}
int limit;
void modifya(int x, lld v) {
    for (int i = x; i <= limit; i += (i & -i))
        a[i] += v;
}
lld b[200010];
lld prefixSumb(int x) {
    lld ans = 0;
    for (int i = x; i; i -= (i & -i))
        ans += b[i];
    return ans;
}
void modifyb(int x, lld v) {
    for (int i = x; i <= limit; i += (i & -i))
        b[i] += v;
}
struct Edge
{
    int v,next;
}edge[400010];
int head[maxn];
int pos;
void insert(int x,int y)
{
    edge[pos].v=y;
    edge[pos].next=head[x];
    head[x]=pos++;
}
vector<int>Q[maxn];
vector<int>val[maxn];
bool vis[maxn];
lld dp[maxn];
lld sum[maxn];
int fa[maxn];
int find(int x)
{
    if(fa[x] != x)
        fa[x]=find(fa[x]);
    return fa[x];
}
vector<pair<int,int> >ask[maxn];
vector<int>cost[maxn];
int l[maxn];
int r[maxn];
int T;
void ddd(int now,int pre)
{
    fa[now]=now;
    l[now]=++T;
    vis[now]=true;
    for(int i=head[now];i;i=edge[i].next)
    {
        int v=edge[i].v;
        if(v == pre)
            continue;
        ddd(v,now);
        fa[v]=now;
    }
    int len=Q[now].size();
    for(int i=0;i<len;i++)
    {
        int v=Q[now][i];
        if(vis[v])
        {
            int z=find(v);
            int x=v;
            int y=now;
            ask[z].pb(mp(x,y));
            cost[z].pb(val[now][i]);
        }
    }
    r[now]=++T;
}
void dfs(int now,int pre)
{
    vis[now]=true;
    dp[now]=0;
    sum[now]=0;
    for(int i=head[now];i;i=edge[i].next)
    {
        int v=edge[i].v;
        if(v == pre)
            continue;
        dfs(v,now);
        sum[now]+=dp[v];
    }
//    printf("%d\n",now);
//    for(int i=1;i<=7*2;i++)
//        printf("%I64d ",prefixSuma(i));
//    printf("\n");
    int len=ask[now].size();
    for(int i=0;i<len;i++)
    {
        int x=ask[now][i].X;
        int y=ask[now][i].Y;
        lld tmp=prefixSumb(l[x])+prefixSumb(l[y])+sum[now]-
                prefixSuma(l[x])-prefixSuma(l[y]);
        dp[now]=max(dp[now],tmp+cost[now][i]);
    }
    dp[now]=max(dp[now],sum[now]);
    modifya(l[now],dp[now]);
    modifya(r[now],-dp[now]);
    modifyb(l[now],sum[now]);
    modifyb(r[now],-sum[now]);
}
int main()
{
	//freopen("data.in","r",stdin);
	//freopen("data.out","w",stdout);
    int n,m;
    int tt;
    scanf("%d",&tt);
    while(tt--)
    {
    	scanf("%d %d",&n,&m);
        limit=n+n;
        memset(head,0,sizeof(head));
        pos=1;
        for(int i=1;i<n;i++)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            insert(x,y);
            insert(y,x);
        }
        for(int i=1;i<=n;i++)
        {
            Q[i].clear();
            ask[i].clear();
            val[i].clear();
            cost[i].clear();
        }
        for(int i=1;i<=m;i++)
        {
            int x,y,z;
            scanf("%d %d %d",&x,&y,&z);
            Q[x].pb(y);
            Q[y].pb(x);
            val[x].pb(z);
            val[y].pb(z);
        }
        memset(vis,false,sizeof(vis));
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        T=0;
        ddd(1,-1);
        dfs(1,-1);
        printf("%I64d\n",dp[1]);
//        return 0;
    }
    return 0;
}

/*

3 2
1 2
1 3
1 2 1
1 3 2

7 3
1 2
1 3
2 4
2 5
3 6
3 7
2 3 4
4 5 3
6 7 3
 */
