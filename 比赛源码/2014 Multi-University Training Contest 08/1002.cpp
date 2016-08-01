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
//const int inf=0x20202020;
const ll mod=1000000007;
const double eps=1e-8;
const double pi=3.1415926535897932384626;
const int DX[]={1,0,-1,0},DY[]={0,1,0,-1};
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

inline int getint() {
	int ret=0;bool ok=0,neg=0;
	for(;;) {
		int c=getchar();
		if(c>='0'&&c<='9')ret=(ret<<3)+ret+ret+c-'0',ok=1;
		else if(ok)return neg?-ret:ret;
		else if(c=='-')neg=1;
	}
}

const double inf=1e20;
const int maxp=1111;
int dblcmp(int d) {
	if (d==0)return 0;
	return d>0?1:-1;
}
struct point {
	int x,y;
	point(){}
	point(int _x,int _y):
	x(_x),y(_y){};
	void input() { x=getint(),y=getint(); }
	bool operator==(point a)const {
		return dblcmp(a.x-x)==0&&dblcmp(a.y-y)==0;
	}
	bool operator<(point a)const {
		return dblcmp(a.x-x)==0?dblcmp(y-a.y)<0:x<a.x;
	}
	point add(point p) { return point(x+p.x,y+p.y);}
	point sub(point p) { return point(x-p.x,y-p.y);}
	int len() { return x*x+y*y;}
	int dot(point p) { return x*p.x+y*p.y;}
	int det(point p) { return x*p.y-y*p.x;}
	double rad(point a,point b) {
		point p=*this;
		return fabs(atan2(fabs(a.sub(p).det(b.sub(p))),a.sub(p).dot(b.sub(p))));
	}
	point rotleft() { return point(-y,x);}
	point rotright() { return point(y,-x);}
	point rotate(point p,double angle)//绕点p逆时针旋转angle角度 
	{
		point v=this->sub(p);
		double c=cos(angle),s=sin(angle);
		return point(p.x+v.x*c-v.y*s,p.y+v.x*s+v.y*c);
	}        
};
struct line {
	point a,b;
	line(){}
	line(point _a,point _b) { a=_a;b=_b;}
	bool operator==(line v) { return (a==v.a)&&(b==v.b);}
	//倾斜角angle 
	line(point p,double angle) {
		a=p;
		if (dblcmp(angle-pi/2)==0) b=a.add(point(0,1));
		else b=a.add(point(1,tan(angle)));
	}       
	//ax+by+c=0
	line(double _a,double _b,double _c) {
		if (dblcmp(_a)==0) a=point(0,-_c/_b),b=point(1,-_c/_b);
		else if (dblcmp(_b)==0) a=point(-_c/_a,0),b=point(-_c/_a,1);
		else a=point(0,-_c/_b),b=point(1,(-_c-_a)/_b);
	}
	void input() { a.input();b.input();}
	void adjust() { if (b<a)swap(a,b);}
	//直线倾斜角 0<=angle<180
	double angle() {
		double k=atan2(b.y-a.y,b.x-a.x);
		if (dblcmp(k)<0)k+=pi;
		if (dblcmp(k-pi)==0)k-=pi;
		return k;
	}
	//点和线段关系
	//1 在逆时针
	//2 在顺时针
	//3 平行
	int relation(point p) {
		int c=dblcmp(p.sub(a).det(b.sub(a)));
		if (c<0)return 1;
		if (c>0)return 2;
		return 3;
	}
	bool pointonseg(point p) {
		return dblcmp(p.sub(a).det(b.sub(a)))==0&&dblcmp(p.sub(a).dot(p.sub(b)))<=0;
	}
	bool parallel(line v) {
		return dblcmp(b.sub(a).det(v.b.sub(v.a)))==0;
	}
	int linecrossseg(line v)//*this seg v line
	{
		int d1=dblcmp(b.sub(a).det(v.a.sub(a)));
		int d2=dblcmp(b.sub(a).det(v.b.sub(a)));
		if ((d1^d2)==-2)return 2;
		return (d1==0||d2==0);
	}
	//0 平行
	//1 重合
	//2 相交 
	int linecrossline(line v)
	{
		if ((*this).parallel(v))
		{
			return v.relation(a)==3;
		}
		return 2;
	}
	point crosspoint(line v)
	{
		double a1=v.b.sub(v.a).det(a.sub(v.a));
		double a2=v.b.sub(v.a).det(b.sub(v.a));
		return point((a.x*a2-b.x*a1)/(a2-a1),(a.y*a2-b.y*a1)/(a2-a1));
	}
};
struct polygon 
{
	int n;
	point p[maxp];
	line l[maxp];
	void init() { n=0;}
	void add(point q) { p[n++]=q;}
	void getline()
	{
		for (int i=0;i<n;i++)
		{
			l[i]=line(p[i],p[(i+1)%n]);
		}
	}
	struct cmp
	{
		point p;
		cmp(const point &p0){p=p0;}
		bool operator()(const point &aa,const point &bb)
		{
			point a=aa,b=bb;
			int d=dblcmp(a.sub(p).det(b.sub(p)));
			if (d==0)
			{
				return a.sub(p).len()<b.sub(p).len();
			}
			return d>0;
		}
	};
	void norm()
	{
		point mi=p[0];
		for (int i=1;i<n;i++)mi=min(mi,p[i]);
		sort(p,p+n,cmp(mi));
	}
	void getconvex(polygon &convex)
	{
		int i;
		sort(p,p+n);
		convex.n=n;
		for (i=0;i<min(n,2);i++)
		{
			convex.p[i]=p[i];
		}
		if (n<=2)return;
		int &top=convex.n;
		top=1;
		for (i=2;i<n;i++)
		{
			while (top&&convex.p[top].sub(p[i]).det(convex.p[top-1].sub(p[i]))<=0)
				top--;
			convex.p[++top]=p[i];
		}
		int temp=top;
		convex.p[++top]=p[n-2];
		for (i=n-3;i>=0;i--)
		{
			while (top!=temp&&convex.p[top].sub(p[i]).det(convex.p[top-1].sub(p[i]))<=0)
				top--;
			convex.p[++top]=p[i];
		}
	}
	//3 点上
	//2 边上
	//1 内部
	//0 外部 
	int relationpoint(point q) {
		for (int i=0;i<n;i++) if (p[i]==q)return 1;
		for (int i=0;i<n;i++) if (l[i].pointonseg(q)) return 1;
		return 0;
	}
};

const int N=510;
polygon T,t;
int n,mv,__;
point p[N];
int v[N];
int main() {
	while (1) {
		n=getint();
		if (n==0) break;
		mv=0;
		rep(i,0,n) p[i].input(),v[i]=getint();
		rep(i,0,n) mv=max(mv,v[i]);
		T.init();
		printf("Case #%d: ",++__);
		if (mv==0) {
			rep(i,0,n) putchar('0'); puts("");
			continue;
		}
		rep(i,0,n) if (v[i]==mv) T.add(p[i]);
		T.getconvex(t);
		t.getline();
		rep(i,0,n) {
			int fg=0;
			if (v[i]==mv&&t.relationpoint(p[i])) {
				fg=1;
				rep(j,0,n) if (v[j]==mv&&j!=i&&p[j]==p[i]) { fg=0;break;}
			}
			putchar(fg+'0');
		}
		puts("");
	}
}
