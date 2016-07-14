#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n; scanf("%d", &n); -- n;
    LL r(1), a(2), mod = 1e9 + 7;
    for (; n; n >>= 1) {
      if (n & 1) r = r * a % mod;
      a = a * a % mod;
    }
    r = (r + mod - 1) % mod;
    printf("%lld\n", r);
  }
  return 0;
}