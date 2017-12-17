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
//-----------------

struct Node
{
	int ap,bp;  //price
	int as,bs;	//num
}a[2010];

struct Que
{
	int v,i;
}q[2010];

int n,maxp,w;
int dp[2020][2020]; 

//dp[i][j]=max{dp[i-1][j],dp[i-w-1][k]-(j-k)*ap[i],dp[i-w-1][k]+(k-j)*bp[i]}
//         i  表示天数    j表示股票数 
//天数超过则推出 

int main()
{
	int T;
	read(T);
	while(T--)
	{
		read(n),read(maxp),read(w);
		memset(dp,0x3f,sizeof(dp));
		for(int i=1;i<=n;i++)
		{
			read(a[i].ap);read(a[i].bp);read(a[i].as);read(a[i].bs);
		}
		for(int i=1;i<=n;i++)  
	        for(int j=0;j<=min(a[i].as,maxp);j++)  
	            dp[i][j]=-a[i].ap*j;
  		for(int i=2;i<=n;i++)
  			for(int j=0;j<=maxp;j++)
  				dp[i][j]=max(dp[i][j],dp[i-1][j]);
  		for(int i=w+2;i<=n;i++)
  		{
			int pre=i-w-1;  	
			int head=0,tail=-1;
			for(int j=0;j<=maxp;j++)
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j]);  
	            Que temp;  
	            temp.v=dp[pre][j]+j*a[i].ap;temp.i=j;
	            while(tail>=head&&temp.v>q[tail].v)	tail--;
	            q[++tail]=temp;
	            while(tail>=head&&fabs(j-q[head].i)>a[i].as)	head++;
	            if(tail>=head)
            		dp[i][j]=max(dp[i][j],q[head].v-j*a[i].ap);
			}	
			head=0,tail=-1;
			for(int j=maxp;j>=0;j--)
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j]);  
	            Que temp;  
	            temp.v=dp[pre][j]+j*a[i].bp;temp.i=j;
	            while(tail>=head&&temp.v>q[tail].v)	tail--;
	            q[++tail]=temp;
	            while(tail>=head&&fabs(j-q[head].i)>a[i].bs)	head++;
	            if(tail>=head)
            		dp[i][j]=max(dp[i][j],q[head].v-j*a[i].bp);
			}
  		}
  		printf("%d\n",dp[n][0]);  
	}
	return 0;
}