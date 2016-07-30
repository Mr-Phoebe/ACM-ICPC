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
#define CLR(x,y) memset(x,y,sizeof(x))
#define mp(x,y) make_pair(x,y)
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

int n,m;
int a[1005],g[1005][1005];
int visit[1005],dp[1005];

int dfs(int x)
{
    int ans=0;
    if(visit[x])
        return dp[x];
    visit[x]=1;
    for(int i=1; i<=n; i++)
        if(g[x][i]&&ans<dfs(i)+1)
            ans=dfs(i)+1;
    return dp[x]=ans;
}
int main()
{
    //freopen("d.txt","r",stdin);
    int i,j,k;
    while(read(n),read(m))
    {
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
                read(a[j]);
            for(j=0; j<n; j++)
                for(k=j+1; k<n; k++)
                    g[a[j]][a[k]]|=1;
        }
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                if(g[i][j]&&g[j][i])
                    g[i][j]=g[j][i]=0;
        int ans=0,ti=1;
        CLR(visit,0);
        for(i=0; i<n; i++)
            if(dfs(i)>ans)
                ans=dfs(i);
        printf("%d\n",ans+1);
//        for(ti;ti;ti=pre[ti])
//            printf("%d%c",ti,pre[ti]?' ':'\n');
    }
    return 0;
}
