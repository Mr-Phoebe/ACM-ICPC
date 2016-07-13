#define MAXN 200005
#define N 5005
#define inf 1.0e20
#define eps 1.0e-8
#define MOD 1000000007
 
#define For(i,m,n) for(int i=(m);i<(n);i++)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define rep(i,m,n) for(int i=(m);i<=(n);i++)
#define repd(i,m,n) for(int i=(m);i>=(n);i--)
#define LL long long
 
using namespace std;
const LL INF=300000000000000000;
LL dis[MAXN];
 
struct Edge{
    int fw;
    int to;
    LL cost;
    LL s;
}g[MAXN];
int tot;
struct ed{
    int to;
    LL cost;
    ed(int to, LL cost): to(to),cost(cost) {}
};
vector<ed> gg[N];
typedef pair<LL,int> pli;
 
void add_edge(Edge *g, int x, int y, LL c, LL s, int &tot)
{
    g[tot].fw=x; g[tot].to=y; g[tot].cost=c; g[tot].s=s; tot++;
}
 
bool cmp(const Edge &a, const Edge &b)
{
    if(a.s==b.s) return a.cost<b.cost;
    else return a.s<b.s;
}
 
struct DisjointSet{
    std::vector<int> father,rank;
    DisjointSet(int n):father(n+5),rank(n+5){
        rep(i,1,n){
            father[i]=i;
            rank[i]=0;
        }
    }
    int find(int v){
        return father[v]=father[v]==v?v:find(father[v]);
    }
    void merge(int x,int y){
        int a=find(x),b=find(y);
        if(rank[a]<rank[b]){
            father[a]=b;
        }
        else{
            father[b]=a;
            if(rank[b]==rank[a]){
                ++rank[a];
            }
        }
    }
    void clear(int n){
        rep(i,1,n){
            father[i]=i;
            rank[i]=0;
        }
    }
};
 
LL dijkstra(int n, int src, int des)
{
    priority_queue<pli,vector<pli>,greater<pli> > que;
    while(!que.empty()) que.pop();
    fill(dis+1,dis+n+1,INF);
    dis[src]=0LL;
    que.push(pli(0LL,src));
    while(!que.empty()){
        pli p=que.top(); que.pop();
        int now=p.second;
        if(dis[now]<p.first) continue;
        int sz=gg[now].size();
        for(int i=0;i<sz;i++){
            ed e=gg[now][i];
            if(dis[e.to]>dis[now]+e.cost){
                dis[e.to]=dis[now]+e.cost;
                que.push(pli(dis[e.to],e.to));
            }
        }
    }
    return dis[des];
}
 
LL solve(DisjointSet &D, int src, int des, int n)
{
    For(i,0,tot){
        int a=g[i].fw, b=g[i].to;
        LL cc=g[i].cost;
        D.merge(a,b);
        gg[a].push_back(ed(b,cc));
        gg[b].push_back(ed(a,cc));
        if(D.find(src)==D.find(des)){
            LL ans=g[i].s;
            i++;
            while(i<tot&&g[i].s==ans){
                a=g[i].fw, b=g[i].to;
                cc=g[i].cost;
                gg[a].push_back(ed(b,cc));
                gg[b].push_back(ed(a,cc));
                i++;
            }
            return ans;
        }
    }
    return g[tot-1].s;
}
 
int main()
{
    int t, n, m;
    int x, y, q;
    LL c, s;
    DisjointSet D(N);
    while(scanf("%d%d%d",&n,&m,&q),n||m||q){
        tot=0;
        For(i,0,m){
            scanf("%d%d%lld%lld",&x,&y,&c,&s);
            add_edge(g,x,y,c,s,tot);
        }
        sort(g,g+tot,cmp);
        while(q--){
            D.clear(n);
            rep(i,1,n) gg[i].clear();
            scanf("%d%d",&x,&y);
            LL ans=solve(D,x,y,n);
            printf("%lld %lld\n",dijkstra(n,x,y),ans);
        }
    }
    return 0;
}
