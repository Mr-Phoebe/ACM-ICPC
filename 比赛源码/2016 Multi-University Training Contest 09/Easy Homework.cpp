#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)((x).size())

template<typename T, typename U>
struct HashMap {
  static const int M = 333331;
  int chk[M], cn;
  int q[M], qn;
  vector<T> a;
  vector<U> b;
  int fst[M], m;
  vector<int> nxt;
  HashMap() {
    memset(fst, -1, sizeof fst);
    cn++;
  }
  void clear() {
    for (int i = 0; i < qn; i++) fst[q[i]] = -1;
    cn++;
    qn = m = 0;
    a.clear(), b.clear(), nxt.clear();
  }
  U& operator[](T x) {
    int r = (x % M + M) % M;
    for (int e = fst[r]; ~e; e = nxt[e]) {
      if (a[e] == x) {
        return b[e];
      }
    }
    if (chk[r] != cn) {
      chk[r] = cn;
      q[qn++] = r;
    }
    a.push_back(x), b.push_back(U());
    nxt.push_back(fst[r]), fst[r] = m++;
    return b.back();
  }
  bool count(T x) {
    int r = (x % M + M) % M;
    for (int e = fst[r]; ~e; e = nxt[e]) {
      if (a[e] == x) {
        return 1;
      }
    }
    return 0;
  }
};

HashMap<long long, int> H;

int modExp(int a, int n, int p) {
  int ret = 1;
  for (; n; n >>= 1, a = 1LL * a * a % p) 
    if (n & 1) 
      ret = 1LL * ret * a % p;
  return ret;
}

int modSqrt(int a, int p) {
  a = (a % p + p) % p;
  if (a % p == 0) return 0;
  if (p == 2) return 1;
  int q = p - 1 >> 1;
  int A = a, b = 1, c, r = q / (q & -q);
  for (c = 1; modExp(c, q, p) == 1; c++);
  int d = modExp(c, p - 2, p);
  for (int s = q & -q, t = q / 2; s > 1; s >>= 1, t >>= 1, c = 1LL * c * c % p, d = 1LL * d * d % p) {
    if (modExp(A, t, p) != 1) {
      A = 1LL * A * d % p * d % p;
      b = 1LL * b * c % p;
    }
  }
  int ret = 1LL * b * modExp(A, r + 1 >> 1, p) % p;
  return ret;
}

const int MAXN = 111111;

int f[MAXN];

long long solve(int A, int P, int X, long long L, long long R) {
  int Z = ((long long)A*A+4) % P * X % P * X % P;
  vector<int> cand;
  for (int i = -1; i <= 1; i += 2) {
    int Y = modSqrt(Z+4*i, P);
    cand.push_back(Y);
    if (Y != 0) {
      cand.push_back(P-Y);
    }
  }
  sort(cand.begin(), cand.end());
  cand.erase(unique(cand.begin(), cand.end()), cand.end());
  if (cand.empty()) {
    return 0;
  }
  for (int i = 0; i < cand.size(); i++) {
    cand[i] = (cand[i] - (long long)A*X % P + P) % P;
    cand[i] = (cand[i] + P*(cand[i]&1)) / 2;
  }
  f[0] = 0, f[1] = 1;
  long long C = 0, c = 0;
  int M = (int)ceil(sqrt(2.*P));
  for (int i = 2; i <= M+1; i++) {
    f[i] = ((long long)A*f[i-1] + f[i-2]) % P;
    if (f[i] == 1 && f[i-1] == 0) {
      if (!C) {
        C = i-1;
        break;
      }
    }
  }
  long long ret = 0;
  long long add = 0;
  if (C) {
    for (int i = 0; i < C; i++) {
      if (f[i] == X) {
        c++;
        if (i <= R%C) {
          add++;
        }
        if (i <= (L-1)%C) {
          add--;
        }
      }
    }
    ret = c * (R/C - (L-1)/C) + add;
    return ret;
  }
  H.clear();
  for (int i = 0; i < M; i++) {
    H[(long long)f[i+1]*P+f[i]] = i;
  }
  long long U = f[M+1], V = f[M], W = f[M-1];
  {
    int x = 1, y = 0;
    for (int i = 0; ; i++) {
      int xx = (x*U + y*V) % P;
      int yy = (x*V + y*W) % P;
      long long zz = (long long)xx*P + yy;
      if (H.count(zz)) {
        C = (long long)(i+1)*M - H[zz];
        break;
      }
      x = xx, y = yy;
    }
  }
  for (int i = 0; i < sz(cand); i++) {
    int x = X, y = cand[i];
    long long first = -1;
    for (int j = 0; j <= C/M; j++) {
      long long z = (long long)x*P + y;
      if (H.count(z)) {
        first = (C+H[z]-(long long)j*M+1) % C;
        break;
      }
      int xx = (x*U + y*V) % P;
      int yy = (x*V + y*W) % P;
      x = xx, y = yy;
    }
    if (~first) {
      ret += (R-first+C) / C;
      ret -= (L-1-first+C) / C;
    }
  }
  return ret;
}

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	
  int ncase;
  for (scanf("%d", &ncase); ncase--; ) {
    int A, P, X; long long L, R; scanf("%d%d%d%lld%lld", &A, &P, &X, &L, &R);
    printf("%lld\n", solve(A, P, X, L, R));
  }
  return 0;
}

