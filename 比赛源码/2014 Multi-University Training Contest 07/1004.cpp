#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

struct g
{
    long long t,p,w;
    int i;
    g(){}
    g(long long tt,long long pp,long long ww,long long ii){t=tt;p=pp;w=ww;i=ii;}
}a[100050],b[100050];
pair<long long,int>qa[100050],qb[100050];
int ans[100050];
long long sa[100050];

bool v[100050];

void cal(g a[],int n,g b[],int m,long long s1,long long s2)
{
    for(int i=0;i<n;i++)
        qa[i]=make_pair(a[i].p*s1-s1*s2*a[i].t,i);
    for(int i=0;i<m;i++)
        qb[i]=make_pair(b[i].p*s2-b[i].t*s2*s1,i);
    sort(qa,qa+n);sort(qb,qb+m);
    for(int i=0;i<m;i++)sa[i]=qb[i].first;
    for(int i=0;i<n;i++)
    {
        ans[a[qa[i].second].i]=upper_bound(sa,sa+m,qa[i].first+a[qa[i].second].w)-lower_bound(sa,sa+m,qa[i].first);
        if(ans[a[qa[i].second].i]<0)
        {
            int sb=1;
        }
        if(v[a[qa[i].second].i])
        {
            int sb=1;
        }
        v[a[qa[i].second].i]=1;
    }
}
int main()
{
    int t,ti=1;scanf("%d",&t);
    while(t--)
    {
        int n,s1,s2;scanf("%d%d%d",&n,&s1,&s2);
        int ca=0,cb=0;
        for(int i=0;i<n;i++)
        {
            int ty,x,y,z;
            scanf("%d%d%d%d",&ty,&x,&y,&z);
            if(ty==1)a[ca++]=g(x,y,1ll*z*s1,i);
            else b[cb++]=g(x,y,1ll*z*s2,i);
        }
        cal(a,ca,b,cb,s1,s2);
        cal(b,cb,a,ca,s2,s1);
        printf("Case #%d:\n",ti++);
        for(int i=0;i<n;i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}
