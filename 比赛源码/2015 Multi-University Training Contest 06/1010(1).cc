#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 2000 + 10, MOD = 1e9 + 7;

int C[MAXN][MAXN], mp[MAXN][MAXN], f[MAXN];

LL pm(LL a, LL n) {
  LL r(1);
  for (; n; n >>= 1) {
    if (n & 1) r = r * a % MOD;
    a = a * a % MOD;
  }
  return r;
}

int solve_even(int n, int m) {
  if (m == 0) return 0;
  LL ret(0);
  for (int i = 0; i <= (m - 1) / 2; ++ i) {
    ret += (LL)C[m][i] * mp[m - i * 2][n] % MOD;
  }
  ret %= MOD;
  return ret * pm(pm(2, m - 1), MOD - 2) % MOD;
}

int solve_odd(int n, int m) {
  if (m == 1) return 1;
  LL ret(0);
  for (int i = 0; i <= (n - 1) / 2; ++ i) {
    ret += (LL)f[i * 2] * C[n][i * 2] % MOD;
  }
  return ret * m % MOD;
}

void init() {
  for (int i = 0; i < MAXN; ++ i) {
    C[i][i] = C[i][0] = 1;
    for (int j = 1; j < i; ++ j) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }
  }
  for (int q = 1; q < MAXN; ++ q) {
    mp[q][0] = 1;
    for (int n = 1; n < MAXN; ++ n) {
      mp[q][n] = (LL)mp[q][n - 1] * q % MOD;
    }
  }
}

int main() {
  init();
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    int n, m; scanf("%d%d", &n, &m);
    LL ret(0); f[0] = 1;
    for (int i = 1; i <= n; i ++) {
      LL cost(0);
      if (i & 1) {
        cost = solve_odd(i, m);
      }
      else {
        f[i] = solve_even(i, m - 1);
        cost = solve_even(i, m);
      }
      ret += LL(n - i + 1) * pm(m, n - i) % MOD * cost % MOD;
    }
    ret %= MOD;
    printf("%lld\n", ret % MOD);
  }
  return 0;
}