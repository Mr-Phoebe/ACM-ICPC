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

const int MAXN = 100010;

vi t1, t2;

int main()
{
    int x1, x2, p1, p2;
    int n1, n2, a, n;
    bool flag = true;
    scanf("%d %d", &x1, &x2);
    p1 = x1, p2 = x2;
    t1.pb(0);
    t2.pb(0);
    read(n1);
    for(int i = 1; i <= n1; i++)
    {
        read(a);
        t1.pb(a);
    }
    n = a;
    read(n2);
    for(int i = 1; i <= n2; i++)
    {
         read(a);
         t2.pb(a);
    }
    n = max(n, a);
    if(x1 > x2)
    {
        swap(p1, p2);
        swap(n1, n2);
        t1.swap(t2);
    }
    int ans = -1;
    for(int l = 0, r = 0, t = 0; t <= n && flag; t++)
    {
        //cout<<t<<" : "<<p1<<" "<<p2<<endl;
        if(l < n1)
        {
            if(t1[l+1] <= t)
            {
                l++;
            }
        }
        if(r < n2)
        {
             if(t2[r+1] <= t)
             {
                 r++;
             }
        }
        if(l&1)
            p1++;
        if(r&1)
            p2++;
        if(p2 - p1 < 5)
        {
             flag = false;
             ans = t;
        }
    }
    if(!flag)
    {
         printf("bumper tap at time %d\n", ans+1);
    }
    else
    {
        //cout<<p1<<" "<<p2<<endl;
        if(n1&1 && !(n2&1))
        {
             ans = n + p2 - p1 - 4;
             printf("bumper tap at time %d\n", ans+1);
        }
        else
        {
             puts("safe and sound");
        }
    }

    return 0;
}
