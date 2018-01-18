#include <cstdio>
#include <queue>
#include <cassert>
using namespace std;
typedef long long ll;

const ll mod = 1000000007;
ll dp[510][510];
ll f[510];
int cnt;
struct node {
    int sz, lch, rch, par;
    node(int sz=0, int lch=0, int rch=0, int par=0) :
        sz(sz), lch(lch), rch(rch), par(par) {}
} T[510];

int newnode(int s, int l, int r, int p) {
    ++cnt;
    T[cnt] = node(s, l, r, p);
    return cnt;
}

queue<int> q;
int node_cnt, tree_cnt;

void dfs(int u) {
    node_cnt--;
    if (T[u].lch) {
        if (T[T[u].lch].sz > 0) q.push(T[u].lch);
        else dfs(T[u].lch);
    }
    else tree_cnt++;

    if (T[u].rch) {
        if (T[T[u].rch].sz > 0) q.push(T[u].rch);
        else dfs(T[u].rch);
    }
    else tree_cnt++;
}

ll solve(int root) {
    ll ans = 1;
    q.push(root);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        node_cnt = T[u].sz;
        tree_cnt = 0;
        dfs(u);
        ans = ans * dp[tree_cnt][node_cnt] % mod;
    }
    return ans;
}

void prework() {
    f[0] = 1;
    for (int i = 1; i <= 500; i++) {
        f[i] = 0;
        for (int j = 0; j < i; j++) {
            f[i] = (f[i] + f[j] * f[i-1-j]) % mod;
        }
    }
    dp[0][0] = 1;
    for (int j = 1; j <= 500; j++) dp[0][j] = 0;
    for (int i = 1; i <= 500; i++) {
        dp[i][0] = 0;
        for (int j = 0; j <= 500; j++) {
            for (int k = 0; k <= j; k++) {
                dp[i][j] = (dp[i][j] + dp[i-1][j-k] * f[k]) % mod;
            }
        }
    }
}
int main() {
    int n;
    prework();
    int root, cur, t, x, kase=0;
    while (~scanf("%d", &n)) {
        cnt = 0;
        cur = root = newnode(1, 0, 0, 0);
        while (n--) {
            scanf("%d", &t);
            if (t == 0) {
                assert(T[cur].par > 0);
                cur = T[cur].par;
            }
            else if (t == 1) {
                if (T[cur].lch == 0) {
                    T[cur].lch = newnode(0, 0, 0, cur);
                }
                cur = T[cur].lch;
            }
            else if (t == 2) {
                if (T[cur].rch == 0) {
                    T[cur].rch = newnode(0, 0, 0, cur);
                }
                cur = T[cur].rch;
            }
            else if (t == 3) {
                scanf("%d", &x);
                assert(T[cur].lch == 0);
                T[cur].lch = newnode(x, 0, 0, cur);
            }
            else if (t == 4) {
                scanf("%d", &x);
                assert(T[cur].rch == 0);
                T[cur].rch = newnode(x, 0, 0, cur);
            }
            else {
                assert(0);
            }
        }
        printf("Case #%d: %lld\n", ++kase, solve(root));
    }

    return 0;
}
