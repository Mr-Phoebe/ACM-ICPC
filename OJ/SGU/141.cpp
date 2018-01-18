#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 1000000000000000000LL;

ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if(b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    else
    {
        ll r = exgcd(b, a%b, y, x);
        y -= a/b * x;
        return r;
    }
}

ll find(ll x, ll y, ll approxi, ll delta_x, ll delta_y, ll limit)
{
    for(ll i = approxi - 10; i <= approxi + 10; i++)
    {
        ll tmp = abs(x + delta_x*i) + abs(y - delta_y*i);
        if(tmp <= limit && !(((limit-tmp)) & 1))
            return i;
    }
    return INF;
}

int main()
{
    ll x, y, p, k;
    cin >> x >> y >> p >> k;
    ll gcd, a, b;
    gcd = exgcd(x, y, a, b);
    if(p % gcd != 0)
    {
        puts("NO");
        return 0;
    }
    a *= p/gcd, b *= p/gcd;
    ll tx = -a/(y/gcd), ty = b/(x/gcd);
    ll t = find(a, b, tx, y/gcd, x/gcd, k);
    if(t == INF) t = find(a, b, ty, y/gcd, x/gcd, k);
    if(t == INF)
    {
        puts("NO");
        return 0;
    }
    a += (y/gcd)*t, b -= (x/gcd)*t;
    ll left = k - abs(a) - abs(b);
    ll a_positive = a > 0 ? a : 0,
       a_negative = a < 0 ? -a : 0,
       b_positive = b > 0 ? b : 0,
       b_negative = b < 0 ? -b : 0;
    a_positive += left/2;
    a_negative += left/2;
    puts("YES");
    cout << a_positive << " " << a_negative << " " << b_positive << " " << b_negative << endl;
    return 0;
}
