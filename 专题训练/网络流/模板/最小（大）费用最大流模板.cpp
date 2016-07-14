

struct nedge
{
    int c,f,v,next;				// c为容量，f为费用
} e[MAXN*MAXN];
int head[MAXN],tot;
int ss,tt;
int cost,flow;

void init()
{
	CLR(head,0);
	tot=1;
}

void addedge(int u,int v,int cc,int ff)		// f费用加边有正负
{
    e[++tot].v=v;
    e[tot].c=cc;
    e[tot].f=ff;
    e[tot].next=head[u];
    head[u]=tot;
    e[++tot].v=u;
    e[tot].c=0;
    e[tot].f=-ff;
    e[tot].next=head[v];
    head[v]=tot;
}

int dui[MAXN],tou,wei,d[MAXN],hs[MAXN],last[MAXN],minx[MAXN];

int spfa()
{
    CLR(d,INF);CLR(hs,0);CLR(last,0);CLR(dui,0);
    d[ss]=1;
    hs[ss]=1;
    tou=wei=0;
    dui[wei++]=ss;
    while(tou-wei)
    {
        int now=dui[tou];
        tou=(tou+1)%MAXN;
        hs[now]=0;
        for(int i=head[now]; i; i=e[i].next)
            if(e[i].c>0 && d[e[i].v]>d[now]+e[i].f)
            {
                last[e[i].v]=now;
                minx[e[i].v]=i;
                d[e[i].v]=d[now]+e[i].f;
                if(hs[e[i].v]==0)
                {
                    hs[e[i].v]=1;
                    dui[wei]=e[i].v;
                    wei=(wei+1)%MAXN;
                }
            }
    }
    return d[tt]-INF;
}

void change()
{
    int mi=INF;
    for(int i=tt; i-ss; i=last[i])
        mi=min(mi,e[minx[i]].c);
    cost+=d[tt]*mi;
    for(int i=tt; i-ss; i=last[i])
    {
        e[minx[i]].c-=mi;
        e[minx[i]^1].c+=mi;
    }
}

int Mincost_flow()		//最大费用流则加负值费用，返回 -cost
{
    cost=flow=0;
    while(spfa())
        change();
    return cost;
}
