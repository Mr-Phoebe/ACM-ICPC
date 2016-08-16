#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)((x).size())

const int MAXN = 222222;

int n, m, q;
vector<int> adj[MAXN];
int _a[MAXN], a[19][2*MAXN], b[18][MAXN], c[18][MAXN];
int f[MAXN], dp[MAXN], dis[2][MAXN];

void dfs(int u) {
  _a[u] = m, a[0][m++] = dp[u];
  for (int i = 0; i < sz(adj[u]); i++) {
    dfs(adj[u][i]);
    a[0][m++] = dp[u];
  }
}

int ptr[MAXN];

void dfs1() {
  for (int i = 1; i <= n; i++) {
    ptr[i] = 0;
  }
  m = 0, a[0][m++] = 1;
  while (1) {
    if (m == 2*n-1) {
      break;
    }
    int u = a[0][m-1];
    if (ptr[u] == 0) {
      _a[u] = m-1;
    }
    if (ptr[u] == sz(adj[u])) {
      a[0][m++] = f[u];
    } else {
      a[0][m++] = adj[u][ptr[u]], ptr[u]++;
    }
  }
  for (int i = 0; i < m; i++) {
    a[0][i] = dp[a[0][i]];
  }
}

inline int dist(int u, int v) {
  if (u == v) {
    return 0;
  }
  int l = _a[u], r = _a[v], k = 31-__builtin_clz(abs(r-l)+1);
  if (l > r) {
    swap(l, r);
  }
  return dp[u] + dp[v] - 2*min(a[k][l], a[k][r-(1<<k)+1]);
}

inline int maxb(int l, int r) {
  if (l > r) {
    return 0;
  }
  int k = 31-__builtin_clz(r-l+1);
  return max(b[k][l], b[k][r-(1<<k)+1]);
}

inline int maxc(int l, int r) {
  if (l > r) {
    return 0;
  }
  int k = 31-__builtin_clz(r-l+1);
  return max(c[k][l], c[k][r-(1<<k)+1]);
}

int S, T, D;

int solve(int u, int v, int d) {
  if (u == v) {
    return 0;
  }
  int d1 = dist(u, v);
  if (d1 >= d) {
    return 1;
  }
  for (int i = 0; i < 2; i++) {
    if (dis[i][u] >= d && dis[i][v] >= d) {
      return 2;
    }
  }
  if (max(dis[0][u], dis[1][u]) < d || max(dis[0][v], dis[1][v]) < d) {
    return -1;
  }
  int x = (dis[0][u]-dis[1][u]+D) / 2;
  int y = (dis[0][v]-dis[1][v]+D) / 2;
  if (x > y) {
    swap(x, y), swap(u, v);
  }
  if (y < x+2) {
    return 3;
  }
  int dx = dis[0][u] - x;
  int z = d1/2 - dx + x;
  if (maxb(x+1, z) + dis[0][u] - 2*x >= d) {
    return 2;
  }
  if (maxc(z+1, y-1) + dis[1][v] - 2*(D-y) >= d) {
    return 2;
  }
  return 3;
}

#define FI(n) FastInput::read(n)

namespace FastInput {
	const int SIZE = 1 << 16;
	char buf[SIZE], str[60];
	int bi = SIZE, bn = SIZE, opt;
	int read(char *s) {
		while (bn) {
			for (; bi < bn && buf[bi] <= ' '; bi++);
			if (bi < bn) break;
			bn = fread(buf, 1, SIZE, stdin);
			bi = 0;
		}
		int sn = 0;
		while (bn) {
			for (; bi < bn && buf[bi] > ' '; bi++) s[sn++] = buf[bi];
			if (bi < bn) break;
			bn = fread(buf, 1, SIZE, stdin);
			bi = 0;
		}
		s[sn] = 0;
		return sn;
	}
	bool read(int& x) {
		int n = read(str), bf;
		if (!n) return 0;
		int i = 0; if (str[i] == '-') bf = -1, i++; else bf = 1;
		for (x = 0; i < n; i++) x = x * 10 + str[i] - '0';
		if (bf < 0) x = -x;
		return 1;
	}
};

int main() {
//	freopen("data1.in", "r", stdin);
//	freopen("data1.out", "w", stdout);
	
  int ncase;
  int nsum = 0, tsum = 0;
  for (FI(ncase); ncase--; ) {
    int mod; FI(n), FI(q), FI(mod);
    for (int i = 1; i <= n; i++) {
      adj[i].clear();
    }
    nsum += n;
    for (int i = 2; i <= n; i++) {
      int u; FI(u);
      adj[u].push_back(i);
      f[i] = u, dp[i] = dp[u] + 1;
    }
    dfs1();
    for (int i = 1; (1<<i) <= m ; i++) {
      for (int j = 0; j < m; j++) {
        a[i][j] = a[i-1][j];
        if (j + (1<<i-1) < m) {
          a[i][j] = min(a[i][j], a[i-1][j + (1<<i-1)]);
        }
      }
    }
    D = 0, S = T = 1;
    for (int i = 1; i <= n; i++) {
      if (dp[i] > D) {
        D = dp[i], S = i;
      }
    }
    for (int i = 1; i <= n; i++) {
      int cur = dist(S, i);
      if (cur > D) {
        D = cur, T = i;
      }
    }
    for (int i = 0; i <= D; i++) {
      b[0][i] = c[0][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
      dis[0][i] = dist(i, S);
      dis[1][i] = dist(i, T);
      int x = (dis[0][i]-dis[1][i]+D)/2;
      b[0][x] = max(b[0][x], dis[0][i]);
      c[0][x] = max(c[0][x], dis[1][i]);
    }
    for (int i = 1; (1<<i) <= D+1; i++) {
      for (int j = 0; j <= D; j++) {
        b[i][j] = b[i-1][j], c[i][j] = c[i-1][j];
        if (j + (1<<i-1) <= D) {
          b[i][j] = max(b[i][j], b[i-1][j + (1<<i-1)]);
          c[i][j] = max(c[i][j], c[i-1][j + (1<<i-1)]);
        }
      }
    }
    int u, v, d, A, B, C, ans;
    FI(u), FI(v), FI(d), FI(A), FI(B), FI(C);
    long long ret = 0;
    for (int i = 1; i <= q; i++) {
      ans = solve(u, v, d);
      ret += (long long)i*(ans+1);
      u = ((long long)u * A + B + ans) % n + 1;
      v = ((long long)v * B + C + ans) % n + 1;
      d = ((long long)d * C + A + ans) % mod;
    }
    printf("%lld\n", ret);
  }
	return 0;
}

