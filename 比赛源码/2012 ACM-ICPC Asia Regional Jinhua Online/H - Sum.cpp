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
#define ls (idx<<1)
#define rs (idx<<1|1)
#define lson ls,l,mid
#define rson rs,mid+1,r

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

const int MAXN=400010;
int s[MAXN][10],num[MAXN], a[10];
ll ans;
map<int,int> ma;

int cal(int x,int p)
{
    if(__gcd(x,p)>1)    return 0;
    return x;
}

void init()
{
    for(int i=2; i<MAXN; i++)
        if(num[i]==0)
            for(int j=i; j<MAXN; j+=i)
                s[j][++num[j]]=i;
}

int main()
{

    int T,n,q;
    init();
    read(T);
    while(T--)
    {
        read(n),read(q);
        ma.clear();
        while(q--)
        {
            ll x, y;
            int op,p;
            read(op),read(x),read(y);
            if(op==1)
            {
                read(p);
                ans = (x+y)*(y-x+1)/2;
                for (int i = 1; i <= num[p]; i++)
                {
                    memset(a, 0, sizeof(a));
                    for (int j = num[p]; j >= num[p]-i+1; j--) a[j] = 1;
                    ll cnt = 0;
                    int tmp;
                    do
                    {
                        tmp = 1;
                        for (int k = 1; k <= num[p]; k++)
                        if (a[k] == 1) tmp = tmp*s[p][k];
                        cnt = y/tmp-(x-1)/tmp;
                        ll fir = tmp + ((x-1)/tmp)*tmp, las = tmp + (y/tmp-1)*tmp;
                        ll sum = (fir+las)*cnt/2;
                        if (i&1) ans -= sum;
                        else ans += sum;
                    } while (next_permutation(a+1, a+num[p]+1));
                }
                map<int,int>::iterator it,be=ma.lower_bound(x),en=ma.upper_bound(y);
                for(it=be; it!=en; it++)
                    ans+=cal(it->second,p)-cal(it->first,p);
                printf("%lld\n",ans);
            }
            else
                ma[x]=y;
        }
    }
    return 0;
}
