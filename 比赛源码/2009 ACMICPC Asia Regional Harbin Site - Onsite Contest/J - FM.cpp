#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <string>
#define M 50005
#define N 1010
#define INF 1000000
#define INT_MAX 1000000000
#define CLR(x,y) memset(x,y,sizeof(x))

using namespace std;

struct Graph
{
    struct node
    {
        int v,next,w,flow;
        node(){};
        node(int a,int b,int c,int d){
            next=a;v=b;w=c;flow=d;
        }
    }E[2*M];

    int head[N],pre[N],dis[N];
    int beg,end,flow,cost;
    bool h[N];
    int path[N];
    int NE,NV;

    void resize(int n)
    {
        this->NV=n;
    }
    void init(int n)
    {
        NE=0;
        NV=n;
        memset(head,-1,sizeof(int)*(n+10));
    }
    void insert(int u,int v,int flow,int w)
    {
        E[NE]=node(head[u],v,w,flow);
        head[u]=NE++;
        E[NE]=node(head[v],u,-w,0);
        head[v]=NE++;
    }
    bool update(int u,int v,int w)
    {
        if(dis[u]+w<dis[v])
        {
            dis[v]=dis[u]+w;
            return true;
        }
        return false;
    }
    bool spfa()
    {
        CLR(pre,-1);
        CLR(h,0);
        for(int i=0;i<=NV;i++)
            dis[i]=INF;
        dis[beg]=0;
        queue<int> q;
        q.push(beg);
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            h[u]=0;
            for(int i=head[u];i!=-1;i=E[i].next)
            {
                int v=E[i].v;
                if(E[i].flow>0&&update(u,v,E[i].w))
                {
                    pre[v]=u;
                    path[v]=i;
                    if(!h[v])
                    {
                        h[v]=1;
                        q.push(v);
                    }
                }
            }
        }
        if(pre[end]==-1)
            return false;
        return true;
    }
    int mincost_maxflow(int s,int t)
    {
        this->beg=s;this->end=t;
        flow=0,cost=0;
        while(spfa())
        {
            int Min=INT_MAX;
            for(int i=end;i!=beg;i=pre[i])
                if(Min>E[path[i]].flow)
                    Min=E[path[i]].flow;
            for(int i=end;i!=beg;i=pre[i])
            {
                E[path[i]].flow-=Min;
                E[path[i]^1].flow+=Min;
            }
            flow+=Min;
            cost+=dis[end];
        }
        return cost;
    }
}g;

int n;

struct Node
{
    string name;
    int num[10];
    int ans;
}node[8];

string name[505];
int val[505][8];

void makenode()
{
    node[1].name = "A";
    node[1].num[1] = 1;node[1].num[2] = 2;node[1].num[3] = 1;node[1].num[4] = 1;
    node[1].num[5] = 2;node[1].num[6] = 1;node[1].num[7] = 1;node[1].num[8] = 2;

    node[2].name = "B";
    node[2].num[1] = 1;node[2].num[2] = 2;node[2].num[3] = 1;node[2].num[4] = 1;
    node[2].num[5] = 3;node[2].num[6] = 1;node[2].num[7] = 1;node[2].num[8] = 1;

    node[3].name = "C";
    node[3].num[1] = 1;node[3].num[2] = 2;node[3].num[3] = 1;node[3].num[4] = 1;
    node[3].num[5] = 3;node[3].num[6] = 0;node[3].num[7] = 0;node[3].num[8] = 3;

    node[4].name = "D";
    node[4].num[1] = 1;node[4].num[2] = 3;node[4].num[3] = 0;node[4].num[4] = 0;
    node[4].num[5] = 3;node[4].num[6] = 1;node[4].num[7] = 1;node[4].num[8] = 2;

    node[5].name = "E";
    node[5].num[1] = 1;node[5].num[2] = 3;node[5].num[3] = 0;node[5].num[4] = 0;
    node[5].num[5] = 4;node[5].num[6] = 1;node[5].num[7] = 1;node[5].num[8] = 1;

    node[6].name = "F";
    node[6].num[1] = 1;node[6].num[2] = 3;node[6].num[3] = 1;node[6].num[4] = 1;
    node[6].num[5] = 3;node[6].num[6] = 0;node[6].num[7] = 0;node[6].num[8] = 2;

    node[7].name = "China";
    node[7].num[1] = 1;node[7].num[2] = 4;node[7].num[3] = 1;node[7].num[4] = 1;
    node[7].num[5] = 3;node[7].num[6] = 0;node[7].num[7] = 0;node[7].num[8] = 1;
}

void work(int kind)
{
    g.init(n+30);
    g.insert(1,2,11,0);
    for(int i=1;i<=n;i++)
        g.insert(2,i+2,1,0);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=8;j++)
        g.insert(i+2,n+2+j,1,val[i][j]);

    for(int i=1;i<=8;i++)
        g.insert(n+2+i,n+2+9,node[kind].num[i],0);

    node[kind].ans = -g.mincost_maxflow(1,n+2+9);
}

int main()
{
    makenode();

    while(~scanf("%d",&n))
    {
        if(n == 0) break;

        memset(val,0,sizeof(val));

        for(int i=1;i<=n;i++)
        {
            cin>>name[i];
            for(int j=1;j<=8;j++) scanf("%d",&val[i][j]);
        }

        for(int i=1;i<=n;i++)
            for(int j=1;j<=8;j++)
            val[i][j] = -val[i][j];


        for(int i=1;i<=7;i++) work(i);

        int max_ans = 0;

        for(int i=1;i<=7;i++)
        max_ans = max(max_ans,node[i].ans);

        for(int i=1;i<=7;i++)
        if(node[i].ans == max_ans)
            cout<<"Formation "<<node[i].name<<" has the highest points "<<node[i].ans<<".\n";

        cout<<"\n";
    }
    return 0;
}