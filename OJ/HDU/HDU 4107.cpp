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

const int MAXN=200010;
#define ls id<<1
#define rs id<<1|1

int n,m,p;

struct Node
{
	int l,r;
	int clo,ret;
	int add,val;
}t[MAXN<<2];

void update(int id,int l,int r,int v);

void pushdown(int id)
{
		t[ls].add+=t[id].add;
		t[rs].add+=t[id].add;
		t[ls].val+=t[ls].clo*t[id].add;
		t[rs].val+=t[rs].clo*t[id].add;
		if(t[ls].ret!=INF)
            t[ls].ret-=t[id].add;
        if(t[rs].ret!=INF)
            t[rs].ret-=t[id].add;
        t[id].add=0;
}

void build(int id,int l,int r)
{
	t[id].l=l,t[id].r=r;
	t[id].add=t[id].val=0;
	t[id].clo=1;t[id].ret=p;
	if(l==r)
        return;
    int mid=MID(l,r);
    build(ls,l,mid);
    build(rs,mid+1,r);
}

void update(int id,int l,int r,int v)
{
    if(t[id].l==t[id].r)
    {
        int res=p-t[id].val;
        if(res<=v)
        {
            t[id].val+=v*t[id].clo;
            t[id].clo=2;
            t[id].ret=INF;
        }
        else
        {
            t[id].val+=v*t[id].clo;
            t[id].ret=p-t[id].val;
        }
        //cout<<t[id].l<<" "<<t[id].r<<" "<<t[id].val<<" "<<t[id].add<<endl;
        t[id].add=0;
        return;
    }
    if(l<=t[id].l && t[id].r<=r)
    {
        //cout<<v<<" "<<t[id].ret<<endl;
        if(t[id].ret<=v)
        {
            pushdown(id);
            update(ls,t[ls].l,t[ls].r,v);
            update(rs,t[rs].l,t[rs].r,v);
            t[id].ret=min(t[ls].ret,t[rs].ret);
        }
        else
        {
            t[id].add+=v;
            t[id].ret-=v;
        }
        //cout<<t[id].l<<" "<<t[id].r<<" "<<t[id].val<<" "<<t[id].add<<endl;
        return;
    }
    if(t[id].add)
        pushdown(id);
    int mid=MID(t[id].l,t[id].r);
    if(l<=mid)
        update(ls,l,r,v);
    if(r>mid)
        update(rs,l,r,v);
    t[id].ret=min(t[ls].ret,t[rs].ret);
}

void query(int id)
{
    if(t[id].l==t[id].r)
    {
        if(t[id].l!=n)
            write(t[id].val),putchar(' ');
        else
            write(t[id].val),putchar('\n');
        return;
    }
    if(t[id].add)
        pushdown(id);
    int mid=MID(t[id].l,t[id].r);
    query(ls);
    query(rs);
    t[id].ret=min(t[ls].ret,t[rs].ret);
}

int main()
{
    while(read(n)&&read(m)&&read(p))
    {
        build(1,1,n);
        int l,r;
        ll v;
        for(int i=0;i<m;i++)
        {
            read(l),read(r),read(v);
            update(1,l,r,v);
        }
        query(1);
    }
	return 0;
}
