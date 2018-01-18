#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#pragma comment(linker,"/STACK:102400000,102400000")
using namespace std;

const int mod=1000000007;
int ch[100050][2],pre[100050];
int pos[100050],cnt;
int l[100050],r[100050];
long long sum[100050];
long long w[100050];
inline void Rotate(int x,bool f)
{
    int y=pre[x];
    if(y)ch[y][ch[y][1]==x]=ch[x][f];
    pre[ch[x][f]]=y;
    y=ch[x][f];
    pre[ch[y][!f]]=x;
    ch[x][f]=ch[y][!f];
    pre[x]=y;
    ch[y][!f]=x;
    if(ch[x][0])l[x]=l[ch[x][0]];
    else l[x]=pos[x];
    if(ch[x][1])r[x]=r[ch[x][1]];
    else r[x]=pos[x];
    sum[x]=(sum[ch[x][0]]+sum[ch[x][1]]+w[x])%mod;
    if(ch[y][0])l[y]=l[ch[y][0]];
    else l[y]=pos[y];
    if(ch[y][1])r[y]=r[ch[y][1]];
    else r[y]=pos[y];
    sum[y]=(sum[ch[y][0]]+sum[ch[y][1]]+w[y])%mod;
}
long long dat[400050];
inline void push_up(int i)
{
    dat[i]=dat[i<<1]*dat[i<<1|1]%mod;
}
inline long long query(int i,int l,int r,int l1,int r1)
{
    if(l==l1 && r==r1) return dat[i];
    else
    {
        int mid=l+r>>1;
        if(l1>mid)return query(i<<1|1,mid+1,r,l1,r1);
        else if(r1<=mid)return query(i<<1,l,mid,l1,r1);
        else return query(i<<1,l,mid,l1,mid)*query(i<<1|1,mid+1,r,mid+1,r1)%mod;
    }
}
inline void updat(int i,int l,int r,int l1,long long x)
{
    if(l==l1 && r==l1)dat[i]=x;
    else
    {
        int mid=l+r>>1;
        if(l1>mid)updat(i<<1|1,mid+1,r,l1,x);
        else updat(i<<1,l,mid,l1,x);
        push_up(i);
    }
}
void dfs(int s)
{
    l[s]=cnt;
    if(ch[s][0])dfs(ch[s][0]),sum[s]+=sum[ch[s][0]],pre[ch[s][0]]=s;
    pos[s]=cnt++;
    if(ch[s][1])dfs(ch[s][1]),sum[s]+=sum[ch[s][1]],pre[ch[s][1]]=s;;
    r[s]=cnt-1;
    sum[s]=(sum[s]+w[s])%mod;
}
int main()
{
    //freopen("1.txt","r",stdin);
    int t,ti=1;scanf("%d",&t);
    while(t--)
    {
        int n,m;scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%d%d%d",w+i,&ch[i][0],&ch[i][1]);
        memset(sum,0,sizeof(sum));
        cnt=1;dfs(1);pre[1]=0;
        for(int i=1;i<=n;i++)
            updat(1,1,n,pos[i],sum[i]);
        int ty,x,y;
        long long a,b;
        printf("Case #%d:\n",ti++);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&ty,&x);
            if(ty==2)printf("%I64d\n",query(1,1,n,l[x],r[x]));
            else
            {
                y=ch[x][ty];
                if(y)
                {
                    Rotate(x,ty);
                    updat(1,1,n,pos[x],sum[x]);
                    updat(1,1,n,pos[y],sum[y]);
                }
            }
        }
    }
    return 0;
}
