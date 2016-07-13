#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101000
struct snode{
    int to,w,next;
}Tree[MAX<<2];
int visit[MAX],pre[MAX],sum[MAX],Index,Answer[MAX],Ansn;

void Add_edge(int a,int b,int c)
{
    Tree[Index].w=c;Tree[Index].to=b;
    Tree[Index].next=pre[a];
    pre[a]=Index++;
}

int DFS(int Star,int w)
{
    visit[Star]=1;           //记录结点被访问过
    int i,v,pd=0,kk=0;
    for(i=pre[Star];i!=-1;i=Tree[i].next)
    {
        if(visit[Tree[i].to])
            continue;
        sum[Star]+=DFS(Tree[i].to,Tree[i].w);
    }
    if(w==2||sum[Star]>=1)   //若该条路需要被修复||子节点已经被修复
    {
        if(sum[Star]==0)     //未被记录则加入集合
        {
            Answer[Ansn++]=Star;
        }
        return 1;
    }
    else                      //不需要修复
        return 0;
}

int main()
{
    int n,i,j,a,b,c,ans;
    while(scanf("%d",&n)!=EOF)
    {
        Index=ans=Ansn=0;
        memset(pre,-1,sizeof(pre));
        memset(sum,0,sizeof(sum));
        memset(visit,0,sizeof(visit));
        for(i=1;i<n;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            Add_edge(a,b,c);
            Add_edge(b,a,c);
        }
        visit[1]=1;
        ans+=DFS(1,0);       //1结点开始深搜
        printf("%d\n",Ansn);
        for(i=0;i<Ansn;i++)
        {
            printf("%d",Answer[i]);
            if(i!=Ansn)
                printf(" ");
        }
        puts("");
    }
    return 0;
}
