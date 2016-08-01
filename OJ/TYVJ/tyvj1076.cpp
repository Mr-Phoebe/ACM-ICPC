# include "stdio.h"
int a[30][30]={0},f[30][30][110]={0};
int main()
{
    int  i,j,k,n,tem,max=-1;
   
    scanf("%d",&n);
        
    for(i=1;i<=n;i++)
       for(j=1;j<=i;j++)    
         scanf("%d",&a[i][j]);
    
    f[1][1][(a[1][1])%100]=1;        
         
    for(i=2;i<=n;i++)
       for(j=1;j<=i;j++)           
         for(k=0;k<=99;k++)
            {
            if (f[i-1][j][k]==1 || f[i-1][j-1][k]==1) f[i][j][(a[i][j]+k)%100]=1;
            }            
  
    for(j=1;j<=n;j++) 
       for(k=0;k<=99;k++)
          if (f[n][j][k]==1 && k>max) max=k;
          
    printf("%d",max);
             
    return 0;
}