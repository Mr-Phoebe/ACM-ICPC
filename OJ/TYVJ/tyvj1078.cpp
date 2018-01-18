# include "stdio.h"
int f[110][110],a[110],sum[110][110],n;
int main()
{
    
    int i,j,k,max,tem;
    
    scanf("%d",&n);
    for(i=1;i<=n;i++)
       scanf("%d",&a[i]);
    
     for(i=1;i<=n;i++)
       for(j=1;j<=n;j++)
         {
         sum[i][j]=(a[i]-a[j])*(j-i+1);
         if (sum[i][j]<0) sum[i][j]=-sum[i][j];
         if (i==j) sum[i][j]=a[i]; 
         }
               
    
    for(j=1;j<=n;j++)
       for(i=j;i>=1;i--)
          {          
          if (i==j) f[i][j]=sum[i][j];
          else 
             {
             max=-1;
             for(k=i;k<j;k++)
                {             
                tem=f[i][k]+f[k+1][j];
                if (tem>max) max=tem;                
                }
             if (sum[i][j]>max) max=sum[i][j];
             f[i][j]=max;   
             }
          }
  
    printf("%d",f[1][n]);
    
    return 0;
}