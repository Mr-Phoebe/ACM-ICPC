#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long int ll;
const int maxn = 10000005;
ll a[maxn];
int main()
{
    ll n,k;
    scanf("%I64d %I64d",&n,&k);
    ll cnt = 0;
    ll sq = (ll)sqrt(n);
    for(ll i = 1; i <= sq; ++i)
        if(n%i==0)
            a[++cnt] = i;
    ll t = cnt;
    cnt = cnt * 2;
    if(sq * sq == n)cnt--;
    if(cnt < k)printf("-1\n");
    else
    {
        if(k <= t)
            printf("%I64d\n",a[k]);
        else
        {
            k = cnt-k+1;
            printf("%I64d\n",n/a[k]);
        }
    }
    return 0;
}
