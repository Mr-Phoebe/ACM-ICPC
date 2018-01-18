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

const int MAXN=400010;
//dp[i] = dp[j] + sum[i] - sum[j] -(i - j)*a[j+1]


ll dp[MAXN],sum[MAXN],a[MAXN];
int q[MAXN];

ll getdp(int i,int j)
{
    return dp[j]+sum[i]-sum[j]-(i-j)*a[j+1];
}

ll getup(int j,int i)
{
    return dp[j]-sum[j]+j*a[j+1]-(dp[i]-sum[i]+i*a[i+1]);
}

ll getdown(int j,int i)
{
    return a[j+1]-a[i+1];
}

int main()
{
    int t,n;
    while(read(n)&&read(t))
    {
        for(int i=1;i<=n;i++)
            read(a[i]);
        sort(a+1,a+n+1);
        sum[0]=0;
        for(int i=1;i<=n;i++)
            sum[i]=sum[i-1]+a[i];
        int head=0,tail=0;
        dp[0]=0;
        q[tail++]=0;
        for(int i=t;i<=n;i++)
        {
            while(tail>head+1 && getup(q[head+1],q[head])<=i*getdown(q[head+1],q[head]))
                head++;
            dp[i]=getdp(i,q[head]);
            if(i>=2*t-1)
            {
                int j=i-t+1;
                while(tail>head+1 && getup(q[tail-1],q[tail-2])*getdown(j,q[tail-1])>=
                    getup(j,q[tail-1])*getdown(q[tail-1],q[tail-2]))
                        tail--;
                q[tail++]=j;
            }
        }
        write(dp[n]);putchar('\n');
    }
    return 0;
}


