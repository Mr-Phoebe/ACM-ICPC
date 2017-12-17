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

int x,n,m,ret,a[210][210],l,r,vis[210][210],tc;
char pt[101000];
void check(int x,string info) {
	if (x==0) {  printf("wa"); exit(0);}
}
void success() {
	puts("AC!");
}
int main(int argc,char **argv) {
	FILE *fin=fopen(argv[1],"r"),*fout=stdin;
	while (fscanf(fin,"%d%d",&n,&m)!=EOF) {
		int sm=0; pair<int,PII> mx=mp(1<<29,mp(0,0));
		rep(i,0,n) rep(j,0,m) {
			fscanf(fin,"%d",&x);
			sm+=x; a[i][j]=x; vis[i][j]=0;
			if ((i+j)&1) mx=min(mp(x,mp(i,j)),mx);
		}
		int x=0,y=0,ans=0;
		ans+=a[0][0],vis[0][0]=1;
		if (n%2==1||m%2==1) ret=sm; else ret=sm-mx.fi;
		fscanf(fout,"%d",&r);
		check(ret==r,"答案错误");
		fscanf(fout,"%s",pt);
		l=strlen(pt);
		rep(i,0,l) {
			if (pt[i]=='L') --y;
			else if (pt[i]=='R') ++y;
			else if (pt[i]=='U') --x;
			else if (pt[i]=='D') ++x;
			else check(0,"奇怪的方向");
			check(POSIN(x,y),"越界");
			check(!vis[x][y],"重复");
			vis[x][y]=1; ans+=a[x][y];
		}
		check(x==n-1&&y==m-1,"结束错误");
		check(ans==r,"结束答案错误");
	}
	success();
}