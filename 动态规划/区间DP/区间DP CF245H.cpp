#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<cctype>

using namespace std;

int dp[5050][5050],q,is[5050][5050];
char a[5050];

int judge(int l,int r)
{
    for(int i=l,j=r;i<j;i++,j--)
        if(a[i]!=a[j])
            return 0;
    return 1;
}

int find(int l,int r)//³¬Ê±
{
 //   cout<<l<<" "<<r<<endl;
    if(l>r)
        return 0;
    if(l==r)
        return dp[l][r]=1;
    if(dp[l][r]>0)
        return dp[l][r];
    return dp[l][r]=find(l+1,r)+find(l,r-1)-find(l+1,r-1)+judge(l,r);
}

int main()
{
 //   freopen("data.txt","r",stdin);
    scanf("%s",a);
    int len=strlen(a);
    for(int i=0;i<len;i++)
        dp[i][i]=is[i][i]=1;
    for(int i=2;i<=len;i++)
    {
        for(int l=0;l<len+1-i;l++)
        {
            int r=l+i-1;
            if((l+1>r-1 || is[l+1][r-1]) && a[l]==a[r])
                is[l][r]=1;
            dp[l][r]=dp[l+1][r]+dp[l][r-1]-dp[l+1][r-1]+is[l][r];
        }
    }
    scanf("%d",&q);
    while(q--)
    {
        int temp1,temp2;
        scanf("%d %d",&temp1,&temp2);
        printf("%d\n",dp[temp1-1][temp2-1]);
    }
    return 0;
}