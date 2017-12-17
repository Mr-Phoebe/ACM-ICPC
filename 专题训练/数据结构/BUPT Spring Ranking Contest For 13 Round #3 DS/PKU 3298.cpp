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

using namespace std;

const int MAXN=30010;

int dp[MAXN];
int a[MAXN];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        if(n==1)
        {
            printf("%d\n",n);
            continue;
        }
        dp[n-1]=1;
        if(a[n-1]>=a[n-2])
            dp[n-2]=1;
        else
            dp[n-2]=2;
        for(int i=n-3;i>=0;i--)
        {
            if(a[i]>a[i+1])
            {
                int k=i+1;
                while(a[k]==a[k+1])
                {
                    k++;
                    if(k>=n-1)
                        break;
                }
                if(a[k]>a[k+1])
                    dp[i]=dp[i+1];
                else if(a[k]<a[k+1])
                    dp[i]=dp[i+1]+2;
            }
            else if(a[i]<=a[i+1])
                dp[i]=dp[i+1];
        }
        printf("%d",dp[0]);
        puts("");
    }

    return 0;
}
