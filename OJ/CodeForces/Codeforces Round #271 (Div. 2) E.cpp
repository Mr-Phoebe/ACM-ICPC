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
#define pb(x) push_back(x)
#define eps 1e-9
#define INF 0x3f3f3f3f
#define LLINF 1LL<<62

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;

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

const int MAXN=100100;

int dp[MAXN],n;
int pre[MAXN],last,ans;
ll h[MAXN],d;

void print(int x)
{
	if(pre[x]!=x)
		print(pre[x]);
	printf("%d ",x);
}

int main()
{
	read(n),read(d);
	for(int i=1;i<=n;i++)
		read(h[i]);
	for(int i=1;i<=n;i++)
	{
		pre[i]=i;dp[i]=1;
		for(int j=max(1,i-300);j<i;j++)
		{
			if(abs(h[i]-h[j])<d)
				continue;
			if(dp[i]<dp[j]+1)
			{
				dp[i]=dp[j]+1;
				pre[i]=j;
			}
		}
		if(ans<dp[i])
		{
			ans=dp[i];last=i;
		}
	}
	write(ans),putchar('\n');
	print(last);putchar('\n');
	return 0;
}