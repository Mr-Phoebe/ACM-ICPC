//      whn6325689
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
#define INF 0x3f3f3f3f
#define LLINF 1LL<<62

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



const int MAXN=100100;
int a[MAXN];
vi duan;

int main()
{
    int n, s, l;
    read(n), read(s), read(l);
    for(int i = 1; i <= n; i ++)
        read(a[i]);
    int maxx = 1, minn = 1;
    for(int i = 1; i <= n; i ++)
    {
        if(a[maxx] < a[i])
            maxx = i;
        else if(a[maxx] == a[i] && maxx <= minn)
            maxx = i;
        if(a[minn] > a[i])
            minn = i;
        else if(a[minn] == a[i] && minn <= maxx)
            minn = i;
        if(abs(a[maxx] - a[minn]) > s)
        {
            duan.push_back(min(maxx, minn));        //维护极差区间
            duan.push_back(max(maxx, minn));
            maxx = minn = max(maxx, minn);
        }
    }
    int ans = duan.size() / 2 + 1;
    int pre = 0;
    for(int i = 0; i < duan.size(); i += 2)
    {
        int L = duan[i], R = duan[i + 1];
        if(R - pre - 1 < l)
            ans = -1;
        pre = max(L, pre + l);
    }
    if(n < l || (n - pre) < l)
        ans = -1;
    printf("%d\n", ans);
    return 0;
}
