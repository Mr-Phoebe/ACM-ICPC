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
#define CLR(x,y) memset(x,y,sizeof(x))
#define mp(x,y) make_pair(x,y)
#define eps 1e-9
#define INF 0x3f3f3f3f
#define LLINF 1LL<<62

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

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

#define MID(x,y) (x+((y-x)>>1))

const int MAXN=100010;

struct Node
{
	int l,r;
	ll v,maxx;
}t[MAXN<<2];

void pushup(int id)
{
    t[id].v=t[id<<1].v+t[id<<1|1].v;
    t[id].maxx=max(t[id<<1].maxx,t[id<<1|1].maxx);
}

void build(int id,int l,int r)
{
	t[id].l=l,t[id].r=r;
	t[id].v=0;
	if(l==r)
	{
		read(t[id].v);
		t[id].maxx=t[id].v;
		return;
	}
	int mid=MID(l,r);
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	pushup(id);
}

ll query(int id,int l,int r)
{
    if(l<=t[id].l && t[id].r<=r)
    {
        return t[id].v;
    }
    int mid=MID(t[id].l,t[id].r);
    ll ret=0;
    if(l<=mid)
        ret+=query(id<<1,l,r);
    if(r>mid)
        ret+=query(id<<1|1,l,r);
    return ret;
}

void update(int id,int l,int r,int x,int k)
{
    if(k==2 && t[id].maxx<x)
        return;
    if(t[id].l==t[id].r)
    {
        if(k==2)
            t[id].v=t[id].maxx=t[id].v%x;
        else if(k==3)
            t[id].v=t[id].maxx=x;
        return;
    }
    int mid=MID(t[id].l,t[id].r);
    if(l<=mid)
        update(id<<1,l,r,x,k);
    if(r>mid)
        update(id<<1|1,l,r,x,k);
    pushup(id);
    return;
}


int main()
{
	int n,m,k,l,r,x;
	read(n),read(m);
	build(1,1,n);
	while(m--)
    {
        read(k);
        if(k==1)
        {
            read(l),read(r);
            ll ans=query(1,l,r);
            write(ans),putchar('\n');
        }
        else if(k==2)
        {
            read(l),read(r),read(x);
            update(1,l,r,x,k);
        }
        else if(k==3)
        {
            read(l),read(x);
            update(1,l,l,x,k);
        }
    }
    return 0;
}
