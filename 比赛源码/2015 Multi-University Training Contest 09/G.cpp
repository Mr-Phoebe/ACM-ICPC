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

int n,m,x;
int main() {
	while (scanf("%d%d",&n,&m)!=EOF) {
		int sm=0; pair<int,PII> mx=mp(1<<29,mp(0,0));
		rep(i,0,n) rep(j,0,m) {
			scanf("%d",&x);
			sm+=x;
			if ((i+j)&1) mx=min(mp(x,mp(i,j)),mx);
		}
		if (n%2==1) {
			printf("%d\n",sm);
			rep(i,0,n/2) {
				rep(j,0,m-1) putchar('R'); putchar('D');
				rep(j,0,m-1) putchar('L'); putchar('D');
			}
			rep(j,0,m-1) putchar('R');
		} else if (m%2==1) {
			printf("%d\n",sm);
			rep(i,0,m/2) {
				rep(j,0,n-1) putchar('D'); putchar('R');
				rep(j,0,n-1) putchar('U'); putchar('R');
			}
			rep(j,0,n-1) putchar('D');
		} else {
			printf("%d\n",sm-mx.fi);
			int x=mx.se.fi,y=mx.se.se;
			rep(i,0,x/2) {
				rep(j,0,m-1) putchar('R'); putchar('D');
				rep(j,0,m-1) putchar('L'); putchar('D');
			}
			rep(j,0,y/2) putchar('D'),putchar('R'),putchar('U'),putchar('R');
			if (x%2==1) putchar('R'),putchar('D');
			else putchar('D'),putchar('R');
			rep(j,y/2+1,m/2) putchar('R'),putchar('U'),putchar('R'),putchar('D');
			rep(i,x/2+1,n/2) {
				putchar('D'); rep(j,0,m-1) putchar('L');
				putchar('D'); rep(j,0,m-1) putchar('R');
			}
		}
		puts("");
	}
}
