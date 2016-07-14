#include <stdio.h>
#include <stdlib.h>
using namespace std;

int T,n,m,t,i,j,k,l;
int a[105][105],b[505],c[505],ans[505];
char opt[505],ch;

int main()
{
    scanf("%d",&T);
    for(;T;--T)
    {
        scanf("%d%d",&n,&m);t=0;
        for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
        scanf("%d",&a[i][j]);
        for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
        scanf("%d",&a[i][j]);
        for(i=1;i<=m;++i)
        {
            for(ch=getchar();ch!='H'&&ch!='L';ch=getchar());
            opt[i]=ch;scanf("%d%d",&b[i],&c[i]);
        }
        for(;t<m;)
        {
            for(i=1;i<=m;++i)
            if(b[i])
            {
                k=b[i];
                if(opt[i]=='L')
                {
                    for(j=1;j<=n;++j)
                    if(a[j][k]&&a[j][k]!=c[i])
                    break;
                    if(j>n)
                    {
                        ans[++t]=i;b[i]=0;
                        for(j=1;j<=n;++j)a[j][k]=0;
                    }
                }
                else
                {
                    for(j=1;j<=n;++j)
                    if(a[k][j]&&a[k][j]!=c[i])
                    break;
                    if(j>n)
                    {
                        ans[++t]=i;b[i]=0;
                        for(j=1;j<=n;++j)a[k][j]=0;
                    }
                }
            }
        }
        for(i=m;i>=1;--i)printf("%d ",ans[i]);
        printf("\n");
    }
}