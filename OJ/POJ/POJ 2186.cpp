#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
 
const int N = 10005;
const int M = 50005;
 
struct Edge
{
    int v;
    int next;
};
 
int head[N];
Edge edge[M];
int n, m;
int cnt_edge;
 
void add_edge(int u, int v)
{   
    edge[cnt_edge].next = head[u];
    edge[cnt_edge].v = v;
    head[u] = cnt_edge++;
}
 
int scc_head[N];
Edge scc_edge[N];
int cnt_scc_edge;
 
void add_edge2(int u, int v)
{
    scc_edge[cnt_scc_edge].next = scc_head[u];
    scc_edge[cnt_scc_edge].v = v;
    scc_head[u] = cnt_scc_edge++;
}
 
int cnt_scc_node;
int Stack[N];
int low[N], dfn[N], outdegree[N];
int Index,top;
bool in_stack[N];
int belong[N];
int scc_node_size[N];
 
void tarjan(int u)
{
    dfn[u] = low[u] = ++Index;
    Stack[top++] = u;
    in_stack[u] = true;
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (in_stack[v])
            low[u] = min(low[u], dfn[v]);
    }
 
    if (dfn[u] == low[u])
    {   
        int j;
        do{
            j = Stack[--top];
            in_stack[j] = false;
            scc_node_size[cnt_scc_node]++;
            belong[j] = cnt_scc_node;
        }while (u != j);
        cnt_scc_node++; 
    }
}
 
int main()
{
    int a, b;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        cnt_edge = 0;
        memset(head, -1, sizeof(head));
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &a, &b);
            add_edge(a, b);
        }
 
        memset(dfn, 0, sizeof(dfn));
        memset(in_stack, false, sizeof(in_stack));
        Index = 0;
        cnt_scc_node = 0;
        top = 0;
 
        memset(scc_node_size, 0, sizeof(scc_node_size));
        for (int i = 1; i <= n; i++)
            if (!dfn[i])
                tarjan(i);
 
        //重新构图，求出度为0的点
        memset(scc_head, -1, sizeof(scc_head));
        cnt_scc_edge = 0;
 
        for (int i = 1; i <= n; i++)
            for (int j = head[i]; j != -1 ; j = edge[j].next)
            {
                int v = edge[j].v;
                if (belong[i] != belong[v])
                    add_edge2(belong[i], belong[v]);
            }
 
        memset(outdegree, 0, sizeof(outdegree));
        for (int i = 0; i < cnt_scc_node; i++)
            for (int j = scc_head[i]; j != -1; j = scc_edge[j].next)                    
                outdegree[i]++;
 
        int ans = 0;
        int ans_count = 0;
        for (int i = 0; i < cnt_scc_node; i++)
            if (outdegree[i] == 0)
            {
                ans = scc_node_size[i];
                ans_count++;
            }
 
        if (ans_count == 1)
            printf("%d\n", ans);
        else
            printf("0\n");
    }
    return 0;
}