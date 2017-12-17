#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MAXN = 100000 + 10;

struct P{int x,y;};
P ret[MAXN];
int A[MAXN], B[MAXN], n, m;

bool check(int A[], int n) {
  for (int i = 1; i < n; ++ i) {
    if (A[i] == 0) continue;
    else if (A[i] == -1) ret[m].x = i + 1, ret[m ++].y = i;
    else if (A[i] == 1) ret[m].x = i, ret[m ++].y = i + 1;
    else return false;
    A[i + 1] += A[i];
  }
  return A[n] == 0;
}

bool solve() {
  if (A[0] >= 0 && A[0] <= 2) {
    memcpy(B, A, sizeof(A[0]) * n);
    B[0] --; B[1] ++; B[n] = B[0];
    m = 1; ret[0].x = 0; ret[0].y = 1;
    if (check(B, n)) return true;
  }
  if (A[0] <= 0 && A[0] >= -2) {
    memcpy(B, A, sizeof(A[0]) * n);
    B[0] ++; B[1] --; B[n] = B[0];
    m = 1; ret[0].x = 1; ret[0].y = 0;
    if (check(B, n)) return true;
  }
  A[n] = A[0]; m = 0;
  return check(A, n);
}

bool all_same() {
  for (int i = 0; i < n; ++ i){
    if (A[i] != A[0]) return false;
  }
  return true;
}

int main() {
  int T; scanf("%d", &T);
  for (int _ = 0; _ < T; ++ _) {
    scanf("%d", &n);
    LL sum = 0;
    for (int i = 0; i < n; ++ i) {
      scanf("%d", A + i);
      sum += A[i];
    }
    if (all_same()) {
      puts("YES\n0");
      continue;
    }
    if (sum % n != 0) {
      puts("NO"); 
      continue;
    }
    sum /= n;
    for (int i = 0; i < n; ++ i) A[i] -= sum;
    if (solve()) {
      puts("YES");
      printf("%d\n", m);
      for (int i = 0; i < m; ++ i) {
        if (ret[i].x == n) ret[i].x = 0;
        if (ret[i].y == n) ret[i].y = 0;
        printf("%d %d\n", ret[i].x + 1, ret[i].y + 1);
      }
    }
    else puts("NO");
  }
  return 0;
}
