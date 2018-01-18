#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <cmath>
#define CLR(x,y) memset(x,y,sizeof(x))
#define eps 1e-9
#define INF 0x3fffffff


using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

template<class T>
inline bool read(T &n)
{
    T x = 0, tmp = 1; char c = getchar();
    while((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();
    if(c == EOF) return false;
    if(c == '-') c = getchar(), tmp = -1;
    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c = getchar();
    n = x*tmp;
    return true;
}
template <class T>
inline void write(T n)
{
    if(n < 0)
    {
        putchar('-');
        n = -n;
    }
    int len = 0,data[20];
    while(n)
    {
        data[len++] = n%10;
        n /= 10;
    }
    if(!len) data[len++] = 0;
    while(len--) putchar(data[len]+48);
}
//-----------------------------------

const int maxn = 1000 + 10;

struct Edge {
    int from;
    int to;
    int cap;
    int flow;
}edge[2*maxn];
vector<int> G[maxn];
int head[maxn];
int cur[maxn];
bool used[maxn];
int deep[maxn];
int front[maxn];
int gap[maxn];
int cnt;
int N;
int M;

void addEdge(int from, int to, int cap)
{
    edge[cnt].from = from;
    edge[cnt].to = to;
    edge[cnt].cap = cap;
    edge[cnt].flow = 0;
    cnt ++;

    edge[cnt].from = to;
    edge[cnt].to = from;
    edge[cnt].cap = 0;
    edge[cnt].flow = 0;
    cnt ++;

    G[from].push_back(cnt-2);
    G[to].push_back(cnt-1);
}

bool BFS(int s, int t)
{
    memset(used,0,sizeof(used));
    queue<int> Q;
    Q.push(t);
    deep[t] = 0;
    used[t] = true;
    while(!Q.empty())
    {
        int top = Q.front();
        Q.pop();
        int i;
        for(i=0; i<G[top].size(); i++)
        {
            Edge e = edge[G[top][i]];
            if(!used[e.to])
            {
                used[e.to] = true;
                deep[e.to] = deep[top] + 1;
                Q.push(e.to);
            }
        }
    }
    return used[s];
}

int Augment(int s,int t)
{
    int begin = t;
    int minFlow = INF;
    while(begin != s)
    {
        Edge& e = edge[front[begin]];
        minFlow = min(minFlow, e.cap-e.flow);
        begin = edge[front[begin]].from;
    }
    begin = t;
    while(begin != s)
    {
        edge[front[begin]].flow += minFlow;
        edge[front[begin]^1].flow -= minFlow;
        begin = edge[front[begin]].from;
    }
    return minFlow;
}

int Maxflow(int s,int t)
{
    int flow = 0;
    BFS(s,t);
    memset(gap,0,sizeof(gap));
    memset(cur,0,sizeof(cur));
    int i;
    for(i=0; i<=N; i++)
    {
        gap[deep[i]] ++;
    }
    int begin = s;
    while(deep[s] < N)
    {
        if(begin == t)
        {
            flow += Augment(s,t);
            begin = s;
        }
        bool ok = false;
        int i;
        for(i=cur[begin]; i<G[begin].size(); i++)
        {
            Edge& e = edge[G[begin][i]];
            if(e.cap > e.flow && deep[begin] == deep[e.to] + 1)
            {
                ok = true;
                front[e.to] = G[begin][i];
                cur[begin] = i;
                begin = e.to;
                break;
            }
        }
        if(!ok)
        {
            int m = N - 1;
            int i;
            for(i=0; i<G[begin].size(); i++)
            {
                Edge& e = edge[G[begin][i]];
                if(e.cap > e.flow)
                {
                    m = min(m, deep[e.to]);
                }
            }
            if(--gap[deep[begin]] == 0)
            {
                break;
            }
            gap[deep[begin] = m+1] ++;
            cur[begin] = 0;
            if(begin != s)
            {
                begin = edge[front[begin]].from;
            }
        }
    }
    return flow;
}
int main()
{
    int cas=1;
    int T;
    read(T);
    while(T--)
    {
        read(N),read(M);
        for(int i=0;i<=N;i++)
            G[i].clear();
        cnt=0;
        CLR(deep,0);
        while(M--)
        {
            int b1, b2, fp;
            read(b1), read(b2),read(fp);
            addEdge(b1, b2, fp);
        }
        int flow = Maxflow(1,N);
        printf("Case %d: %d\n", cas++,flow);

    }
    return 0;
}

