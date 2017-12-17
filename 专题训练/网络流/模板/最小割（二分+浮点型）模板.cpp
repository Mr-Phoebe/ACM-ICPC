

int dcmp(double x)
{
    if(fabs(x) < EPS) return 0;
    else if(x > 0) return 1;
    else return -1;
}

struct Mincut
{
	struct edge
	{
	    int from,to;
	    double cap,flow;
	    int num;
	    edge(int u =0,int v =0,double c=0.0,double f=0.0,int n = 0):from(u),to(v),cap(c),flow(f), num(n) {}
	}a[MAXN];
    int head[MAXN];//ÿ���ڵ��Ӧ����Ŀ�ʼλ��
    int next[MAXN];//�������һ���ڵ���edges�����λ��
    int tot;//edges����Ĵ�С
    edge edges[2 * MAXN];//����ߵ�����
    int que[MAXN],front,tail;//���У�����ڵ�
    int d[MAXN];//������
    bool vis[MAXN];//���ʱ��
    int num[MAXN];//gap�Ż�
    int pre[MAXN];//����·�У��ڵ�X��ǰ��һ�����ı��
    int cur[MAXN];//����ÿ���ڵ�ģ�����ĵ�ǰ����
    int s,t,n;//sԴ���ţ�t����ţ�n�ڵ�����
    int mcut[2 * MAXN],sz;//��ļ���
    void resize(int n)
    {
    	this->n=n;
    }
    void init(int n)
    {
    	this->n=n;
        CLR(head,-1);
        tot = sz = 0;//
    }
    void addedge(int from,int to, double cap,int num)
    {
        edges[tot] = edge(from,to,cap,0.0,num);
        next[tot] = head[from], head[from] = tot++;
        edges[tot] = edge(to,from,cap,0.0,num);
        next[tot] = head[to],head[to] = tot++;
    }
    void bfs()
    {
        CLR(vis,0);
        front = tail = 0;
        d[t] = 0;
        vis[t] = true;
        que[tail++] = t;
        while(front < tail)
        {
            int u = que[front++];
            for(int v = head[u]; v != -1; v = next[v])
            {
                edge & e = edges[v^1];
                if(dcmp(e.cap-e.flow) > 0 && !vis[e.from]) //�Դ��ڲ��������еĻ���û���ʹ��Ľڵ㴦��
                {
                    d[e.from] = d[u] + 1;
                    vis[e.from] = true;
                    que[tail++] = e.from;
                }
            }
        }
    }
    double augment()
    {
        int x = t;
        double a = INF;
        while(x != s)
        {
            edge& e = edges[pre[x]];
            a = min(a,e.cap - e.flow);
            x = e.from;
        }

        for(int x = t; x != s; x = edges[pre[x]].from)
        {
            edges[pre[x]].flow += a;
            edges[pre[x]^1].flow -= a;
        }
        return a;
    }
    double maxflow(int s, int t)
    {
        this->s = s, this->t = t;
        CLR(num,0);
        double flow = 0.0;
        bfs();
        for(int i = 1; i <= n; ++i) //ע��˴����±�����
        {
            num[d[i]]++;
            cur[i] = head[i];
        }
        int x = s;
        while(d[s] < n)
        {
            if(x == t)
            {
                flow += augment();
                x = s;
            }
            bool ok = false;
            for(int v = cur[x]; v != -1; v = next[v])
            {
                edge& e = edges[v];
                if(dcmp(e.cap - e.flow) > 0 && d[x] == d[e.to] + 1)
                {
                    ok = true;
                    cur[x] = v;
                    pre[x = e.to] = v;
                    break;
                }
            }
            if(!ok)
            {
                int m = n - 1;
                for(int v = head[x]; v != -1; v = next[v])
                {
                    edge & e = edges[v];
                    if(dcmp(e.cap - e.flow) > 0) m = min(m,d[e.to]);
                }
                if(--num[d[x]] == 0) break;
                num[d[x]=m+1]++;
                cur[x] = head[x];
                if(x != s) x = edges[pre[x]].from;
            }
        }
        return flow;
    }
    bool build(int n,int m,double mid)
    {
        init(n);
        double flow = 0.0;
        for(int i = 1 ; i <= m; ++i)
        {
            edge & e = a[i];
            if(e.cap + EPS < mid) mcut[sz++] = e.num,flow += e.cap - m;
            else addedge(e.from, e.to,e.cap - m,e.num);
        }
        return dcmp(flow + maxflow(1,n)) > 0;
    }
    void mincut()
    {
        bfs();
        for(int i = 0 ; i < tot; ++i)
        {
            edge & e = edges[i];
            if(!vis[e.from] && vis[e.to] && e.cap > 0)
                mcut[sz++] = e.num;
        }
        sort(mcut,mcut + sz);
    }
    void print()
    {
        printf("Graph:\n");
        for(int i = 0 ; i < tot; ++i)
        {
            edge & e = edges[i];
            printf("->%d c:%f p:%f\n",e.to,e.cap,e.flow);
        }
    }
} g;
