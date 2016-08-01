#include <iostream>
#include <cstring>
#define MAX 50
using namespace std;
char fh[MAX],dr[MAX];
int head,tail;
long long num[MAX],n,len,sum,tt;
int csfh=0,csnum=0;
int cul(int x,int y)
{
    tt=0;
    int q=1;
    for(int i=y;i>=x;i--,q*=10)
       tt+=(dr[i]-'0')*q;
    return(tt);
}
int pd(char a,char b)
{
    if(a=='#') return(0);
    if((b=='+'&&a=='-')||(b=='-'&&a=='+')||(b=='*'&&a=='/')||(b=='/'&&a=='*'))
        return(1);
    if((b=='+'&&a=='/')||(b=='+'&&a=='*')||(b=='-'&&a=='/')||(b=='-'&&a=='*')||a=='^')
       return(1);
    if((b=='+'&&a=='+')||(b=='-'&&a=='-')||(b=='*'&&a=='*')||(b=='/'&&a=='/'))
        return(1);
    return(0);
}
void solve(int x,char f,int y)
{
    if(f=='^')
    {
         num[csnum]=1;
         for(int i=1;i<=y;i++)
               num[csnum]*=x;
    }
    if(f=='-')
    {
         num[csnum]=x-y;
    }
    if(f=='+')
    {
         num[csnum]=x+y;
    }
    if(f=='*')
    {
         num[csnum]=x*y;
    }
    if(f=='/')
    {
         num[csnum]=x/y;
    }
}
int main()
{
    fh[0]='#';
    cin>>dr;
    len=strlen(dr);
    int q=1,dk=1;
    head=0,tail=-1;
    for(int i=0;i<=len;i++)
    {
          if(i==len&&csfh==0) break;
          if(i==len&&csfh!=0)
          {
                  int pq=cul(head,tail);
                  if(pq!=0)
                  {
                      num[++csnum]=pq;
                      head=i+1;tail=i;
                  }
                  csnum--;
                  solve(num[csnum],fh[csfh],num[csnum+1]);
                  csfh--;
                  i--;
                  continue;
          }
          if(dr[i]>='0'&&dr[i]<='9')
          {
                tail++;
          }
          else
          {
              int pq=cul(head,tail);
              if(pq!=0)
              {
                  num[++csnum]=pq;
                  head=i+1;tail=i;
              }
              if(pd(fh[csfh],dr[i])==0)
              {
                 fh[++csfh]=dr[i];
              }
              else
              {
                  csnum--;
                  solve(num[csnum],fh[csfh],num[csnum+1]);
                  csfh--;
                  i--;
              }
          }
    }
    cout<<num[1];
    return 0;
}