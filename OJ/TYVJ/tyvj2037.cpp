#include<iostream>
#include<cstdlib>
#include<cstring>

#define N 33
using namespace std;


struct node
{
    int cost,p;
}a[N];


int p[N],c[N],ans[N],t[N];
int m,n,money;


void Init()
{
    scanf("%d%d",&m,&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].p,&a[i].cost);
        p[a[i].p]=i;
    }
    int x,y;
    scanf("%d%d",&x,&y);
    while (x!=0  &&  y!=0)
    {
        x=p[x];
        y=p[y];
        c[x]=c[x] | (1 << (y-1));
        c[y]=c[y] | (1 << (x-1));
        scanf("%d%d",&x,&y);
    }
    //for (int i=1;i<=n;i++) printf("%d %d\n",i,c[i]);
}


void Judge(int cost)
{
    if (t[0]>ans[0]  ||  (cost))
    {
        money=cost;
        for (int i=0;i<=t[0];i++) ans[i]=t[i];
    }
}


void Dfs(int x,int cost,int now)
{
    if (x==n+1)
    {
        Judge(cost);
        return;
    }
    Dfs(x+1,cost,now);
    
    
    int jy=c[x];
    jy=jy | (1 << (x-1));
    int tt=x-1;
    if ( ((now & (1<<tt))==0)  &&  cost-a[x].cost>=0)
    {
        t[++t[0]]=x;
        Dfs(x+1,cost-a[x].cost,now | jy);
        t[0]--;
    }
}


bool cmp(int x,int y)
{
    if (a[x].p)
    return false;
}


void Main()
{
    money=m;
    Dfs(1,m,0);
    sort(ans+1,ans+ans[0]+1,cmp);
    printf("%d %d\n",ans[0],m-money);
    for (int i=1;i<=ans[0];i++) printf("%d\n",a[ans[i]].p);
}


int main()
{
    freopen("in","r",stdin);
    
    Init();
    Main();
    
    fclose(stdin);
    return 0;
}
