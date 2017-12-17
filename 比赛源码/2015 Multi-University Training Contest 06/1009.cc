#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 200000 + 10;
const LL inf = 1ll << 60;

LL dis[MAXN];
int dsu[MAXN], l[MAXN], r[MAXN], c[MAXN];

struct Cmp {
  bool operator () (int a, int b) const {
    if (dis[a] != dis[b]) return dis[a] > dis[b];
    else return a < b;
  }
};

int get(int x) {
  if (x != dsu[x]) return dsu[x] = get(dsu[x]);
  return dsu[x];
}

int main() {
  /*int size=64<<20;
  char *p=(char*)std::malloc(size)+size;
  __asm__("movl %0, %%esp\n"::"r"(p));*/
  int T; scanf("%d", &T);
  fprintf(stderr, "%d\n", T);
  for (int cas = 1; cas <= T; ++ cas) {
    fprintf(stderr, "%d:\n", cas);
    int n; scanf("%d", &n);
    fprintf(stderr, "%d\n", n);
    assert(1 <= n && n <= 200000);
    for (int i = 0; i <= n; ++ i) dsu[i] = i, dis[i] = inf;
    for (int i = 0; i < n; ++ i) scanf("%d", l + i);
    for (int i = 0; i < n; ++ i) scanf("%d", r + i);
    for (int i = 0; i < n; ++ i) scanf("%d", c + i);
    for (int i = 0; i < n; ++ i) {
      assert(0 <= l[i] && l[i] <= r[i] && r[i] <= n);
      assert(1 <= c[i] && c[i] <= 1000000000);
    }
    priority_queue<int, vector<int>, Cmp> Q;
    dis[0] = c[0]; Q.push(0);
    while (!Q.empty()) {
      int u = Q.top(); Q.pop();
      for (int d = -1; d <= 1; d += 2) {
        int left = u + d * l[u], right = u + d * r[u];
        if (left > right) swap(left, right);
        left = max(0, left); left = min(left, n);
        if (left > right) continue;
        for (int v = left; ; ++ v) {
          v = get(v); if (v >= n || v > right) break;
          if (dis[v] > dis[u] + c[v]) {
            if (dis[v] == inf) {
              dis[v] = dis[u] + c[v];
              Q.push(v);
            }
          }
          dsu[get(v)] = get(v + 1);
        }
      }
    }
    for (int i = 0; i < n; ++ i) {
      if (dis[i] == inf) dis[i] = -1;
      else dis[i] -= c[i];
      printf("%lld%c", dis[i], " \n"[i == n - 1]);
    }
  }
  return 0;
}
