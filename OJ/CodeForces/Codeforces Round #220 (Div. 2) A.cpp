#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<stack>
#include<ctime>
#include<cstdlib>
#define mem(a,b) memset(a,b,sizeof(a))
#define M 1000005
typedef long long ll;
using namespace std;
int n,m,i,j,a,b,ans=1<<30;
int abc(int x,int y)
{
    int x1=x%a;
    int y1=y%b;  
    if(!x1&&!y1)   //如果都整除
    {
        int p=abs(x/a-y/b);   //并且其次数之差为偶数才行
        if(!(p&1)) return min(max(x/a,y/b),ans);   //因为次数不相等的话，那大的那个得先变为与次数小的一样才行，变的过程借助a或者b，故偶数时才得正常转化
    }
    return ans;
}
int main()
{
    cin>>n>>m>>i>>j>>a>>b;
    if(i==1&&j==1||i==n&&j==1||i==1&&j==m||i==n&&j==m)
        printf("0\n");
    else
    {
        if(i-1>0&&j-1>0) ans=abc(i-1,j-1);
        if(i-1>0&&m-j>0) ans=abc(i-1,m-j);  //如果不在边界正常判断，调用判断函数
        if(n-i>0&&j-1>0) ans=abc(n-i,j-1);
        if(n-i>0&&m-j>0) ans=abc(n-i,m-j);
        if((i+a<=n&&i==1&&!((j-1)%b)||n-a>0&&i==n&&!((j-1)%b))&&((j-1)/b)%2==0) ans=min((j-1)/b,ans);  //如果在边界可以直接判断，符合的话，次数会更少
        if((i+a<=n&&i==1&&!((m-j)%b)||n-a>0&&i==n&&!((m-j)%b))&&((m-j)/b)%2==0) ans=min((m-j)/b,ans);  //但是在边界因为要借助a或者b
        if((j+b<=m&&j==1&&!((i-1)%a)||m-b>0&&j==m&&!((i-1)%a))&&((i-1)/a)%2==0) ans=min((i-1)/a,ans);  //所以需要判断i+a,n-i,j+b,m-j不能超过边界
        if((j+b<=m&&j==1&&!((n-i)%a)||m-b>0&&j==m&&!((n-i)%a))&&((n-i)/a)%2==0) ans=min((n-i)/a,ans);
        if(ans==(1<<30)) printf("Poor Inna and pony!\n");
        else printf("%d\n",ans);
    }
    return 0;
}
