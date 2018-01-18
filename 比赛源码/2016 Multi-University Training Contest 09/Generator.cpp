#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int modExp(int a, int n, int p) {
  int ret = 1;
  for (; n; n >>= 1, a = (long long)a*a % p) {
    if (n & 1) {
      ret = (long long)ret*a % p;
    }
  }
  return ret;
}

const int MAXM = 111;
const int MAXN = 22;
const int MAXL = 55555;

int a[MAXM];
int s[MAXN][MAXL];
int f[MAXL], c[MAXN][MAXL], d[MAXN][MAXL];
int p[MAXN][MAXN], x[MAXN][MAXN];

void solve(int n) {
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      if (x[j][i]) {
        if (j > i) {
          for (int k = i; k <= n+1; k++) {
            swap(x[j][k], x[i][k]);
          }
        }
        break;
      }
    }
    if (!x[i][i]) {
      return;
    }
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
}

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	
  int ncase;
  int total = 0;
  for (scanf("%d", &ncase); ncase--; ) {
    int n, m, L; scanf("%d%d%d", &n, &m, &L);
    int S = 0;
    total += n*L;
    for (int i = 1; i <= m; i++) {
      scanf("%d", &a[i]), S += a[i];
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < L; j++) {
        scanf("%d", &s[i][j]);
      }
    }
    for (int i = 1; i <= n; i++) {
      f[1] = 0;
      for (int j = 1, k = 0; j < L; j++) {
        while (k && s[i][j] != s[i][k]) {
          k = f[k];
        }
        if (s[i][j] == s[i][k]) {
          k++;
        }
        f[j+1] = k;
      }
      c[i][0] = 1;
      for (int j = 1; j <= L; j++) {
        c[i][j] = (long long)c[i][j-1] * modExp(a[s[i][j-1]], MOD-2, MOD) % MOD * S % MOD;
      }
      c[i][0] = 0;
      for (int j = 1; j <= L; j++) {
        c[i][j] = (c[i][j] + c[i][f[j]]) % MOD;
      }
      int maxl = 0;
      for (int j = 1; j <= n; j++) {
        for (int k = 0, l = 0; k < L; k++) {
          while (l && s[j][k] != s[i][l]) {
            l = f[l];
          }
          if (s[j][k] == s[i][l]) {
            l++;
          }
          if (k == L-1) {
            p[i][j] = c[i][l];
          }
          if (l == L) {
            l = f[l];
          }
        }
      }
    }
    int ans = 0;
    for (int cur = 1; cur < (1<<n); cur++) {
      vector<int> V;
      for (int j = 0; j < n; j++) {
        if (cur >> j & 1) {
          V.push_back(j+1);
        }
      }
      int tot = V.size();
      for (int j = 0; j < tot; j++) {
        for (int k = 0; k < tot; k++) {
          x[j+1][k+1] = p[V[j]][V[k]];
        }
        x[j+1][tot+1] = MOD-1;
        x[j+1][tot+2] = 0;
      }
      for (int j = 0; j < tot; j++) {
        x[tot+1][j+1] = 1;
      }
      x[tot+1][tot+1] = 0;
      x[tot+1][tot+2] = 1;
      solve(tot+1);
      if (tot & 1) {
        ans = (ans + x[tot+1][tot+2]) % MOD;
      } else {
        ans = (ans + MOD - x[tot+1][tot+2]) % MOD;
      }
    }
    printf("%d\n", ans);
  }
	return 0;
}

