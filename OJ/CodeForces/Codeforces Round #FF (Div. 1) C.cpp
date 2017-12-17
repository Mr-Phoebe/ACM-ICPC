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

const int MOD=1000000009;
const int MAXN=300010;

struct Node
{
	int l,r;
	ll v,x,y;
}t[MAXN<<2];

int n,m,q,l,r;
ll f[MAXN];

inline ll fib(ll a,ll b,int n)
{
    if(n==0)
        return a;
    if(n==1)
        return b;
    return (a*f[n-1]%MOD+b*f[n]%MOD)%MOD;
}

void update(int id,int l,int r,ll a,ll b);
void build(int id,int l,int r)
{
    t[id].l=l,t[id].r=r;
    t[id].v=t[id].x=t[id].y=0;
    if(l==r)
    {
        read(t[id].v);
        return;
    }
    build(id<<1,l,MID(l,r));
    build(id<<1|1,MID(l,r)+1,r);
    t[id].v=(t[id<<1].v+t[id<<1|1].v)%MOD;
}

void pushdown(int id)
{
    if (t[id].x||t[id].y)
    {
        update(id<<1,t[id].l,t[id].r,t[id].x,t[id].y);
        update(id<<1|1,t[id].l,t[id].r,t[id].x,t[id].y);
        t[id].x=0;
        t[id].y=0;
    }
}

void update(int id,int l,int r,ll a,ll b)
{
//    cout<<id<<"->("<<t[id].l<<","<<t[id].r<<") -> "<<MID(t[id].l,t[id].r)<<"-> (" <<l<<","<<r<<")"<<endl;
    if(l<=t[id].l && t[id].r<=r)
    {
        ll na,nb;
        na=fib(a,b,t[id].l-l);
        nb=fib(a,b,t[id].l-l+1);
        a=na;
        b=nb;
        t[id].x=(t[id].x+a)%MOD;
        t[id].y=(t[id].y+b)%MOD;
        t[id].v=(t[id].v+fib(a,b,t[id].r-t[id].l+2)-b)%MOD;
        return;
    }
    pushdown(id);
    int mid=MID(t[id].l,t[id].r);
    if(l<=mid)
        update(id<<1,l,r,a,b);
    if(r>mid)
        update(id<<1|1,l,r,a,b);
    t[id].v=(t[id<<1].v+t[id<<1|1].v)%MOD;
}

ll query(int id,int l,int r)
{
//    cout<<id<<"->("<<t[id].l<<","<<t[id].r<<") -> "<<MID(t[id].l,t[id].r)<<"-> (" <<l<<","<<r<<")"<<endl;
    if(l<=t[id].l && t[id].r<=r)
    {
        return t[id].v;
    }
    pushdown(id);
    ll ret=0;
    int mid=MID(t[id].l,t[id].r);
    if(l<=mid)
        ret+=query(id<<1,l,r);
    if(r>mid)
        ret+=query(id<<1|1,l,r);
    return ret%MOD;
}

int main()
{
	read(n),read(m);
	f[1]=f[2]=1;
	for(int i=3;i<MAXN;i++)
        f[i]=(f[i-1]+f[i-2])%MOD;
	build(1,1,n);
    while(m--)
    {
        read(q),read(l),read(r);
        if(q==1)
        {
            update(1,l,r,1LL,1LL);
        }
        else
        {
            ll ans=(query(1,l,r)+MOD)%MOD;
            write(ans),putchar('\n');
        }
    }
    return 0;
}
