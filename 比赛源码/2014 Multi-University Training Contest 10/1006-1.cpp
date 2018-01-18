#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[1010],vis[1010],fee[1010];
int dp[1010][1010];
int main()
{
    int ti;scanf("%d",&ti);
    for(int ca=1;ca<=ti;ca++)
    {
        int n;
        if(scanf("%d",&n)==EOF)printf("zzzz!");
        for(int i=0;i<n;i++)scanf("%d",a+i);
        sort(a,a+n);
        int cnt=0,now=0;
        memset(fee,-1,sizeof(fee));
        for(int i=0;i<n;i++)
        {
            while(now<a[i])vis[cnt++]=now++;
            if(cnt>0)
            {
                --cnt;
                fee[vis[cnt]+1]=now-vis[cnt];
            }
        }
        //for(int i=1;i<=a[n-1];i++)printf("%d ",fee[i]);
        for(int i=0;i<=a[n-1];i++)
        {
            dp[i][0]=0;
            if(i>0)
            {
                for(int j=0;j<i;j++)dp[i][j+1]=dp[i-1][j];
            }
            if(fee[i]!=-1)for(int j=fee[i];j<=i;j++)
            {
                dp[i][j-fee[i]]=max(dp[i][j-fee[i]],dp[i][j]+1);
            }
        }
        int ret=0;for(int j=0;j<=a[n-1];j++)ret=max(dp[a[n-1]][j],ret);
        printf("Case #%d: %d\n",ca,ret);
    }
}
