//      whn6325689
//		Mr.Phoebe
//		http://blog.csdn.net/u013007900
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <cmath>
#include <functional>
#include <numeric>
#pragma comment(linker, "/STACK:1024000000,1024000000")


using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;

#define CLR(x,y) memset(x,y,sizeof(x))
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define lowbit(x) (x&(-x))
#define MID(x,y) (x+((y-x)>>1))
#define eps 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LLINF 1LL<<62

template<class T>
inline bool read(T &n)
{
    T x = 0, tmp = 1; char c = getchar();
    while((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();
    if(c == EOF) return false;
    if(c == '-') c = getchar(), tmp = -1;
    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c = getchar();
    n = x*tmp;
    return true;
}
template <class T>
inline void write(T n)
{
    if(n < 0)
    {
        putchar('-');
        n = -n;
    }
    int len = 0,data[20];
    while(n)
    {
        data[len++] = n%10;
        n /= 10;
    }
    if(!len) data[len++] = 0;
    while(len--) putchar(data[len]+48);
}
//-----------------------------------

const int MAXN=100010; 

struct Day
{
	double a,b,r,k;
	int idx;
	bool operator < (const Day b) const
	{
		return k>b.k;
	}
}d[MAXN],td[MAXN];

struct Point
{
	double x,y;
	bool operator < (const Point b) const
	{
		if(abs(x-b.x)<eps)	return y<b.y;
		return x<b.x;
	}
}p[MAXN],tp[MAXN];

int n,q[MAXN];
double s,dp[MAXN];

double getslope(int i,int j)
{
	if(abs(p[i].x-p[j].x)<eps)	return -1.0e20;
	return (p[i].y-p[j].y)/(p[i].x-p[j].x);
}

void cdq(int l,int r)
{
	if(l==r)
	{
		dp[l]=max(dp[l],dp[l-1]);
		p[l].y=dp[l]/(d[l].a*d[l].r+d[l].b);
		p[l].x=p[l].y*d[l].r;
		return;
	}
	int mid=MID(l,r);
	int l1=l,l2=mid+1;
	for(int i=l;i<=r;i++)
		if(d[i].idx<=mid) td[l1++]=d[i];
		else		      td[l2++]=d[i];
	for(int i=l;i<=r;i++)
		d[i]=td[i];
	cdq(l,mid);
	int head=0,tail=0;
	for(int i=l;i<=mid;i++)
	{
		while(tail-head>1 && getslope(i,q[tail-1]) > getslope(q[tail-1],q[tail-2]))
			tail--;
		q[tail++]=i;
	}
	for(int i=mid+1;i<=r;i++)
	{
		while(tail-head>1 && d[i].k < getslope(q[head],q[head+1]))
			head++;
		dp[d[i].idx]=max(dp[d[i].idx],p[q[head]].x*d[i].a+p[q[head]].y*d[i].b);
	}
	cdq(mid+1,r);
	l1=l,l2=mid+1;
	for(int i=l;i<=r;i++)
		if(l1<=mid && (l2>r || p[l1]<p[l2]))	tp[i]=p[l1++];
		else	tp[i]=p[l2++];
	for(int i=l;i<=r;i++)
		p[i]=tp[i];
}

int main()
{
//	freopen("data.txt","r",stdin);
//	freopen("wa.txt","w",stdout);
	scanf("%d %lf",&n,&dp[0]);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf %lf %lf",&d[i].a,&d[i].b,&d[i].r);
		d[i].k=-d[i].a/d[i].b;d[i].idx=i;
	}
	sort(d+1,d+n+1);
	cdq(1,n);
	printf("%.3f\n",dp[n]);
	return 0;
}