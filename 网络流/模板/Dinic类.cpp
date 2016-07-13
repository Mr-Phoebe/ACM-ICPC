struct Dinic
{
    struct Edge
    {
        int to,next;
		ll f;
    } e[MAXM];
    int n,src,sink;
    int head[MAXN];
    int tot;

    void addedge(int u,int v,ll c)
    {
        e[++tot].to=v;
        e[tot].f=c;
        e[tot].next=head[u];
        head[u]=tot;
        e[++tot].to=u;
        e[tot].f=0;
        e[tot].next=head[v];
        head[v]=tot;
    }

    void Resize(int n)
    {
        this->n=n;
    }

    void Clear()
    {
        CLR(head,-1);
        tot=1;
    }

    bool vis[MAXN];
    int dist[MAXN];

    void bfs()
    {
        CLR(dist,0);
        queue<int> que;
        vis[src]=true;
        que.push(src);
        while(!que.empty())
        {
            int u=que.front();que.pop();
            for(int i=head[u]; ~i; i=e[i].next)
            {
                if(e[i].f>0 && !vis[e[i].to])
                {
                    que.push(e[i].to);
                    dist[e[i].to]=dist[u]+1;
                    vis[e[i].to]=true;
                }
            }
        }
    }

    ll dfs(int u,ll delta)
    {
        if(u==sink || delta==0)
            return delta;
        else
        {
            ll ret=0;
            for(int i=head[u]; ~i; i=e[i].next)
                if(e[i].f && dist[e[i].to]==dist[u]+1)
                {
                    ll dd=dfs(e[i].to,min(e[i].f,delta));
                    e[i].f-=dd;
                    e[i^1].f+=dd;
                    delta-=dd;
                    ret+=dd;
                }
            return ret;
        }
    }

    ll MaxFlow(int s,int t)
    {
        ll ret=0;
        this->src=s;this->sink=t;
        while(1)
        {
            CLR(vis,0);
            bfs();
            if(!vis[sink])
                return ret;
            ret+=dfs(src,LLINF);
        }
    }

    void print()
    {
        puts("GRAPH:");
        for(int i=0;i<n;i++)
        {
            printf("%d ->",i);
            for(int j=0;~j;j=e[j].next)
                printf("%d(%d) ",e[j].to,e[i].f);
            putchar('\n');
        }
    }

};

Dinic g;
