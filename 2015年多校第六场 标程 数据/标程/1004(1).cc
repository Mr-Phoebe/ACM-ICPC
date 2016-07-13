#include <bits/stdc++.h> 
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 2000 + 10;
vector<PII> G[MAXN];
LL cache[MAXN], sz;
int s[MAXN];
 
LL dfs(int u, int f = -1) {
  LL ret = 0;
  for (auto &to : G[u]) {
    if (to.first == f) continue;
    LL cur = dfs(to.first, u) + to.second;
    LL mn = min(ret, cur), mx = max(ret, cur);
    if (mn != 0) cache[sz ++] = mn;
    ret = mx;
  }
  return ret;
}
 
void solve(int v) {
  sz = 0;
  LL last = dfs(v);
  cache[sz ++] = last;
  for (int i = 0; i < sz; ++ i) cache[i] *= s[v];
}
 
int main() {
  int T; scanf("%d", &T);
    for (int cas = 1; cas <= T; ++ cas) {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i) G[i].clear();
    for (int i = 1; i < n; ++ i) {
      int u, v, w; scanf("%d%d%d", &u, &v, &w); -- u, -- v;
      G[u].push_back(PII(v, w));
      G[v].push_back(PII(u, w));
    }
    for (int i = 0; i < n; ++ i) scanf("%d", s + i);
    vector<LL> pt;
    for (int i = 0; i < n; ++ i) {
      solve(i);
      for (int i = 0; i < sz; ++ i) pt.push_back(cache[i]);
    }
    m = min<int>(pt.size(), m);
    nth_element(pt.begin(), pt.end() - m, pt.end());
    LL ret = accumulate(pt.end() - m, pt.end(), 0LL);
    printf("%lld\n", ret);
  }
  return 0;
}