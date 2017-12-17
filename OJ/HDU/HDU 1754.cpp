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

int bit[200010], num[200010];

int main()
{
    int n, m;
    while(scanf("%d%d", &n, &m) > 0)
    {
        memset(bit, 0, sizeof bit);
        for(int i = 1; i <= n; i++)
        {
            int tmp;
            scanf("%d", &tmp);
            num[i] = tmp;
            for(int j = i; j <= n; j += j & (-j))
                bit[j] = max(bit[j], tmp);
        }
        char str[3];
        int x, y;
        while(m--)
        {
            scanf("%s%d%d", str, &x, &y);
            if(str[0] == 'U')
            {
                for(int i = x; i <= n; i += i & (-i))
                    bit[i] = max(bit[i], y);
                num[x] = y;
            }
            else
            {
                int ans = 0;
                while(1)
                {
                    ans = max(ans, num[y]);
                    if(x == y) break;
                    for(y--; y - x >= (y & (-y)); y -= y & (-y))
                        ans = max(ans, bit[y]);
                }
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}
