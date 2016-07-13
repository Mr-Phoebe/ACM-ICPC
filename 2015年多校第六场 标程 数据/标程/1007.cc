#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
const int MAXN = 400000 + 10, MAXM = MAXN << 3;

struct Edge {
  int v, nx;
} E[MAXM];

int G[MAXN], pred[MAXN], succ[MAXN], mp[MAXN];
int esz, n, m;
char ret[MAXN];

void addedge(int u, int v, int g[]) {
  E[esz].v = v; E[esz].nx = g[u]; g[u] = esz ++;
}

struct Tarjan {
  int low[MAXN], dfn[MAXN], stk[MAXN];
  int col[MAXN], cnt[MAXN], scc[MAXN];
  int scc_cnt, sz, top;
  void dfs(int x, const int G[]) {
    low[x] = dfn[x] = ++ sz; stk[++ top] = x;
    for (int it(G[x]),y; ~it; it = E[it].nx) {
      if (!dfn[y = E[it].v]) {
        dfs(y, G);
        low[x] = min(low[x], low[y]);
      }
      else if (col[y] == -1) low[x] = min(low[x], dfn[y]);
    }
    if (dfn[x] == low[x]) {
      cnt[scc_cnt] = scc_cnt ? cnt[scc_cnt - 1] : 0;
      do {
        scc[cnt[scc_cnt] ++] = stk[top];
        col[stk[top]] = scc_cnt;
      } while (stk[top --] != x);
      ++ scc_cnt;
    }
  }
  int solve(int n, const int G[]) {
    sz = top = scc_cnt = 0;
    memset(dfn, 0, sizeof(dfn[0]) * n);
    memset(col, -1, sizeof(col[0]) * n);
    for (int i = 0; i < n; ++ i) {
      if (!dfn[i]) dfs(i, G);
    }
    return scc_cnt;
  }
} SCC;

struct DominatorTree {
  int dom[MAXN], dfn[MAXN], pre[MAXN], pt[MAXN], sz;
  int semi[MAXN], dsu[MAXN], idom[MAXN], best[MAXN];
  int get(int x) {
    if (x == dsu[x]) return x;
    int y = get(dsu[x]);
    if (semi[best[x]] > semi[best[dsu[x]]]) best[x] = best[dsu[x]];
    return dsu[x] = y;
  }
  void dfs(int u, const int succ[]) {
    dfn[u] = sz; pt[sz ++] = u;
    for (int it = succ[u], v; ~it; it = E[it].nx) {
      if (dfn[v = E[it].v] == -1) {
        dfs(v, succ); pre[dfn[v]] = dfn[u];
      }
    }
  }
  void tarjan(const int pred[]) {
    for (int j = sz - 1, u; u = pt[j], j > 0; -- j) {
      for (int it = pred[u]; ~it; it = E[it].nx) {
        int v = dfn[E[it].v]; get(v);
        if (semi[best[v]] < semi[j]) semi[j] = semi[best[v]];
      }
      addedge(semi[j], j, dom);
      int x = dsu[j] = pre[j];
      for (int it = dom[x], z; ~it; it = E[it].nx) {
        get(z = E[it].v);
        if (semi[best[z]] < x) idom[z] = best[z];
        else idom[z] = x;
      }
      dom[x] = -1;
    }
    for (int i = 1; i < sz; ++ i) {
      if (semi[i] != idom[i]) idom[i] = idom[idom[i]];
      addedge(idom[i], i, dom);
    }
  }
  VI build(int n, int s, const int succ[], const int pred[]) {
    for (int i = 0; i < n; ++ i) {
      dfn[i] = dom[i] = -1;
      dsu[i] = best[i] = semi[i] = i;
    }
    sz = 0; dfs(s, succ); tarjan(pred);
    VI ret; assert(sz == n);
    for (int i = 1; i < n; ++ i) {
      if (dom[i] != -1) ret.push_back(pt[i]);
    }
    return ret;
  }
} dom;


void solve() {
  for (int _ = 0; _ < SCC.scc_cnt; ++ _) {
    int tmp_esz = esz, src(-1);
    int l = _ ? SCC.cnt[_ - 1] : 0, r = SCC.cnt[_];
    if (l + 1 == r) continue;
    memset(pred, -1, sizeof(pred[0]) * (r - l));
    memset(succ, -1, sizeof(succ[0]) * (r - l));
    for (int i = l; i < r; ++ i) mp[SCC.scc[i]] = i - l;
    for (int i = l; i < r; ++ i) {
      int u = SCC.scc[i], v;
      if (u < ::n) src = mp[u];
      for (int it = G[u]; ~it; it = E[it].nx) {
        if (SCC.col[u] == SCC.col[v = E[it].v]) {
          int x = mp[u], y = mp[v];
          addedge(x, y, succ); addedge(y, x, pred);
        }
      }
    }
    assert(src != -1);
    VI nw = dom.build(r - l, src, succ, pred);
    for (size_t i = 0; i < nw.size(); ++ i) {
      int u = SCC.scc[l + nw[i]];
      if (u >= n) ret[u - n] = '1';
    }
    nw = dom.build(r - l, src, pred, succ);
    for (size_t i = 0; i < nw.size(); ++ i) {
      int u = SCC.scc[l + nw[i]];
      if (u >= n) ret[u - n] = '1';
    }
    esz = tmp_esz;
  }
}

int main() {
  /*int size=64<<20;
  char *p=(char*)std::malloc(size)+size;
  __asm__("movl %0, %%esp\n"::"r"(p));*/
  int T; scanf("%d", &T);
  for (int cas = 0; cas < T; ++ cas) {
    scanf("%d%d", &n, &m); esz = 0;
    memset(G, -1, sizeof(G[0]) * (n + m));
    for (int i = 0; i < m; ++ i) {
      int u, v; scanf("%d%d", &u, &v);
      ret[i] = '0';
      addedge(u - 1, n + i, G);
      addedge(n + i, v - 1, G);
    }
    SCC.solve(n + m, G);
    solve();
    ret[m] = 0; puts(ret);
  }
  return 0;
}