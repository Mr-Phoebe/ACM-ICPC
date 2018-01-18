/*
ID: CUGB-wwj
PROG:
LANG: C++
*/
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#define INF 1111111111
#define MAXN 100005
#define MAXM 444444
#define PI acos(-1.0)
using namespace std;
struct node
{
    int ver;    // vertex
    int cap;    // capacity
    int flow;   // current flow in this arc
    int next, rev;
}edge[MAXM];
int dist[MAXN], numbs[MAXN], src, des, n;
int head[MAXN], e;
void add(int x, int y, int c)
{       //e记录边的总数
    edge[e].ver = y;
    edge[e].cap = c;
    edge[e].flow = 0;
    edge[e].rev = e + 1;        //反向边在edge中的下标位置
    edge[e].next = head[x];   //记录以x为起点的上一条边在edge中的下标位置
    head[x] = e++;           //以x为起点的边的位置
    //反向边
    edge[e].ver = x;
    edge[e].cap = 0;  //反向边的初始网络流为0
    edge[e].flow = 0;
    edge[e].rev = e - 1;
    edge[e].next = head[y];
    head[y] = e++;
}
void rev_BFS()
{
    int Q[MAXN], qhead = 0, qtail = 0;
    for(int i = 1; i <= n; ++i)
    {
        dist[i] = MAXN;
        numbs[i] = 0;
    }
    Q[qtail++] = des;
    dist[des] = 0;
    numbs[0] = 1;
    while(qhead != qtail)
    {
        int v = Q[qhead++];
        for(int i = head[v]; i != -1; i = edge[i].next)
        {
            if(edge[edge[i].rev].cap == 0 || dist[edge[i].ver] < MAXN)continue;
            dist[edge[i].ver] = dist[v] + 1;
            ++numbs[dist[edge[i].ver]];
            Q[qtail++] = edge[i].ver;
        }
    }
}
void init()
{
    e = 0;
    memset(head, -1, sizeof(head));
}
int maxflow()
{
    int u, totalflow = 0;
    int Curhead[MAXN], revpath[MAXN];
    for(int i = 1; i <= n; ++i)Curhead[i] = head[i];
    u = src;
    while(dist[src] < n)
    {
        if(u == des)     // find an augmenting path
        {
            int augflow = INF;
            for(int i = src; i != des; i = edge[Curhead[i]].ver)
                augflow = min(augflow, edge[Curhead[i]].cap);
            for(int i = src; i != des; i = edge[Curhead[i]].ver)
            {
                edge[Curhead[i]].cap -= augflow;
                edge[edge[Curhead[i]].rev].cap += augflow;
                edge[Curhead[i]].flow += augflow;
                edge[edge[Curhead[i]].rev].flow -= augflow;
            }
            totalflow += augflow;
            u = src;
        }
        int i;
        for(i = Curhead[u]; i != -1; i = edge[i].next)
            if(edge[i].cap > 0 && dist[u] == dist[edge[i].ver] + 1)break;
        if(i != -1)     // find an admissible arc, then Advance
        {
            Curhead[u] = i;
            revpath[edge[i].ver] = edge[i].rev;
            u = edge[i].ver;
        }
        else        // no admissible arc, then relabel this vertex
        {
            if(0 == (--numbs[dist[u]]))break;    // GAP cut, Important!
            Curhead[u] = head[u];
            int mindist = n;
            for(int j = head[u]; j != -1; j = edge[j].next)
                if(edge[j].cap > 0)mindist = min(mindist, dist[edge[j].ver]);
            dist[u] = mindist + 1;
            ++numbs[dist[u]];
            if(u != src)
                u = edge[revpath[u]].ver;    // Backtrack
        }
    }
    return totalflow;
}
int in()
{
    char ch;
    int a = 0;
    while((ch = getchar()) == ' ' || ch == '\n');
    a += ch - '0';
    while((ch = getchar()) != ' ' && ch != '\n')
    {
        a *= 10;
        a += ch - '0';
    }
    return a;
}
int peo[1111];
int val[55];
int main()
{
	freopen("data.txt","r",stdin);
    int num, m;
    int u, v;
    while(scanf("%d%d", &num, &m) != EOF)
    {
        init();
        memset(peo, 0, sizeof(peo));
        src = 1;
        des = 1 + (1 << m) + m + 1;
        n = des;
        for(int i = 0; i < num; i++)
        {
            int t = 0;
            for(int j = 0; j < m; j++)
            {
                u = in();
                if(u) t += (1 << j);
            }
            peo[t]++;
        }
        for(int i = 0; i < m; i++)
        {
            scanf("%d", &val[i]);
            add(i + (1 << m) + 2, des, val[i]);
        }
        for(int i = 0; i < (1 << m); i ++)
        {
            if(peo[i] == 0) continue;
            add(src, i + 2, peo[i]);
            for(int j = 0; j < m; j++)
            {
                int k = 1 << j;
                if(i & k) add(i + 2, j + (1 << m) + 2, INF);
            }
        }
        rev_BFS();
        int ans = maxflow();
        
        for(int i=0;i<=des;i++)
        {
            if(head[i]==-1)
                continue;
            printf("%d ->",i);
            for(int j=head[i];~j;j=edge[j].next)
                printf("%d(%d) ",edge[j].ver,edge[j].flow);
            putchar('\n');
        }
        cout<<src<<" "<<des<<" "<<ans<<endl;
        if(ans >= num) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}