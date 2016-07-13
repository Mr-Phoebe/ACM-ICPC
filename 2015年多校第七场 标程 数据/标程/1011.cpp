#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <stack>
#include <bitset>
#define INF 0x3f3f3f3f
#define eps 1e-8
#define FI first
#define SE second
using namespace std;
typedef long long LL;
const int mod = 1e9 + 7;
const int N = 100005;
int head[N];
struct Edge {
    int nxt, to;
} ed[N * 2];
int ecnt;

void addedge(int u, int v) {
    ed[ecnt].nxt = head[u];
    ed[ecnt].to = v;
    head[u] = ecnt++;
}

int fac[N];
int dp[N], sz[N], son[N];
bool dfs(int u, int fa) {
    sz[u] = 1;
    for(int e = head[u]; ~e; e = ed[e].nxt) {
        int v = ed[e].to;
        if(v == fa) continue;
        if(!dfs(v, u)) return 0;
        sz[u] += sz[v];
    }
    int c1 = 0, c2 = 0;
    for(int e = head[u]; ~e; e = ed[e].nxt) {
        int v = ed[e].to;
        if(v == fa) continue;
        if(sz[v] > 1) {
            son[c1++] = dp[v];
        }
        else {
            c2++;
        }
    }
    if(c1 > 2) return 0;
    if(c1 == 0) {
        dp[u] = fac[c2];
    }
    else if(c1 == 1) {
        dp[u] = 2LL * son[0] * fac[c2] % mod;
    }
    else {
        dp[u] = 2LL * son[0] * son[1] % mod * fac[c2] % mod;
    }
    return 1;
}

int main() {
    fac[0] = 1;
    for(int i = 1; i < N; ++i) {
        fac[i] = (LL)fac[i - 1] * i % mod;
    }
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas) {
        int n;
        scanf("%d", &n);
        memset(head, -1, (n + 3) * sizeof(int));
        ecnt = 0;
        for(int u, v, i = 1; i < n; ++i) {
            scanf("%d%d", &u, &v);
            addedge(u, v);
            addedge(v, u);
        }
        printf("Case #%d: ", cas);
        if(n == 1) {
            puts("1");
            continue;
        }
        if(dfs(1, 0)) {
            printf("%d\n", dp[1] * 2 % mod);
        }
        else {
            puts("0");
        }
    }
    return 0;
}
