#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
int dp[13000];
int n,m;
int w[3500],d[3500];


int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d %d",&w[i],&d[i]);
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
        for(int j=m;j>=w[i];j--)
            dp[j]=max(dp[j],dp[j-w[i]]+d[i]);
    printf("%d\n",dp[m]);
    return 0;
}