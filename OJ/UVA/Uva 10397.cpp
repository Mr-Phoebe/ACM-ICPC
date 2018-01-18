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

const int N = 760;;
const int M = 600000;

struct edge
{
    double dis;
    int l;
    int r;
}s[M];

int n, cnt, f[N], x[N], y[N];

int getfa(int c)
{
    return c == f[c] ? c : f[c] = getfa(f[c]);
}

double addedge(int i, int j)
{
    s[cnt].dis = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * ( y[i] - y[j]));
    s[cnt].l = i;
    s[cnt].r = j;
    cnt++;
}

bool cmp(const edge& a, const edge& b)
{
    return b.dis - a.dis > 1e-9;
}

double kruskal()
{
    sort(s, s + cnt, cmp);;
    double sum = 0;
    for(int i = 0; i < cnt; i++)
    {
        int p = getfa(s[i].l), q = getfa(s[i].r);
        if(p != q)
        {
            f[q] = p;
            sum += s[i].dis;
        }
    }
    return sum;
}

int main ()
{
    while(read(n))
    {
        cnt = 0;
        for(int i = 0; i < n; i++)
        {
            f[i] = i;
            read(x[i]), read(y[i]);
            for (int j = 0; j < i; j++)
                addedge(i, j);
        }

        int m, a, b;
        read(m);
        for(int i = 0; i < m; i++)
        {
            read(a), read(b);
            int p = getfa(a - 1), q = getfa(b - 1);
            if(p != q)
                f[q] = p;
        }
        printf("%.2lf\n", kruskal());
    }
    return 0;
}
