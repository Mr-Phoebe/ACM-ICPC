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
#define eps 1e-9
#define INF 0x3f3f3f3f
#define lowbit(x) x&(-x)

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

const int MAXN=1000010;

int cnt[MAXN],a[MAXN],b[MAXN],f[MAXN],n;
int c[MAXN];

ll getsum(int i)
{
    ll sum=0;
    for(;i>0;i-=lowbit(i))
        sum+=c[i];
    return sum;
}

void update(int i)
{
    for(;i<=n;i+=lowbit(i))
        c[i]++;
}

int main()
{
    read(n);
    for(int i=0;i<n;i++)
    {
        read(a[i]);
        b[i]=a[i];
    }
    sort(b,b+n);
    for(int i=0;i<n;i++)
        cnt[a[i]=lower_bound(b,b+n,a[i])-b+1]++;
    cnt[a[0]]--;                // 维护a[0]的后f数
    ll ret=0,tot=0,po;
    for(int i=0;i<n-1;i++)
    {
        po=++f[a[i]];           // 得到f(1,i,a[i])
        update(po);             // 记录f的数量
        tot++;
        ret+=tot-getsum(cnt[a[i+1]]);   //总的个数 - 小于a[i+1]后f数 = 大于a[i+1]的后f数
        cnt[a[i+1]]--;                  //a[i+1]的后f数维护
    }
    write(ret);putchar('\n');
    return 0;
}
