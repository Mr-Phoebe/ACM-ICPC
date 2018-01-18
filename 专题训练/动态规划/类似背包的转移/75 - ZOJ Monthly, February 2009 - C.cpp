//      whn6325689
//		Mr.Phoebe
//		http://blog.csdn.net/u013007900
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
#pragma comment(linker, "/STACK:1024000000,1024000000")


using namespace std;

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
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LLINF 1LL<<62

template<class T>
inline bool read(T &n)
{
    T x = 0, tmp = 1;
    char c = getchar();
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

int a[305];
int g[305][305],dp[305][305];
int val[305];
int n,m;

int main()
{
    while(read(n)&&read(m))
    {
        CLR(g,0);
        CLR(dp,0);
        CLR(val,0);
        int l,r;
        for(int i=0; i<m; i++)
        {
            read(l),read(r);
            g[l][r]=g[r][l]=1;
        }
        for(int i=1; i<=n; i++)
            read(a[i]);
        for(int i=1; i<=n; i++)
        {
            val[i]=val[i-1];
            for(int j=1; j<i; j++)
            {
                if(g[a[i]][a[j]])
                {
                    if(i-j==1 || dp[i-1][j+1])
                    {
                        dp[i][j]=1;
                        for(int k=j-2; k>=1; k-=2)
                            if( dp[j-1][k] )
                                dp[i][k] = 1;
                    }
                }
            }
            for(int j=1; j<i; j++)
                if(dp[i][j])
                {
                    if(val[j-1]+i-j+1>val[i])
                        val[i]=val[j-1]+i-j+1;
                    break;
                }
        }
        printf("%d\n",val[n]);
    }
    return 0;
}

