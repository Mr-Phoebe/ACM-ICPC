#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <utility>
#include <map>
#include <set>
#include <cctype>
#include <climits>
#include <stack>
#include <cmath>
#include <bitset>
#include <numeric>
#include <functional>

using namespace std;

typedef long long ll;

const int MAXN = 55;
ll c[MAXN][MAXN];

int main()
{
    c[0][0] = 1;
    c[1][0] = c[1][1] = 1;
    for(int i = 2; i <= 50; i ++)
    {
        c[i][0] = c[i][i] = 1;
        for(int j = 1; j < i; j++)
            c[i][j] = c[i-1][j-1] + c[i-1][j];
    }
    int T = 0, m;
    ll n, v1, v2;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%lld %lld %lld %d", &n, &v1, &v2, &m);
        ll rest = n - v1 - v2;
        if(v1+rest <= v2)
        {
             puts("RECOUNT!");
             continue;
        }
        ll sum = 0;
        for(int i = 0; i <= rest; i++)
        {
             int r1 = i, r2 = rest - i;
             if(v1+r1 <= v2+r2) continue;
             sum += c[rest][i];
        }
        double ans = (double)sum / pow(2.0, (double)rest);
        if(ans*100 > m)
        {
             puts("GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!");
        }
        else
        {
            puts("PATIENCE, EVERYONE!");
        }
    }
    return 0;
}
