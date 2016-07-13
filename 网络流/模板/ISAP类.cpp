struct ISAP
{
    struct nedge
    {
        int u,v,next;
        ll c;
    } e[M*2];
    int head[N],tot,n;
    int ss,tt;

    void Resize(int n)
    {
        this->n=n;
    }

    void Clearall()
    {
        tot=1;
        CLR(head,0);
    }

    void Addedge(int u,int v,ll w)
    {
        e[++tot].v=v;
        e[tot].u=u;
        e[tot].c=w;
        e[tot].next=head[u];
        head[u]=tot;
        e[++tot].v=u;
        e[tot].u=v;
        e[tot].c=0;
        e[tot].next=head[v];
        head[v]=tot;
    }

    int dep[N],gap[N];

    void bfs()
    {
        CLR(dep,-1);
        CLR(gap,0);
        queue<int> que;
        gap[0]=1;
        dep[tt]=0;
        que.push(tt);
        while(!que.empty())
        {
            int u=que.front();
            que.pop();
            for(int i=head[u]; i; i=e[i].next)
                if(dep[e[i].v]==-1)
                {
                    que.push(e[i].v);
                    dep[e[i].v]=dep[u]+1;
                    ++gap[dep[e[i].v]];
                }
        }
    }

    int res,cur[N],num[N];
    int top;
    int MaxFlow(int s,int t)
    {
        this->ss=s;
        this->tt=t;
        bfs();
        top=res=0;
        memcpy(cur,head,sizeof(head));
        int u=ss,i;
        while(dep[ss]<n)
        {
            if(u==tt)
            {
                int temp=INF;
                int inser;
                for(i=0; i<top; i++)
                    if(temp>e[num[i]].c)
                    {
                        temp=e[num[i]].c;
                        inser=i;
                    }
                for(i=0; i<top; i++)
                {
                    e[num[i]].c-=temp;
                    e[num[i]^1].c+=temp;
                }
                res+=temp;
                top=inser;
                u=e[num[top]].u;
            }
            if(u!=tt && gap[dep[u]-1]==0)
                break;
            for(i=cur[u]; i; i=e[i].next)
                if(e[i].c != 0 && dep[u]==dep[e[i].v]+1)
                    break;
            if(i)
            {
                cur[u]=i;
                num[top++]=i;
                u=e[i].v;
            }
            else
            {
                int mi=n;
                for(i=head[u]; i; i=e[i].next)
                    if(e[i].c>0 && mi>dep[e[i].v])
                    {
                        mi=dep[e[i].v];
                        cur[u]=i;
                    }
                --gap[dep[u]];
                dep[u]=mi+1;
                ++gap[dep[u]];
                if(u!=ss)
                    u=e[num[--top]].u;
            }
        }
        return res;
    }

    void print()
    {
        puts("GRAPH:");
        for(int i=0; i<=n; i++)
        {
            if(!head[i])
                continue;
            printf("%d ->",i);
            for(int j=head[i]; j; j=e[j].next)
                printf("%d(%I64d) ",e[j].v,e[j].c);
            putchar('\n');
        }
    }
};
