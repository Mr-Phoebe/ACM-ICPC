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
const int MOD = 1000000007;
int n;
bool c[10005];
int tot, p[10005], fac[10], a[10];
ll ans;

ll calc(ll x, ll p)
{
    ll tmp = 1;
    while (p)
    {
        if (p&1) tmp = tmp*x%MOD;
        p >>= 1; x = x*x%MOD;
    }
    return tmp;
}

int main()
{
    int T;
    memset(c, 1, sizeof(c));
    c[1] = false; p[0] = 0;
    for (int i = 2; i <= 10000; i++)
    if (c[i])
    {
        p[0]++;
        p[p[0]] = i;
        int j = 2;
        while (i*j <= 10000)
        {
            c[i*j] = false;
            j++;
        }
    }
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        ans = 6*calc(ll(n), ll(5))%MOD;
        ans = (ans+15*calc(ll(n), ll(4)))%MOD;
        ans = (ans+10*calc(ll(n), ll(3)))%MOD;
        ans = (ans-n+MOD)%MOD;
        ans = ans*calc(ll(30), MOD-2)%MOD;
        int tmp = n; tot = 0;
        for (int i = 1; i <= p[0]; i++)
        {
            if (tmp == 1) break;
            if (tmp%p[i] == 0)
            {
                tot++;
                fac[tot] = p[i];
                while (tmp%p[i] == 0) tmp /= p[i];
            }
        }
        if (tmp != 1)
        {
            tot++;
            fac[tot] = tmp;
        }
        for (int i = 1; i <= tot; i++)
        {
            memset(a, 0, sizeof(a));
            for (int j = tot; j >= tot-i+1; j--) a[j] = 1;
            do
            {
                int tmp = 1;
                for (int j = 1; j <= tot; j++)
                if (a[j] == 1) tmp *= fac[j];
                int cnt = n/tmp;
                ll sum;
                sum = 6*calc(ll(cnt), ll(5))%MOD;
                sum = (sum+15*calc(ll(cnt), ll(4)))%MOD;
                sum = (sum+10*calc(ll(cnt), ll(3)))%MOD;
                sum = (sum-cnt+MOD)%MOD;
                sum = sum*calc(ll(30), MOD-2)%MOD;
                sum = sum*calc(ll(tmp), ll(4))%MOD;
                if (i&1) ans = (ans-sum+MOD)%MOD;
                else ans = (ans+sum)%MOD;
            } while(next_permutation(a+1, a+tot+1));
        }
        printf("%lld\n", ans);
    }
    return 0;
}