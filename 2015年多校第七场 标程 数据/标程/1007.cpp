#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[200010];
int a[200010],dp[200010][2];
int main()
{
    int T,len;
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%s",s+1);
        len=strlen(s+1);
        for(int i=1;i<=len;i++)
            scanf("%d",&a[i]);
        if(s[1]=='1')
            dp[1][1]=a[1];
        else
            if(s[1]=='0')
                dp[1][0]=0;
            else
            {
                dp[1][1]=a[1];
                dp[1][0]=0;
            }
        for(int i=2;i<=len;i++)
        {
            if(s[i]=='1')
            {
                if(dp[i-1][0]>=0)
                    dp[i][1]=max(dp[i][1],dp[i-1][0]+a[i]);
                if(dp[i-1][1]>=0)
                    dp[i][1]=max(dp[i][1],dp[i-1][1]);
            }
            else
                if(s[i]=='0')
                {
                    if(dp[i-1][0]>=0)
                        dp[i][0]=max(dp[i][0],dp[i-1][0]);
                    if(dp[i-1][1]>=0)
                        dp[i][0]=max(dp[i][0],dp[i-1][1]+a[i]);
                }
                else
                {
                    if(dp[i-1][0]>=0)
                        dp[i][1]=max(dp[i][1],dp[i-1][0]+a[i]);
                    if(dp[i-1][1]>=0)
                        dp[i][1]=max(dp[i][1],dp[i-1][1]);
                    if(dp[i-1][0]>=0)
                        dp[i][0]=max(dp[i][0],dp[i-1][0]);
                    if(dp[i-1][1]>=0)
                        dp[i][0]=max(dp[i][0],dp[i-1][1]+a[i]);
                }
        }
        // for(int i=1;i<=len;i++)
        //      printf()
        printf("Case #%d: %d\n",cas,max(dp[len][0],dp[len][1]));
    }
    return 0;
}