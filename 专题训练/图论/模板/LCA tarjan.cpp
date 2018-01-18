#include<cstdio>  
#include<algorithm>  
#include<iostream>  
#include<cstring>  
#include<string>  
#include<cmath>  
#include<vector>  
#include<queue>  
using namespace std;  
int fa[10005],dis[10005],ans[1000005],tr[10005];  
bool vd[10005];

struct node  
{  
    int v,w;  
};

vector < node > eg[10005],q[10005];

void init(int n)  
{  
    for(int i=0;i<=n;i++)  
        fa[i]=i,dis[i]=0,eg[i].clear(),q[i].clear(),vd[i]=0;  
    memset(ans,-1,sizeof(ans));  
} 

int find(int n)  
{  
    return n==fa[n]?n:fa[n]=find(fa[n]);  
} 

void tarjan(int n,int dth,int f)  
{  
    vd[n]=1;dis[n]=dth;tr[n]=f;  
    for(int i=0;i<q[n].size();i++)  
    {  
        int v=q[n][i].v,id=q[n][i].w;  
        if(vd[v])  
            if(tr[n]==tr[v])  
				ans[id]=dis[n]+dis[v]-2*dis[find(v)];  
    }  
    for(int i=0;i<eg[n].size();i++)  
    {  
        int v=eg[n][i].v,w=eg[n][i].w;  
        if(!vd[v])  
        {  
            tarjan(v,dth+w,f);  
            fa[v]=n;  
        }  
    }  
}  
int main()  
{  
    int n,m,k,x,y,w;  
    while(~scanf("%d%d%d",&n,&m,&k))  
    {  
        init(n);  
        for(int i=0;i<m;i++)  
        {  
            scanf("%d%d%d",&x,&y,&w);  
            node tem;tem.v=y,tem.w=w;  
            eg[x].push_back(tem);            //Ë«Ïò±ß 
            tem.v=x;eg[y].push_back(tem);  
        }  
        for(int i=0;i<k;i++)  
        {  
            scanf("%d%d",&x,&y);  
            node tem;tem.v=y,tem.w=i;  
            q[x].push_back(tem);tem.v=x;  
            q[y].push_back(tem);  
        }  
        for(int i=1;i<=n;i++)  
        {  
            tarjan(i,0,i);  
        }  
        for(int i=0;i<k;i++)  
        {  
            if(ans[i]==-1)  
                printf("Not connected\n");  
            else  
                printf("%d\n",ans[i]);  
        }  
    }  
    return 0;  
}  