#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const double eps=1e-6;
int x[10],y[10],a[10],b[10],X[10],Y[10];
double C[10];
int n,i,ans,T;
inline void check(int T)
{
    int c=0;
    for (int i=1; i<4; i++)
        for (int j=i+1; j<=4; j++)
            C[c++]=sqrt((X[i]-X[j])*(X[i]-X[j])+.0+(Y[i]-Y[j])*(Y[i]-Y[j]));
    sort(C,C+6);
    if (fabs(C[0])<=eps) return;
    for (int i=1; i<4; i++)
        if (fabs(C[i]-C[i-1])>eps) return;
    if (fabs(C[5]-C[4])>eps) return;
    if (fabs(C[3]*sqrt(2.0)-C[4])>eps) return;
    if (ans==-1||T<ans) ans=T;
}
void dfs(int k,int T)
{
    if (k>4)
    {
        check(T);
        return;
    }
    X[k]=x[k];
    Y[k]=y[k];
    for (int i=0; i<4; i++)
    {
        dfs(k+1,T+i);
        int newx=a[k]-Y[k]+b[k],newy=b[k]+X[k]-a[k];
        X[k]=newx;
        Y[k]=newy;
    }
}
int main()
{
    scanf("%d",&n);
    while (n--)
    {
        for (i=1; i<=4; i++) scanf("%d%d%d%d",&x[i],&y[i],&a[i],&b[i]);
        ans=-1;
        dfs(1,0);
        printf("%d\n",ans);
    }
}
