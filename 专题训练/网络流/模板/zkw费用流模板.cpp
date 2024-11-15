

const int N=440, M=N*2;

struct Edge
{
    int t, u, c;
    Edge *next, *pair;
    Edge() {}
    Edge(int T, int U, int C, Edge* N): t(T), u(U), c(C), next(N) {}
    void* operator new(unsigned, void* p){return p;}
} *e[N], Te[M*2], *Pe;

int S, T, n, piS, cost;
bool v[N];

void addedge(int s, int t, int c, int u)
{
    e[s] = new(Pe++) Edge(t, +u, c, e[s]);
    e[t] = new(Pe++) Edge(s, -u, 0, e[t]);
    e[s]->pair = e[t];
    e[t]->pair = e[s];
}

int aug(int no, int m)
{
    if (no == T) return cost += piS * m, m;
    v[no] = true;
    int l = m;
    for (Edge *i = e[no]; i; i = i->next)
        if (i->c && !i->u && !v[i->t])
        {
            int d = aug(i->t, l < i->c ? l : i->c);
            i->c -= d, i->pair->c += d, l -= d;
            if (!l) return m;
        }
    return m - l;
}

bool modlabel()
{
    static int d[N]; memset(d, 0x3F, sizeof(d)); d[T] = 0;
    static deque<int> Q; Q.push_back(T);
    while(Q.size())
    {
        int dt, no = Q.front(); Q.pop_front();
        for(Edge *i = e[no]; i; i = i->next)
            if(i->pair->c && (dt = d[no] - i->u) < d[i->t])
                (d[i->t] = dt) <= d[Q.size() ? Q.front() : 0]
                    ? Q.push_front(i->t) : Q.push_back(i->t);
    }
    for(int i = 0; i < n; ++i)
        for(Edge *j = e[i]; j; j = j->next)
            j->u += d[j->t] - d[i];
    piS += d[S];
    return d[S] < INF;
}

int mincost_maxflow()
{
	piS = cost = 0;
	while(modlabel())
	{
		do
		{
			CLR(v,0);
		}while(aug(S, INF));
	}
    return -cost;
}
