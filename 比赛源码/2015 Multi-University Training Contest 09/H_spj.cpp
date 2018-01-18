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

namespace Factor {
	const int N=1010000;
	ll C,fac[10010],n,mut,a[1001000];
	int T,cnt,i,l,prime[N],p[N],psize,_cnt;
	ll _e[100],_pr[100];
	vector<ll> d;
	inline ll mul(ll a,ll b,ll p) {
		if (p<=1000000000) return a*b%p;
		else if (p<=1000000000000ll) return (((a*(b>>20)%p)<<20)+(a*(b&((1<<20)-1))))%p;
		else {
			ll d=(ll)floor(a*(long double)b/p+0.5);
			ll ret=(a*b-d*p)%p;
			if (ret<0) ret+=p;
			return ret;
		}
	}
	void prime_table(){
		int i,j,tot,t1;
		for (i=1;i<=psize;i++) p[i]=i;
		for (i=2,tot=0;i<=psize;i++){
			if (p[i]==i) prime[++tot]=i;
			for (j=1;j<=tot && (t1=prime[j]*i)<=psize;j++){
				p[t1]=prime[j];
				if (i%prime[j]==0) break;
			}
		}
	}
	void init(int ps) {
		psize=ps;
		prime_table();
	}
	ll powl(ll a,ll n,ll p) {
		ll ans=1;
		for (;n;n>>=1) {
			if (n&1) ans=mul(ans,a,p);
			a=mul(a,a,p);
		}
		return ans;
	}
	bool witness(ll a,ll n) {
		int t=0;
		ll u=n-1;
		for (;~u&1;u>>=1) t++;
		ll x=powl(a,u,n),_x=0;
		for (;t;t--) {
			_x=mul(x,x,n);
			if (_x==1 && x!=1 && x!=n-1) return 1;
			x=_x;
		}
		return _x!=1;
	}
	bool miller(ll n) {
		if (n<2) return 0;
		if (n<=psize) return p[n]==n;
		if (~n&1) return 0;
		for (int j=0;j<=7;j++) if (witness(rand()%(n-1)+1,n)) return 0;
		return 1;
	}
}

int k,e[110];
ll x,a,b,p[110];
char s[110];
FILE *fin,*fout;
void check(int x,string info) {
	if (x==0) {  printf("wa"); exit(0);}
}
void success() {
	puts("AC!");
}
bool good(ll x) {
	if (x==1) return 1;
	ll s=1;
	rep(i,0,k) {
		if (p[i]>s+1) return 0;
		ll c=0,r=1;
		rep(j,0,e[i]+1) c+=r,r*=p[i];
		s*=c;
	}
	return 1;
}

void read(ll x) {
	fscanf(fout,"%d",&k);
	check(0<=k&&k<=60,"根本没有这么多素因子！");
	ll s=x;
//	fprintf(stderr,"%d\n",k);
	rep(i,0,k) {
		fscanf(fout,"%lld%d",p+i,e+i);
		check(2<=p[i]&&p[i]<=x,"底数范围不对哦！");
		check(1<=e[i]&&e[i]<=60,"指数范围不对哦！");
	}
	rep(i,1,k) check(p[i-1]<p[i],"p要递增！");
	rep(i,0,k) {
		rep(j,0,e[i]) {
			check(x%p[i]==0,"分解不对！");
			x/=p[i];
		}
	}
	check(x==1,"分解不对！");
	rep(i,0,k) check(Factor::miller(p[i]),"底数不是质数哦！");
	check(good(s),"不是好数哦！");
}
int main(int argc,char **argv) {
	fin=fopen(argv[1],"r"),fout=stdin;
	Factor::init(1000000);
	while (fscanf(fin,"%lld",&x)!=EOF) {
//		fprintf(stderr,"%lld\n",x);
		fscanf(fout,"%s",s);
		check(s[0]=='Y'&&s[1]=='E'&&s[2]=='S'&&s[3]==0,"根本就是有答案的！");
		fscanf(fout,"%lld%lld",&a,&b);
		check(1<=a&&a<=x&&1<=b&&b<=x,"a,b范围不对");
		check(a+b==x,"a+b根本不等于x！");
		read(a); read(b);
	}
	success();
}