#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
#include<queue>
#include<cstring>
#define INF 1000000000

using namespace std;

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

struct node
{
    int first, second;
};

vector<node> g[100010];
int dist[100010], n, m, k, cost[100010], step, src;
bool inque[100010];
queue<int>que;
vector<int> q;
int pre[100010];

void spfa();

int main()
{
    int nn;
    scanf("%d", &nn);
    while(nn--)
    {
        node tmp;
        int to, from;
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 1; i <= n; i++)
            scanf("%d", &cost[i]);
        tmp.first = 1, tmp.second = 0;
        g[0].push_back(tmp);
        for(int i = 1; i <= m; i++) {
            scanf("%d%d", &from, &to);
            tmp.first = to, tmp.second = cost[to];
            g[from].push_back(tmp);
            //printf("tmp.first = %d tmp. second = %d\n", tmp.first, tmp.second);
        }
        src = 1;
        pre[1] = -1;
        spfa();
        for(int i = 1; i <= n; i++) g[i].clear();
        if(dist[n] == INF) { puts("Doomed to lonely life."); continue;}
        int ii = n;
        stack<int> s;
        while(pre[ii]!= -1) { s.push(ii); ii = pre[ii];}
        s.push(1);
        step = 0;
        while(!s.empty()) {
            ii = s.top();
            s.pop();
            k-=cost[ii];
            if(k < 0) step++, k= -1;
        }

        if(step != 0) printf("What a pity! It's only %d step%s left.\n", step, step == 1 ? "" : "s");
        else puts("Girlfriend!");
    }
}


void spfa()
{
    fill(dist, dist + n +1, INF);
    memset(inque, 0 ,sizeof(inque));
    dist[src] = 0;
    while(!que.empty()) que.pop();
    que.push(src);
    inque[src] = true;
    while(!que.empty())
    {
        int u = que.front();
        que.pop();
        for(int i = 0; i < g[u].size(); i++)
        if(dist[u] + g[u][i].second < dist[g[u][i].first])
        {
            dist[g[u][i].first] = dist[u] +g[u][i].second;
            pre[g[u][i].first] = u;
            if(!inque[g[u][i].first])
            {
                inque[g[u][i].first] = true;
                que.push(g[u][i].first);
            }
        }
        inque[u] = false;
    }
}
