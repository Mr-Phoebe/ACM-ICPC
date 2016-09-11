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

const int maxn=2010;

int n;
ll a[maxn][maxn],s[maxn][maxn];

int main()
{
	
	freopen("data.txt","r",stdin);
    read(n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
			read(a[i][j]);

    memset(s,0,sizeof(s));

    for(int i=1;i<=2*n;i++)
    {
        ll sum=0;
        for(int j=1;j<i;j++)
        	if(j>=1 && j<=n && i-j>=1 && i-j<=n) sum+=a[j][i-j];

        for(int j=1;j<i;j++)
        	if(j>=1 && j<=n && i-j>=1 && i-j<=n) s[j][i-j]+=sum;
    }

    for(int i=1-n;i<=n-1;i++)
    {
        ll sum=0;
        for(int j=1;j<=n;j++)
            if(j>=1 && j<=n && j-i>=1 && j-i<=n) sum+=a[j][j-i];

        for(int j=1;j<=n;j++)
            if(j>=1 && j<=n && j-i>=1 && j-i<=n) s[j][j-i]+=sum;
    }


    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        	s[i][j]-=a[i][j];

    ll ans1=-1,ans2=-1;
    int x1,y1,x2,y2;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(abs(i-j)%2==0 && s[i][j]>ans1)
            {
                ans1=s[i][j];
                x1=i;
                y1=j;
            }
            if(abs(i-j)%2==1 && s[i][j]>ans2)
            {
                ans2=s[i][j];
                x2=i;
                y2=j;
            }
        }


	printf("%I64d\n",ans1+ans2);
	printf("%d %d %d %d\n",x1,y1,x2,y2);
    return 0;
}
