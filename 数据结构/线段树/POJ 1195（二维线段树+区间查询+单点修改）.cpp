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

const int MAXN=1010;

#define ls id<<1
#define rs id<<1|1

int sum[MAXN<<2][MAXN<<2];
int n;

void subuild(int id,int l,int r,int t)
{
    sum[t][id]=0;
    if(l==r)
        return;
    int mid=MID(l,r);
    subuild(ls,l,mid,t);
    subuild(rs,mid+1,r,t);
}

void build(int id,int l,int r)
{
    subuild(1,1,n,id);
    if(l==r)
        return;
    int mid=MID(l,r);
    build(ls,l,mid);
    build(rs,mid+1,r);
}

void suupdate(int id,int l,int r,int y,int val,int t)
{
    if(l==r)
    {
         sum[t][id]+=val;
         return;
    }
    int mid=MID(l,r);
    if(y<=mid)
        suupdate(ls,l,mid,y,val,t);
    else
        suupdate(rs,mid+1,r,y,val,t);
    sum[t][id]=sum[t][ls]+sum[t][rs];
}

void update(int id,int l,int r,int x,int y,int val)
{
    suupdate(1,1,n,y,val,id);
    if(l==r)
        return;
    int mid=MID(l,r);
    if(x<=mid)
        update(ls,l,mid,x,y,val);
    else
        update(rs,mid+1,r,x,y,val);
}

ll suquery(int id,int l,int r,int YL,int YR,int t)
{
    if(YL<=l && r<=YR)
        return sum[t][id];

    int mid=MID(l,r);
    ll ans=0;
    if(YL<=mid)
        ans+=suquery(ls,l,mid,YL,YR,t);
    if(YR>mid)
        ans+=suquery(rs,mid+1,r,YL,YR,t);
    return ans;
}

ll query(int id,int l,int r,int XL,int XR,int YL,int YR)
{
    if(XL<=l && r<=XR)
        return suquery(1,1,n,YL,YR,id);

    int mid=MID(l,r);
    ll ans=0;
    if(XL<=mid)
        ans+=query(ls,l,mid,XL,XR,YL,YR);
    if(XR>mid)
        ans+=query(rs,mid+1,r,XL,XR,YL,YR);
    return ans;
}

int main()
{
    int op,a,b,c,d;
    while(read(op)&&read(n))
    {
        n++;
        build(1,1,n);
        while(read(op))
        {
            if(op==3)
                break;
            if(op==1)
            {
                read(a),read(b),read(c);
                a++,b++;
                update(1,1,n,a,b,c);
            }
            else
            {
                read(a),read(b),read(c),read(d);
                a++,b++,c++,d++;
                write(query(1,1,n,a,c,b,d)),putchar('\n');
            }
        }
    }
    return 0;
}

