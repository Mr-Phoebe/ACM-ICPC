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

const int MOD=23333;
const int MAXN=10100;
int prime[MAXN];
bool vis[MAXN];

ll qpow(ll x,ll n)
{
    ll res=1;
    while(n)
    {
        if(n&1)
            res=(res*x)%MOD;
        x=(x*x)%MOD;
        n>>=1;
    }
    return res;
}

void getPrime()
{
    for(int i=2;i<=MAXN;i++)
        if(!vis[i])
            for(int j=i*i;j<=MAXN;j+=i)
                vis[j]=true;
    for(int i=2;i<=MAXN;i++)
        if(!vis[i])
            prime[++prime[0]]=i;
}

ll getPhi(int n)
{
    ll ret=n;
    for(int i=1;prime[i]*prime[i]<=n;i++)
    {
        if(n%prime[i])
            continue;
        ret-=ret/prime[i];
        n/=prime[i];
        while(n%prime[i]==0)
            n/=prime[i];
        if(n==1)
            break;
    }
    if(n!=1)
        ret-=ret/n;
    return ret;
}


int main()
{
    getPrime();
    int n,k,T;
    read(T);
    while(T--)
    {
        read(k),read(n);
        int i;
        ll ans=0;
        for(i=1;i<sqrt(n);i++)
        {
            if(n%i==0)
            {
                ans=(ans+getPhi(n/i)*qpow(k,i))%MOD;
                        //cout<<getPhi(n/i)<<" "<<qpow(k,i)<<endl;
                ans=(ans+getPhi(i)*qpow(k,n/i))%MOD;
                        //cout<<getPhi(i)<<" "<<qpow(k,n/i)<<endl;
            }
        }
        if(i*i==n)
            ans=(ans+getPhi(i)*qpow(k,i))%MOD;
        printf("%lld\n",ans);
    }
}
