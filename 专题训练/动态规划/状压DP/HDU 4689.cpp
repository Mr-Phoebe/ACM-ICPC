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

ll dp[30][30];//在 i 位前没有填写的共有 j 位
char str[30];

int main()
{
    int len=0;
	while(scanf("%s",str)!=EOF)
    {
        len=strlen(str);
        CLR(dp,0);
        dp[0][0]=1;
        for(int i=1;i<=len;i++)
        {
            if(str[i-1]=='+')
                for(int j=1;j<=i;j++)
                    dp[i][j]+=dp[i-1][j]*j+dp[i-1][j-1];
            else
                for(int j=1;j<=i;j++)
                {
                    dp[i][j]+=dp[i-1][j]*j;
                    dp[i][j-1]+=dp[i-1][j]*j*j;
                }
        }
        printf("%I64d\n",dp[len][0]);
    }
    return 0;
}
