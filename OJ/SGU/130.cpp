#include <bits/stdc++.h>

#define up(i, lower, upper) for(int i = lower; i < upper; i++)
#define down(i, lower, upper) for(int i = upper-1; i >= lower; i--)

using namespace std;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef long long ll;
typedef unsigned long long ull;

const double pi = acos(-1);
const double eps = 1.0e-9;

inline void read(int &n)
{
    int x = 0, tmp = 1;
    char c = getchar();
    while((c < '0' || c > '9') && c != '-') c = getchar();
    if(c == '-') c = getchar(), tmp = -1;
    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c = getchar();
    n = x*tmp;
}

inline void read(ll &n)
{
    ll x = 0,tmp = 1;
    char c = getchar();
    while((c < '0' || c > '9') && c != '-') c = getchar();
    if(c == '-') c = getchar(), tmp = -1;
    while(c >= '0' && c <= '9') x *= 10,x += (c-'0'), c = getchar();
    n = x*tmp;
}

inline void write(int n)
{
    if(n<0)
    {
        putchar('-');
        n = -n;
    }
    int len = 0,data[10];
    while(n)
    {
        data[len++] = n%10;
        n /= 10;
    }
    if(!len) data[len++] = 0;
    while(len--) putchar(data[len]+48);
}

inline void write(ll n)
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

//---------------------------------------------------------
int main()
{
    int n;
    read(n);
    ll dp[31] = { 1 };
    up(i, 1, 31) up(j, 0, i) dp[i] += dp[j]*dp[i-1-j];
    printf("%I64d %d\n", dp[n], n+1);
    return 0;
}
