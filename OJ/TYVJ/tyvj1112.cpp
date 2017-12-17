#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>
#include<cstdlib>
using namespace std;
struct asd
{
  int b[300];
  int l;
};
asd a[300];
int w,n,k,p,ans,i,j;
bool f,m[330];
void init()
{
  scanf("%d%d",&n,&k);
  memset(a,0,sizeof(a));
  for(i=1;i<=n;i++)
  {
   scanf("%d",&w);
   while(w!=0)
   {
      a[i].l++;
      a[i].b[a[i].l]=w;
      scanf("%d",&w);
   }
  }
}

int main()
{

  init();
  f=false;
  memset(m,true,sizeof(m));
  while(f==false)
  {
      f=true;
      for(i=1;i<=n;i++)
      if((m[i])&&(a[i].l<k))
      {
        f=false;
        m[i]=false;
        for(j=1;j<=n;j++)
        for(p=1;p<=a[j].l;p++)
        if(a[j].b[p]==i){a[j].b[p]=a[j].b[a[j].l];a[j].l--;break;}
      }
  }       
  ans=0;
  for(i=1;i<=n;i++)
  if(m[i])ans++;   
  printf("%d\n",ans);
  return 0;
}