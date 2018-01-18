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

int dp[12][3], digit[12];

int dfs(int bit, int kind, bool limit)
{
    if(bit == -1)
        return kind == 0 || kind == 1;
    if(!limit && dp[bit][kind] != -1)
        return dp[bit][kind];
    int upper = limit ? digit[bit] : 9;
    int sum = 0;
    for(int i = 0; i <= upper; ++i)
    {
        int next_kind = kind;
        if(kind == 0)
        {
            if(i == 4)
                next_kind = 2;
            else if(i == 6)
                next_kind = 1;
        }
        else if(kind == 1)
        {
            if(i == 2 || i == 4)
                next_kind = 2;
            else if(i != 6)
                next_kind = 0;
        }
        sum += dfs(bit-1, next_kind, limit && i == upper);
    }
    if(!limit)
        dp[bit][kind] = sum;
    return sum;
}

int calc(int num)
{
    int len = 0;
    digit[0] = 0;
    while(num)
    {
        digit[len++] = num%10;
        num/=10;
    }
    return dfs(len-1, 0, 1);
}

int main()
{
    int n, m;
    memset(dp, -1, sizeof dp);
    while(scanf("%d%d", &n, &m) && m)
    {
        printf("%d\n", calc(m) - calc(n-1));
    }
    return 0;
}
