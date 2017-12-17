#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1000000 + 10, MOD = 1e9 + 7;
char s[MAXN];
int up[MAXN], mt[MAXN], stk[MAXN];
int a[MAXN], b[MAXN], n;
LL c[MAXN];

int main() {
  int T; scanf("%d", &T);
  for (int cas = 1; cas <= T; ++ cas) {
    scanf("%s", s + 1); n = strlen(s+1);
    int top = 0;
    memset(mt, 0, sizeof(mt[0]) * (n + 2));
    memset(a, 0, sizeof(a[0]) * (n + 2));
    memset(b, 0, sizeof(b[0]) * (n + 2));
    memset(c, 0, sizeof(c[0]) * (n + 2));
    for (int i = 1; i <= n; ++ i) {
      if (s[i] == '(') up[i] = stk[top], stk[++ top] = i;
      else if (top) {
        mt[mt[i] = stk[top --]] = i;
        b[i] = b[mt[i] - 1] + 1;
      }
    }
    while (top) up[stk[top --]] = 0;
    for (int i = n; i; -- i) if (s[i] == '(' && mt[i]) {
      a[i] = a[mt[i] + 1] + 1;
    }
    LL ret(0);
    for (int i = 1; i <= n; ++ i) {
      if (s[i] == '(' && mt[i]) {
        c[mt[i]] = c[i] = (up[i] ? c[up[i]] : 0) + (LL)a[i] * b[mt[i]];
      }
      ret += c[i] * i % MOD;
    }
    printf("%lld\n", ret);
  }
  return 0;
}