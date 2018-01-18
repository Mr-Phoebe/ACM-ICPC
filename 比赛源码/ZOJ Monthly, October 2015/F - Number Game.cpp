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
int n, m, k;
int a[100005], b[100005];
ll ans;
struct node
{
    int val, pos;
    node(int v = 0, int p = 0)
    {
        val = v; pos = p;
    }
    bool operator < (const node& b) const
    {
        return val<b.val;
    }
};
priority_queue<node> q;
bool v[100005];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d %d", &n, &m, &k);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        sort(a+1, a+n+1);
        int p = 1;
        while (p <= n && a[p] <= k-1) p++; p--;
        int st = 1;
        memset(v, 0, sizeof(v)); b[0] = 0;
        while (!q.empty()) q.pop();
        for (int i = p; i >= 1; i--)
        if (!v[i])
        {

            v[i] = true;
            while (st <= i && a[st]+a[i] <= k)
            {
                if (!v[st]) q.push(node(a[st], st));
                st++;
            }
            while (!q.empty() && v[q.top().pos]) q.pop();
            if (q.empty()) continue;
            node tmp = q.top();
            b[0]++; b[b[0]] = a[i]*tmp.val;
            v[tmp.pos] = true;
            q.pop();
        }
        sort(b+1, b+b[0]+1);
        int cnt = 0; ans = 0;
        for (int i = b[0]; i >= 1; i--)
        {
            if (cnt >= m) break;
            ans += b[i];
            cnt++;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
