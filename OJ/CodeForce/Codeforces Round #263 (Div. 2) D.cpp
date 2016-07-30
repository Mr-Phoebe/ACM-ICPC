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

const int MOD=1000000007;
const int MAXN=100010;
vector<int> g[MAXN];
int color[MAXN],pre[MAXN];
ll dp[MAXN][2];
int n;

void dfs(int x)
{
    int len=g[x].size();
    dp[x][color[x]]=1;dp[x][color[x]^1]=0;
    for(int i=0;i<len;i++)
    {
        int v=g[x][i];
//        if(pre[x]==v)
//            continue;
//        pre[v]=x;
        dfs(v);
        dp[x][1]=(((dp[v][1]+dp[v][0])*dp[x][1])%MOD+dp[x][0]*dp[v][1])%MOD;
        dp[x][0]=(dp[x][0]*(dp[v][0]+dp[v][1])%MOD)%MOD;
    }
}

int main()
{
	read(n);
	for(int i=0,temp;i<n-1;i++)
    {
        read(temp);
        g[temp].push_back(i+1);
//        g[i+1].push_back(temp);
    }
    for(int i=0;i<n;i++)
        read(color[i]);
    dfs(0);
    printf("%I64d\n",dp[0][1]);
    return 0;
}
