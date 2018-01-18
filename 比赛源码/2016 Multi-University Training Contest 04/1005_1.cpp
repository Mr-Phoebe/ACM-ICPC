#include<cstdio>
#include<utility>
#include<numeric>
#include<functional>
using namespace std;
inline void err(void)
{
    puts("err");
    return;
}
inline bool isprime(const long long& x)
{
    static int i;
    for(i=2;i*i<=x;++i)
    {
        if(x%i==0)
        {
            return false;
        }
    }
    return true;
}
inline long long extgcd(long long a,long long m)
{
    static long long mt,k0,k1,kt,me;
    k0=1;
    k1=0;
    me=m;
    while(a%m)
    {
        kt=k0-k1*(a/m);
        k0=k1;
        k1=kt;
        mt=m;
        m=a%m;
        a=mt;
    }
    return k1>=0?k1:k1+me;
}
inline pair<long long,long long> chinamerge(long long* a,long long* b,const int n)
{
    static long long mul,mult;
    static __int128 ans;
    static int i;
    mul=accumulate(a,a+n,1LL,multiplies<long long>());
    ans=0;
    for(i=0;i<n;++i)
    {
        mult=mul/a[i];
        ans+=mult*extgcd(mult,a[i])*((__int128)b[i]);
    }
    return make_pair(mul,(long long)(ans%mul));
}
inline long long f(const long long& l,const long long& r,const pair<long long,long long>& m)
{
    return (r+m.first-m.second)/m.first-(l-1+m.first-m.second)/m.first;
}
int main()
{
    int n,T,cas=0,i,j,nn;
    bool tag;
    long long a[15],b[15],l,r,ans,mul,at[16],bt[16],mmm;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%I64d%I64d",&n,&l,&r);
        if(n<1||n>15||l>=r||r<=0||r>1000000000000000000LL)
        {
            err();
        }
        mmm=1000000000000000000LL;
        for(i=0;i<n;++i)
        {
            scanf("%I64d%I64d",&a[i],&b[i]);
            for(j=0;j<i;++j)
            {
                if(a[i]==a[j])
                {
                    err();
                }
            }
            if(
            a[i]>=mmm||
            a[i]==7||
            a[i]>1e5||
            a[i]<=0||
            !isprime(a[i])||
            b[i]<=0||
            b[i]>=a[i]
            )
            {
                err();
            }
            mmm/=a[i];
        }
        ans=f(l,r,{7LL,0LL});
        for(i=(1<<n)-1;i>0;--i)
        {
            nn=0;
            for(j=0;j<n;++j)
            {
                if(i&(1<<j))
                {
                    at[nn]=a[j];
                    bt[nn++]=b[j];
                }
            }
            at[nn]=7;
            bt[nn]=0;
            ans+=(nn&1?-1:1)*f(l,r,chinamerge(at,bt,nn+1));
        }
        printf("Case #%d: %I64d\n",++cas,ans);
    }
    if(cas>20)
    {
        puts("ERR");
    }
    return 0;
}
/*
2 1 100
3 2
5 3
*/
