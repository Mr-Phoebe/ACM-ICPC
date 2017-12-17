#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10, MAXM = 1e5 + 10;
 
struct edge {
  int x, y, st, ed;
} e[MAXM << 2];

char ret[MAXM];
 
namespace dsu {
  int fa[MAXN], d[MAXN], a[MAXN];
  int s[MAXN << 4], top;
   
  int find(int x) {
    while (fa[x] != x) x = fa[x];
    return x;
  }
  int dep(int x) {
    static int res;
    for (res = 0; fa[x] != x; x = fa[x])
      res ^= a[x];
    return res;
  }
   
  void set_union(int x, int y, int _d) {
    if (d[x] > d[y]) swap(x, y);
    if (d[x] == d[y]) ++d[y], s[++top] = -y;
    fa[x] = y, a[x] = _d, s[++top] = x; 
  }
   
  void set_resume(int t) {
    for (; top != t; --top) {
      if (s[top] < 0) --d[-s[top]];
      else fa[s[top]] = s[top], a[s[top]] = 0;
    }
  }
}
using namespace dsu;
 
void work(int l, int r, int m) {
  int mid = l + r >> 1, now = top;
  int i, j, fx, fy, _d;
  for (i = 1; i <= m; ++i) {
    if (e[i].st <= l && r <= e[i].ed) {
      fx = find(e[i].x), fy = find(e[i].y), _d = !(dep(e[i].x) ^ dep(e[i].y));
      if (fx != fy) set_union(fx, fy, _d);
      else if (_d) {
        while (l <= r)
          ret[l - 1] = '0', ++l;
        set_resume(now);
        return;
      }
      swap(e[m--], e[i--]);
    }
  }
  if (l == r) ret[l - 1] = '1';
  else {
    for (i = 1, j = m; i <= j; ++i)
      if (e[i].st > mid) swap(e[j--], e[i--]);
    work(l, mid, j);
    for (i = 1, j = m; i <= j; ++i)
      if (e[i].ed <= mid) swap(e[j--], e[i--]);
    work(mid + 1, r, j);
  }
  set_resume(now);
}
 
void solve(int n, int m, int time) {
  dsu::top = 0;
  for (int i = 1; i <= n; ++i) fa[i] = i, d[i] = 1, a[i] = 0;
  work(1, time, m);
}

vector<int> G[MAXN], invalid[MAXM];
int u[MAXM], v[MAXM];

int main() {
  int T; scanf("%d", &T);
  for (int cas = 1; cas <= T; ++ cas) {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++ i) G[i].clear();
    for (int i = 1; i <= m; ++ i) {
      invalid[i].clear();
      scanf("%d%d", u + i, v + i);
      G[u[i]].push_back(i);
      G[v[i]].push_back(i);
    }
    for (int i = 1; i <= n; ++ i) {
      for (size_t j = 0; j < G[i].size(); ++ j) {
        invalid[G[i][j]].push_back(i);
      }
    }
    int sz(0);
    for (int i = 1; i <= m; ++ i) {
      assert(invalid[i].size() <= 2);
      if (invalid[i].size() == 0) {
        e[++ sz].x = u[i]; e[sz].y = v[i];
        e[sz].st = 1; e[sz].ed = n;
      }
      else if (invalid[i].size() == 1) {
        if (1 < invalid[i][0]) {
          e[++ sz].x = u[i]; e[sz].y = v[i];
          e[sz].st = 1; e[sz].ed = invalid[i][0] - 1;
        }
        if (invalid[i][0] < n) {
          e[++ sz].x = u[i]; e[sz].y = v[i];
          e[sz].st = invalid[i][0] + 1; e[sz].ed = n;
        }
      }
      else {
        if (1 < invalid[i][0]) {
          e[++ sz].x = u[i]; e[sz].y = v[i];
          e[sz].st = 1; e[sz].ed = invalid[i][0] - 1;
        }
        if (invalid[i][0] + 1 <= invalid[i][1] - 1) {
          e[++ sz].x = u[i]; e[sz].y = v[i];
          e[sz].st = invalid[i][0] + 1; e[sz].ed = invalid[i][1] - 1;
        }
        if (invalid[i][1] < n) {
          e[++ sz].x = u[i]; e[sz].y = v[i];
          e[sz].st = invalid[i][1] + 1; e[sz].ed = n;
        }        
      }
    }
    solve(n, sz, n);
    ret[n] = 0; puts(ret);
  }
  return 0;
}