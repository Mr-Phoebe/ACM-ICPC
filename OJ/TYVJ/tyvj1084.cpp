# include "stdio.h"
int a[30][30]={0},n,x,y;
int max(int a,int b)
{
    if (a>b) return a;
    return b;
}
int main()
{
    int i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
       for(j=1;j<=i;j++)
          scanf("%d",&a[i][j]);
    scanf("%d%d",&x,&y);      
          
    k=max(x,y);
    
    for(i=1;i<=k;i++)
       for(j=1;j<=k;j++)
          a[i][j]+=max(a[i-1][j],a[i-1][j-1]);
    
    for(i=n;i>x+1;i--)
       for(j=y;j<=y+n-x;j++)
            a[i-1][j]+=max(a[i][j],a[i][j+1]);
          
    printf("%d",max(a[x+1][y],a[x+1][y+1])+a[x][y]);   
    return 0;
}