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

ll a[100020],b[100020];
int main()
{
    int m,n;
    read(m),read(n);
    ll sum1=0,sum2=0,s1=0,s2=0,Max1=0,Max2=0;
    for(int i=1;i<=m;i++)
    {
        read(a[i]);
        sum1+=a[i];
        if(a[i]>Max1)
        {
            Max1=a[i];
            s1=i;
        }
    }
    for(int i=1;i<=n;i++)
    {
        read(b[i]);
        sum2+=b[i];
        if(b[i]>Max2)
        {
            Max2=b[i];
            s2=i;
        }
    }
    ll ans1=sum1*n,ans2=sum2*m;
    for(int i=1;i<=m;i++)
    {
    	if(i!=s1&&a[i]<sum2)
            ans2-=sum2-a[i];
    }
    for(int i=1;i<=n;i++)
    {
    	if(i!=s2&&b[i]<sum1)
            ans1-=sum1-b[i];
    }
            
    if(ans1>ans2)
        printf("%I64d\n",ans2);
    else
        printf("%I64d\n",ans1);
    return 0;
}