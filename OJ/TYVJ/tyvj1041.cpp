#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=300;
char s[N];
int a[N],b[N];
struct data
{
   int pos;
   char s;
}f[N],flag; 
int main()
{
     int i,j,k;
 scanf("%s",s);
     int l1=strlen(s);
  k=0;
     for(i=0;i<l1;++i)
     {
    if(s[i]=='+') {k++;f[k].s='+';f[k].pos=i;}
    if(s[i]=='-') {k++;f[k].s='-';f[k].pos=i;}
 }
  flag.s='+';flag.pos=-1; 
  int l=1;int len=0;
 for(i=1;i<=k;++i)
 {
    if(flag.s=='+')
    {
   len=max(len,f[i].pos-flag.pos-1);
   for(j=f[i].pos-1;j>flag.pos;--j)
   {
      a[l]+=s[j]-'0';
      if(a[l]>=10) {a[l+1]+=a[l]/10;a[l]=a[l]%10;}
      l++;
   }
   if(a[l+1]!=0) l++;
   len=max(len,l);
   flag=f[i];
   l=1;
}
    else
    {
  for(j=f[i].pos-1;j>flag.pos;--j)
  {
      a[l]-=s[j]-'0';
      while(a[l]<0) {a[l]=a[l]+10;a[l+1]=a[l+1]-1;}
      l++;
  }
  flag=f[i];
  l=1;
}
 }
 if(flag.s=='+')
  {
 len=max(len,l1-flag.pos-1);
 for(j=l1-1;j>flag.pos;--j)
     {
      a[l]+=s[j]-'0';
      if(a[l]>=10) {a[l+1]+=a[l]/10;a[l]=a[l]%10;}
      l++;
 }
 if(a[l+1]!=0) l++;
 len=max(len,l);
  }
  else 
  {
     for(j=l1-1;j>flag.pos;--j)
     {
  a[l]-=s[j]-'0';
      while(a[l]<0) {a[l]=a[l]+10;a[l+1]=a[l+1]-1;}
      l++;	
 }
  }
   i=1;
  for(i=1;i<=len;++i) 
   while(a[i]<0) 
   {
     a[i]=a[i]+10;
     a[i+1]=a[i+1]-1;
     i++;
   }
   for(i=len+10;i>=1;--i)
    {
  if(a[i]!=0) {j=i;printf("%d",a[i]);break;}
    }
    if(i==0) printf("0");
   else
   {
 for(i=j-1;i>=1;--i)
     printf("%d",a[i]);
   }

   return 0;
}