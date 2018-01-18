#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> PII;
const int MAXN = 100000 + 10;

struct W {
  int l, r, id;
  bool operator < (const W &rhs) const {
    return l < rhs.l || (l == rhs.l && r < rhs.r);
  }
} A[MAXN];

int ret[MAXN], vs[MAXN], n;

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
      scanf("%d", &A[i].l);
      A[i].id = i; vs[i] = 0;
    }
    for (int i = 0; i < n; ++ i) {
      scanf("%d", &A[i].r);
    }
    sort(A, A + n);
    priority_queue<PII> Q;
    int cnt(0), i(0);
    while (1) {
      while (i < n && A[i].l <= cnt) Q.push(PII(-A[i].r, A[i].id)), ++ i;
      while (!Q.empty() && -Q.top().first < cnt) Q.pop();
      if (Q.empty()) break;
      ret[cnt ++] = Q.top().second; Q.pop();
      vs[ret[cnt - 1]] = 1;
    }
    printf("%d\n", cnt);
    for (int i = 0; i < n; ++ i) if (!vs[i]) ret[cnt ++] = i;
    for (int i = 0; i < n; ++ i) {
      printf("%d%c", ret[i] + 1, " \n"[i == n - 1]);
    }
  }
  return 0;
}