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

const int maxn=402;

vector <int> e[maxn];
int dp[maxn][maxn], path[maxn][maxn][maxn], id[maxn][maxn], fa[maxn], n;

void dfs(int u, int pre)
{
    fa[u]=pre;
    dp[u][1]=0;
    for (int i=0; i<e[u].size(); i++)
    {
        int v=e[u][i];
        if (v==pre) continue;
        dfs(v, u);
        for (int j=n; j>=0; j--)
        {
            dp[u][j]++;
            for (int l=0; l<=j; l++)
            if (dp[u][j]>=dp[u][j-l]+dp[v][l])  dp[u][j]=dp[u][j-l]+dp[v][l], path[u][v][j]=l;
        }
    }
    
}

void out(int u, int k, int pre)
{
     int t=k;
     for (int i=e[u].size()-1; i>=0; i--)
     {
         int v=e[u][i];
         if (v==pre) continue;  // ??????? 
         if (path[u][v][t]==0) cout<<id[u][v]<<' '; // ??????§Ö? 
         else
         {
             out(v,path[u][v][t],u);
             t-=path[u][v][t];
         }
         
     }
}

int main()
{
    int k;
    read(n),read(k);
    for (int i=1; i<n; i++)
    {
        int u,v;
        read(u),read(v);
        e[u].push_back(v);
        e[v].push_back(u);
        id[u][v]=id[v][u]=i;
    }
    CLR(dp, INF);
    dfs(1,0);
/*
	   for (int i=1; i<=n; i++){
	   for (int j=1; j<=n; j++) cout<<dp[i][j]<<' '; cout<<endl;}
	   cout<<endl;
	   for (int i=1; i<=n; i++)
	   { for (int j=1; j<=n; j++) {
	   	 for (int k=1; k<=n; k++) cout<<path[j][k][i]<<' '; cout<<endl;
	   }
	     cout<<endl;
	   } 
*/
    int ans=dp[1][k], root=1;
    for (int i=2; i<=n; i++) if (dp[i][k]+1<ans) ans=dp[i][k]+1, root=i;
    cout<<ans<<endl;
    if (root!=1) cout<<id[root][fa[root]]<<' ';
    out(root, k, fa[root]);
    return 0;
}