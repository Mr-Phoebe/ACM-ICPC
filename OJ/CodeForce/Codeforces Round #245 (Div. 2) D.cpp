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

const int MAXN=1010;
int n,m;
ll a[MAXN][MAXN];
ll dp1[MAXN][MAXN],dp2[MAXN][MAXN],dp3[MAXN][MAXN],dp4[MAXN][MAXN];

void print(ll b[][MAXN])
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			cout<<b[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}

int main()
{
	while(read(n)&&read(m))
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				read(a[i][j]);
		for(int i=1;i<=n;i++)				//   从 1，1 到 i，j 最大的消耗 
			for(int j=1;j<=m;j++)
				dp1[i][j]=a[i][j]+max(dp1[i-1][j],dp1[i][j-1]);
		for(int i=n;i>=1;i--)				//   从 i，j 到 n，m 最大的消耗 
			for(int j=m;j>=1;j--)
				dp2[i][j]=a[i][j]+max(dp2[i+1][j],dp2[i][j+1]); 
		for(int i=n;i>=1;i--)				//   从 n，1 到 i，j 最大的消耗 
			for(int j=1;j<=m;j++)
				dp3[i][j]=a[i][j]+max(dp3[i+1][j],dp3[i][j-1]); 
		for(int i=1;i<=n;i++)				//   从 i，j 到 1，m 最大的消耗 
			for(int j=m;j>=1;j--)
				dp4[i][j]=a[i][j]+max(dp4[i-1][j],dp4[i][j+1]); 
		ll ans=-INF;
		for(int i=2;i<n;i++)
		    for(int j=2;j<m;j++)
		      {
		        ans=max(ans,dp1[i-1][j]+dp2[i+1][j]+dp3[i][j-1]+dp4[i][j+1]);
		        ans=max(ans,dp1[i][j-1]+dp2[i][j+1]+dp3[i+1][j]+dp4[i-1][j]);
		      }
		write(ans),putchar('\n');
	}
	return 0;
}