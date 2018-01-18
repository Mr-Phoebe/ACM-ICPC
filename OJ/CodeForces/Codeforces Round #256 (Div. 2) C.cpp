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

using namespace std;

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
//--------------------------------

int main()
{
    int n;
	read(n);
    int a[n+1];
    a[0]=0;
    for(int i=1;i<=n;i++)
		read(a[i]);
    int dp[n+1][n+1];
    for(int j=0;j<=n;j++)
		dp[n][j]=0;
    for(int i=n-1;i>=0;i--)
		for(int j=0;j<=i;j++)
	    	if(a[j]>=a[i+1])
				dp[i][j]=dp[i+1][i+1];
	    	else
	        	dp[i][j]=min(1+dp[i+1][j],a[i+1]-a[j]+dp[i+1][i+1]);
    printf("%d\n",dp[0][0]);
    return 0;
}
