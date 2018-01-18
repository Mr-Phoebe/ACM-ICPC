#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<map>
using namespace std;
typedef long long ll;
const int maxn=1e6+1;
const int maxv=1e5+1;
bool isnp[maxv];
int prime[maxv],pnum;
int cas;
void get_prime()
{
    pnum=0;
    int i,j;
    memset(isnp,0,sizeof(isnp));
    isnp[0]=isnp[1]=true;
    for(i=2;i<maxv;i++)
    {
        if(!isnp[i])prime[pnum++]=i;
        for(j=0;j<pnum&&prime[j]*i<maxv;j++)
        {
            isnp[i*prime[j]]=true;
            if(i%prime[j]==0)break;
        }
    }
}    
ll qukpow(ll k,ll base,ll p)
{
    ll res=1;
    for(;k;k>>=1)
    {
        if(k&1)res=(res*base)%p;
        base=(base*base)%p;
    }
    return res;
}
ll fpr[maxv];
ll find_primitive_root(ll p)
{
        ll cnt=0,num=p-1,res;
        int i;
        if(p==2)return 1;
        for(i=0;i<pnum&&prime[i]*prime[i]<=num&&num>1;i++)
        {
            if(num%prime[i]==0)
            {
                fpr[cnt++]=prime[i];
                while(num%prime[i]==0)num/=prime[i];
            }
        }
        if(num>1)fpr[cnt++]=num;
        for(res=2;res<=p-1;res++)
        {
            for(i=0;i<cnt;i++)
                if(qukpow(p/prime[i],res,p)==1)break;
            if(i>=cnt)return res;
        }
        return -1;
};
const int mod=1e6+7;
struct solve
{
    struct HashTable
    {
        int top,head[mod];
        struct Node
        {
            int x,y,next;
        }node[mod];
        void init()
        {
            top=0;
            memset(head,0,sizeof(head));
        }
        void insert(ll x,ll y)
        {
            node[top].x=x;node[top].y=y;node[top].next=head[x%mod];
            head[x%mod]=top++;
        }
        ll query(ll x)
        {
            for(int tx=head[x%mod];tx;tx=node[tx].next)
                if(node[tx].x==x)return node[tx].y;
            return -1;
        }
    }mp;
    ll p;
    ll discretelog(ll prt,ll a)
    {
        ll res,am=qukpow(maxn-1,prt,p),inv=qukpow(p-2,a,p),x=1;
        for(ll i=maxn-1;;i+=(maxn-1))
        {
            if((res=mp.query((x=x*am%p)*inv%p))!=-1)
            {
                //cout <<"sb:"<<i<<" "<<it->second<<endl;        
                return i-res;
            }
            if(i>p)break;
        }
        return -1;
    }
    void ex_gcd(long long a,long long b,long long &d,long long &x,long long &y)
    {
        if(!b){d=a;x=1;y=0;}
        else {ex_gcd(b,a%b,d,y,x);y-=x*(a/b);}
    }
    ll proot;
    void init()
    {
        mp.init();
        ll tmp,x,y,d;
        int i;
        proot=find_primitive_root(p);
        for(i=0,tmp=1;i<maxn-1;i++,tmp=tmp*proot%p)mp.insert(tmp%p,i*1ll);
    }
    ll query(ll x,ll y)
    {
        ll d;
        x%=p;
        y%=p;
        //if(cas==6)cerr <<x<<" "<<y<<" "<<proot<<endl;
        if(y==1)return 0;
        else if(x==0)
        {
            if(y==0)return 1;
            else return -1;
        }
        else if(y==0)return -1;
        else
        {
            ll s=discretelog(proot,x);
            //if(cas==6)cerr <<s<<" finish discretelog "<<endl;
            ll t=discretelog(proot,y);
            //if(cas==6)cerr <<s<<" finish discretelog "<<t<<endl;
            ex_gcd(s,p-1,d,x,y);
            if(t%d)return -1;
            else
            {
                ll dx=(p-1)/d;
                x=(x%dx+dx)%dx;
                x*=(t/d);
                x=(x%dx+dx)%dx;
                return x;
            }
        }
    }
}sol[32];
int main()
{
    int i,j,q,con,T;
    ll sum,x,y;
    scanf("%d",&T);
    get_prime();
    for(cas=1;cas<=T;cas++)
    {
        con=0;
        scanf("%I64d %d",&sum,&q);
        if(sum>100000000)cerr <<"sum limit"<<endl;
        if(q>100000)cerr <<"sum limit"<<endl;
        for(i=0;i<pnum&&prime[i]*prime[i]<=sum&&sum!=1;i++)
        {
            if(sum%prime[i]==0)
            {
                sol[con].p=prime[i];
                sol[con].init();
                con++;
                while(sum%prime[i]==0)sum/=prime[i];
            }
        }
        if(sum>1)
        {
            sol[con].p=sum;
            sol[con].init();
            con++;
        }
        //for(i=0;i<con;i++)printf("%d ",sol[con].p);cout <<endl;
        //cerr<<"Case #"<<cas<<":"<<endl;
        printf("Case #%d:\n",cas);
        if(cas==8)cerr <<con<<" "<<sol[0].p<<endl;
        for(i=0;i<q;i++)
        {
            scanf("%lld %lld",&x,&y);
            if(x>1000000000||y>1000000000)cerr<<"x or y limit"<<endl;
            ll res=1e18,tmp;
            for(j=0;j<con;j++)
            {
                //if(cas==6)cerr<<x<<" "<<y<<" "<<sol[j].p<<endl;
                tmp=sol[j].query(x,y);
                if(tmp!=-1)res=min(res,tmp);
            }
            if(res==1e18)res=-1;
            printf("%I64d\n",res);
        }
    }
    return 0;
}
