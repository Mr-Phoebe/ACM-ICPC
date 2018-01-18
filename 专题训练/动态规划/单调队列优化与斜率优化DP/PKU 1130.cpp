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
//-------------------------

int v[305],a[305][305],p,n;
int dp[305][35];//代表在前x个村庄中建立y个邮局的最小的距离的


int main()
{

    read(n),read(p);
	for(int i=1;i<=n;i++)
		read(v[i]);
    for(int tmp=1;tmp<n;tmp++)
	{
        for(int i=0;i<=n-tmp;i++)
		{
			int j=i+tmp;
			a[i][j]=a[i+1][j]+v[(i+1+j)/2]-v[i];
		}
	}
	memset(dp,INF,sizeof(dp));
	for(int i=1;i<=n;i++)
		dp[i][1]=a[1][i];
	for(int i=2;i<=p;i++)
		for(int j=i;j<=n;j++)
			for(int k=i;k<=j;k++)
				if(dp[j][i]>dp[k][i-1]+a[k+1][j])
					dp[j][i]=dp[k][i-1]+a[k+1][j];

	printf("%d\n",dp[n][p]);
	return 0;
}