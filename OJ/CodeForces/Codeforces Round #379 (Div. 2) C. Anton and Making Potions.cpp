#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
const int M = 2e5 + 20;
ll a[M] , b[M] , c[M] , d[M];
int main()
{
    ll n , m , k;
    scanf("%I64d%I64d%I64d" , &n , &m , &k);
    ll x , s;
    scanf("%I64d%I64d" , &x , &s);
    for(int i = 0 ; i < m ; i++) {
        scanf("%I64d" , &a[i]);
    }
    for(int i = 0 ; i < m ; i++) {
        scanf("%I64d" , &b[i]);
    }
    for(int i = 0 ; i < k ; i++) {
        scanf("%I64d" , &c[i]);
    }
    for(int i = 0 ; i < k ; i++) {
        scanf("%I64d" , &d[i]);
    }
    ll MIN = n * x;
    a[m] = x;
    for(int i = 0 ; i <= m ; i++) {
        if(s >= b[i]) {
            ll temp = s - b[i];
            int pos = upper_bound(d , d + k , temp) - d;
            if(pos == 0) {
                MIN = min(MIN , n * a[i]);
                continue;
            }
            pos--;
            ll gg = n - c[pos];
            gg *= a[i];
            MIN = min(MIN , gg);
        }
    }
    printf("%I64d\n" , MIN);
    return 0;
}