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


std::set<ll> base;

bool check(ll n,ll i)
{
    ll v;
    while(n)
    {
        v=n%i;
        if(v!=3 && v!=4 && v!=5 && v!=6)
            return false;
        n/=i;
    }
    return true;
}

int main()
{
    ll n;
    int T;
    read(T);
    for(int t=1; t<=T; t++)
    {
        printf("Case #%d: ",t);
        read(n);
        if(3<=n && n<=6)
        {
            puts("-1");
            continue;
        }
        base.clear();
        int ans=0;
        for(int i=3; i<=6; i++)
            for(int j=3; j<=6; j++)
                if((n-j)%i==0)
                {
                    base.insert((n-j)/i);
                    if(check(n,(n-j)/i))
                        ans++;

                }
        for(ll a=3; a<=6; a++)
            for(ll b=3; b<=6; b++)
                for(ll c=3; c<=6; c++)
                {
                    ll temp=b*b-4*a*(c-n);
                    if(temp<0)
                        continue;
                    ll de=sqrt(temp);
                    temp=(-b + de)/(2*a);
                    if(temp<6)
                        temp=6;
                    for(ll i=temp-2;i<=temp+2;i++)
                    {
                        if(base.count(i))
                            continue;
                        base.insert(i);
                        if(check(n,i))
                            ans++;
                    }
                }
        for(int i=4; i<n && i<=7000; i++)
        {
            if(base.count(i))
                continue;
            if(check(n,i))
                ans++;
        }
        write(ans),putchar('\n');
    }
    return 0;
}
