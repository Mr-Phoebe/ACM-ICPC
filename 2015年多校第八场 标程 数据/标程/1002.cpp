#include <stdio.h>
#include <stdlib.h>
using namespace std;

int T,n,m,i,j,k,ll,rr;
int st[35],g[35],top;

int gcd(int a,int b){if(!b)return a;return gcd(b,a%b);}

void insert(int len,int gc)
{
    gc=gcd(g[top],gc);
    if(gc==g[top])st[top]+=len;
    else ++top,st[top]=len,g[top]=gc;
}

struct node
{
    int lst[35],lg[35],ltop;
    int rst[35],rg[35],rtop;
    long long sum;
    
    void update(node a)
    {
        int i,j,k;
        sum+=a.sum;
        for(i=1;i<=rtop;++i)
        {
            k=rg[i];
            for(j=1;j<=a.ltop;++j)
            {
                k=gcd(k,a.lg[j]);
                sum+=(long long)k*rst[i]*a.lst[j];
            }
        }
        
        for(i=1;i<=ltop;++i)st[i]=lst[i],g[i]=lg[i];
        top=ltop;
        for(i=1;i<=a.ltop;++i)insert(a.lst[i],a.lg[i]);
        for(i=1;i<=top;++i)lst[i]=st[i],lg[i]=g[i];
        ltop=top;
        
        for(i=1;i<=a.rtop;++i)st[i]=a.rst[i],g[i]=a.rg[i];
        top=a.rtop;
        for(i=1;i<=rtop;++i)insert(rst[i],rg[i]);
        for(i=1;i<=top;++i)rst[i]=st[i],rg[i]=g[i];
        rtop=top;
    }
}t[400005],ans;

void B(int x,int l,int r)
{
    if(l==r)
    {
        int val;
        scanf("%d",&val);
        t[x].ltop=t[x].rtop=1;
        t[x].lst[1]=t[x].rst[1]=1;
        t[x].lg[1]=t[x].rg[1]=val;
        t[x].sum=val;
        return;
    }
    int mid=l+r>>1;
    B(x<<1,l,mid);
    B(x<<1|1,mid+1,r);
    t[x]=t[x<<1];
    t[x].update(t[x<<1|1]);
}

void Q(int x,int l,int r)
{
    if(l>=ll&&r<=rr)
    {
        if(l==ll)ans=t[x];
        else ans.update(t[x]);
        return;
    }
    int mid=l+r>>1;
    if(rr<=mid)Q(x<<1,l,mid);
    else if(ll>mid)Q(x<<1|1,mid+1,r);
        else Q(x<<1,l,mid),Q(x<<1|1,mid+1,r);
}

int main()
{
    scanf("%d",&T);
    for(;T;--T)
    {
        scanf("%d",&n);
        B(1,1,n);
        scanf("%d",&m);
        for(;m;--m)
        {
            scanf("%d%d",&ll,&rr);
            Q(1,1,n);
            printf("%I64d\n",ans.sum);
        }
    }
}