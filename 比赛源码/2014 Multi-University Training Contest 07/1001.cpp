#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


int prim[1000050],pk;
bool v[1000050];
void cal()
{
    for(int i=2;i<1000005;i++)
    {
        if(v[i]==0)prim[pk++]=i;
        for(int j=0;j<pk&&prim[j]*i<1000005;j++)
        {
            v[i*prim[j]]=1;
            if(i%prim[j]==0)break;
        }
    }
}
int te[50];
long long min_sa(long long n)
{
    int k=0,cnt;
    for(int i=0;1ll*prim[i]*prim[i]<=n;i++)
        if(n%prim[i]==0)
        {
            cnt=0;
            do cnt++,n/=prim[i];
            while(n%prim[i]==0);
            te[k++]=cnt;
        }
    if(n!=1)te[k++]=1;
    sort(te,te+k);
    long long c=1;
    for(int i=0;i<k;i++)
        for(int j=0;j<te[k-i-1];j++)
            c*=prim[i];
    return c;
}
pair<long long,int> sa[5050];
int fk;
const long long lim=100000000005ll;
vector<long long>fac[5050];
void dfs(long long s,int j,int k)
{
    int las=fk-1;
    long long te;
    for(int i=0;i<=k;i++)
        if(s*prim[j]<lim)
        {
            s*=prim[j];
            for(int z=0;z<fac[las].size();z++)
            {
                fac[fk].push_back(fac[las][z]);
                fac[fk].push_back(fac[las][z]*prim[j]);
            }
            sort(fac[fk].begin(),fac[fk].end());
            fac[fk].erase(unique(fac[fk].begin(),fac[fk].end()),fac[fk].end());
            sa[las=fk]=make_pair(s,fk);fk++;
            dfs(s,j+1,i);
        }
        else return;
}
double dp[5050][40];
double pre[5050][40];
bool vis[5050];
int hash[35050];
const int seed=33179;
int dfs_dp(long long n)
{
    int ind=hash[n%seed];
    if(vis[ind]==0)
    {
        vis[ind]=1;
        int tot=fac[ind].size()-2,cnt,c,d;
        long long l,ll;
        //double pp=1.0/tot;
        for(int i=1;i<=tot;i++)
            if(fac[ind][i]<=n/fac[ind][i])
            {
                c=dfs_dp(l=min_sa(fac[ind][i]));
                d=dfs_dp(ll=min_sa(n/fac[ind][i]));
                double pp=2.0/tot;
                if(fac[ind][i]==n/fac[ind][i])pp*=0.5;
                cnt=65-__builtin_clzll(max(l,ll));
                for(int j=1;j<cnt;j++)
                {
                    dp[ind][j+1]+=dp[c][j]*pre[d][j]*pp;
                    dp[ind][j+1]+=pre[c][j]*dp[d][j]*pp;
                    dp[ind][j+1]-=dp[c][j]*dp[d][j]*pp;
                }
            }
            else break;
        for(int i=1;i<40;i++)
            pre[ind][i]=pre[ind][i-1]+dp[ind][i];
    }
    return ind;
}
int main()
{
    cal();fk=1;
    fac[0].push_back(1);
    dfs(1,0,100000);
    sort(sa,sa+fk);
    for(int i=1;i<fk;i++)
        hash[sa[i].first%seed]=sa[i].second;
    vis[1]=1;dp[1][1]=1.0;
    for(int i=1;i<40;i++)pre[1][i]=1.0;
    int t,ti=1;scanf("%d",&t);
    while(t--)
    {
        long long n,m;scanf("%I64d",&n);
        int z=dfs_dp(m=min_sa(n));
        double ans=0;
        int cnt=65-__builtin_clzll(m);
        for(int i=1;i<cnt;i++)
            ans+=dp[z][i]*i;
        printf("Case #%d: %.6f\n",ti++,ans);
    }
    return 0;
}

