#include <cstdio>
#define rep(i,a,n) for (int i=a;i<n;i++)
inline int getint() {
	int ret=0;bool ok=0;
	for(;;) {
		int c=getchar();
		if(c>='0'&&c<='9')ret=(ret<<3)+ret+ret+c-'0',ok=1;
		else if(ok)return ret;
	}
}
const int mod=1000000007;
const int N=1010;
int n,m,sr,a[N],__;
int dp[N][N],pd[N][N];
int main() {
	while (1) {
		n=getint();
		if (n==0) break;
		m=0;
		rep(i,0,n) {
			a[m]=getint();
			rep(j,0,a[m]) getint();
			if (a[m]) m++;
		}
		sr=0;
		dp[0][0]=1; 
		rep(i,0,m) {
			pd[0][0]=0;
			rep(j,0,i+1) pd[0][j+1]=1ll*dp[i][j]*(sr-j)%mod;
			rep(k,1,a[i]+1) {
				pd[k][0]=0;
				rep(j,1,i+2) pd[k][j]=(1ll*pd[k-1][j-1]*(i+2-j)+pd[k-1][j])%mod;
			}
			rep(j,0,i+2) dp[i+1][j]=pd[a[i]][j];
			rep(j,0,i+1) pd[0][j]=dp[i][j];
			rep(k,1,a[i]+1) {
				pd[k][0]=pd[k-1][0];
				rep(j,0,i+1) pd[k][j]=(1ll*pd[k-1][j-1]*(i+1-j)+pd[k-1][j])%mod;
			}
			rep(j,0,i+1) {
				dp[i+1][j]+=pd[a[i]][j];
				if (dp[i+1][j]>=mod) dp[i+1][j]-=mod;
			}
			sr+=a[i];
		}
		printf("Case #%d: %d\n",++__,dp[m][m]);
	}
}
