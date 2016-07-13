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

const int MAXN=110;

int n,cnt;
bool g[MAXN][MAXN],r[MAXN][MAXN];
bool vis[MAXN],dp[MAXN][MAXN];
int ans[MAXN][MAXN];

struct Node
{
    int a[2];       //该连通区该颜色的人数
    int s[2][MAXN]; //该连通区该颜色的人数
} p[MAXN];

void dfs(int v,int color,int num)
{
    vis[v]=true;
    p[num].s[color][++p[num].a[color]]=v;
    for(int i=1; i<=n; i++)
        if(!vis[i] && r[v][i])
            dfs(i,color^1,num);
}

bool fit()
{
    for(int i=1; i<=cnt; i++)
        for(int t=0; t<2; t++)
            for(int j=1; j<=p[i].a[t]; j++)
                for(int k=j+1; k<=p[i].a[t]; k++)
                    if(r[p[i].s[t][j]][p[i].s[t][k]])  //同一联通快内，同颜色不认识的话有矛盾
                        return false;

    return true;
}

int main()
{
    while(read(n))
    {
        CLR(g,0);CLR(r,0);
        for(int i=1,j; i<=n; i++)
            while(read(j)&&j)
                g[i][j]=1;			// µ¥Ïò±ß
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if(!g[i][j] || !g[j][i])
                    r[i][j]=r[j][i]=1;	//建无向反图
        CLR(vis,0);
        cnt=0;
        for(int i=1; i<=n; i++)  //对每一个连通区间 染色
            if(!vis[i])
            {
                cnt++;
                p[cnt].a[0]=p[cnt].a[1]=0;
                dfs(i,0,cnt);
            }

        if(!fit())
        {
            puts("No solution");
            continue;
        }
        int ans1[MAXN],ans2[MAXN];
        CLR(dp,0);CLR(ans,0);
        dp[0][0]=true;
        for(int i=1; i<=cnt; i++) //简单背包，每个连通分量每种颜色必须进一个小队
        {
            for(int j=p[i].a[0]; j<=n; j++)
                if(!dp[i][j]&&dp[i-1][j-p[i].a[0]])
                    dp[i][j]=true,ans[i][j]=0;
            for(int j=p[i].a[1]; j<=n; j++)
                if(!dp[i][j]&&dp[i-1][j-p[i].a[1]])
                    dp[i][j]=true,ans[i][j]=1;
        }
        int gap=n,temp1=0,temp2=0;
        for(int i=1; i<=n; i++)
            if(dp[cnt][i]&&abs(2*i-n)<gap) //求出 差值最小的 两支队伍数
                gap=abs(2*i-n),temp1=i;
        temp2=n-temp1;
        if(!temp1 || !temp2)
            puts("No solution");
        else
        {
            int t=0,k=0;
            for(int i=cnt; i>=1; i--)
            {
                if(ans[i][temp1])
                {
                    for(int j=1; j<=p[i].a[1]; j++)
                        ans1[t++]=p[i].s[1][j];
                    for(int j=1; j<=p[i].a[0]; j++)
                        ans2[k++]=p[i].s[0][j];
                    temp1-=p[i].a[1];
                }
                else
                {
                    for(int j=1; j<=p[i].a[0]; j++)
                        ans1[t++]=p[i].s[0][j];
                    for(int j=1; j<=p[i].a[1]; j++)
                        ans2[k++]=p[i].s[1][j];
                    temp1-=p[i].a[0];
                }
            }
            write(k);
            for(int i=0;i<k;i++)
                putchar(' '),write(ans2[i]);
            putchar('\n');
            write(t);
            for(int i=0;i<t;i++)
                putchar(' '),write(ans1[i]);
            putchar('\n');
        }
    }
    return 0;
}
