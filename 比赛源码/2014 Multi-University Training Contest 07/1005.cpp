#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
long long n,x,y,z,t;
long long  dp[2000][2000];
int main() 
{
    int cas=0;
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%I64d%I64d%I64d%I64d%I64d",&n,&x,&y,&z,&t);
        long long ans = n * x * t;
        memset(dp , 0 , sizeof(dp));
        for (int i = 1; i <= n; ++i)
        {
            dp[i][0] = dp[i-1][0] + t * (i - 1) * y;
            ans=max(ans,dp[i][0] + t*y*(n - i)*i + x*(n - i)*t);
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= i; ++j)
            {
                if (i==j)
                {
                    dp[i][j]=0;
                }
                else
                {
                    long long damage1=(i - j)*y*(t + (j - 1)*z);
                    long long damage2=(i - 1 - j)*y*(t + j*z);
                    dp[i][j]=max(dp[i-1][j-1] + damage1 , dp[i-1][j] + damage2);
                }
                long long temp=(n - i)*x*(t + j*z) + (n - i)*(t + j*z)*(i - j)*y;
                ans=max(ans,dp[i][j] + temp);
            }
        }
        printf("Case #%d: %I64d\n", ++cas , ans);
    }
    return 0;
}
