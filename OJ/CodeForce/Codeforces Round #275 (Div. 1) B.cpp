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

const int MAXN=100007;
#define MID(x,y) (x+((y-x)>>1))

struct Node
{
    int l,r;
    int sum,mark;
} t[MAXN*4],q[MAXN];


void pushup(int rt)
{
    t[rt].sum=t[rt<<1].sum&t[rt<<1|1].sum;
}

void pushdown(int rt)
{
    if(t[rt].mark)
    {
        t[rt<<1].mark |= t[rt].mark;
        t[rt<<1|1].mark |= t[rt].mark;
        t[rt<<1].sum |= t[rt].mark;
        t[rt<<1|1].sum |= t[rt].mark;
        t[rt].mark = 0;
    }
}

void build(int l,int r,int rt)
{
    t[rt].mark = t[rt].sum = 0;
    t[rt].l = l,t[rt].r = r;
    if(l == r)
        return;
    int mid = (l+r)/2;
    build(l,mid,rt<<1);
    build(mid+1,r,rt<<1|1);
}

void update(int aa,int bb,int val,int rt)
{
    int l = t[rt].l, r = t[rt].r;
    if(aa <= l && bb >= r)
    {
        t[rt].sum |= val;
        t[rt].mark |= val;
        return;
    }
    pushdown(rt);
    int mid = MID(l,r);
    if(aa <= mid) update(aa,bb,val,rt<<1);
    if(bb > mid)  update(aa,bb,val,rt<<1|1);
    pushup(rt);
}

int query(int aa,int bb,int rt)
{
    int l = t[rt].l, r = t[rt].r;
    if(aa <= l && r <=bb)
        return t[rt].sum;
    pushdown(rt);
    int mid = MID(l,r);
    if(bb <= mid)     return query(aa,bb,rt<<1);
    else if(aa > mid) return query(aa,bb,rt<<1|1);
    else              return (query(aa,bb,rt<<1)&query(aa,bb,rt<<1|1));
}

void print(int rt)
{
    if(t[rt].l == t[rt].r)
    {
        printf("%d ",t[rt].sum);
        return;
    }
    pushdown(rt);
    print(rt<<1);
    print(rt<<1|1);
}

int main()
{
    int n,m,i;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        build(1,n,1);
        for(i=1; i<=m; i++)
        {
            scanf("%d%d%d",&q[i].l,&q[i].r,&q[i].sum);
            update(q[i].l,q[i].r,q[i].sum,1);
        }
        for(i=1; i<=m; i++)
            if(query(q[i].l,q[i].r,1) != q[i].sum)
                break;
        if(i == m+1)
            puts("YES"),print(1),puts("");
        else
            puts("NO");
    }
    return 0;
}
