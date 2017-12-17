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

const int N=50000;
VI d[201000];
int mu[N+100],p[N+100],pr[N/5],tot;
int l,Q,__;
ll c[N+100],s[N+100];

void modify(int x,ll v) { if (x<=l) s[x]+=v;for (;x<=l;x+=x&-x) c[x]+=v; }
ll query(int x) { ll s=0;for (;x;x-=x&-x) s+=c[x];return s;}
void init() {
	mu[1]=1;p[1]=1;
	rep(i,2,N+1) {
		if (!p[i]) p[i]=i,pr[++tot]=i,mu[i]=-1;
		for (int j=1;j<=tot&&pr[j]*i<=N;j++) {
			p[i*pr[j]]=pr[j];
			if (p[i]==pr[j]) break;
			else mu[i*pr[j]]=-mu[i];
		}
	}
	rep(i,1,N+1) if (mu[i]) for (int j=i;j<=200000;j+=i) d[j].pb(i);
}

const int R=300;
int main() {
	init();
	while (1) {
		l=getint();Q=getint();
		if (!l&&!Q) break;
		printf("Case #%d:\n",++__);
		rep(i,1,l+1) c[i]=s[i]=0;
		ll ts=0;
		rep(i,0,Q) {
			int ty=getint();
			if (ty==1) {
				int p1=getint(),p2=getint(),p3=getint();
				if (p1%p2!=0) continue;
				int p4=p1/p2;
				rep(j,0,SZ(d[p4])) {
					int p=d[p4][j]*p2,v=mu[d[p4][j]]*p3;
					if (p<=R) ts+=v,s[p]+=v;
					else modify(d[p4][j]*p2,mu[d[p4][j]]*p3);
				}
			} else {
				int p1=getint();
				ll cs=0,ans=0;
				for (int j=1;j<=R&&j<=p1;j++) ans+=s[j]*(p1/j),cs+=s[j];
				for (int j=R+1;j<=p1;j++) {
					int r=p1/(p1/j); ll ps=0;
					if (r-j<=20&&TWO(r-j)<=r) {
						rep(k,j,r+1) ps+=s[k];
						ans+=ps*(p1/j);
						cs+=ps;
					} else {
						ps=query(r)+ts;
						ans+=(ps-cs)*(p1/j);
						cs=ps;
					}
					j=r;
				}
				printf("%I64d\n",ans);
			}
		}
	}
}
