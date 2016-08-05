#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>

#define N 100005

using namespace std;

vector<int>v[N];

int f[N][10][2],i,j,m,n,p,k,fa[N],R[10][2],l,T,x,y;

void add(int x,int y) 
{
    v[x].push_back(y); 
}

void up(int &x,int y)
{
   if (x>y) x=y; 
}

void dfs(int x)
{
      int i;
      if (v[x].size()==1) f[x][0][1]=f[x][1][0]=0;
      else f[x][0][0]=0;
      for (i=0;i<(int)v[x].size();++i)
      {
          int p=v[x][i];
          if (fa[x]==p) continue;
          fa[p]=x;
          dfs(p);
          memset(R,60,sizeof(R));
          for (j=4;j>=0;--j)
            for (k=4;k;--k)
              for (l=0;l<=min(j,k);++l)
               {
                  int rest=j+k-2*l;
                  up(R[rest][0],f[x][j][0]+f[p][k][0]+k);
                  up(R[rest][1],f[x][j][0]+f[p][k][1]+k);
                  up(R[rest][1],f[x][j][1]+f[p][k][0]+k);
               }
          memcpy(f[x],R,sizeof(f[x]));
      }
      for (i=4;i;--i) up(f[x][i-1][1],f[x][i][0]);
}

inline int read()
{
    int x;char c;
    while (c=getchar(),c<'0'||c>'9');
    x=c-'0';
    while (c=getchar(),c>='0'&&c<='9') x=(x<<1)+(x<<3)+c-'0';
    return x;
}

int main()
{
    scanf("%d",&T);
    for (;T--;)
    {
      for (i=1;i<=n;++i) v[i].clear();
      scanf("%d",&n);
      for (i=1;i<n;++i) x=read(),y=read(),add(x,y),add(y,x);
      if (n<=2) printf("%d\n",n-1);
      else 
      {
           memset(f,60,sizeof(f));
           memset(fa,0,sizeof(fa));
           for (i=1;i<=n;++i) if (v[i].size()>1) break;
           dfs(i);
           printf("%d\n",min(f[i][0][0],f[i][0][1]));
      }
    }
}
