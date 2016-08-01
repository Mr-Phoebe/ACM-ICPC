#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 209
#define maxm 20000
#define INF 1e9
using namespace std;
struct Edge
{
    int v,cap,next;
}edge[maxm];
int n,tot,src,des;
int head[maxn],h[maxn],gap[maxn],B[maxn];
void addedge(int u,int v,int cap)
{
    edge[tot].v=v;
    edge[tot].cap=cap;
    edge[tot].next=head[u];
    head[u]=tot++;
    edge[tot].v=u;
    edge[tot].cap=0;
    edge[tot].next=head[v];
    head[v]=tot++;
}
int dfs(int u,int cap)
{
    if(u==des)return cap;
    int minh=n-1;
    int lv=cap,d;
    for(int e=head[u];e!=-1;e=edge[e].next)
    {
        int v=edge[e].v;
        if(edge[e].cap>0)
        {
            if(h[v]+1==h[u])
            {
                d=min(lv,edge[e].cap);
                d=dfs(v,d);
                edge[e].cap-=d;
                edge[e^1].cap+=d;
                lv-=d;
                if(h[src]>=n)return cap-lv;
                if(lv==0)
                    break;
            }
            minh=min(minh,h[v]);
        }
    }
    if(lv==cap)
    {
        --gap[h[u]];
        if(gap[h[u]]==0)
            h[src]=n;
        h[u]=minh+1;
        ++gap[h[u]];
    }
    return cap-lv;
}
int sap()
{
    int flow=0;
    memset(gap,0,sizeof(gap));
    memset(h,0,sizeof(h));
    gap[0]=n;
    while(h[src]<n)flow+=dfs(src,INF);
    return flow;
}
int main()
{
    int N,M;
    int cot=1;
    int CAS;
    scanf("%d", &CAS);
    while(CAS--)
    {
    	scanf("%d%d",&N,&M);
        memset(head,-1,sizeof(head));
        memset(B,0,sizeof(B));
        tot=0;src=0;des=N+1;n=des+1;
        for(int i=1;i<=M;i++)
        {
            int u,v,b,l;
            scanf("%d%d%d%d",&u,&v,&b,&l);
            addedge(u,v,l);
            B[v]+=b;B[u]-=b;
        }
        int sum=0;
        for(int i=1;i<=N;i++)
        {
            if(B[i]>0)
            {
                addedge(src,i,B[i]);
                sum+=B[i];
            }
            else if(B[i]<0)
            {
                addedge(i,des,-B[i]);
            }
        }
        int flow=sap();
        if(flow==sum)
        {
            printf("Case #%d: happy\n",cot++);
        }
        else
        {
            printf("Case #%d: unhappy\n",cot++);
        }
    }
    return 0;
}
