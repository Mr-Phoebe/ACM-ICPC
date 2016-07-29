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

const int MOD=1000000007;
int dp[2][1111][1111];
int lcm[1111][1111],fac[1111];
int n,m,k;

int Gcd(int a,int b)
{
	return b ? Gcd(b,a%b):a;
}

int Lcm(int a,int b)
{
	return a/Gcd(a,b)*b;
}

int main()
{
	for(int i=1;i<1001;i++)
        for(int j=i;j<1001;j++)
            lcm[i][j]=lcm[j][i]=Lcm(i,j);
	while(read(n)&&read(m)&&read(k))
	{
		int cnt=0;
        for(int i=1;i<=m;i++)
            if(m%i==0)
                fac[cnt++]=i;
		CLR(dp,0);
		for(int i=0;i<cnt;i++)
            dp[1][fac[i]][fac[i]]=1;
		for(int i=1,flag=1;i<=k;i++,flag^=1)
		{
			for(int j=i;j<=n;j++)
                for(int e=0;e<cnt;e++)
                    dp[flag^1][j][fac[e]]=0;
			for(int j=i;j<=n;j++)					//   枚举上一轮的和 
			{
				for(int e=0;e<cnt;e++)				//   枚举上一轮的LCM 
				{
					if(!dp[flag][j][fac[e]])
						continue;
					for(int t=0;t<cnt;t++)			//   枚举下一个数 
					{
						if(j+fac[t]>n)
							break;
						dp[flag^1][j+fac[t]][lcm[fac[t]][fac[e]]]=(dp[flag^1][j+fac[t]][lcm[fac[t]][fac[e]]] + dp[flag][j][fac[e]])%MOD; 
					}
				}
			}
		}
		write(dp[k&1][n][m]),putchar('\n');
	}
	return 0;
}