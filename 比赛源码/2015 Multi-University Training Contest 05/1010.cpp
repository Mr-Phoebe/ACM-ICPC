#include<cstdio>
#include<algorithm>
#include<ctime>
#define N 7005
#define M 1000005
using namespace std;int INF=(int)1e9;
int End[N],f[N],q[N],Go[M],Value[M],Next[M];
int x[N],y[N],flag[N][N],ans[N],num[N][N];
int cnt,n,m,i,j,E,S,T,tot,all,Count,tmp,Test,L,opt,u,v;
void add(int u,int v,int w)
{
    Go[++cnt]=v;Next[cnt]=End[u];Value[cnt]=w;End[u]=cnt;
    Go[++cnt]=u;Next[cnt]=End[v];Value[cnt]=0;End[v]=cnt;
}
int bfs()
{
    for (int i=1;i<=tot;i++) f[i]=-1;
    int h=0,t=1;q[1]=S;f[S]=0;
    while (h<t)
    {
        int k=q[++h];if (k==T) return 1;
        for (int i=End[k],x;i;i=Next[i])
            if (f[x=Go[i]]==-1&&Value[i]>0)
                f[x]=f[k]+1,q[++t]=x;
  }return 0;
}
int dinic(int k,int sum)
{
    if (k==T) return sum;int os=sum;
    for (int i=End[k],x;i&&os;i=Next[i])
        if (f[x=Go[i]]==f[k]+1&&Value[i]>0)
        {
            int flow=dinic(x,min(os,Value[i]));
            Value[i]-=flow;Value[i^1]+=flow;os-=flow;
      }
    if (sum==os) f[k]=-1;
    return sum-os;
}
int get(int u){return f[u]==u?u:f[u]=get(f[u]);}
void record(int k,int u)
{
    for (int i=1;i<=n;i++) f[i]=i;
    for (int i=1;i<=E;i++)
        if (flag[x[i]][y[i]]==Count) 
            f[get(x[i])]=get(y[i]);
    get(u);num[k][0]=Count;
    for (int i=1;i<=n;i++)
        num[k][i]=(get(i)==f[u])*Count;
}
int main()
{
    scanf("%d",&Test);
    for (Count=1;Count<=Test;Count++)
    {
        scanf("%d%d%d",&n,&m,&L);
        cnt=1;E=0;S=n+1;T=tot=S+1;all=*ans=0;
        for (i=1;i<=n;i++) add(i,T,1);
        for (i=1;i<=m;i++)
        {
            scanf("%d",&opt);
            if (opt==1) scanf("%d",&u),record(i,u);
            if (opt==2) 
            {
                ++E,scanf("%d%d",&x[E],&y[E]);
                if (x[E]>y[E]) swap(x[E],y[E]);
                flag[x[E]][y[E]]=Count;
          }
            if (opt==3) 
                for (scanf("%d",&tmp);tmp;tmp--)
                {
                    scanf("%d%d",&u,&v);
                    if (u>v) swap(u,v);flag[u][v]=0;
              }
      }
      for (i=m;i;i--)
          if (num[i][0]==Count)
          {
              add(S,++tot,L);
                for (j=1;j<=n;j++)
                  if (num[i][j]==Count) add(tot,j,1);
              tmp=0;
              while (bfs())
                  tmp+=dinic(S,INF);
              ans[++*ans]=tmp;all+=tmp;
        }
      for (i=1;i<=tot;i++) End[i]=0;
      printf("%d\n",all);
      for (i=*ans;i>1;i--)
          printf("%d ",ans[i]);
      if (*ans) printf("%d\n",ans[1]);
  }
}

