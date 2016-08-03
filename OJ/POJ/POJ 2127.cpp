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

int dp[505][505];
int a[505],b[505];
int n,m;

void print(int s,int t)
{
    if(t==0||s==0)
        return;
    if(a[s]!=b[t])
        print(s,t-1);
    else
    {
        int minn=0,ai;
        for(int k=1; k<s; k++)
            if(a[k]<a[s]&&minn<dp[k][t-1])
            {
                minn=dp[k][t-1];
                ai=k;
            }
        if(minn!=0)
            print(ai,t-1);
        cout<<a[s]<<' ';
    }
}


int main()
{
    while(read(n))
    {
        for(int i=1; i<=n; i++)
            read(a[i]);
        read(m);
        for(int i=1; i<=m; i++)
            read(b[i]);
        CLR(dp,0);
        int ans=0,si,sj;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(a[i]!=b[j])
                    dp[i][j]=dp[i][j-1];
                else
                {
                    int maxn=0;
                    for(int k=1; k<i; k++)
                        if(a[k]<a[i] && maxn<dp[k][j-1])
                            maxn=dp[k][j-1];
                    dp[i][j]=maxn+1;
                }
            }
        }
        for(int i=1; i<=n; i++)
            if(ans<dp[i][m])
            {
                si=i;
                ans=dp[i][m];
            }
        printf("%d\n",ans);
        if(ans)
        {
            print(si,m);
        }
        putchar('\n');
    }
    return 0;
}
