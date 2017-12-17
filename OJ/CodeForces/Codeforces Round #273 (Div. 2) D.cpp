//      whn6325689
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
//-----------------------------------]

const int MOD=1000000007;
const int MAXN=1000;
int num[MAXN];
int dp[2][200005],r,g;

int main()
{
	for(int i=1;i<MAXN;i++)
		num[i]=num[i-1]+i;
	read(r),read(g);
	dp[0][0]=1;
    int now=1;
    int ans=0;
	for(int i=0;i<MAXN;i++,now^=1)
	{
		for(int j=0;j<=r;j++)
			dp[now][j]=0;
		for(int j=0;j<=r;j++)
			if(dp[now^1][j])
			{
				int ways=dp[now^1][j];
                int left_r=r-j;
                int left_g=g-(num[i]-j);
				if(left_r>=i+1)
					dp[now][j+i+1]=(dp[now][j+i+1]+dp[now^1][j])%MOD;
				if(left_g>=i+1)
					dp[now][j]=(dp[now][j]+dp[now^1][j])%MOD;
			}
		int sum=0,ok=0;
		for(int j=0;j<=r;j++)
            if(dp[now][j])
            {
                ok=1;
                sum=(sum+dp[now][j])%MOD;
            }
        if(ok)
            ans=sum;
        else
            break;
	}
	write(ans),putchar('\n');
	return 0;
}
