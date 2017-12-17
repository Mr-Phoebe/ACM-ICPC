# include "stdio.h"
int n,v,f[45100],a[510];
int main()
{
    int i,j,min;
    
    scanf("%d%d",&v,&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    
    
    for(i=0;i<n;i++)    
      {
      for(j=v;j>=0;j--)
          if (j-a[i]>=0)  
          {
             if (f[j]>f[j-a[i]]+a[i])
                 f[j]=f[j];
             else f[j]=f[j-a[i]]+a[i];
          }
          
      }
    
    printf("%d",f[v]);   
    return 0;              
}