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

int a[100010],n;
ll s[100010];

int find(ll c)
{
    int l=1,mid,h=n;
    while(l <= h)
    {
        mid = (l+h)/2;
        if(c == s[mid])
            return mid;
        else if(c > s[mid])
        {
            if(c < s[mid+1])
                return mid+1;
            l = mid+1;
        }
        else if(c < s[mid])
        {
            if(c > s[mid-1])
                return mid;
            h = mid-1;
        }
    }
    return -1;
}

int main()
{

    int i=0,j;
    int t,m,count=0;
    read(n);
    s[0] = 0;
    for(i=1; i<=n; i++)
    {
        read(a[i]);
        s[i] = a[i] + s[i-1];
    }
    read(m);
    ll c;
    for(i=0; i<m; i++)
    {
        read(c);
        int mid=find(c);
        printf("%d\n",mid);
    }
    return 0;
}
