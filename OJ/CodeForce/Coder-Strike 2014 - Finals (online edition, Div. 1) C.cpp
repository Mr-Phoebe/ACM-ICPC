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
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;

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

#define lowbit(x) ((i)&(-i))

const int MAXN = 300010;
int n, p;
int num[MAXN], c[MAXN];
vi e[MAXN];

ll getsum(int i)
{
    ll res = 0;
    for(i++; i; i -= lowbit(i))
        res += c[i];
    return res;
}

void update(int i, int x)
{
    for(i++; i < MAXN; i += lowbit(i))
        c[i] += x;
}

int main()
{
    read(n),read(p);
    for(int i=0; i<n; i++)
    {
        int a, b;
        read(a), read(b);
        e[a].pb(b);
        e[b].pb(a);
    }
    int cnt=0;
    ll ans=0;

    for(int i=1; i<=n; i++)
    {
        num[i]=e[i].size();
        update(num[i], 1);
    }

    for(int i = 1; i <= n; i++)
    {

        for(int j=0; j<e[i].size(); j++)
        {
            update(num[e[i][j]], -1);
            update(--num[e[i][j]], 1);
        }
        if(num[i] >= p)
            ans+=n-1;
        else
            ans+=n-1-getsum(p-num[i]-1)+(num[i] <= p-num[i]-1);

        for(int j=0; j<e[i].size(); j++)
        {
            update(num[e[i][j]], -1);
            update(++num[e[i][j]], 1);
        }
    }
    write(ans/2),putchar('\n');
    return 0;
}
