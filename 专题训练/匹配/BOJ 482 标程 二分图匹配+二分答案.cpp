#include<functional>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<numeric>
#include<cstring>
#include<climits>
#include<cassert>
#include<cstdio>
#include<string>
#include<vector>
#include<bitset>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<list>
#include<set>
#include<map>
#define delta 1e-8
using namespace std;

struct Point
{
    double x,y;
} P1[60], P2[60];

double dis(Point a, Point b)
{
    double x = a.x - b.x, y = a.y - b.y;
    return sqrt(x*x + y*y);
}

vector<int> G[2504];
int n, m;
double t1, t2, v;
bool vis[60];
int Link[60];

bool Find(int x)
{
    for(int i = 0; i < G[x].size(); i++)
    {
        int y = G[x][i];
        if(!vis[y])
        {
            vis[y] = 1;
            if(!Link[y] || Find(Link[y]))
            {
                Link[y] = x;
                return 1;
            }
        }
    }
    return 0;
}

bool Check(double x)
{
    int tot = 0;
    for(int i = 1; i <= n; i++)
    {
        double t = x;
        for(int j = 1; j <= m && t >= t1; j++)
        {
            tot++;
            for(int k = 1; k <= m; k++)
                if(dis(P1[i], P2[k])/v + t1 <= t + delta)
                    G[tot].push_back(k);
            if(G[tot].empty())
            {
                tot--;
                break;
            }
            t -= t2 + t1;
        }
    }
    int Ans = 0;
    memset(Link, 0, sizeof(Link));
    for(int i = 1; i <= tot; i++)
    {
        memset(vis, 0, sizeof(vis));
        if(Find(i)) Ans++;
        if(Ans == m)
        {
            for(int i = 1; i <= tot; i++) G[i].clear();
            return 1;
        }
    }
    for(int i = 1; i <= tot; i++) G[i].clear();
    return 0;
}

int main(int argc, char *argv[])
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d%d%lf%lf%lf", &n, &m, &t1, &t2, &v) != EOF)
    {
        t1 /= 60;
        for(int i = 1; i <= m; i++) scanf("%lf%lf", &P2[i].x, &P2[i].y);
        for(int i = 1; i <= n; i++) scanf("%lf%lf", &P1[i].x, &P1[i].y);
        double l=0,r=200000;
        while(r-l>delta)
        {
            double m = (l+r)/2;
            if(Check(m)) r=m;
            else l=m;
        }
        printf("%.6lf\n", l);
    }
    return 0;
}
