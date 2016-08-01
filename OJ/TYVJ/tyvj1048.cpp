#include "iostream"
#include "cstring"
#include "cstdio"
#include "cstdlib"
#include "algorithm"
using namespace std;
int n;
int tianji[1001];
int qiwang[1001];
int v[1001][1001];
inline int qusi(int i,int j)
{
if (v[i][j]!=-1) return v[i][j];
int ret=tianji[i]>qiwang[j]?200:-200;
if (tianji[i]==qiwang[j]) ret=0;
return v[i][j]=ret;
}
inline bool cmp(int a,int b) {return a>b;;}
int F[1001][1001];
int main()
{
scanf("%d",&n);
for (int i=1;i<=n;i++) scanf("%d",&tianji[i]);
for (int i=1;i<=n;i++) scanf("%d",&qiwang[i]);
sort(tianji+1,tianji+1+n,cmp);sort(qiwang+1,qiwang+1+n,cmp);
memset(v,-1,sizeof v);
for (int i=1;i<=n;i++)
{
F[i][i]=F[i-1][i-1]+qusi(i,i);
for (int j=i-1;j>=1;j--)
F[i][j]=max(F[i-1][j-1]+qusi(j,i),F[i-1][j]+qusi(n-i+j,i));
F[i][0]=F[i-1][0]+qusi(n-i,i);
}
int mx=-100000000;
for (int i=0;i<=n;i++)
mx=max(mx,F[n][i]);
cout<<mx<<endl;
return 0;
}