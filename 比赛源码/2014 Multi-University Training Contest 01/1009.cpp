#include<stdio.h>
#include<string.h>
#include<iostream>
#include<cmath>
using namespace std;
int a[100005];
__int64 pmod = 1000000009;
__int64 inv[100005];
__int64 ba[100005];
__int64 rba[100005];
#define M 100005
void pre() {
	inv[0] = inv[1] = 1;
	ba[0] = ba[1] = 1;
	rba[0] = rba[1] = 1;
	for (int i = 2; i < M; i++) {
		inv[i] = ((pmod - pmod / i) * inv[pmod % i]) % pmod;
		ba[i] = (ba[i - 1] * i)%pmod;
		rba[i] = (rba[i - 1] * inv[i])%pmod;
	}
}
__int64 C(int n, int k) {
	return (ba[n] * rba[k] % pmod )* rba[n - k] % pmod;
}
int main() {
	int n, m;
	int l, r;
	int i;
	int nl, nr;
	pre();
	while (scanf("%d%d", &n, &m) != EOF) {
		for (i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		l = 0;
		r = 1;
		int o = 0;
		for (i = 0; i < n; ++i) {
			nl = min(abs(l - a[i]), abs(r - a[i]));
			if (l <= a[i] && r >= a[i])
				nl = 0;
			nr = max(m - abs(l + a[i] - m), m - abs(r + a[i] - m));
			if (l <= m - a[i] && r >= m - a[i])
				nr = m;
			o = (o + a[i]) % 2;
			l = nl;
			r = nr;
		}
		__int64 ans = 0;
		for (i = l; i <= r; ++i) {
			if (i % 2 == o) {
				ans += C(m, i);
				ans %= pmod;
			}
		}
		printf("%I64d\n", ans);
	}
}
