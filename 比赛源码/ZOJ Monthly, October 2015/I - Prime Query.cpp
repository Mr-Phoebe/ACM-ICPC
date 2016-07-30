//      whn6325689
//      Mr.Phoebe
//      http://blog.csdn.net/u013007900
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
#define eps 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LLINF 1LL<<50
#define speed std::ios::sync_with_stdio(false);

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;

#define CLR(x,y) memset(x,y,sizeof(x))
#define CPY(x,y) memcpy(x,y,sizeof(x))
#define clr(a,x,size) memset(a,x,sizeof(a[0])*(size))
#define cpy(a,x,size) memcpy(a,x,sizeof(a[0])*(size))
#define debug(a) cout << #a" = " << (a) << endl;
#define debugarry(a, n) for (int i = 0; i < (n); i++) { cout << #a"[" << i << "] = " << (a)[i] << endl; }

#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define lowbit(x) (x&(-x))

#define MID(x,y) (x+((y-x)>>1))
#define getidx(l,r) (l+r | l!=r)
#define ls getidx(l,mid)
#define rs getidx(mid+1,r)
#define lson l,mid
#define rson mid+1,r

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
    int num,val;    //val==-1表示杂色
    int la;
    void init()
    {
        num=0,val=-1,la=0;
    }
}t[MAXN<<1];

int isprime[MAXN*10];   //0为素数
int a[MAXN];

void init()
{
    isprime[1]=1;isprime[0]=1;
    for(int i=2;i<MAXN*10;i++)
    {
        if(isprime[i]) continue;
        for(int j=(i<<1);j<MAXN*10;j+=i)
            isprime[j]=1;
    }
}

void pushup(int l,int r)
{
    int idx=getidx(l,r),mid=MID(l,r);
    t[idx].num=t[ls].num+t[rs].num;
    t[idx].val=(t[ls].val==t[rs].val? t[ls].val:-1);
}

void pushdown(int l,int r)
{
    int idx=getidx(l,r),mid=MID(l,r);
    if(!t[idx].la)  return;
    t[ls].la=t[rs].la=t[idx].la;
    t[ls].val=t[rs].val=t[idx].la;
    t[ls].num=(!isprime[t[idx].la])*(mid-l+1);
    t[rs].num=(!isprime[t[idx].la])*(r-mid);
    t[idx].la=0;
}

void build(int l,int r)
{
    int idx=getidx(l,r),mid=MID(l,r);
    t[idx].init();
    if(l==r)
    {
        t[idx].val=a[l];
        t[idx].num=!isprime[a[l]];
        return;
    }
    build(l,mid);build(mid+1,r);
    pushup(l,r);
}

void addupdate(int l,int r,int pos,int v)
{
    int idx=getidx(l,r),mid=MID(l,r);
    if(l==r)
    {
        t[idx].val+=v;
        t[idx].num=!isprime[t[idx].val];
        return;
    }
    pushdown(l,r);
    if(pos>mid)
        addupdate(mid+1,r,pos,v);
    else
        addupdate(l,mid,pos,v);
    pushup(l,r);
}

void reupdate(int l,int r,int L,int R,int v)
{
    int idx=getidx(l,r),mid=MID(l,r);
    if(L==l && r==R)
    {
        int len=(r-l+1);
        t[idx].val=t[idx].la=v;
        t[idx].num=len*(!isprime[v]);
        return;
    }
    pushdown(l,r);
    if(L>mid)
        reupdate(mid+1,r,L,R,v);
    else if(R<=mid)
        reupdate(l,mid,L,R,v);
    else
    {
        reupdate(l,mid,L,mid,v);
        reupdate(mid+1,r,mid+1,R,v);
    }
    pushup(l,r);
}

int query(int l,int r,int L,int R)
{
    int idx=getidx(l,r),mid=MID(l,r);
    if(L==l && r==R)
    {
        return t[idx].num;
    }
    pushdown(l,r);
    if(L>mid)
        return query(mid+1,r,L,R);
    else if(R<=mid)
        return query(l,mid,L,R);
    else
        return query(l,mid,L,mid)+query(mid+1,r,mid+1,R);
}

char op[5];

int main()
{
    init();
    int T,n,q,l,r,v;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&q);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        build(1,n);
        while(q--)
        {
            scanf("%s",op);
            if(op[0]=='A')
            {
                scanf("%d %d",&v,&l);
                addupdate(1,n,l,v);
            }
            else if(op[0]=='R')
            {
                scanf("%d %d %d",&v,&l,&r);
                reupdate(1,n,l,r,v);
            }
            else
            {
                scanf("%d %d",&l,&r);
                int num=query(1,n,l,r);
                printf("%d\n",num);
            }
        }
    }
    return 0;
}
