#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100000 + 10;

LL sum[MAXN];
int a[MAXN], n;

int main() {
  int T; scanf("%d", &T);
  for (int cas = 1; cas <= T; ++ cas) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) scanf("%d", a + i);
    LL ret(0); sum[n] = 0;
    for (int i = n - 1; i >= 0; -- i) {
      sum[i] = sum[i + 1] + i + 1;
      ret += LL(i + 1) * (n - i) + sum[i];
    }
    for (int k = 1; k < 40; ++ k) {
      LL lim = 1ll << k, s(0); // >= lim
      for (int i = 0, j(0); i < n; ++ i) {
        while (j < n && s < lim) s += a[j ++];
        if (s >= lim) ret += LL(i + 1) * (n - j + 1) + sum[j - 1];
        else break; s -= a[i];
      }
    }
    printf("%lld\n", ret);
  }
  return 0;
}
