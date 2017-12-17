//	whn6325689
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


using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;

#define CLR(x,y) memset(x,y,sizeof(x))
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define lowbit(x) (x&(-x))
#define MID(x,y) (x+((y-x)>>1))
#define eps 1e-9
#define INF 0x3f3f3f3f
#define LLINF 1LL<<62

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

const int MAXN=510;

#define cc(x) (x*(x-1)/2)

int mod,n,m;
ll dp[MAXN][MAXN];
int num[MAXN];
char a[MAXN];

ll dfs(ll x,ll y)//x 表示 列和为0的个数 ， y 表示 列和为1的个数 
{
	if(x==0 && y==0)
		return 1;
	if(dp[x][y]!=-1)
		return dp[x][y];
	dp[x][y]=0;
	if(x>=2)
		dp[x][y]=(dp[x][y]+cc(x)*dfs(x-2,y+2))%mod;
	if(y>=2)
		dp[x][y]=(dp[x][y]+cc(y)*dfs(x,y-2))%mod;
	if(x && y)
		dp[x][y]=(dp[x][y]+x*y*dfs(x-1,y))%mod;
	return dp[x][y]%mod;
}



int main()
{
	while(read(n)&&read(m)&&read(mod))
	{
		CLR(dp,-1);CLR(num,0);
		ll one=0,ze=0;
		for(int i=1;i<=m;i++)
		{
			scanf("%s",a);
			for(int j=0;j<n;j++)
   				num[j+1]+=(a[j]=='1');  
		}
		for(int i=1;i<=n;i++)
		{  
  			if(num[i]==0)
			  	ze++;  
      		else if(num[i]==1)
  				one++;  
      		else if(num[i]>2)
  			{  
     			write(0),putchar('\n'); 
                continue; 
     		}  
   		}  	
   		write(dfs(ze,one)),putchar('\n');
	}
	return 0;
}