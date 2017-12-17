//By LH
#pragma warning(disable:4996)
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
#define MAXN 1000005
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
const int MOD = 1000000007;

LL n, m, k, ans;
LL c[1000005], rev[1000005];

LL calc(LL x, LL y)
{
    LL tmp = 1;
    while (y > 0)
    {
        if (y%2 == 1) tmp = tmp*x%MOD;
        x = x*x%MOD; y >>= 1;
    }
    return tmp;
}

int main()
{
    int cnt = 0, T;
    rev[0] = 1; rev[1] = 1;
    for (int i = 2; i <= 1000000; i++) rev[i] = (MOD-MOD/i)*rev[MOD%i]%MOD;
    scanf("%d", &T);
    while (T--)
    {
        cnt++;
        scanf("%I64d %I64d %I64d", &n, &m, &k);
        LL tmp1 = 1;
        for (int i = 1; i <= k; i++)
        {
            tmp1 = tmp1*(m-i+1)%MOD;
            tmp1 = tmp1*rev[i]%MOD;
        }
        c[0] = 1;
        for (int i = 1; i <= k; i++)
        {
            c[i] = c[i-1]*(k-i+1)%MOD;
            c[i] = c[i]*rev[i]%MOD;
        }
        LL tmp2 = 0, flag = 1;
        for (int i = k; i >= 1; i--)
        {
            tmp2 = (tmp2+(calc(i-1, n-1)*i%MOD*c[i]*flag%MOD)+MOD)%MOD;
            flag = -flag;
        }
        ans = tmp1*tmp2%MOD;
        printf("Case #%d: %I64d\n", cnt, ans);
    }
    return 0;
}
