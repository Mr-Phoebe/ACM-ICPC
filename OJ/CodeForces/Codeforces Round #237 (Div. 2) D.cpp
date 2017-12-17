#include <iostream>   
#include <string>   
#include <cstring>   
#include <algorithm>   
#include <stdio.h>   
#include <cctype>   
#include <queue>   
#include <stdlib.h>   
#include <cstdlib>   
#include <math.h>   
#include <set>   
#include <vector>   
using namespace std; 
#define ll __int64
#define mod 1000000007

char s[3000005];
ll dp[1000005][5];
/*
0 这位置为0
1 这位置为1且左边是雷
2 这位置为1且右边是雷
3 这位置为2
4 这位置为雷

*/
int main(){
	ll i, j, k;
	while(~scanf("%s",s)){
		memset(dp[0], 0, sizeof(dp[0]));
		if(s[0]=='0')dp[0][0] = 1;
		else if(s[0]=='1')dp[0][2] = 1;
		else if(s[0]=='*')dp[0][4] = 1;
		else if(s[0]=='?')
			dp[0][0] = dp[0][2] = dp[0][4] = 1;

		for(i = 1; s[i]; i++){
			memset(dp[i], 0, sizeof(dp[i]));
			if(s[i] == '0'){
				dp[i][0] = dp[i-1][1] + dp[i-1][0];	dp[i][0] %= mod;
			}
			else if(s[i] == '1'){
				dp[i][1] = dp[i-1][4]; 
				dp[i][2] = dp[i-1][0] + dp[i-1][1];	dp[i][2] %= mod;
			}
			else if(s[i] == '2'){
				dp[i][3] = dp[i-1][4];
			}
			else if(s[i] == '*'){
				dp[i][4] = dp[i-1][2] + dp[i-1][3] + dp[i-1][4]; dp[i][4] %= mod;
			}
			else if(s[i] == '?'){
				dp[i][0] = dp[i-1][1] + dp[i-1][0];
				dp[i][1] = dp[i-1][4];
				dp[i][2] = dp[i-1][0] + dp[i-1][1];
				dp[i][3] = dp[i-1][4];
				dp[i][4] = dp[i-1][2] + dp[i-1][3] + dp[i-1][4];
				dp[i][0] %= mod; dp[i][4] %= mod; dp[i][2] %= mod;
			}
		}
		i--;
		ll ans = dp[i][0] + dp[i][1] + dp[i][4];
		printf("%I64d\n", ans%mod);
	}
	return 0;
}