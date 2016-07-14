#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX = 31;
const int MAXN = 1e6 + 5;
const int MAXM = MAX * MAXN;
int num[MAXM];
int ne[MAXM][2];
int cnt;
int n, k;

ll query(int x)
{
    int v = 0;
    ll ans = 0;

    auto getCnt = [](int v){return v == -1 ? 0 : num[v];};

    int cur = 0;
    for(int i = 30; i >=0; i--)
    {
        if (v == -1) break;
        int b = (x >> i) & 1;
        if((cur | (1 << i)) >= k)
        {
            ans += getCnt(ne[v][b ^ 1]);
            v = ne[v][b];
        }
        else
        {
            v = ne[v][b ^ 1];
            cur |= (1 << i);
        }
    }
    if (cur >= k) ans += getCnt(v);
    return ans;
}
void ins(int x)
{
    int u = 0;
    for(int i = 30 ; i >=0 ; i--)
    {
        int j = (x >> i) & 1;
        if(ne[u][j] == -1) ne[u][j] = ++cnt;
        u = ne[u][j];
        num[u]++;
    }
}
int main()
{
    while(scanf("%d%d", &n, &k) != EOF)
    {
        memset(num, 0, sizeof num);
        memset(ne, -1, sizeof ne);
        long long ans = 0;
        cnt = 0;
        int sum = 0;
        ins(0);
        for(int i = 0, u ; i < n ; i++)
        {
            scanf("%d", &u);
            sum ^= u;
            ans += query(sum);
            ins(sum);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
