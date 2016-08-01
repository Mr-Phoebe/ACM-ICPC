#include <bits/stdc++.h>
#define max(a,b) ((a)>(b))?(a):(b)
#define min(a,b) ((a)>(b))?(b):(a)
#define rep(i,initial_n,end_n) for(int (i)=(initial_n);(i)<(end_n);i++)
#define repp(i,initial_n,end_n) for(int (i)=(initial_n);(i)<=(end_n);(i)++)
#define eps 1.0E-8
#define MAX_N 1010
#define INF 1 << 30
using namespace std;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef long long ll;
typedef unsigned long long ull;

bool ok[110] = { false };
int color[101][101] = { { 0 } }, vis[110] = { 0 }, n;
vector<int> v[101];

void dfs(int now);
bool check();

int main()
{
    int tmp;
    scanf("%d", &n);
    repp(i, 1, n)
    while(scanf("%d", &tmp) && tmp) v[i].push_back(tmp);
    repp(i, 1, n) if(v[i].size() <= 1) ok[i] = true;
    repp(i, 1, n)
    if(!vis[i] && v[i].size() >= 3) dfs(i);
    repp(i, 1, n)
    if(!vis[i] && v[i].size() == 2) dfs(i);
    repp(i, 1, n) if(!vis[i]) dfs(i);
    if(!check())
    {
        puts("No solution");
        exit(0);
    }
    repp(i, 1, n)
    {
        int len = v[i].size();
        rep(j, 0, len)
        printf("%d ", color[i][v[i][j]]);
        puts("0");
    }
    return 0;
}

void dfs(int now)
{
    int to, len = v[now].size();
    rep(i, 0, len)
    {
        to = v[now][i];
        if(color[now][to]) continue;
        if(!vis[now])
        {
            color[now][to] = color[to][now] = 1;
            vis[now] = vis[to] = 1;
            dfs(to);
        }
        else if(vis[now] == 1)
        {
            ok[now] = true;
            color[now][to] = color[to][now] = 2;
            vis[now] = vis[to] = 2;
            dfs(to);
        }
        else
        {
            ok[now] = true;
            color[now][to] = color[to][now] = 1;
            vis[now] = vis[to] = 1;
            dfs(to);
        }
    }
}

bool check()
{
    repp(i, 1, n) if(!ok[i]) return false;
    return true;
}
