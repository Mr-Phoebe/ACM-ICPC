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

#define ls id<<1
#define rs id<<1|1

const int MAXN=200010;

int n,len[MAXN],pos[MAXN],m;
vector<pii> qu[MAXN];
int ans[MAXN];
deque<int> deq;

struct Node
{
	int l,r;
	int num;
}t[MAXN<<2];

void build(int id,int l,int r)
{
	t[id].l=l,t[id].r=r;
	t[id].num=0;
	if(l==r)
		return;
	int mid=MID(l,r);
	build(ls,l,mid);
	build(rs,mid+1,r);
}

void update(int id,int l,int r,int v)
{
	if(l>r)
		return;
	if(t[id].l==l && t[id].r==r)
	{
		t[id].num+=v;
		return;
	}
	int mid=MID(t[id].l,t[id].r);
	if(r<=mid)
		update(ls,l,r,v);
	else if(l>mid)
		update(rs,l,r,v);
	else
	{
		update(ls,l,mid,v);
		update(rs,mid+1,r,v);
	}
}

void pushdown(int id)
{
	t[ls].num+=t[id].num;
	t[rs].num+=t[id].num;
	t[id].num=0;
}

int query(int id,int x)
{
	if(t[id].r==t[id].l)
		return t[id].num;
	pushdown(id);
	int mid=MID(t[id].l,t[id].r);
	if(x<=mid)
		return query(ls,x);
	else
		return query(rs,x);
}

int main()
{
	read(n);
	for(int i=1;i<=n;i++)
		read(pos[i]),read(len[i]);
	read(m);
	for(int i=1,u,v;i<=m;i++)
	{
		read(u),read(v);
		qu[v].pb(mp(u,i));
	}
	build(1,1,n);
	for(int k=2;k<=n;k++)
	{
		while(!deq.empty())
		{
			int id=deq.back();
			if(len[id]+pos[id] <= len[k-1]+pos[k-1])
				deq.pop_back();
			else
				break;
		}
		bool flag=0;
		deq.push_back(k-1);
		while(!deq.empty())
		{
			int id=deq.back();
			if(len[id]+pos[id] >= pos[k])
				break;
			deq.pop_back();
			int last=0,temp=pos[k]-len[id]-pos[id];
			if(!deq.empty())
				last=deq.back();
			update(1,last+1,id,temp);
			len[id]+=temp;
			flag=1;
		}
		if(flag)
			deq.push_back(k-1);
		for(int i=0;i<qu[k].size();i++)
		{
			int last=qu[k][i].first;
			int temp=qu[k][i].second;
			ans[temp]=query(1,last);
		}
	}
	for(int i=1;i<=m;i++)
		write(ans[i]),putchar('\n');
	return 0;
}
