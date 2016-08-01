#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
using namespace std;
int n,m,k,l,d,h[1001],s[1001];
void solve(int len,int tot,int a[])
{
     int i,j,maxn;
     bool vis[1001]={0};
     a[0]=0;
     for (j=1;j<=tot;j++)
     {
       maxn=0;
       for (i=1;i<=len;i++)
       {
         if (!vis[i]&&a[i]>a[maxn])
           maxn=i;
       }
       vis[maxn]=1;
     }
     j=0;
     for (i=1;i<=len;i++)
     {
       if (vis[i])
       {
         if (j==0)  
         {
           printf("%d",i);
           j=1;
         }
         else
           printf(" %d",i);  
       }
     }
}  
int main ()
{
    int i,x,y,p,q;
    scanf("%d%d%d%d%d",&n,&m,&k,&l,&d);
    for (i=1;i<=d;i++)
    {
        scanf("%d%d%d%d",&x,&y,&p,&q);
        if (x==p)
          s[min(y,q)]++;
        else
          h[min(x,p)]++;
    }
    solve(n,k,h);
    cout<<endl;
    solve(m,l,s);
    fclose(stdin);
    fclose(stdout);
    return 0;
}