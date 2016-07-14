#include<cstdio>
#include<iostream>
#include<vector>
#define N 100010
#define P 1000000007
using namespace std;
int n,i,a[N],j,t,q[N];
int l[N],tmp,r[N];
long long a1,a2,ans;
vector<int> vec[10010];
int main()
{
        freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    
    while (scanf("%d",&n)!=EOF)
    {
    for (i=101;i<=10000;i++)
    vec[i].clear();
    for (i=1;i<=n;i++)
    {
        l[i]=0;
        r[i]=n+1;
        scanf("%d",&a[i]);
        if (a[i]>100)
        vec[a[i]].push_back(i);
    }
    
    for (j=1;j<=100;j++)
    {
        tmp=0;
        for (i=1;i<=n;i++)
        {
            if (a[i]%j==0) l[i]=max(l[i],tmp);
            if (a[i]==j)
            tmp=i;
        }
        
        tmp=n+1;
        for (i=n;i>=1;i--)
        {
            if (a[i]%j==0) r[i]=min(r[i],tmp);
            if (a[i]==j)
            tmp=i;
        }
    }
    
    for (i=101;i<=10000;i++)
    q[i]=0;
    for (i=1;i<=n;i++)
    if (a[i]>100)
    {
        for (j=a[i];j<=10000;j=j+a[i])
        while ((q[j]<vec[j].size())&&(vec[j][q[j]]<i))
        {
              r[vec[j][q[j]]]=min(r[vec[j][q[j]]],i);
              if ((q[j]<vec[j].size()-1)&&(vec[j][q[j]+1]<i))
              q[j]++;
              else
              break;
        }
    }
  
    for (i=101;i<=10000;i++)
    q[i]=vec[i].size()-1;
    
    for (i=n;i>=1;i--)
    if (a[i]>100)
    {
        for (j=a[i];j<=10000;j=j+a[i])
        while ((q[j]>=0)&&(vec[j][q[j]]>i))
        {
              l[vec[j][q[j]]]=max(l[vec[j][q[j]]],i);
              if ((q[j]>0)&&(vec[j][q[j]-1]>i))
              q[j]--;
              else
              break;
        }
    }
    ans=0;
    for (i=1;i<=n;i++)
    {
        a1=r[i]-i;
        a2=i-l[i];
        ans=(ans+a1*a2)%P;
    }
   printf("%I64d\n",ans);
    }   
}
