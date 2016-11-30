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

const int MAXN = 300010;

struct node
{
    int m,l,r;
}t[MAXN<<1];

int n,m;
ll a[MAXN];
ll dif[MAXN];

template <class T>
int sign(T x)
{
    if(x>0)
        return 1;
    if(x<0)
        return -1;
    return 0;
}

void getmax(int l, int r)
{
    int id = getidx(l, r);
    int mid = MID(l, r);
    t[id] = {max(t[ls].m, t[rs].m), t[ls].l, t[rs].r};
    if(!!dif[mid] && !!dif[mid+1] && sign(dif[mid]) >= sign(dif[mid+1]))
    {
        t[id].m = max(t[id].m, t[ls].r + t[rs].l);
        if(t[ls].m == mid - l + 1)
            t[id].l = t[ls].l + t[rs].l;
        if(t[rs].m == r - mid)
            t[id].r = t[ls].r + t[rs].r;
    }
}

void build(int l, int r)
{
    int id = getidx(l, r);
    if(l == r)
    {
        int tmp = !!dif[l];
        t[id] = {tmp, tmp, tmp};
        return;
    }
    int mid = MID(l, r);
    build(lson);
    build(rson);
    getmax(l, r);
}

void update(int l, int r, int pos, int d)
{
    int id = getidx(l, r);
    if(l == r)
    {
        dif[pos] += d;
        int tmp = !!a[pos];
        t[id] = {tmp, tmp, tmp};
        return;
    }
    int mid = MID(l, r);
    if(pos <= mid)
        update(lson, pos, d);
    else
        update(rson, pos, d);
    getmax(l, r);
}

int main()
{
    read(n);
    for(int i = 0; i < n; i++)
        read(a[i]);
    for(int i = 0; i < n-1; i++)
        dif[i] = a[i+1] - a[i];
    if(n > 1)
        build(0, n-2);
    read(m);
    while(m--)
    {
        int l, r, d;
        read(l), read(r), read(d);
        if(n == 1)
        {
            write(1), putchar('\n');
            continue;
        }
        if(l > 1)
            update(0, n-2, l-2, d);
        if(r < n)
            update(0, n-2, r-1, -d);
        write(t[getidx(0,n-2)].m + 1), putchar('\n');
    }
    return 0;
}
