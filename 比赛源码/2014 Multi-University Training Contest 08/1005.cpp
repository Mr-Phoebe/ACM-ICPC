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
const ll mod=1000000007;
const double eps=1e-9;
const double pi=3.1415926535897932384626;
const int DX[]={1,0,-1,0},DY[]={0,1,0,-1};
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

inline int getint() {
	int ret=0;bool ok=0;
	for(;;) {
		int c=getchar();
		if(c>='0'&&c<='9')ret=(ret<<3)+ret+ret+c-'0',ok=1;
		else if(ok)return ret;
	}
}

int n,m,f[20][20],__;
char g[20][20];
int hs[1100000],gs[1100000];
int dp[2][101000],sta[2][101000],T,t,K,ctm;
void init() { ctm++; T=0;} 
void add(int S,int p) {
	if (hs[S]!=ctm) hs[S]=ctm,gs[S]=T,dp[K][T]=inf,sta[K][T]=S,++T;
	dp[K][gs[S]]=min(dp[K][gs[S]],p);
}
#define ff(k,x) (k<<(2*(x)))
#define gg(k,x) ((k>>(2*(x)))&3)
inline int F(int S,int pos) { return gg(S,pos);}
inline int G(int S,int pos,int v) { return (S&(~ff(3,pos)))|ff(v,pos);}

int main() {
	while (1) {
		n=getint(),m=getint();
		if (n==0&&m==0) break;
		rep(i,0,n) scanf("%s",g[i]);
		if (n>=m) rep(i,0,n) rep(j,0,m) f[i][j]=g[i][j]-'0';
		else { rep(i,0,m) rep(j,0,n) f[i][j]=g[j][i]-'0'; swap(n,m);}
		init();
		add((TWO(2*m)-1)/3*2,0); t=T;
		rep(qx,0,n) rep(qy,0,m) {
			K=1-K;
			init();
			rep(j,0,t) {
				int S=sta[1-K][j],v=dp[1-K][j],nS=0;
				nS=S;
				if (F(nS,qy)!=0) {
					nS=G(nS,qy,2);
					if (qy>0&&F(nS,qy-1)!=2) nS=G(nS,qy-1,F(nS,qy-1)^1);
					if (qx!=n-1||((!qy||F(nS,qy-1)!=1)&&(qy!=m-1||F(nS,qy)!=1))) add(nS,v+1);
				}
				nS=S;
				if (F(nS,qy)!=1) {
					nS=G(nS,qy,(qx&&F(nS,qy)==2)^(qy&&F(nS,qy-1)==2)^f[qx][qy]);
					if (qx!=n-1||((!qy||F(nS,qy-1)!=1)&&(qy!=m-1||F(nS,qy)!=1))) add(nS,v);
					nS=G(nS,qy,F(nS,qy)^1);
					if (qx!=n-1||((!qy||F(nS,qy-1)!=1)&&(qy!=m-1||F(nS,qy)!=1))) add(nS,v+2);
				}
			}
			t=T;
		}
		int ans=inf;
		rep(j,0,t) ans=min(ans,dp[K][j]);
		printf("Case #%d: %d\n",++__,ans);
	}
}
