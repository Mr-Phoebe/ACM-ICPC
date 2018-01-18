#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2222;

int T;
int a[MAXN], mark[4*MAXN*MAXN];
int sum[MAXN];

FILE* fp_in; 

bool check() {
	T++;
	int n;
  assert(fscanf(fp_in, "%d", &n) == 1);
  assert(n > 0 && n <= 2000);
	for (int i = 0; i < n; i++) {
	  if (scanf("%d", &a[i]) != 1) {
	    return 0;
    }
    if (a[i] <= 0 || a[i] > 3*n+18) {
      return 0;
    }
  }
	for (int i = 0; i < n; i++) {
		sum[i+1] = sum[i] + a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int s = sum[j+1]-sum[i];
			if (mark[s] == T) {
				return 0;
			}
			mark[s] = T;
		}
	}
	return 1;
}

int validate() {
  int ncase;
  fscanf(fp_in, "%d", &ncase);
  while (ncase--) {
    if (!check()) {
      printf("WA!\n");
      return 1;
    }
  }
  printf("AC!\n");
  return 0;
}

int main(int argc, char** argv) {
  fp_in = fopen(argv[1], "r");
  validate();
}
