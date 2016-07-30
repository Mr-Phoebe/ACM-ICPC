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

const int MAXN=100010;

struct BIT
{
    int c[MAXN];
    BIT()
    {
        CLR(c,0);
    }
    void update(int i,int v)
    {
        for(; i<MAXN; i+=lowbit(i))
            c[i]+=v;
    }
    int getsum(int i)
    {
        int sum=0;
        for(; i; i-=lowbit(i))
            sum+=c[i];
        return sum;
    }
    int dif(int i,int j)
    {
        return getsum(j)-getsum(i-1);
    }
} t[25];

int n,m,x,y;
int a[MAXN][25];
ll s[25],f[MAXN];


int find(int y,int x)
{
    if(y<1 || y>n)
        return 0;
    if(!t[x].dif(y,y))
        return 0;
    int l=1,r=y;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(t[x].dif(mid,y)==y-mid+1)
            r=mid;
        else l=mid+1;
    }
    int ll=l;
    l=y;
    r=n;
    while(l<r)
    {
        int mid=(l+r+1)/2;
        if(t[x].dif(y,mid)==mid-y+1)
            l=mid;
        else
            r=mid-1;
    }
    return r-ll+1;
}

int main()
{
    read(n),read(m);
    for(ll i=1; i<=n; i++)
        f[i]=i*(i+1)/2;
    for(int i=1; i<=n; i++)
    {
        read(x);
        for(int j=0; j<25; j++)
        {
            a[i][j]=x&1;
            if(a[i][j])
                t[j].update(i,1);
            x>>=1;
        }
    }
    for(int j=0; j<25; j++)
    {
        x=0;
        for(int i=1; i<=n+1; i++)
            if(a[i][j])
                x++;
            else
            {
                s[j]+=f[x];				//    ³õÊ¼»¯sÖµ
                x=0;
            }
    }
    while(m--)
    {
        read(x),read(y);
        for(int j=0; j<25; j++)
        {
            if(a[x][j]!=(y&1))
            {
                a[x][j]=y&1;
                if(a[x][j])
                {
                    s[j]-=f[find(x-1,j)]+f[find(x+1,j)];
                    t[j].update(x,1);
                    s[j]+=f[find(x,j)];
                }
                else
                {
                    s[j]-=f[find(x,j)];
                    t[j].update(x,-1);
                    s[j]+=f[find(x-1,j)]+f[find(x+1,j)];
                }
            }
            y>>=1;
        }
        ll ans=0;
        for(ll j=0; j<25; j++)
            ans+=(1LL<<j)*s[j];
        write(ans),putchar('\n');
    }
    return 0;
}
