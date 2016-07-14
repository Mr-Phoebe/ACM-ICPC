#include<stdio.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn = 100010;
long long add[maxn*4+1]; long long sum[maxn*4+1];

void pushup(int rt)
{
    sum[rt] = sum[rt<<1] + sum[rt<<1|1] ;
}
void pushdown(int rt,int m)
{
    if(add[rt])
    {
        add[rt<<1]+=add[rt];  add[rt<<1|1]+=add[rt];
        sum[rt<<1]+=add[rt]*(m-(m>>1));
        sum[rt<<1|1]+=add[rt]*(m>>1);
        add[rt]=0;
    }
}
void build(int l,int r,int rt)
{
    add[rt]=0;
    if(l==r)
    {
        scanf("%lld",&sum[rt]);
        return;
    }
    int m=(l+r)/2;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int L,int R,int c,int l,int r,int rt)
{
    if( L<=l && r<=R )
    {
        add[rt]+=c;
        sum[rt] += c*(r-l+1);
        return;
    }
    pushdown(rt,r-l+1);
    int m=(l+r)/2;
    if(L<=m) update(L,R,c,lson);
    if(R>m) update(L,R,c,rson);
    pushup(rt);
}
long long query(int L,int R,int l,int r,int rt)
{
    long long ret=0;
    if(L<=l && r<=R)
    {
        return sum[rt];
    }
    pushdown(rt,r-l+1);
    int m=(l+r)/2;
    if(L<=m) ret+=query(L,R,lson);
    if(R>m)  ret+=query(L,R,rson);
    return ret;
}
int main()
{
    int n,q,i; char ch[10]; long long ans; int a,b,c;
    scanf("%d%d",&n,&q);
    build(1,n,1);
    for(i=1;i<=q;i++)
    {
        scanf("%s",ch);
        if(ch[0]=='Q')
        {
            scanf("%d%d",&a,&b);
            ans=query(a,b,1,n,1);
            printf("%lld\n",ans);
        }
        else if(ch[0]=='C')
        {
            scanf("%d%d%d",&a,&b,&c);
            update(a,b,c,1,n,1);
        }
    }
    return 0;
}
