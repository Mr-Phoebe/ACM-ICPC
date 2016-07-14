#include<string.h>  
#include<algorithm>  
#include<iostream>  
#include<cmath>  
#include<cstdio>  
#include<vector>  
#define N 10005  
using namespace std;  
int lev[2*N],first[N],visit[2*N];  
int head[N];  
typedef struct str  
{  
    int to;  
    int next;  
}Node;  
Node node[N];  
int dpmin[15][2*N];  
int in[N];  
int tot,res;  
void init()  
{  
    memset(first,-1,sizeof(first));  
    memset(in,0,sizeof(in));  
    memset(head,-1,sizeof(head));  
    tot=1;  
    res=1;  
}  
void add(int a,int b)  
{  
    node[res].to=b;  
    node[res].next=head[a];  
    head[a]=res++;  
}  
void RMQ(int num)  
{    
    for(int i=1;i<=num;++i)  
        dpmin[0][i]=lev[i];  
    for(int i=1;(1<<i)<=num;++i)  
        for(int j=1;j+(1<<i)-1<=num;++j)  
            dpmin[i][j]=min(dpmin[i-1][j],dpmin[i-1][j+(1<<(i-1))]);  
}  
int doit(int sx,int ex)  
{  
    int k=(int)(log(ex-sx+1.0)/log(2.0));  
    int temp=min(dpmin[k][sx],dpmin[k][ex-(1<<k)+1]);  
    for(int i=sx;i<=ex;++i)  
        if(lev[i]==temp)  
            return visit[i];  
}  
void dfs(int cur,int now)//深搜遍历  
{  
    if(first[now]==-1)  
        first[now]=tot;  
        visit[tot]=now;  
        lev[tot++]=cur;  
        if(head[now]==-1) return;  
    for(int i=head[now];i!=-1;i=node[i].next)  
    {  
        dfs(cur+1,node[i].to);  
        visit[tot]=now;  
        lev[tot++]=cur;  
    }  
}  
int main()  
{  
    int T;  
    scanf("%d",&T);  
    while(T--)  
    {  
        int n,i;  
        scanf("%d",&n);  
        init();  
        for( i=1;i<n;++i)  
        {  
            int a,b;  
            scanf("%d%d",&a,&b);  
            add(a,b);  
            in[b]++;  
        }  
        for( i=1;in[i];++i);  
        dfs(0,i);  
        RMQ(2*n-1);  
        int a,b;  
        scanf("%d%d",&a,&b);  
        a=first[a],b=first[b];//查找a和b第一次出现的位置  
        if(a>b) swap(a,b);  
        printf("%d\n",doit(a,b));  
    }return 0;  
}  
//in记录的是结点的入度，frist记录的是该结点第一次出现的位置，visit是记录结点的访问顺序（包括回溯时）  
//lev记录的是相应结点的深度  