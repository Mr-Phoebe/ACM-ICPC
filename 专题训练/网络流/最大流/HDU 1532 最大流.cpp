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
#define INF 0x3f3f3f3f

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
    T x = 0, tmp = 1;
    char c = getchar();
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

const int MAXN=222;

int cur[MAXN], head[MAXN], aug[MAXN], pre[MAXN], gap[MAXN], dis[MAXN];
int n,m;


struct Edge
{
    int u, v, next, cap;
    Edge () { }
    Edge (int u, int v, int next, int cap) : u(u), v(v), next(next), cap(cap) { }
} e[MAXN*2];
int tot;


void init()
{
    tot = 0;
    memset(head, -1, sizeof(head));
}

void add_edge(int u, int v, int cap)
{
    e[tot] = Edge(u, v, head[u], cap);
    head[u] = tot++;
    e[tot] = Edge(v, u, head[v], 0);
    head[v] = tot++;
}

int ISAP(int s, int sink, int n)
{
    aug[s] = INF;
    pre[s] = -1;
    memset(dis, 0, sizeof(dis));
    memset(gap, 0, sizeof(gap));
    gap[0] = n;
    memcpy(cur, head, sizeof(head));
    int max_flow = 0, u = s;
    while(dis[s] < n)
    {
        bool flag = false;
        if(u == sink)
        {
            max_flow += aug[sink];
            for(int v = pre[sink]; v != -1; v = pre[v])
            {
                int k = cur[v];
                e[k].cap -= aug[sink];
                e[k ^ 1].cap += aug[sink];
                aug[v] -= aug[sink];
                if(e[k].cap == 0) u = v;
            }
        }


        for(int k = cur[u]; k != -1; k = e[k].next)
        {
            int v = e[k].v;
            if(e[k].cap > 0 && dis[u] == dis[v] + 1)
            {
                flag = true;
                pre[v] = u;
                cur[u] = k;
                aug[v] = min(aug[u], e[k].cap);
                u = v;
                break;
            }
        }
        if(!flag)
        {
            if(--gap[dis[u]] == 0) break;       /* gap优化，层次树出现断层则结束算法 */
            int mindis = n;
            cur[u] = head[u];
            for(int k = head[u]; k != -1; k = e[k].next)
            {
                int v = e[k].v;
                if(e[k].cap > 0 && dis[v] < mindis)
                {
                    mindis = dis[v];
                    cur[u] = k;
                }
            }
            dis[u] = mindis + 1;
            gap[dis[u]]++;
            if(u != s) u = pre[u];
        }
    }
    return max_flow;
}

int main()
{
    while(read(n)&&read(m))
    {
        init();
        int u,v,w;
        for(int i=1;i<=n;i++)
        {
            read(u),read(v),read(w);
            add_edge(u,v,w);
        }
        printf("%d\n",ISAP(1,m,m));
    }
    return 0;
}
