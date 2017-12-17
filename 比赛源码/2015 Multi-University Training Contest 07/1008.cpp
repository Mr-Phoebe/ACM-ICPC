#include<cstdio>
#include<iostream>
#define mod 1000000007
using namespace std;
int f[100005],ny[100005],fac[100005];
void pre()
{
    f[0]=f[1]=ny[0]=ny[1]=fac[0]=fac[1]=1;
    for(int i=2;i<100005;i++)
    {
        fac[i]=1LL*fac[i-1]*i%mod;
        int t=mod/i,k=mod%i;
        f[i]=1LL*i*t%mod*t%mod*f[k]%mod*f[k]%mod;
        ny[i]=1LL*ny[i-1]*f[i]%mod;
    }
}
int c(int n,int m)
{
    if(n<m) return 0;
    return 1LL*fac[n]*ny[m]%mod*ny[n-m]%mod;
}
int solve(int n,int m,int k)
{
    if(m==3)
    {
        if(k<=1) return 0;
        if(k==3) return (1LL*n*(n+1)*(2*n+1)/6)%mod;
        if(k==2) return (0LL+c(2*n+1,3)-(1LL*n*(n+1)*(2*n+1)/6)%mod+mod)%mod;
    }
    if(k>=3) return 0;
    else if(k==2)
        return 1LL*(2*n+1)*(0LL+c(n+1,m-1)+c(n,m-1))%mod;
    else if(k==1)
        return 1LL*(2*n+1)*(m-4)%mod*c(n+1,m-1)%mod;
    else
        return (0LL+c(2*n+1,m)-1LL*(2*n+1)*(0LL+c(n+1,m-1)+c(n,m-1))%mod-1LL*(2*n+1)*(m-4)%mod*c(n+1,m-1)%mod+2*mod)%mod;
    
}
int main()
{
    //freopen("1.in","r",stdin); freopen("1.out","w",stdout);
    pre();
    int T,cas=0;scanf("%d",&T);
    while(T--)
    {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        printf("Case #%d: %d\n",++cas,solve(n/2,m,k));
    }
    return 0;
}