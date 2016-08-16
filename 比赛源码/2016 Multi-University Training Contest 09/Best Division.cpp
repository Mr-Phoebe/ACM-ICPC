#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)((x).size())

typedef long long LL;

inline void chkmax(int &x, int y) {
  if (x < y) x = y;
}

const int MAXN = 111111;
const int MAXM = 2800000;

int chd[MAXM][2], ptr[MAXM];
vector<int> V[MAXM];

int s[MAXN], a[MAXN], dp[MAXN];
int m;

int add_node() {
  chd[m][0] = chd[m][1] = -1;
  ptr[m] = 0;
  return m++;
}

void add(int x, int i) {
  int u = 0;
  for (int j = 27; j >= -1; j--) {
    while (V[u].size() > ptr[u] && dp[V[u].back()] <= dp[i]) {
      V[u].pop_back();
    }
    V[u].push_back(i);
    if (j < 0) {
      return;
    }
    int c = x>>j&1;
    if (!~chd[u][c]) {
      chd[u][c] = add_node();
    }
    u = chd[u][c];
  }
}

int get(int y, int x, int l) {
  int u = 0, ret = 0;
  for (int j = 27; j >= 0; j--) {
    int a = x>>j&1, b = y>>j&1;
    if (a) {
      if (~chd[u][b]) {
        int v = chd[u][b];
        for (int &k = ptr[v]; k < sz(V[v]) && V[v][k] < l; k++);
        if (ptr[v] < sz(V[v])) {
          chkmax(ret, 1+dp[V[v][ptr[v]]]);
        }
      }
    }
    u = chd[u][b^a];
    if (u == -1) {
      return ret;
    }
  }
  return ret;
}

int main() {
//  freopen("data1.in", "r", stdin);
//  freopen("data1.out", "w", stdout);

  int ncase;
  for (scanf("%d", &ncase); ncase--; ) {
    int n, X, L, p, q; scanf("%d%d%d%d%d%d", &n, &X, &L, &a[1], &p, &q), X++;
    for (int i = 2; i <= n; i++) {
      a[i] = ((LL)a[i-1]*p+q) & 268435455;
    }
    for (int i = 1; i <= n; i++) {
      s[i] = s[i-1] ^ a[i];
    }
    m = dp[0] = 0;
    add_node();
    add(0, 0);
    for (int i = 1; i <= n; i++) {
      dp[i] = get(s[i], X, i-L);
      if (dp[i] > 0) {
        add(s[i], i);
      }
    }
    for (int i = 0; i < m; i++) {
      V[i].clear();
    }
    printf("%d\n", dp[n]);
  }
	return 0;
}

