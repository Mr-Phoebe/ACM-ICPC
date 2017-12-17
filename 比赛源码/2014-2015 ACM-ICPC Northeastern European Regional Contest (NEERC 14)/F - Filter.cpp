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
#define LLINF 1LL<<62
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

#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define lowbit(x) (x&(-x))

#define MID(x,y) (x+((y-x)>>1))
#define ls (idx<<1)
#define rs (idx<<1|1)
#define lson ls,l,mid
#define rson rs,mid+1,r
#define root 1,1,n

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

const int MAXN=1010;

int n,f,q;
ll a[MAXN],m;
int ans[MAXN],cnt;
bool vis[MAXN];
bitset<2000> b[MAXN];
bitset<2000> sum;
char str[MAXN];

int val(char ch)
{
    if('0'<=ch && ch<='9')  return ch-'0';
    return ch-'a'+10;
}

int change(int x,int len)
{
    int bit[4];
    for(int i=0;i<len;i++)
        bit[i]=(x>>i)&1;
    x=0;
    for(int i=0;i<len;i++)
    {
        x<<=1;
        x+=bit[i];
    }
    return x;
}

int main()
{
    //freopen("data.txt","r",stdin);
    freopen("filter.in","r",stdin);
    freopen("filter.out","w",stdout);
    while(read(m)&&read(f))
    {
        cnt=0;CLR(vis,0);
        for(int i=1;i<=f;i++)
            read(a[i]);
        read(n);
        int x;
        for(int i=1;i<=n;i++)
        {
            gets(str);
            b[i].reset();
            if(m%4==0)
            {
                for(int j=0;j<m/4;j++)
                {
                    b[i]<<=4;
                    x=change(val(str[j]),4);
                    b[i]|=x;
                }
            }
            else
            {
                for(int j=0;j<m/4;j++)
                {
                    b[i]<<=4;
                    x=change(val(str[j]),4);
                    b[i]|=x;
                }
                b[i]<<=(m%4);
                x=change(val(str[m/4]),m%4);
                b[i]|=x;
            }
        }
        read(q);
        for(int i=1;i<=q;i++)
        {
            read(x);sum.reset();
            for(int j=1;j<=f;j++)
            {
                sum.set(m-1-(x*a[j])%m);
            }
            for(int j=1;j<=n;j++)
                if(!vis[j] && (b[j]|sum)==b[j])
                {
                    ans[cnt++]=j;
                    vis[j]=1;
                }
        }
        sort(ans,ans+cnt);
        write(cnt),putchar(' ');
        for(int i=0;i<cnt;i++)
            write(ans[i]-1),putchar(' ');
        putchar('\n');
    }
    return 0;
}