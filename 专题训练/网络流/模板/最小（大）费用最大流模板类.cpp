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
