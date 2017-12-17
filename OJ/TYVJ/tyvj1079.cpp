# include "stdio.h"
int max(int a,int b)
{
    if (a>b) return a;
    return b;
}
int main()
{

    int a[30][30]={0},i,j,n,ans=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
       for(j=1;j<=i;j++)
          scanf("%d",&a[i][j]);
    
    for(i=1;i<n/2;i++) ans+=a[i][i];

    for(i=n;i>n/2;i--)
       for(j=n/2;j<=i;j++)
            a[i-1][j]+=max(a[i][j],a[i][j+1]);
    
    ans+=a[n/2][n/2];   
    printf("%d",ans);
  
    return 0;
}
