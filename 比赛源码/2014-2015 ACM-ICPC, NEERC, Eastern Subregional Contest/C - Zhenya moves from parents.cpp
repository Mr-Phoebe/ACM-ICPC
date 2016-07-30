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

ll Time[MAXN];
ll money[MAXN];
ll T[MAXN];

ll change(int mon,int day,int hou,int mi)
{
    return 1LL*((mon*31+day)*24+hou)*60+mi;
}

ll la[MAXN<<1],mi[MAXN<<1];

void pushdown(int l,int r)
{
    int idx=getidx(l,r),mid=MID(l,r);
    if(!la[idx])    return;
    la[ls]+=la[idx];
    la[rs]+=la[idx];
    mi[ls]+=la[idx];
    mi[rs]+=la[idx];
    la[idx]=0;
}

void pushup(int l,int r)
{
    int idx=getidx(l,r),mid=MID(l,r);
    mi[idx]=min(mi[ls],mi[rs]);
}

void update(int l,int r,int L,int R,ll v)
{
    int idx=getidx(l,r),mid=MID(l,r);
    if(L==l && r==R)
    {
        mi[idx]+=v;
        la[idx]+=v;
        return;
    }
    pushdown(l,r);
    if(L>mid)   update(mid+1,r,L,R,v);
    else if(R<=mid) update(l,mid,L,R,v);
    else
    {
        update(l,mid,L,mid,v),update(mid+1,r,mid+1,R,v);
    }
    pushup(l,r);
}

int main()
{
//freopen("data.txt","r",stdin);
    int n;
    ll mo;
    char op;
    scanf("%d\n",&n);
    for(int i=1,day,mouth,hh,mm; i<=n; i++)
    {
        scanf("%c%lld %d.%d %d:%d",&op,&mo,&day,&mouth,&hh,&mm);
        money[i]=mo;
        if(op=='-') money[i]*=-1;
        Time[i]=change(mouth,day,hh,mm);
        T[i]=Time[i];
    }
    sort(T+1,T+n+1);
    int cnt=unique(T+1,T+n+1)-T;
    for(int i=1;i<=n;i++)
    {
        int pos=lower_bound(T+1,T+n+1,Time[i])-T;
        update(1,n,pos,n,money[i]);
        printf("%lld\n",mi[getidx(1,n)]>=0?0:mi[getidx(1,n)]);
    }

}
