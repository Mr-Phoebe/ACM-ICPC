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
    T x = 0, tmp = 1; char c = getchar();
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

const int MAXN=1010;

char Next[222],word[MAXN][MAXN];
int dp[MAXN][MAXN],vis[MAXN][MAXN];
int n,m,ans=0;
int dir[4][2]={1,0,-1,0,0,1,0,-1};

inline bool in(int x,int y)
{
    return (x>=0 && x<n && y>=0 && y<m);
}

int dfs(int x,int y)
{
    if(dp[x][y])
        return dp[x][y];
    int best=0;
    for(int i=0;i<4;i++)
    {
        int xx=x+dir[i][0];
        int yy=y+dir[i][1];
        if(in(xx,yy) && Next[word[x][y]]==word[xx][yy])
        {
            if(vis[xx][yy])
                best=INF;
            else
            {
                vis[xx][yy]=1;
                int t=dfs(xx,yy);
                vis[xx][yy]=0;
                best=max(t,best);
            }
        }
    }
    return dp[x][y]=best+1;
}

int main()
{
//    freopen("data.txt","r",stdin);
	Next['D']='I',Next['I']='M',Next['M']='A',Next['A']='D';
    read(n),read(m);
    for(int i=0;i<n;i++)
        gets(word[i]);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(word[i][j]=='D')
            {
                vis[i][j]=1;
                int t=dfs(i,j);
                ans=max(ans,t/4);
                vis[i][j]=0;
            }
        }
    }
    if(ans==0)
        printf("Poor Dima!\n");
    else if(ans>=INF/4)
        printf("Poor Inna!\n");
    else
        printf("%d\n",ans);
    return 0;
}
