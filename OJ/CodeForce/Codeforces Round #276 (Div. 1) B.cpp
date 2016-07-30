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
#define LLINF 1LL<<62

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

const int MAXN=1000005;
int vis[MAXN];
int a[MAXN];
int n,cnt;


int main()
{
    read(n);
    for(int i=1,t;i<=n;i++)
    {
        read(t);
        vis[t]=1;
    }
    for(int i=1;i<MAXN;i++)
    {
        if(!vis[i])
			continue;
        a[++cnt]=i;
    }
    int ans=0;
    if(cnt<=5000)
    {
        for(int i=1;i<=cnt;i++)
            for(int j=i+1;j<=cnt;j++)
                ans=max(ans,a[j]%a[i]);
                //cout<<a[j]%a[i]<<endl;
    }
    else
    {
        for(int i=cnt-1;i;i--)
        {
            if(ans>=a[i]-1)
				break;
            for(int j=a[i]*2;j-a[i]<=a[cnt];j+=a[i])
            {
                int u=lower_bound(a+1,a+cnt+1,j)-a;
                //cout<<i<<' '<<j<<' '<<u<<' '<<a[u-1]%a[i]<<endl;
                ans=max(ans,a[u-1]%a[i]);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}