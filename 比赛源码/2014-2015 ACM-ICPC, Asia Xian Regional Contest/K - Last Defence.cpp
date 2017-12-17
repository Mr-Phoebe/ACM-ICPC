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

LL a, b, ans;

int main()
{
    int cnt, T;
    cnt = 0;
    scanf("%d", &T);
    while (T--)
    {
        cnt++;
        scanf("%I64d %I64d", &a, &b);
        if (a > b) swap(a, b);
        if (a == 0)
        {
            if (b != 0) printf("Case #%d: 2\n", cnt);
            else printf("Case #%d: 1\n", cnt);
        }
        else
        {
            ans = 1;
            while (a != 0)
            {
                ans += b/a;
                LL tmp = b%a;
                b = a;
                a = tmp;
            }
            printf("Case #%d: %I64d\n", cnt, ans);
        }
    }
    return 0;
}
