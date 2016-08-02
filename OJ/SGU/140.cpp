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

const double pi = acos(-1.0);
const double eps = 1.0e-9;

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

///---------------------------------------------------------

int exgcd(int a, int b, int &x, int &y)
{
    if(b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    else
    {
        int r = exgcd(b, a%b, y, x);
        y -= x*(a/b);
        return r;
    }
}

int a[101], x[101], y[101];

int main()
{
    int n, p, b;
    read(n), read(p), read(b);
    up(i, 0, n)
    {
        read(a[i]);
        a[i]%=p;
    }
    int gcd_fn = a[0];
    up(i, 1, n) gcd_fn = exgcd(gcd_fn, a[i], y[i], x[i]);
    gcd_fn = exgcd(gcd_fn, p, y[n], x[n]);
    if(b%gcd_fn != 0)
    {
        puts("NO");
        return 0;
    }
    puts("YES");
    int mul = b/gcd_fn;
    x[0] = 1;
    down(i, 0, n)
    {
        while(y[i+1] < 0) y[i+1] += p;
        mul = mul*y[i+1]%p;
        while(x[i] < 0) x[i] += p;
        x[i] = x[i]*mul%p;
    }
    up(i, 0, n) printf("%d ", x[i]);
    return 0;
}
