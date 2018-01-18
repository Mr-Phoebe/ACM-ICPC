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

int cnt[3010];
ll f[101000],g[101000];
int pn,n,__;
int dp[13][3010];
inline int getint() {
	int ret=0;bool ok=0;
	for(;;) {
		int c=getchar();
		if(c>='0'&&c<='9')ret=(ret<<3)+ret+ret+c-'0',ok=1;
		else if(ok)return ret;
	}
}
int binom(int x,int y) {
	if (x<y||y<0) return 0;
	else return f[x]*g[y]%mod*g[x-y]%mod;
}
inline void upd(int &a,int b) { a+=b; if (a>=mod) a-=mod;}
int main() { 
	f[0]=1; rep(i,1,100001) f[i]=f[i-1]*i%mod;g[100000]=powmod(f[100000],mod-2);
	per(i,0,100000) g[i]=g[i+1]*(i+1)%mod;
	while (1) {
		n=getint();
		if (n==0) break;
		rep(i,0,12) cnt[TWO(i)]=0;
		rep(i,0,n) cnt[getint()]++;
		pn=0;
		rep(i,0,12) pn+=cnt[TWO(i)];
		rep(i,0,11) rep(j,0,TWO(10-i)) dp[i][j]=0; dp[11][0]=0;
		int ct=cnt[1];
		ll cof=f[ct];
		rep(j,0,TWO(11)) {
			if (j>ct) break;
			upd(dp[0][j>>1],g[ct-j]%mod*g[j]%mod);
		}
		rep(i,0,11) {
			ct=cnt[TWO(i+1)];
			cof=cof*f[ct]%mod;
			rep(j,0,TWO(10-i)) if (dp[i][j]) {
				rep(k,0,TWO(10-i)) {
					if (k>ct||j+k>TWO(10-i)) break;
					upd(dp[i+1][(j+k)>>1],1ll*dp[i][j]*g[k]%mod*g[ct-k]%mod);
				}
			}
		}
		int ans=(powmod(2,pn)-dp[11][0]*cof)%mod*powmod(2,n-pn)%mod;
		if (ans<0) ans+=mod;
		printf("Case #%d: %d\n",++__,ans);
	}
}

