#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2222;

bool chk[MAXN];
int ans[MAXN];
int sum[MAXN];

void solve(int n) {
	if (n < 5) {
		for (int i = 0; i < n; i++) {
		  ans[i] = 1<<i;
		}
		return;
	}
	int p = n;
	while (chk[p]) {
		p++;
	}
	int minm = p, minx = 1;
	for (int x = 1; x < p; x++) {
	  int z = 0;
	  for (int j = 0, s = 0; j < n; j++) {
	    int y = j*x % p; s += y;
	    if (s >= p) {
	      s -= p, y -= p;
      }
      z = max(z, y);
      if (z >= minm) {
        break;
      }
    }
    if (z < minm) {
      minm = z, minx = x;
    }
    if (minm < 3*n+18-2*p) {
      break;
    }
  }
  for (int i = 0, s = 0; i < n; i++) {
    int y = i*minx % p; s += y;
    if (s >= p) {
      s -= p, y -= p;
    }
    ans[i] = y + 2*p;
  }
}

int T;

int main() {
//	freopen("data1.in", "r", stdin);
//	freopen("data1.out", "w", stdout);
	
	chk[1] = 1;
	for (int i = 2; i < MAXN; i++) {
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				chk[i] = 1;
				break;
			}
		}
	}
	int ncase, T = 0;
	for (scanf("%d", &ncase); ncase--; ) {
		int n; scanf("%d", &n); solve(n);
		for (int i = 0; i < n; i++) {
			printf("%d%c", ans[i], i<n-1 ? ' ' : '\n');
		}
	}
	return 0;
}

