# include "stdio.h"
int f[5100],a[5100],n;
int main()
{
   
    int i,j,max=0;    
    
    scanf("%d",&n);
    for(i=0;i<n;i++)
       scanf("%d",&a[i]);
       
    for(i=0;i<n;i++)
       {
       for(j=0;j<i;j++)
          {
          if (a[j]<=a[i] && f[j]+1>f[i]) f[i]=f[j]+1;
          if (f[i]>max) max=f[i];
          }
       }

    printf("%d",max+1);
    return 0;
}