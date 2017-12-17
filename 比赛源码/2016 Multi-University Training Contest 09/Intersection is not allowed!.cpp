#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int MAXN = 222222;

int f[MAXN], g[MAXN], r[MAXN];

int modExp(int a, int n, int p) {
  int ret = 1;
  for (; n; n >>= 1, a = (long long)a*a % p) {
    if (n & 1) {
      ret = (long long)ret*a % p;
    }
  }
  return ret;
}

int C(int n, int m) {
  if (m < 0 || m > n) {
    return 0;
  }
  return (long long)f[n]*g[n-m]%MOD*g[m]%MOD;
}

const int MAXM = 111;
int a[MAXM], b[MAXM], x[MAXM][MAXM];

int solve(int x[MAXM][MAXM], int n) {
  int ret = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      if (x[j][i]) {
        if (j > i) {
          for (int k = i; k <= n+1; k++) {
            swap(x[j][k], x[i][k]);
          }
          ret = (MOD-ret) % MOD;
        }
        break;
      }
    }
    if (!x[i][i]) {
      return 0;
    }
    ret = (long long)ret*x[i][i] % MOD;
    int y = modExp(x[i][i], MOD-2, MOD);
    for (int j = i; j <= n+1; j++) {
      x[i][j] = (long long)x[i][j]*y % MOD;
    }
    for (int j = i+1; j <= n; j++) {
      if (x[j][i]) {
        int y = MOD-x[j][i];
        for (int k = i; k <= n+1; k++) {
          x[j][k] = (x[j][k] + (long long)y*x[i][k]) % MOD;
        }
      }
    }
  }
  return ret;
}

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	
	int ncase;
	f[0] = f[1] = g[0] = g[1] = r[1] = 1;
	for (int i = 2; i < MAXN; i++) {
	  f[i] = (long long)f[i-1]*i % MOD;
	  r[i] = (long long)(MOD-r[MOD%i]) * (MOD/i) % MOD;
	  g[i] = (long long)g[i-1]*r[i] % MOD;
  }
	for (scanf("%d", &ncase); ncase--; ) {
	  int n, m; scanf("%d%d", &m, &n);
	  for (int i = 1; i <= n; i++) {
	    scanf("%d", &a[i]);
    }
	  for (int i = 1; i <= n; i++) {
	    scanf("%d", &b[i]);
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        x[i][j] = C(m-1+b[j]-a[i], b[j]-a[i]);
      }
    }
    printf("%d\n", solve(x, n));
	}
	return 0;
}

