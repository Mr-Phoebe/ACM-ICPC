#include<cstdio>
#include<algorithm>
using namespace std;
int n;
double a[1001],f[1001][2],ans;
bool cmp(double a,double b){return a>b;}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
		scanf("%lf",a+i);
    sort(a+1,a+n+1,cmp);
    f[0][0]=1;
    for (int i=1;i<=n;i++)
    {
      f[i][0]=f[i-1][0]*(1-a[i]);
      f[i][1]=f[i-1][0]*a[i]+f[i-1][1]*(1-a[i]);
    }
    for (int i=1;i<=n;i++)
      ans=max(ans,f[i][1]);
    printf("%.12lf",ans);
}