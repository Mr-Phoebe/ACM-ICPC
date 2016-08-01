#include<cstdio>
#include<cstring>
#define scf scanf
#define ptf printf
#define forp(i,j,k) for(int i=j;i<k;i++)
#define form(i,j,k) for(int i=j;i>k;i--)
#define sz(x) (int)x.size()
#define pb push_back
#define fst first
#define scd second
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

const int N=1e6+10,maxn=5e5;
const LL mo=1LL<<32;

LL f[N],g[N],h[N];
int used[N],notp[N],mnp[N],prime[N];

void pr()
{
    memset(notp,0,sizeof(notp));
    int pcnt=0;
    notp[1]=1;
    forp(i,2,maxn+1)
    {
        if(!notp[i])
        {
            prime[pcnt++]=i;
            mnp[i]=i;
        }
        for(int j=0;j<pcnt&&prime[j]*i<=maxn;j++)
        {
            mnp[i*prime[j]]=prime[j];
            notp[i*prime[j]]=1;
            if(i%prime[j]==0)break;
        }
    }
    f[1]=1;
    int t0;
    forp(i,2,maxn+1)
    {
        t0=1;
        for(int j=i;j%mnp[i]==0;j/=mnp[i])t0*=mnp[i];
        if(i-t0)
            f[i]=f[t0]*f[i/t0]%mo;
        else
            f[i]=(1LL*t0*mnp[i]-1)/(mnp[i]-1)%mo;
    }
}

int main()
{
    pr();
    forp(i,1,maxn+1)
    {
        g[i]+=1LL*i*(i+1)/2;
        g[i]%=mo;
        for(int j=2*i;j<=maxn;j+=i)
        {
            g[j]-=1LL*j/i*g[i]%mo;
            g[j]=(g[j]%mo+mo)%mo;
        }
    }
    forp(i,1,maxn+1)
        for(int j=i;j<=maxn;j+=i)
        {
            h[j]+=f[j/i]*j%mo*g[i]%mo;
            h[j]%=mo;
        }
    forp(i,1,maxn+1)
        h[i]=(h[i]+h[i-1])%mo;
    int T,x;
    scf("%d",&T);
    forp(tcnt,0,T)
    {
        scf("%d",&x);
        ptf("Case #%d: %I64d\n",tcnt+1,h[x]);
    }
    return 0;
}
