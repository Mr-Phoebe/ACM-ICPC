#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node
{
    long long val,max;
    int lazy;
}nt[200010];
int n;

void update(int who,int lazy=1)
{
    nt[who].val<<=lazy;
    nt[who].max<<=lazy;
    nt[who].lazy+=lazy;
}

void push_down(int who)
{
    if(nt[who].lazy)
    {
        update(who<<1,nt[who].lazy);
        update(who<<1|1,nt[who].lazy);
        nt[who].lazy=0;
    }
}

void push_up(int who)
{
    nt[who].val=nt[who<<1].val+nt[who<<1|1].val;
    nt[who].max=max(nt[who<<1].max,nt[who<<1|1].max);
}

long long query_val(int L,int R,int who=1,int l=1,int r=n)
{
    if(L<=l&&R>=r)
    {
        return nt[who].val;
    }
    long long ret=0;
    int mid=(l+r)>>1;
    push_down(who);
    if(L<=mid)ret+=query_val(L,R,who<<1,l,mid);
    if(R>mid)ret+=query_val(L,R,who<<1|1,mid+1,r);
    return ret;
}

long long query_max(int L,int R,int who=1,int l=1,int r=n)
{
    if(L<=l&&R>=r)
    {
        return nt[who].max;
    }
    long long ret=0;
    int mid=(l+r)>>1;
    push_down(who);
    if(L<=mid)ret=max(query_max(L,R,who<<1,l,mid),ret);
    if(R>mid)ret=max(query_max(L,R,who<<1|1,mid+1,r),ret);
    //printf("zz%d %d %I64d\n",l,r,ret);
    return ret;
}

void cheng(int L,int R,int who=1,int l=1,int r=n)
{
    //printf("%d %d %d\n",who,l,r);
    if(L<=l&&R>=r)
    {
        //printf("%I64d %I64d\n",nt[who].val,nt[who].max);
        update(who);
        //printf("%I64d %I64d\n",nt[who].val,nt[who].max);
        return;
    }
    push_down(who);
    int mid=(l+r)>>1;
    if(L<=mid)cheng(L,R,who<<1,l,mid);
    if(R>mid)cheng(L,R,who<<1|1,mid+1,r);
    push_up(who);
}

void add(int pos,long long val,int who=1,int l=1,int r=n)
{
    if(pos<l||pos>n)return;
    //printf("zz%d %I64d %d %d\n",pos,val,l,r);
    if(l==r)
    {
        nt[who].val+=val;
        nt[who].max=nt[who].val;
        //printf("cc%d %I64d %d\n",who,nt[who].val,l);
        return;
    }
    push_down(who);
    int mid=(l+r)>>1;
    if(pos<=mid)add(pos,val,who<<1,l,mid);
    else add(pos,val,who<<1|1,mid+1,r);
    push_up(who);
}

void build(int who=1,int l=1,int r=n)
{
    nt[who].val=r-l+1;
    nt[who].max=1;
    if(l==r)
    {
        return;
    }
    int mid=(l+r)>>1;
    build(who<<1,l,mid);
    build(who<<1|1,mid+1,r);
}
int main()
{
    int ti;scanf("%d",&ti);
    for(int ca=1;ca<=ti;ca++)
    {
        printf("Case #%d:\n",ca);
        int m;scanf("%d%d",&n,&m);
        memset(nt,0,sizeof(nt));
        build();
        for(int i=0;i<m;i++)
        {
            char tmp[3];
            int L,R;
            scanf("%s%d%d",tmp,&L,&R);
            int nl,nr;
            int l=0,r=n;
            while(l+1<r)
            {
                int mid=(l+r)>>1;
                if(query_val(1,mid)<L)l=mid;
                else r=mid;
            }
            nl=r+1;
            l=0,r=n;
            while(l+1<r)
            {
                int mid=(l+r)>>1;
                if(query_val(1,mid)<=R)l=mid;
                else r=mid;
            }
            nr=l;
            if(tmp[0]=='D')
            {
                if(nr>=nl-1)
                {
                    add(nr+1,R-query_val(1,nr));
                    add(nl-1,query_val(1,nl-1)-L+1);
                    cheng(nl,nr);
                }
                else
                {
                    add(nl-1,R-L+1);
                }
            }
            else
            {
                long long ret=0;
                if(nr>=nl-1)
                {
                    ret=query_max(nl,nr);
                    ret=max(ret,query_val(1,nl-1)-L+1);
                    ret=max(ret,R-query_val(1,nr));
                }
                else
                {
                    ret=R-L+1;
                }
                printf("%I64d\n",ret);
            }
        }
        // printf("\n");
    }
}
