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

const int MAXN=100010;

int dp[MAXN];
int a[MAXN],b[MAXN];
vi c[MAXN];
int n,m,s,e,ans;


int main()
{
	read(n),read(m),read(s),read(e);
	for(int i=1;i<=n;i++)
		read(a[i]);
	for(int i=1;i<=m;i++)
	{
		read(b[i]),c[b[i]].pb(i);
	}
	CLR(dp,INF);
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=s/e;j>=0;j--)
		{
			vi::iterator it=upper_bound(c[a[i]].begin(),c[a[i]].end(),dp[j]);//找到第j次操作，a[i]在b数组最前端的位置 ,此位置不可取 
			if(it==c[a[i]].end())
				continue;
			dp[j+1]=min(*it,dp[j+1]);
			if(i+dp[j+1]+(j+1)*e<=s)
				ans=max(ans,j+1);
//			cout<<dp[j+1]<<" ";
		}
//		cout<<endl;
	}
	write(ans),putchar('\n');
	return 0;
}