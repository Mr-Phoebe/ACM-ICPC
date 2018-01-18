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
#define eps 1e-9
#define INF 0x3f3f3f3f
#define ll long long

using namespace std;

template<class T>
inline bool read(T &n)
{
    T x = 0, tmp = 1;
    char c = getchar();
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

struct Node
{
    ll l,r;
    ll sum;
    ll x,d;      //x表示首项 ， d表示公差
}a[8*MAXN];

int n,m,num[MAXN];

void build(int idx, ll l, ll r)
{
    a[idx].l=l,a[idx].r=r;
    a[idx].sum=a[idx].x=a[idx].d=0;
    if(l==r)
    {
        a[idx].sum=num[l];
        return;
    }
    ll mid=l+((r-l)>>1);
    build(idx<<1,l,mid);
    build(idx<<1|1,mid+1,r);
    a[idx].sum=a[idx<<1].sum+a[idx<<1|1].sum;
}

void pushdown(int idx)
{
    ll l=a[idx].l,r=a[idx].r;
    ll lc=idx<<1,rc=idx<<1|1,mid=l+((r-l)>>1);
    a[lc].x+=a[idx].x;
    a[rc].x+=a[idx].x+(mid-l+1)*a[idx].d;
    a[lc].d+=a[idx].d;
    a[rc].d+=a[idx].d;
    a[idx].sum+=a[idx].x*(r-l+1);
    a[idx].sum+=(r-l+1)*(r-l)/2*a[idx].d;
    a[idx].x=a[idx].d=0;
}


//如果标记相同则下推
void update(int idx,ll L,ll R,int x,int d)
{
    ll l=a[idx].l,r=a[idx].r;
    ll lc=idx<<1,rc=idx<<1|1,mid=l+((r-l)>>1);
    if(l==L&&r==R)
    {
        a[idx].x+=x;
        a[idx].d+=d;
        return;
    }
    pushdown(idx);                //标记下放同时更新
    if(R<=mid)  update(lc,L,R,x,d);
    else if(L>mid)  update(rc,L,R,x,d);
    else
    {
        update(lc,L,mid,x,d);
        update(rc,mid+1,R,x+d*(mid-L+1),d);
    }
    a[idx].sum+=x*(R-L+1)+(R-L+1)*(R-L)/2*d;
}

ll query(int idx,int L,int R)
{
    ll l=a[idx].l,r=a[idx].r;
    ll mid=l+((r-l)>>1);
    ll ret=(a[idx].x*2+(L+R-l*2)*a[idx].d)*(R-L+1)/2;
    if(l==L&&r==R)
    {
        pushdown(idx);
        return a[idx].sum;
    }
    if(R<=mid)
        return ret+query(idx<<1,L,R);
    if(L>mid)
        return ret+query(idx<<1|1,L,R);
    return ret+query(idx<<1,L,mid)+query(idx<<1|1,mid+1,R);
}

int main()
{
	int T,t,l,r,x,d;
	read(T);
	while(T--)
    {
        read(n),read(m);
        for(int i=1;i<=n;i++)
            read(num[i]);
        build(1,1,n);
/*        for(int i=1;i<=2*n+1;i++)
            printf("%d : (%d->%d)  %d\n",i,a[i].l,a[i].r,a[i].sum);*/
        while(m--)
        {
            read(t),read(l),read(r);
            if(t==1)
            {
                read(x),read(d);
                update(1,l,r,x,d);
 /*               for(int i=1;i<=2*n+1;i++)
                    printf("%d : (%d->%d)  %d\n",i,a[i].l,a[i].r,a[i].sum);*/
            }
            else
            {
                ll ans=query(1,l,r);
                write(ans);
                putchar('\n');
            }
        }
    }
    return 0;
}
