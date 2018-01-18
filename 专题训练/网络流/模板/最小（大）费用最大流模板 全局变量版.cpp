const int MAXN=3000;

struct Node
{
    int v , w , s ;
    int next ;
} e[8*MAXN];
int a[33][33],head[MAXN],tot ;
int pre[MAXN],vis[MAXN],dis[MAXN] ;
int cost,flow;


void init()
{
	CLR(head,-1);
 	tot=0 ;
}

void addedge(int u,int v,int w,int s)
{
    e[tot].v = v ; e[tot].w = w ; e[tot].s = s ;
    e[tot].next = head[u] ; head[u] = tot++ ;
    e[tot].v = u ; e[tot].w = 0 ; e[tot].s = -s ;
    e[tot].next = head[v] ; head[v] = tot++ ;
}
int spfa(int s,int t)
{
    int u , v , i ;
    CLR(dis,INF);
    dis[s] = 0 ; vis[s] = 1 ;
    pre[s] = pre[t] = -1 ;
    queue <int> Q ;
    Q.push(s) ;
    while( !Q.empty() )
    {
        u = Q.front();
        Q.pop();
        vis[u] = 0 ;
        for(i = head[u] ; ~i  ; i = e[i].next)
        {
            v = e[i].v ;
            if( e[i].w && dis[v] > dis[u] + e[i].s )
            {
                dis[v] = dis[u] + e[i].s ;
                pre[v] = i ;
                if( !vis[v] )
                {
                    vis[v] = 1 ;
                    Q.push(v) ;
                }
            }
        }
    }
    if( pre[t] == -1 )
        return 0 ;
    return 1 ;
}
int f(int s,int t)
{
    CLR(pre,-1);
    CLR(vis,0);
    int i,mi ;
    cost=flow=0;
    while(spfa(s,t))
    {
        mi=INF ;
        for(i=pre[t]; ~i ;i=pre[e[i^1].v])
            if(e[i].w < mi)
                mi = e[i].w ;
        flow+=mi;
    	cost+=dis[t]*mi;
        for(i=pre[t]; ~i ;i=pre[e[i^1].v])
        {
            e[i].w-=mi;
            e[i^1].w+=mi;
        }
    }
    return -cost;
}
