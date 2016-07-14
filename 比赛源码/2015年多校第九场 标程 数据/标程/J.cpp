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
#define rep(i,a,n) for (int i=a;i<n;i++)
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


const int N=101000;
struct BIT {
	ll c[N]; int n;
	void init(int tot) { n=tot; rep(i,1,n+1) c[i]=0;}
	void build() { rep(i,1,n+1) { int x=i+(i&-i); if (x<=n) c[x]=c[i]+c[x]; } }
	void modify(int x,ll s) { for (;x<=n;x+=x&-x) c[x]=c[x]+s;}
	ll query(int x) { ll s=0; for (;x;x-=x&-x) s=s+c[x]; return s%mod;}
}cw,cp;

int q[N],hs[N],hv[N],dep[N],id[N],l[N],r[N],bel[N],s[N],f[N],tot,w[N];
ll sw;
int n,m,u,v,ty;
VI e[N];

inline ll sqr(ll w) { w%=mod; return w*w%mod;}
void dfs(int u,int f) {
	id[l[u]=++tot]=u; cw.c[l[u]]=w[u];
	dep[u]=dep[f]+1; s[u]=w[u];
	ll ret=0;
	if (hv[u]) { dfs(hv[u],u); s[u]=(s[u]+s[hv[u]])%mod;}
	rep(j,0,SZ(e[u])) {
		int v=e[u][j];
		if (v==f||v==hv[u]) continue;
		dfs(v,u); ret=(ret+sqr(s[v]))%mod; s[u]=(s[u]+s[v])%mod;
	}
	cp.c[l[u]]=ret%mod;
	r[u]=tot;
}
void HLDoT(int rt) {
	int t=1;
	q[0]=rt; tot=0;
	rep(i,1,n+1) f[i]=s[i]=bel[i]=hs[i]=hv[i]=0;
	rep(i,0,n) {
		int u=q[i];
		rep(j,0,SZ(e[u])) if (e[u][j]!=f[u])
			f[e[u][j]]=u,dep[q[t++]=e[u][j]]=dep[u]+1;
	}
	per(i,0,n) {
		int u=q[i],p=f[u];
		s[u]++,s[p]+=s[u];
		if (hs[p]<s[u]) hs[p]=s[u],hv[p]=u;
	}
	rep(i,0,n) {
		int u=q[i];
		if (!bel[u]) bel[u]=u;
		if (hv[u]) bel[hv[u]]=bel[u];
	}
	dfs(rt,0);
}

inline ll queryw(int u) {
	return cw.query(r[u])-cw.query(l[u]-1);
}
void change(int u,int v) {
	cw.modify(l[u],v); sw=(sw+v)%mod; w[u]+=v;
	u=bel[u];
	while (f[u]) {
		ll s=queryw(u);
		cp.modify(l[f[u]],sqr(s)-sqr(s-v));
		u=bel[f[u]];
	}
}
ll query(int u,int v) {
	ll ans=0;
	while (1) {
		if (bel[u]==bel[v]) {
			if (dep[u]<dep[v]) swap(u,v);
			ans+=cp.query(l[u])-cp.query(l[v]-1);
			if (hv[u]) ans+=sqr(queryw(hv[u]));
			ans+=sqr(sw-queryw(v));
			break;
		} else {
			if (dep[bel[u]]<dep[bel[v]]) swap(u,v);
			ans+=cp.query(l[u])-cp.query(l[bel[u]]-1);
			if (hv[u]) ans+=sqr(queryw(hv[u]));
			ans-=sqr(queryw(bel[u]));
			u=f[bel[u]];
		}
	}
	return ans%mod;
}

int main() {
	while (scanf("%d%d",&n,&m)!=EOF) {
		sw=0; cp.init(n); cw.init(n);
		rep(i,1,n+1) scanf("%d",w+i),sw+=w[i],e[i].clear();
		sw%=mod;
		rep(i,1,n) {
			scanf("%d%d",&u,&v);
			e[u].pb(v); e[v].pb(u);
		}
		HLDoT(1);
		cp.build(); cw.build();
		rep(i,0,m) {
			scanf("%d%d%d",&ty,&u,&v);
			if (ty==1) {
				v-=w[u]; change(u,v);
			} else {
				ll ret=(sqr(sw)-query(u,v))%mod;
				if (ret<0) ret+=mod;
				printf("%d\n",(int)ret);
			}
		} 
	}
}