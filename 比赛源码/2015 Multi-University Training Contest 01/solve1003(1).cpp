#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#define INF 100000000
#define N 100010
#define U 200010
#define M 105
using namespace std;
int dp,p[U],pre[U],n,tt[U],a[N],i,u,v,j,MA;
int t,w,z[N],fa[N];
int f[N][M],g[N][M],fm[N][M],gm[N][M],h[N],t1[M],t2[M];
void link(int x,int y)
{
     dp++;pre[dp]=p[x];p[x]=dp;tt[dp]=y;
}
long long min(long long a,long long b)
{
     if (a<b) return a;return b;
}
void cl(int x,int fa)
{
     int i,j,tmp,flag;
     flag=0;
     tmp=INF;
     for (i=0;i<=MA;i++)
     {
     	f[x][i]=0;
     	g[x][i]=0;
         fm[x][i]=INF;
         gm[x][i]=INF;
         t1[i]=INF;
         t2[i]=INF;
     }
     t2[0]=0;
     f[x][MA]=INF;
     i=p[x];
     while (i)
     {
           if (tt[i]!=fa)
           {
                 flag=1;
                 g[x][0]+=f[tt[i]][0];
                 for (j=0;j<=MA;j++)
                 {
                     if (j<MA)
                     {
                     if (j)
                     f[x][j]=f[x][j]+min(fm[tt[i]][j+1],gm[tt[i]][j-1]);
                     else
                     f[x][j]=f[x][j]+fm[tt[i]][j+1];
                     if (f[tt[i]][j+1]!=INF)
                     {
                     if (j)
                     t1[j]=min(t1[j],f[tt[i]][j+1]-min(fm[tt[i]][j+1],gm[tt[i]][j-1]));
                     else
                     t1[j]=min(t1[j],f[tt[i]][j+1]-fm[tt[i]][j+1]);
                     }
                     }
                     
                     
                     if (j>0)
                     {
                     g[x][j]=g[x][j]+min(gm[tt[i]][j-1],fm[tt[i]][j]);
                     if (g[tt[i]][j-1]!=INF)
                     t2[j]=min(t2[j],g[tt[i]][j-1]-min(gm[tt[i]][j-1],fm[tt[i]][j]));
                     }
                 }
           }
           i=pre[i];
     }
     if (flag==0)
     f[x][0]=INF;
     for (i=0;i<=a[x];i++)
         tmp=min(tmp,min(g[x][i],f[x][i])+1);
     f[x][0]=min(f[x][0],INF);
     g[x][0]=min(g[x][0],INF);
     for (i=0;i<=MA;i++)
     {
         f[x][i]=min(INF,f[x][i]+t1[i]);
         g[x][i]=min(INF,g[x][i]+t2[i]);
     }
     f[x][a[x]]=min(f[x][a[x]],tmp);
     fm[x][0]=f[x][0];
     gm[x][0]=g[x][0];
     for (i=1;i<=MA;i++)
     {
         fm[x][i]=min(fm[x][i-1],f[x][i]);
         gm[x][i]=min(gm[x][i-1],g[x][i]);
     }
}
int main()
{
   freopen("a.in","r",stdin);
   freopen("a.out","w",stdout);
   
    while (scanf("%d",&n)!=EOF)
    {
    MA=0;
    for (i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        MA=max(MA,a[i]);
    }
    dp=0;memset(p,0,sizeof(p));
    for (i=1;i<=n;i++)
    fa[i]=0;
    for (i=1;i<=n-1;i++)
    {
        scanf("%d%d",&u,&v);
        link(u,v);
        link(v,u);   
    }
    
    t=0;w=1;z[w]=1;fa[1]=-1;
    while (t!=w)
    {
          t++;
          i=p[z[t]];
          while (i)
          {
                if (fa[tt[i]]==0)
                {
                     fa[tt[i]]=z[t];
                     w++;z[w]=tt[i];
                }
                i=pre[i];
          }
    }
    for (i=n;i>=1;i--)
    cl(i,fa[i]);
    printf("%d\n",fm[1][MA]);
   }
}
