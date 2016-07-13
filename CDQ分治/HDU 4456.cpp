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

const int MAXN=80010;

struct Node
{
	int kind;
	int x,y,z,idx;
	Node(int k=0,int xx=0,int yy=0,int zz=0,int idx=0):kind(k),x(xx),y(yy),z(zz),idx(idx){}
}ask[4*MAXN],tmp1[4*MAXN],tmp2[4*MAXN];
int n,m,tot;
int c[MAXN];
int ans[MAXN];

bool cmp(Node a,Node b)
{
	if(a.x==b.x)
		return a.y<b.y;
	return a.x<b.x;
}

void update(int i,int v)
{
	for(;i<MAXN;i+=lowbit(i))
		c[i]+=v;
}

int getsum(int i)
{
	int sum=0;
	for(;i;i-=lowbit(i))
		sum+=c[i];
	return sum;
}

void clr(int i)
{
	for(;i<MAXN;i+=lowbit(i))
		c[i]=0;
}

void change(int x,int y,int &xx,int &yy)
{
	xx=x-y+n;
	yy=x+y;
}

void cdq(int l,int r)
{
	if(l==r)	return;
	int mid=MID(l,r);
	int l1=0,l2=0;
	cdq(l,mid);
 	for(int i=l;i<=r;i++)
 	{
        if(i<=mid && ask[i].kind==1) tmp1[l1++]=ask[i];
        if(i> mid && ask[i].kind==2) tmp2[l2++]=ask[i];
    }
    sort(tmp1,tmp1+l1,cmp);
    sort(tmp2,tmp2+l2,cmp);
    for(int i=0,j=0;i<l2;i++)
   	{
	   	while(j<l1 && tmp1[j].x <= tmp2[i].x)
	   	{
	   		update(tmp1[j].y,tmp1[j].z);j++;
	   	}
   		ans[tmp2[i].idx]+=getsum(tmp2[i].y)*tmp2[i].z;
	}
	for(int i=0;i<l1;i++)
		clr(tmp1[i].y);
	cdq(mid+1,r);
}

int main()
{
//    freopen("data.txt","r",stdin);
//    freopen("wa.txt","w",stdout);
	while(read(n)&&n)
	{
		read(m);
		CLR(c,0);CLR(ans,0);CLR(ask,0);tot=0;
		for(int i=0,x,y,xx,yy,k,z;i<m;i++)
		{
			read(k),read(x),read(y),read(z);
			change(x,y,xx,yy);
			if(k==1)
			{
				tot++;ask[tot].kind=1;ask[tot].x=xx;ask[tot].y=yy;ask[tot].z=z;ask[tot].idx=i;
			}
			else
			{
				int x1=max(0,xx-z-1);
				int y1=max(0,yy-z-1);
				int x2=min(2*n,xx+z);
				int y2=min(2*n,yy+z);
				tot++;ask[tot].kind=2;ask[tot].x=x1;ask[tot].y=y1;ask[tot].z=1; ask[tot].idx=i;
				tot++;ask[tot].kind=2;ask[tot].x=x2;ask[tot].y=y1;ask[tot].z=-1;ask[tot].idx=i;
				tot++;ask[tot].kind=2;ask[tot].x=x1;ask[tot].y=y2;ask[tot].z=-1;ask[tot].idx=i;
				tot++;ask[tot].kind=2;ask[tot].x=x2;ask[tot].y=y2;ask[tot].z=1; ask[tot].idx=i;
			}
		}
		cdq(1,tot);
		for(int i=1;i<=tot;i++)
			if(ask[i].kind==2)
			{
				printf("%d\n",ans[ask[i].idx]);
				i+=3;
			}
	}
	return 0;
}
