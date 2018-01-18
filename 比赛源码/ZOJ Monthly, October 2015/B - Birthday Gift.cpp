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
#define debug(a) cout << #a" = " << (a) << endl;
#define debugarry(a, n) for (int i = 0; i < (n); i++) { cout << #a"[" << i << "] = " << (a)[i] << endl; }

#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define lowbit(x) (x&(-x))

#define MID(x,y) (x+((y-x)>>1))
#define getidx(l,r) (l+r|l!=r)
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

const int maxn=50005;
const int MOD=786433;

ll n1, n2, m, q;
bool p[maxn];
ll A[maxn], B[maxn], C[maxn], f[maxn], g[maxn], ans[maxn], fac[maxn], inv[maxn];

ll qpow(ll a,ll b,ll p)
{
    ll base=a,res=1;
    while(b)
    {
        if(b&1) res=res*base%p;
        base=base*base%p;
        b>>=1;
    }
    return res;
}

namespace NTT
{
const int r=11,gl=20;
ll p,rp[50],irp[50];
void setMOD(ll _p=786433)
{
    p=_p;
    for(int i=0; i<gl; i++) rp[i]=qpow(r,(p-1)/(1<<i),p);
}
void FFT(ll a[],int n,ll wt[]=rp)
{
    for(int i=0,j=0; i<n; i++)
    {
        if(j>i) swap(a[i],a[j]);
        int k=n;
        while(j&(k>>=1)) j&=~k;
        j|=k;
    }
    for(int m=1,b=1; m<n; m<<=1,b++)
        for(int k=0,w=1; k<m; k++)
        {
            for(int i=k; i<n; i+=m<<1)
            {
                int v=a[i+m]*w%p;
                if((a[i+m]=a[i]-v)<0) a[i+m]+=p;
                if((a[i]+=v)>=p) a[i]-=p;
            }
            w=w*wt[b]%p;
        }
}
void IFFT(ll a[], int n)
{
    for(int i=0; i<gl; i++) irp[i]=qpow(rp[i],n-1,p);
    FFT(a,n,irp);
    ll inv=qpow(n,p-2,p);
    for(int i=0; i<n; i++) a[i]=a[i]*inv%p;
}
void Mul(ll a[],ll b[],ll n,ll c[])
{
    int len = 1;
    while (len < n) len <<= 1;
    len <<= 1;
    FFT(a,len);
    FFT(b,len);
    for(int i=0; i<len; i++) c[i]=a[i]*b[i]%p;
    IFFT(c,len);
}
}

int main()
{
    int T;
    memset(p, 1, sizeof(p));
    p[0] = p[1] = false;
    for (int i = 2; i <= maxn; i++)
    if (p[i])
    {
        int j = 2;
        while (i * j <= maxn)
        {
            p[i*j] = false;
            j++;
        }
    }
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= maxn; i++)
    {
        fac[i] = fac[i-1]*i%MOD;
        inv[i] = inv[i-1]*qpow(i, MOD-2, MOD)%MOD;
    }
    read(T);
    while(T--)
    {
        scanf("%lld%lld%lld%lld", &n1, &n2, &m, &q);
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));
        A[0]=1;
        for(int i=1; i<=n1; i++)  A[i]=A[i-1]*i%MOD;
        for(int i=0; i<=n1; i++)  A[i]=B[i]=qpow(A[i],MOD-2,MOD);
        for(int i=1; i<=n1; i+=2) A[i]=A[i]*(MOD-1)%MOD;
        for(int i=0; i<=n1; i++)  B[i]=B[i]*qpow(i,n1,MOD)%MOD;
        NTT::setMOD();
        NTT::Mul(A,B,n1+1,C);
        memset(f, 0, sizeof(f));
        memset(g, 0, sizeof(g));
        for (int i = 1; i <= n1 && i <= m; i++)
        {
            if (p[i]) f[i] = C[i];
            else if (i == n1) f[i] = 1;
            else f[i] = fac[n1]*inv[i-1]%MOD*inv[n1-i+1]%MOD;
        }
        for (int i = 1; i <= n2 && i <= m; i++)
            g[i] = (fac[m]*inv[i]%MOD*inv[m-i]%MOD)*(fac[n2-1]*inv[i-1]%MOD*inv[n2-i]%MOD)%MOD;
        NTT::Mul(f,g,m+1,ans);
        for (int i = 1; i <= q; i++)
        {
            int x;
            scanf("%d", &x);
            printf("%lld\n", ans[x]);
        }
    }
    return 0;
}
