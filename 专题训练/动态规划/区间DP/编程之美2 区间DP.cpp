//      whn6325689  
//      Mr.Phoebe  
//      http://blog.csdn.net/u013007900  
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

const int MAXN=1010; 
const int MOD=100007;

char s[MAXN];
ll dp[MAXN][MAXN];

int main()
{
	int T,cas=1;
	read(T);
	while(T--)
	{
		scanf("%s",s);
		int n=strlen(s);
		for(int len=0;len<n;len++)
			for(int i=0;i<n;i++)
			{
				int j=i+len;
				if(j>=n) break;
				if(s[i]==s[j])
				{
					dp[i][j]=1;
					int l=i+1,r=j-1;
					if(l<=r)
						dp[i][j]=(dp[i][j]+dp[l][r])%MOD;
				}
				else
					dp[i][j]=0;

				if(i!=j)
				{
					dp[i][j]=(dp[i][j]+dp[i+1][j]+dp[i][j-1])%MOD;
					int l=i+1,r=j-1;
					if(l<=r)
						dp[i][j]=(dp[i][j]-dp[l][r])%MOD;
				}
			}
		printf("Case #%d: %lld\n",cas++,dp[0][n-1]);
	}
	return 0;
}