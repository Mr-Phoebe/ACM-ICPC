#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <climits>

#define MAXN 205
#define eps 1e-5

#define INF 0x3f3f3f3f

#define test

#define For(i,m,n) for(int i=(m);i<(n);i++)
#define vecfor(iter,a) for(vector<int>::iterator iter=a.begin();iter!=a.end();iter++)
#define rep(i,m,n) for(int i=(m);i<=(n);i++)
#define LL long long

/*author birdstorm*/
using namespace std;
const double pi=acos(-1.0);
const LL MOD=10007;
template<class T>
inline bool read(T &n){
    T x=0, tmp=1; char c=getchar();
    while((c < '0' || c > '9') && c != '-' && c != EOF) c=getchar();
    if(c == EOF) return false;
    if(c == '-') c=getchar(), tmp=-1;
    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c=getchar();
    n=x*tmp;
    return true;
}

template <class T>
inline void write(T n) {
    if(n < 0) {
        putchar('-');
        n=-n;
    }
    int len=0,data[20];
    while(n) {
        data[len++]=n%10;
        n /= 10;
    }
    if(!len) data[len++]=0;
    while(len--) putchar(data[len]+48);
}

int n, m, t;
struct edge{
    int to,next;
}e[MAXN<<1];
bool vis[MAXN];
int tot, head[MAXN];
int total[MAXN];
int dp[MAXN];
int dp2[MAXN][MAXN];
int child[MAXN];

void add(int u,int v)
{
    e[tot].to=v; e[tot].next=head[u]; head[u]=tot++;
    e[tot].to=u; e[tot].next=head[v]; head[v]=tot++;
}

void dfs(int u, int father)
{
    dp[u]=0;
    total[u]=1;
    for(int i=head[u];i!=-1;i=e[i].next){
        int v=e[i].to;
        if(v==father) continue;
        dfs(v,u);
        dp[u]=max(dp[u],total[v]);
        total[u]+=total[v];
    }
}

void dfs2(int u,int father)
{
    dp2[u][0]=dp2[u][1]=1; child[u]=1;
    for(int i=head[u];i!=-1;i=e[i].next){
        int v=e[i].to;
        if(v==father) continue;
        dfs2(v,u); child[u]+=child[v];
    }
    for(int i=head[u];i!=-1;i=e[i].next){
        int v=e[i].to;
        if(v==father) continue;
        for(int i=child[u];i>=2;i--){
            for(int j=1;j<i&&j<=child[v];++j)
                dp2[u][i]=(dp2[u][i]+dp2[v][j]*dp2[u][i-j])%MOD;
        }
    }
}

int main()
{
//    freopen("1003.in","r",stdin);
    //freopen("output.txt","w",stdout);
    int u, v, w;
    read(t);
    while(t--){
        read(n);
        memset(head,-1,sizeof head);
        memset(total,-1,sizeof total);
        memset(dp,0,sizeof dp);
        tot=0;
        For(i,0,n-1){
            read(u),read(v);
            add(u,v);
        }
        dfs(1,-1);
        int minn=INF, ans;
        for(int i=1;i<=n;i++){
            int t=max(dp[i],n-total[i]);
            if(minn>t){
                minn=t;
                ans=i;
            }
        }
        memset(dp2,0,sizeof dp2);
        dfs2(ans,-1);
        int ret=0, g=0;
        for(int i=1;i<=n;++i) g=(g+dp2[ans][i])%MOD;
        ret=g;cout<<g<<endl; 
        for(int k=head[ans];k!=-1;k=e[k].next){
            for(int i=0;i<=n;++i) dp[i]=dp2[ans][i];
            int v=e[k].to;
            for(int i=1;i<=n;++i) for(int j=1;j<i;++j)
                dp[i]=((dp[i]-dp[i-j]*dp2[v][j])%MOD+MOD)%MOD;
            dp[0]=1;
            for(int i=1;i<n;++i) dp[i]=(dp[i-1]+dp[i+1])%MOD;
            for(int i=1;i<=n;++i) ret=((ret-dp2[v][i]*dp[i-1])%MOD+MOD)%MOD;
        }

        printf("%d\n",(g-ret+MOD)%MOD);
    }
    return 0;
}
