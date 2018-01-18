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

int v[2010];
ll dp[2010][2010];
const int MOD=1e9+7;

int main()
{
	int T,n;
	read(T);
	while(T--)
	{
		CLR(dp,0); 
		int sum=0;
		read(n);
		for(int i=1;i<=n;i++)
		{
			read(v[i]);
			sum+=v[i];
		}
		dp[0][0]=1;
		for(int j=1;j<=n;j++)
			for(int k=0;k<=v[j];k++)
				for(int i=k;i<=sum;i++)
						dp[i][j]=(dp[i][j]+dp[i-k][j-1])%MOD;
		printf("%lld\n",dp[sum/2][n]);
	}
	return 0;
}