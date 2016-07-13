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

const int N=70;
map<PLL,ll> dp2[N];
map<ll,ll> dp1[N];
ll pt[N],cnt[N],c[N],d[N],e[N],dp[N];
int m,a[N],b[N];
ll query2(int i,ll u,ll v) {
	assert(0<=u&&u<cnt[i]&&0<=v&&v<cnt[i]);
//	printf("%d %lld %lld\n",i,u,v);
	if (u>v) swap(u,v);
	if (dp2[i].count(mp(u,v))) return dp2[i][mp(u,v)];
	if (v<cnt[a[i]]) return dp2[i][mp(u,v)]=query2(a[i],u,v);
	else if (u>=cnt[a[i]]) return dp2[i][mp(u,v)]=query2(b[i],u-cnt[a[i]],v-cnt[a[i]]);
	else return dp2[i][mp(u,v)]=(query2(a[i],u,c[i])+e[i]+query2(b[i],d[i],v-cnt[a[i]]))%mod;
}
ll query(int i,ll u) {
	assert(u<cnt[i]);
	if (dp1[i].count(u)) return dp1[i][u];
	if (u<cnt[a[i]]) return dp1[i][u]=(query(a[i],u)+(query2(a[i],u,c[i])+e[i])*pt[b[i]]+query(b[i],d[i]))%mod;
	else return dp1[i][u]=(query(b[i],u-cnt[a[i]])+(query2(b[i],u-cnt[a[i]],d[i])+e[i])*pt[a[i]]+query(a[i],c[i]))%mod;
}
int main() {
	while (scanf("%d",&m)!=EOF) {
		rep(i,0,m+1) dp1[i].clear(),dp2[i].clear();
		dp1[0][0]=0; dp2[0][mp(0,0)]=0; cnt[0]=1; pt[0]=1;
		rep(i,1,m+1) scanf("%d%d%lld%lld%lld",a+i,b+i,c+i,d+i,e+i);
		rep(i,1,m+1) {
			cnt[i]=cnt[a[i]]+cnt[b[i]]; pt[i]=cnt[i]%mod;
			dp[i]=(query(a[i],c[i])*pt[b[i]]+query(b[i],d[i])*pt[a[i]]+e[i]*pt[a[i]]%mod*pt[b[i]])%mod;
			printf("%lld\n",dp[i]);
		}
	}
}
