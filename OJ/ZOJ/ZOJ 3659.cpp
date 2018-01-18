#include <bits/stdc++.h>

using namespace std;

int p[200010], num[200010];
long long sum[200010];

int find(int x)
{
    return p[x] == x ? x : p[x] = find(p[x]);
}

struct edge
{
    int u, v, cost;
    friend bool operator < (edge a, edge b)
    {
        return a.cost > b.cost;
    }
};

edge v[200010];

int main()
{
    int n;
    while(scanf("%d", &n) > 0)
    {
        for(int i = 0; i < n-1; i++)
            scanf("%d%d%d", &v[i].u, &v[i].v, &v[i].cost);
        sort(v, v+n-1);
        for(int i = 1; i <= n; i++)
            p[i] = i, sum[i] = 0, num[i] = 1;
        for(int i = 0; i < n-1; i++)
        {
            int uf = find(v[i].u), vf = find(v[i].v);
            if(sum[uf] + (long long)v[i].cost*num[vf] > sum[vf] + (long long)v[i].cost*num[uf])
                sum[uf] += (long long)v[i].cost*num[vf], num[uf] += num[vf], p[vf] = uf;
            else
                sum[vf] += (long long)v[i].cost*num[uf], num[vf] += num[uf], p[uf] = vf;
        }
        printf("%I64d\n", sum[find(1)]);
    }
    return 0;
}
