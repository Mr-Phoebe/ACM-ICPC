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
#define eps 1e-9
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

template<class T>
inline bool read(T &n)
{
    T x = 0, tmp = 1;
    char c = getchar();
    while((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();
    if(c == EOF) return false;
    if(c == '-') c = getchar(), tmp = -1;
    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c = getchar();
    n = x*tmp;
    return true;
}
template <class T>
inline void write(T n)
{
    if(n < 0)
    {
        putchar('-');
        n = -n;
    }
    int len = 0,data[20];
    while(n)
    {
        data[len++] = n%10;
        n /= 10;
    }
    if(!len) data[len++] = 0;
    while(len--) putchar(data[len]+48);
}
//-----------------------------------

const int MAXN=222;
const int MOD=10007;

struct Edge
{
    int to,next;
} e[MAXN*2];
int n,mi;
int head[MAXN],tot=0;
int son[MAXN],cen,pre[MAXN];
int dp[MAXN][MAXN],sum[MAXN],child[MAXN];
bool vis[MAXN];

void add(int u,int v)
{
    e[tot].next=head[u];
    e[tot].to=v;
    head[u]=tot++;
    e[tot].next=head[v];
    e[tot].to=u;
    head[v]=tot++;
}

int dfsson(int x)
{
    int y,mx=0;
    vis[x]=true;
    son[x]=1;
    for(int i=head[x];~i;i=e[i].next)
    {
        y=e[i].to;
        if(vis[y])
            continue;
        int tm=dfsson(y);
        mx=max(tm,mx),son[x]+=tm;
    }
    mx=max(mx,n-son[x]);
    if (mx<mi)
    {
        mi=mx,cen=x;
    }
    vis[x]=false;
    return son[x];
}

int dfs(int x)
{
    dp[x][0]=dp[x][1]=1;child[x]=1;//cout<<x<<" "<<pre[x]<<endl;system("pause");
    for(int i=head[x];~i;i=e[i].next)
    {
        int y=e[i].to;
        if(pre[y])
            continue;
        pre[y]=x;
        ;
        child[x]+=dfs(y);
    }
    for(int i=head[x];~i;i=e[i].next)
    {
        int y=e[i].to;
        if(pre[x]==y)
            continue;
        for(int i=child[x];i>=2;i--)
            for(int j=1;j<i&&j<=child[y];j++)
                dp[x][i]=(dp[x][i]+dp[y][j]*dp[x][i-j])%MOD;
    }
    return child[x];
}

int main()
{
    int T;
//    freopen("data.txt","r",stdin);
    read(T);
    while(T--)
    {
        memset(head,-1,sizeof(head));
        memset(dp,0,sizeof(dp));
        memset(pre,0,sizeof(pre));
        tot=0;
        read(n);mi=n;
        int u,v;
        for(int i=0; i<n-1; i++)
        {
            read(u),read(v);
            add(u,v);
        }
        dfsson(1);
        pre[cen]=-1;
        dfs(cen);//cout<<cen<<endl;
        int ret=0;
        for(int k=head[cen];~k;k=e[k].next)
        {
            for(int i=0;i<=n;i++)
                sum[i]=dp[cen][i];
            int y=e[k].to;
            for(int i=1;i<=n;i++)
                for(int j=1;j<i;j++)
                    sum[i]=((sum[i]-sum[i-j]*dp[y][j])%MOD+MOD)%MOD;
        //下面是birdstorm的思路，我实在是写不下去了
            for(int i=1;i<n;i++)
                sum[i]=(sum[i-1]+sum[i+1])%MOD;
            for(int i=1;i<=n;i++)
                ret=(ret+dp[y][i]*sum[i-1])%MOD;
        }
        printf("%d\n",ret);
    }
    return 0;
}


