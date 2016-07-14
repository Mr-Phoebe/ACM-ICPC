#include <cstdio>
#include <algorithm>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
typedef long long ll;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=110;
ll f[N],g[N],inv[N],pr1[N][N][N],pr2[N][N][N],dp[N][N][N];
int st[N],n,k,m,val[N],ual[N],p;
void upd(ll &a,ll b) { a=(a+b)%mod; }
int main() {
	f[0]=g[0]=1; 
	rep(i,1,101) f[i]=f[i-1]*i%mod,inv[i]=powmod(i,mod-2),g[i]=g[i-1]*inv[i]%mod;
	while (scanf("%d%d%d",&n,&k,&m)!=EOF) {
		rep(i,1,n+1) st[i]=0;
		rep(i,0,m) scanf("%d",&p),st[p]=1;
		rep(i,1,n+1) val[i]=val[i-1]+st[i],ual[i]=ual[i-1]+!st[i];
		rep(l,1,n+1) rep(r,l,n+1) rep(k,0,val[l-1]+1) {
			ll p1=(ual[r]-ual[l-1])*(ual[r]-ual[l-1]-1)/2,p2=0;
			rep(c,l,r+1) if (st[c]) {
				p2=p2+(k+val[c])*(ual[r]-ual[c-1]);
				p1=p1+2*(ual[c]-ual[l-1]);
				p2=p2-(k+val[c])*(ual[c]-ual[l-1]);
			}
			pr1[l][r][k]=p1*inv[2]%mod*g[k+val[r]]%mod*f[k+val[l-1]]%mod;
			pr2[l][r][k]=p2*g[k+val[r]+1]%mod*f[k+val[l-1]]%mod;
		}
		rep(i,0,n+1) rep(j,0,i/2+1) rep(s,0,val[i]+1) dp[i][j][s]=0;
		dp[0][0][0]=1;
		rep(i,0,n) rep(j,0,i/2+1) rep(s,0,val[i]+1) if (dp[i][j][s]) {
			rep(r,i+2,n+1) {
				upd(dp[r][j+1][s+1],dp[i][j][s]*pr2[i+1][r][s]);
				upd(dp[r][j+1][s],dp[i][j][s]*pr1[i+1][r][s]);
			}
		}
		ll ret=0;
		rep(s,0,val[n]+1) upd(ret,dp[n][k][s]);
		ret=ret*f[val[n]]%mod;
		if (ret<0) ret+=mod;
		printf("%d\n",(int)ret);
	}
}
