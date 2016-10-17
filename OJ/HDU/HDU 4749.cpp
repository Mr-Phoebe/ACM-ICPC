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


int n, m, p;
int a[100010], b[100010];
int bit[30];
int low[100010], eq[100010];
int next[100010];

int get(int i) {
    int res = 0;
    for (; i; i -= i & -i) res += bit[i];
    return res;
}

void add(int i, int x) {
    for (; i <= p; i += i & -i) bit[i] += x;
}

void init() {
    fill(bit, bit + p + 1, 0);
    low[0] = eq[0] = 0;
    for (int i = 1; i <= m; i++) {
        low[i] = get(b[i] - 1);
        eq[i] = get(b[i]) - low[i];
        add(b[i], 1);
    }
}

int last;

bool ok(int *a, int lim, int x, int j) {
    while (last < lim) add(a[last++], -1);
    int l = get(x - 1), e = get(x) - l;
    return l == low[j] && e == eq[j];
}

int kmp() {
	memset(bit, 0, sizeof bit);
    int j = 0;
	int ret = 0;
    next[1] = 0;
    last = 1;
    add(b[1], 1);
    for (int i = 2; i <= m; i++) {
        while (j && !ok(b, i - j, b[i], j + 1)) {
            j = next[j];
        }
        if (j == 0 || ok(b, i - j, b[i], j + 1)) j++;
        next[i] = j;
        add(b[i], 1);
    }
	memset(bit, 0, sizeof bit);
    j = 0;
    last = 1;
    for (int i = 1; i <= n; i++) {
        while (j && !ok(a, i - j, a[i], j + 1))
            j = next[j];
        if (j == 0 || ok(a, i - j, a[i], j + 1))
            j++;
        if (j == m) {
			++ret;
            j = 0;
        }
        add(a[i], 1);
    }
	return ret;
}

void MAIN() {
	for (int i = 1; i <= n; i++)
         scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++)
		scanf("%d", &b[i]);
    init();
    printf("%d\n", kmp());
}

int main() {
    while (scanf("%d%d%d", &n, &m, &p) > 0)
        MAIN();
	return 0;
}

