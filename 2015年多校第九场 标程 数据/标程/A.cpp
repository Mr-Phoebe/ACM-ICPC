#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
typedef long long ll;
const ll mod=1000000007;
const int N=210;
char op[N];
int a[N],n,_;
ll dp[N][N],comb[N][N],fac[N];
int main() {
	rep(i,0,101) {
		comb[i][0]=comb[i][i]=1;
		rep(j,1,i) comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%mod;
	}
	fac[0]=1;
	rep(i,1,101) fac[i]=fac[i-1]*i%mod;
	while (scanf("%d",&n)!=EOF) {
		rep(i,0,n) scanf("%d",a+i);
		scanf("%s",op);
		per(i,0,n) {
			dp[i][i]=a[i];
			rep(j,i+1,n) {
				dp[i][j]=0;
				rep(k,i,j) {
					if (op[k]=='*') dp[i][j]=(dp[i][j]+dp[i][k]*dp[k+1][j]%mod*comb[j-i-1][k-i])%mod;
					if (op[k]=='+') dp[i][j]=(dp[i][j]+(dp[i][k]*fac[j-k-1]+dp[k+1][j]*fac[k-i])%mod*comb[j-i-1][k-i])%mod;
					if (op[k]=='-') dp[i][j]=(dp[i][j]+(dp[i][k]*fac[j-k-1]-dp[k+1][j]*fac[k-i])%mod*comb[j-i-1][k-i])%mod;
				}
			}
		}
		if (dp[0][n-1]<0) dp[0][n-1]+=mod;
		printf("%lld\n",dp[0][n-1]);
	}
}