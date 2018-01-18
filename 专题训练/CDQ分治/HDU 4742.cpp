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

int n,tot;
struct Node
{
	int x,y,z;
	bool operator < (const Node& b) const
	{
		if(x!=b.x)	return x<b.x;
		if(y!=b.y)	return y<b.y;
		return z<b.z;
	}
}a[MAXN];

struct Point
{
	int y,z,pos;
	Point(const int& y=0,const int& z=0,const int& pos=0):y(y),z(z),pos(pos){}
	bool operator < (const Point& b) const
	{
		if(y!=b.y)	return y<b.y;
		return z<b.z;
	}
}p1[MAXN/2],p2[MAXN/2];

struct DP
{
    int len, num;
    DP(const int& len=0,const int& num=0):len(len),num(num){}
}dp[MAXN],c[MAXN];

int zz[MAXN];

DP MAX(DP a,const DP& b)
{
    if(a.len==b.len)	 a.num+=b.num;
    else if(a.len<b.len) a=b;
    return a;
}

void update(int i,const DP& v)
{
	for(;i<tot+10;i+=lowbit(i))
		c[i]=MAX(c[i],v);
}

DP getsum(int i)
{
	DP sum;
	for(;i>0;i-=lowbit(i))
		sum=MAX(sum,c[i]);
	return sum;
}

void clr(int i)
{
	for(;i<tot+10;i+=lowbit(i))
		c[i]=DP();
}

void cdq(int l,int r)
{
	if(l==r)
		return; 
	int mid=MID(l,r);
	cdq(l,mid);
	for(int i=l;i<=mid;i++)
		p1[i]=Point(a[i].y,a[i].z,i);
	for(int i=mid+1;i<=r;i++)
		p2[i]=Point(a[i].y,a[i].z,i);
	sort(p1+l,p1+mid+1);
	sort(p2+mid+1,p2+r+1);
	for(int i=mid+1,j=l;i<=r;i++)
	{
		while(j<=mid && p1[j].y<=p2[i].y)
		{
			update(p1[j].z,dp[p1[j].pos]);j++;
		}
		DP temp=getsum(p2[i].z);
		temp.len++;
		dp[p2[i].pos]=MAX(dp[p2[i].pos],temp);
	}
	for(int i=l;i<=mid;i++)
		clr(p1[i].z);
	cdq(mid+1,r);
}

int main()
{
	int T;
	read(T);
	while(T--)
	{
		read(n);
		for(int i=1;i<=n;i++)
			read(a[i].x),read(a[i].y),read(a[i].z);
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
			zz[i]=a[i].z;
		sort(zz+1,zz+n+1);
		tot=unique(zz+1,zz+n+1)-zz-1;
		for(int i=1;i<=n;i++)
			a[i].z=upper_bound(zz+1,zz+tot+1,a[i].z)-zz-1;
		for(int i=0;i<=tot+10;i++)
			c[i]=DP();
		for(int i=1;i<=n;i++)
			dp[i]=DP(1,1);
		cdq(1,n);
		DP ans;
		for(int i=1;i<=n;i++)
			ans=MAX(ans,dp[i]);
		write(ans.len),putchar(' '),write(ans.num),putchar('\n');
	}
	return 0;
}