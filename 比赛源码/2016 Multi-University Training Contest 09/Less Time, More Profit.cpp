#include <bits/stdc++.h>
using namespace std;

int n, m, p, E;

const int INF = 1e9;
const int MAXN = 555;
const int MAXM = 88888;

vector<int> adj[MAXN];
int y[MAXM], z[MAXM], nxt[MAXM];
int fst[MAXN], q[MAXN], a[MAXN], b[MAXN], t[MAXN], dis[MAXN], ptr[MAXN];

namespace dinic {
typedef long long F;

const int N = 555;
const int M = 111111;
const F INF = 1e9+1e8;

int fst[N], nxt[M], to[M];
F cap[M];
int dis[N], q[N], ptr[N];
int E;

void init() {
  memset(fst, -1, sizeof fst);
  E = 0;
}

inline void add(int u, int v, F c) {
  to[E] = v, cap[E] = c, nxt[E] = fst[u], fst[u] = E++;
  to[E] = u, cap[E] = 0, nxt[E] = fst[v], fst[v] = E++;
}

inline bool bfs(int S, int T, int n) {
  memset(dis, -1, sizeof(int) * n);
  int h = 0, t = 0;
  dis[S] = 0, q[t++] = S;
  while (h < t) {
    int u = q[h++];
    for (int e = fst[u]; ~e; e = nxt[e]) if (cap[e] > 0 && dis[to[e]] == -1) {
      dis[to[e]] = dis[u] + 1, q[t++] = to[e];
      if (to[e] == T) return 1;
    }
  }
  return (dis[T] != -1);
}

F dfs(int u, int T, F f) {
  if (u == T) return f;
  for (int &e = ptr[u]; ~e; e = nxt[e]) if (cap[e] > 0 && dis[to[e]] > dis[u]) {
    F ret = dfs(to[e], T, min(f, cap[e]));
    if (ret > 0) {
      cap[e] -= ret, cap[e ^ 1] += ret;
      return ret;
    }
  }
  return 0;
}

F dinic(int S, int T, int n) {
  F ret = 0;
  while (bfs(S, T, n)) {
    memcpy(ptr, fst, sizeof(int) * n);
    for (F cur; (cur = dfs(S, T, INF)) > 0; ret += cur);
  }
  return ret;
}
}

int solve(int x) {
  int S = 0, T = n+m+1;
  dinic::init();
  for (int i = 1; i <= n; i++) {
    if (t[i] <= x) {
      dinic::add(S, i, a[i]);
    } else {
      dinic::add(S, i, INF);
    }
    for (int j = 0; j < adj[i].size(); j++) {
      dinic::add(i, adj[i][j], INF);
    }
  }
  int ret = 0;
  for (int i = 1; i <= m; i++) {
    dinic::add(i+n, T, b[i]);
    ret += b[i];
  }
  long long temp = dinic::dinic(S, T, T+1);
  if (temp >= ret) {
    return 0;
  }
  return ret - temp;
}

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	
  int ncase, T = 0;
  for (scanf("%d", &ncase); ncase--; ) {
    printf("Case #%d: ", ++T);
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 1; i <= n; i++) {
      scanf("%d%d", &a[i], &t[i]), adj[i].clear();
    }
    for (int i = 1; i <= m; i++) {
      int c; scanf("%d%d", &b[i], &c);
      for (int j = 0; j < c; j++) {
        int k; scanf("%d", &k); adj[k].push_back(n+i);
      }
    }
    int lo = -1, hi = INF+1;
    while (hi - lo > 1) {
      int mid = lo + hi >> 1;
      if (solve(mid) >= p) {
        hi = mid;
      } else {
        lo = mid;
      }
    }
    if (hi > INF) {
      puts("impossible");
    } else {
      printf("%d %d\n", hi, solve(hi));
    }
  }
  return 0;
}
