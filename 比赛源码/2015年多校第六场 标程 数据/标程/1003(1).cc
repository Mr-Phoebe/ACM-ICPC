#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 500000 + 10;
int ret[10][MAXN];
int vis[100], a[100];
int tot, tar;

bool dfs(int dep, int now, int u, int c) {
  if (now == 0) {
    int k = 0;
    while (vis[k] != -1) ++ k; vis[k] = c;
    if (dfs(dep + 1, a[k], k + 1, c)) return true;
    vis[k] = -1; return false;
  }
  if (now == tar) {
    if (dep == tot) return true;
    else return dfs(dep, 0, 0, c + 1);
  }
  for (int i = u; i < tot; ++ i) {
    if (vis[i] == -1 && now + a[i] <= tar) {
      vis[i] = c;
      if (dfs(dep + 1, now + a[i], i + 1, c)) return true;
      vis[i] = -1;
    }
  }
  return false;
}

int main() {
  int T; scanf("%d", &T);
  for (int cas = 1; cas <= T; ++ cas) {
    int n, k; scanf("%d%d", &n, &k);
    //fprintf(stderr, "%d %d\n", n, k);
    LL sum = (LL)n * (n + 1) / 2;
    if (sum % k == 0 && n >= k * 2 - 1) {
      while (n >= 40) {
        for (int i = 0; i < k; ++ i) ret[i][++ ret[i][0]] = n - i;
        for (int i = 0; i < k; ++ i) ret[i][++ ret[i][0]] = n - k * 2 + i + 1;
        n -= k * 2;
      }
      tot = n; tar = n * (n + 1) / 2 / k;
      for (int i = 0; i < tot; ++ i) a[i] = tot - i;
      for (int i = 0; i < tot; ++ i) vis[i] = -1;
      dfs(0, 0, 0, 0);
      for (int i = 0; i < tot; ++ i) {
        ret[vis[i]][++ ret[vis[i]][0]] = a[i];
      }
      for (int i = 0; i < k; ++ i) {
        printf("%d ", ret[i][0]);
        for (int j = 1; j <= ret[i][0]; ++ j) printf(" %d", ret[i][j]);
        puts("");
      }
    }
    else puts("NO");
  }
  return 0;
}
