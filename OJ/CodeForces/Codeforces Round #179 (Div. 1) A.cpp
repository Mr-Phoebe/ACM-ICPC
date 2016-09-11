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
#define ls idx<<1
#define rs idx<<1|1
#define eps 1e-9
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

int n,m,k;

struct BIT
{
	int c[MAXN];
	BIT(){CLR(c,0);}
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
	int dif(int i)
	{
		return getsum(i)-getsum(i-1);
	}
	void clear()
	{
		CLR(c,0);
	}
} g;

struct Node
{
	int l,r;
	ll add,v;
}t[MAXN<<2],q[MAXN];

void pushdown(int idx)
{
	if(t[idx].add)
	{
//		cout<<"PUSHDOWN "<<t[ls].l<<" "<<t[ls].r<<" : "<<t[ls].l<<" "<<t[rs].r<<endl;
		t[ls].v+=(t[ls].r-t[ls].l+1)*t[idx].add;
		t[rs].v+=(t[rs].r-t[rs].l+1)*t[idx].add;
		t[ls].add+=t[idx].add;
		t[rs].add+=t[idx].add;
		t[idx].add=0;
	}
}


void build(int idx,int l,int r)
{
	t[idx].l=l,t[idx].r=r;
	t[idx].add=t[idx].v=0;
	if(l==r)
	{
		read(t[idx].v);
		return;
	}
	int mid=MID(l,r);
	build(ls,l,mid);
	build(rs,mid+1,r);
	t[idx].v=t[ls].v+t[rs].v;
}

void update(int idx,int l,int r,ll v)
{
	if(l<=t[idx].l && t[idx].r<=r)
	{
//		cout<<t[idx].l<<" "<<t[idx].r<<endl; 
		t[idx].v+=(t[idx].r-t[idx].l+1)*v;
		t[idx].add+=v;
		return;
	}
	pushdown(idx);
	int mid=MID(t[idx].l,t[idx].r);
	if(l<=mid)
		update(ls,l,r,v);
	if(r>mid)
		update(rs,l,r,v);
	t[idx].v=t[ls].v+t[rs].v;
}

void query(int idx,int l,int r)
{
	if(l==t[idx].l && t[idx].r==r)
	{
		write(t[idx].v),putchar(' ');
		return;
	}
	pushdown(idx);
	int mid=MID(t[idx].l,t[idx].r);
	if(l<=mid)
		query(ls,l,r);
	if(r>mid)
		query(rs,l,r);
}

int main()
{
//	freopen("data.txt","r",stdin);
	while(read(n)&&read(m)&&read(k)&&(n+m+k))
	{
		g.clear();CLR(t,0);CLR(q,0);
		build(1,1,n);
		for(int i=1;i<=m;i++)
			read(q[i].l),read(q[i].r),read(q[i].v);
		for(int i=1,l,r;i<=k;i++)
		{
			read(l),read(r);
			g.update(l,1);
			g.update(r+1,-1);
		}
		for(int i=1;i<=m;i++)
		{
			update(1,q[i].l,q[i].r,q[i].v*g.getsum(i));

		}	
		for(int i=1;i<=n;i++)
			query(1,i,i);	
		putchar('\n');
	}
	return 0;
}