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

const int MAXN=11;
const int MOD=1000000007;

int n,m,k;
ll dp[2][1<<MAXN];
int color[MAXN][MAXN];

void DP()
{
    ll *crt=dp[0],*next=dp[1];
    crt[0]=1;
    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            for(int used=0;used< 1<<m;used++)
            {
                if((used>>j & 1)||color[i][j])
                    next[used]=crt[used & ~(1<<j)];
                else
                {
                    ll res=0;
                    if(j+1<m && !(used>>(j+1) & 1) && !color[i][j+1])
                    {
                        res+=crt[used | 1<<(j+1)];
                    }
                    if(i+1<n && !color[i+1][j])
                    {
                        res+=crt[used | 1<<j];
                    }
                    next[used]= res % MOD;
                }
            }
            swap(crt,next);
        }
    }
    printf("%lld\n",crt[0]);
}

int main()
{
    while(read(n)&&read(m)&&read(k))
    {
        int x,y;
        memset(color,0,sizeof(color));
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=k;i++)
        {
            read(x);read(y);
            color[x][y]=1;
        }
        DP();
    }
    return 0;
}
