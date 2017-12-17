#include<bits/stdc++.h>

using namespace std;

const int MAXN=100105;
long long dp[MAXN][12];

void add(int x,int y,long long val)
{
    for(int i=x; i<MAXN; i+=i&(-i))
        dp[i][y]+=val;
}

long long sum(int x,int y)
{
    long long ans = 0;
    for(int i=x; i>0; i-=i&(-i))
        ans+=dp[i][y];
    return ans;
}

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    add(1,0,1);
    for(int i=0; i<n; i++)
    {
        int x;
        scanf("%d",&x);
        x++;
        for(int j=k+1; j>0; j--)
        {
            long long temp = sum(x,j-1);
            add(x,j,temp);
        }
    }
    long long ans = sum(n+1,k+1);
    printf("%lld\n",ans);
    return 0;
}
