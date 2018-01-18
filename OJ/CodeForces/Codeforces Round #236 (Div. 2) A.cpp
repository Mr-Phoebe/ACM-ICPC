#include <cstdio>
#include<cmath>
#include<cctype>
#include<cstring>
#define MAX 101
int k,a,b,v;
int main()
{

   while(scanf("%d%d%d%d",&k,&a,&b,&v)!=EOF)
   {
       int count=0;
       if(a%v==0)
	   		count=a/v;
	   else
	   		count=a/v+1;
       if(k==1)
	   		printf("%d\n",count);
       if(k>=count&&b>=count-1)
	   		printf("1\n");
       else
       {
           int ok=1,n=0,s=0,sum=0;
           for(int i=1;i<=b;i++)
           {
               if(ok)n++;
               ok=0;s++;
               if(i%(k-1)==0)
               {
                   ok=1;
                   sum+=k;
                   s=0;
                   if(sum==count)break;
               }
               if(sum+s+1==count)break;
           }
           if(s)sum+=s+1;
           n+=count-sum;
           printf("%d\n",n);
       }
   }
    return 0;
}
