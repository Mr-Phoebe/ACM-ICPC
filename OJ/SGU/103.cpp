#include <bits/stdc++.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
#define rep(i,initial_n,end_n) for(int (i)=(initial_n);(i)<(end_n);i++)
#define repp(i,initial_n,end_n) for(int (i)=(initial_n);(i)<=(end_n);(i)++)
#define reep(i,initial_n,end_n) for((i)=(initial_n);(i)<(end_n);i++)
#define reepp(i,initial_n,end_n) for((i)=(initial_n);(i)<=(end_n);(i)++)
#define eps 1.0e-9
#define MAX_N 500

using namespace std;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef long long ll;
typedef unsigned long long ull;

int n, m, pre[310], src, dest, t[310][2], ini[310], dis[310], init[310];
vector<pii> edge[310];

void spfa();
int check(int i, int now);
int next(int i, int now);

int main()
{
    scanf("%d%d", &src, &dest);
    scanf("%d%d", &n, &m);
    repp(i, 1, n)
    {
        char c[5];
        scanf("%s%d%d%d", c, &ini[i], &t[i][0], &t[i][1]);
        if(c[0] == 'B') init[i] = 0;
        else init[i] = 1;
    }
    int one, two, cost;
    rep(i, 0, m)
    {
        scanf("%d%d%d", &one, &two, &cost);
        edge[one].push_back(make_pair(two, cost));
        edge[two].push_back(make_pair(one, cost));
    }
    spfa();
    if(dis[dest] == INT_MAX)
    {
        puts("0");
        exit(0);
    }
    printf("%d\n", dis[dest]);
    stack<int> s;
    s.push(dest);
    while(pre[dest] != -1) s.push(pre[dest]), dest = pre[dest];
    while(1)
    {
        printf("%d", s.top());
        s.pop();
        if(s.empty())
        {
            puts("");
            break;
        }
        else putchar(' ');
    }
    return 0;
}

int check(int i, int now)
{
    if(now < ini[i]) return init[i];
    else
    {
        now = (now - ini[i]) % (t[i][0] + t[i][1]);
        if(now < t[i][1 - init[i]]) return 1 - init[i];
        else return init[i];
    }
}

int next(int i, int now)
{
    if(now < ini[i]) return ini[i] - now;
    else
    {
        now = (now - ini[i]) % (t[i][0] + t[i][1]);
        if(now < t[i][1 - init[i]]) return t[i][1 - init[i]] - now;
        else return t[i][0] + t[i][1] - now;
    }
}

void spfa()
{
    fill(dis, dis + n + 1, INT_MAX);
    dis[src] = 0, pre[src] = -1;
    queue<int> q;
    q.push(src);
    while(!q.empty())
    {
        int tmp = q.front(), len = edge[tmp].size();
        q.pop();
        rep(i, 0, len)
        {
            int tmpp = edge[tmp][i].first, tmp_dis;
            int  s1 = check(tmp, dis[tmp]), s2 = check(tmpp, dis[tmp]);
            tmp_dis = dis[tmp] + edge[tmp][i].second;
            if(s1 != s2)
            {
                int t1 = next(tmp, dis[tmp]), t2 = next(tmpp, dis[tmp]), t3, t4;
                tmp_dis += min(t1, t2);
                if(t1 == t2)
                {
                    t3 = next(tmp, dis[tmp] +t1), t4 = next(tmpp, dis[tmp] + t1);
                    if(t3 == t4) tmp_dis = INT_MAX;
                    else tmp_dis += min(t3, t4);
                }
            }
            if(tmp_dis < dis[tmpp])
            {
                pre[tmpp] = tmp;
                dis[tmpp] = tmp_dis;
                q.push(tmpp);
            }
        }
    }
}
