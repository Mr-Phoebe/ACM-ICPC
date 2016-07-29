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
    T x = 0, tmp = 1; char c = getchar();
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

ll gcd(ll a,ll b)
{
    return b ? gcd(b,a%b):a;
}

int main()
{
    ll s,s1,s2,v1,v2,n,m,tmp,res,t,maxn;
    int T,i,cas=1;
    read(T);
    while(T--)
    {
        read(s),read(s1),read(v1),read(s2),read(v2);
        tmp=s1/gcd(s1,s2)*s2;
        n=s/tmp,m=s%tmp;
        if(n)
        {
            n--;
            m+=tmp;
        }
        res=max(n*(tmp/s1)*v1,n*(tmp/s2)*v2);
        if(s1<s2)
        {
            swap(s1,s2);swap(v1,v2);
        }
        maxn=0;
        for(i=0; i<=m/s1; i++)
        {
            t=i*v1+(m-i*s1)/s2*v2;
            if(maxn<t)
                maxn=t;
        }
        printf("Case #%d: %lld\n",cas++,maxn+res);
    }
    return 0;
}
