#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <cassert>
#include <complex>
using namespace std;
#define rep(i,a,n) for (int i=a;i<(int)n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define ACCU accumulate
#define TWO(x) (1<<(x))
#define TWOL(x) (1ll<<(x))
#define clr(a) memset(a,0,sizeof(a))
#define POSIN(x,y) (0<=(x)&&(x)<n&&0<=(y)&&(y)<m)
#define PRINTC(x) cout<<"Case #"<<++__<<": "<<x<<endl 
#define POP(x) (__builtin_popcount(x))
#define POPL(x) (__builtin_popcountll(x))
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long ll;
typedef long double LD;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
typedef vector<ll> VL;
typedef vector<PII> VPII;
typedef complex<double> CD;
const int inf=0x20202020;
const ll mod=998244353;
const double eps=1e-9;
const double pi=3.1415926535897932384626;
const int DX[]={1,0,-1,0},DY[]={0,1,0,-1};
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=601000;
int r[N],Pw[N],a[N],p[N],q[N],tmp[N];
ll pw[N],fac[N];
int n,m,x,M,__;
inline int getint() {
	int ret=0;bool ok=0;
	for(;;) {
		int c=getchar();
		if(c>='0'&&c<='9')ret=(ret<<3)+ret+ret+c-'0',ok=1;
		else if(ok)return ret;
	}
}

void rev(int *a,int n) {
	r[0]=0;
	rep(i,1,n) if (i&1) r[i]=(r[i>>1]>>1)+(n>>1); else r[i]=(r[i>>1]>>1);
	rep(i,0,n) if (r[i]<i) swap(a[r[i]],a[i]);
}
void dft(int* a,int n,bool inv) {
	rev(a,n);
	for (int i=0;i<n;i++) pw[i]=Pw[i*(M/n)];
	for (int m=2;m<=n;m<<=1) {
		int wi=inv?n-n/m:n/m;
		for (int j=0;j<n;j+=m) {
			int w=0;
			for (int k=j,k2=j+m/2;k2<j+m;k++,k2++) {
				int u=a[k],v=(a[k2]*pw[w])%mod;
				a[k]=u+v; if (a[k]>=mod) a[k]-=mod;
				a[k2]=u-v; if (a[k2]<0) a[k2]+=mod;
				w+=wi;
				if (w>=n) w-=n;
			}
		}
	}
	if (inv) {
		int rv=powmod(n,mod-2);
		rep(j,0,n) a[j]=1ll*a[j]*rv%mod;
	}
}
void mul(int n) {
	if (n>32) {
		dft(p,n,0);
		dft(q,n,0);
		rep(i,0,n) tmp[i]=1ll*p[i]*q[i]%mod;
		dft(tmp,n,1);
	} else {
		rep(i,0,n) tmp[i]=0;
		rep(i,0,n/2) rep(j,0,n/2) tmp[i+j]=(tmp[i+j]+1ll*p[i]*q[j])%mod;
	}
}
int dp[150][150];
void solve(int l,int r) {
	if (l>n) return;
	if (l+1==r) return;
	if (l+64>=r) {
		int len=r-l;
		rep(i,0,len+1) rep(j,0,i+1) dp[i][j]=0;
		dp[0][0]=1;
		rep(i,1,len+1) {
			dp[i][i]=1;
			rep(j,1,i) dp[i][j]=(dp[i-1][j-1]+1ll*dp[i-1][j]*a[l+i-1])%mod;
			dp[i][0]=1ll*dp[i-1][0]*a[l+i-1]%mod;
		}
		rep(i,0,len) a[l+i]=dp[len][i];
		return;
	}
	int md=(l+r)>>1;
	solve(l,md);
	solve(md,r);
	rep(i,0,2*(r-l)) p[i]=q[i]=0;
	rep(i,l,md) p[i-l]=a[i];
	rep(i,md,r) q[i-md]=a[i];
	mul(r-l);
	rep(i,md,r) {
		tmp[i-l]+=a[i]; if (tmp[i-l]>=mod) tmp[i-l]-=mod;
		tmp[i-l]+=a[i-md+l]; if (tmp[i-l]>=mod) tmp[i-l]-=mod;
	}
	rep(i,l,r) a[i]=tmp[i-l];
}
int main() {
	fac[0]=1; fac[1]=0;
	rep(i,2,201001) fac[i]=(i-1)*(fac[i-1]+fac[i-2])%mod;
	while (1) {
		n=getint(); m=getint();
		if (n==0) break;
		M=1;while (M<=2*n+m+10) M+=M;
		Pw[0]=1; Pw[1]=powmod(3,(mod-1)/M);
		rep(i,2,M) Pw[i]=1ll*Pw[i-1]*Pw[1]%mod;
		int c=1;
		while (c<=n) c+=c;
		rep(i,0,c) a[i]=0;
		rep(i,0,n) a[i]=getint();
		solve(0,c);
		a[c]=1;
		rep(i,0,M) p[i]=q[i]=0;
		rep(i,0,n+1) p[i]=a[c-i];
		rep(i,0,n+m+1) q[i]=fac[i];
		mul(M);
		printf("Case #%d:\n",++__);
		rep(i,n,n+m) printf("%d\n",tmp[i]);
	}
}

