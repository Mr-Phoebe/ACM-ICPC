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
#include <functional>
#include <numeric>


using namespace std;

typedef long double ld;
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



ld a[1005], b[1005], dist[1005], par[1005], L;
int n;
int main()
{
	read(n),read(L);
	ld l=0.0,r=0.0,sum=0.0;
	for (int i=1; i<=n; i++)
	{
		read(a[i]),read(b[i]);
		r+=sqrt(abs(a[i]-a[i-1]-L));
		sum+=b[i];
	}
	r/=sum;
	while(r-l > eps)
	{
		ld m=(l+r)/2;
		for (int i=1; i<=n; i++)
		{
			par[i]=-1;
			dist[i]=1e22;
		}
		for (int i=0; i<=n; i++)
		{
			for (int j=i+1; j<=n; j++)
			{
				ld temp=dist[i]+sqrt(abs(a[j]-a[i]-L))-m*b[j];
				if(temp < dist[j])
				{
					par[j]=i;
					dist[j]=temp;
				}
			}
		}
		if(dist[n]<0)
			r=m;
		else
			l=m;
	}
	
	vector<int> ans;
	int cur=n;
	while(cur!=0)
	{
		ans.push_back(cur);
		cur=par[cur];
	}
	for(int i=ans.size()-1; i>=0; i--)
		write(ans[i]),putchar(' ');
	putchar('\n');
	return 0;
}