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

int g[55][55];
int num[55][55];
int dp[55][55][55][55];
int main()
{
    int n,m,q;
    read(n),read(m),read(q);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            scanf("%1d",&g[i][j]);
            num[i][j]=num[i][j-1]+1;
            if(g[i][j]==1)
                num[i][j]=0;
        }
    for(int a=1; a<=n; a++)
        for(int b=1; b<=m; b++)
            for(int c=a; c<=n; c++)
                for(int d=b; d<=m; d++)
                {
                    int& now=dp[a][b][c][d]=dp[a][b][c][d-1]+dp[a][b][c-1][d]-dp[a][b][c-1][d-1];
                    int add=d-b+1;
                    for(int i=c; i>=a; i--)
                    {
                        add=min(add,num[i][d]);
                        now+=add;
                    }
                }
    for(int i=1; i<=q; i++)
    {
        int a,b,c,d;
        read(a),read(b),read(c),read(d);
        cout<<dp[a][b][c][d]<<endl;
    }
    return 0;
}
