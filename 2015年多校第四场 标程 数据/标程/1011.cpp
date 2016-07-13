#include <cstdio>
#include <string.h>
using namespace std;

#define P 1000000007


int T;
char x[11000], y[11000];
int to[4], a[4], b[4], s1[4], s2[4];
long long cost[4], maxCost;

void spe1() {
	while (a[1] != b[1] || a[2] != b[2]) {
		if ((a[1] + 1) % 3 == a[2]) maxCost -= cost[a[2]], a[2] = (a[2] + 1) % 3;
		else maxCost -= cost[a[1]], a[1] = (a[1] + 1) % 3;
	}
	if (maxCost < 0) printf("0\n");
	else printf("%lld\n", (maxCost / 2 / (cost[0] + cost[1] + cost[2]) + 1) % P);
}

long long spe2() {
	long long ans = 0;
	for (int i = 0; i < 6; i++) {
		int t;
		if ((a[1] + 1) % 3 == a[2]) t = 1;
		else t = 2;
		for (int j = 1; j <= 3; j++) {
			maxCost -= cost[a[t]];
			a[t] = (a[t] + 1) % 3;
			if (a[t] == b[t]) {
				if (maxCost < 0) ans += 0;
				else {
					long long kk = maxCost / (cost[0] + cost[1] + cost[2]);
					ans += (kk + 1 + kk % 2 + 1) / 2 % P * ((kk / 2 + 1) % P) % P;
				}
			}
		}
		maxCost += cost[0] + cost[1] + cost[2];
		if ((a[1] + 1) % 3 == a[2]) maxCost -= cost[a[2]], a[2] = (a[2] + 1) % 3;
		else maxCost -= cost[a[1]], a[1] = (a[1] + 1) % 3;
	}
	maxCost += cost[0] * 2 + cost[1] * 2 + cost[2] * 2;
	return ans % P;
}

int main() {
	// freopen("a.in", "r", stdin);
	// freopen("a.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		scanf("%lld%lld%lld%lld", &cost[0], &cost[1], &cost[2], &maxCost);
		memset(to, 0, sizeof to);
		scanf("%s%s", x, y);
		int l = strlen(x);
		bool ok = true;
		for (int i = 0; i < 3; i++)
			to[i] = -1, s1[i] = 0, s2[i] = 0;
		for (int i = 0; i < l; i++)
			if (x[i] < 'x')
				while (1);
		for (int i = 0; i < l; i++) {
			if (to[int(x[i] - 'x')] != -1 && to[int(x[i] - 'x')] != y[i] - 'x') ok = false;
			to[int(x[i] - 'x')] = y[i] - 'x';
			s1[int(x[i] - 'x')] = 1;
			s2[int(y[i] - 'x')] = 1;
		}
		if (!ok) {
			printf("0\n");
			continue;
		}
		int sum1 = 0, sum2 = 0;
		for (int i = 0; i < 3; i++)
			if (s1[i]) sum1++, a[sum1] = i, b[sum1] = to[i];
		for (int i = 0; i < 3; i++)
			if (s2[i]) sum2++;
		if (sum1 == 1 && sum2 == 1) {
			while (a[1] != b[1]) maxCost -= cost[a[1]], a[1] = (a[1] + 1) % 3;
			if (maxCost < 0) printf("0\n");
			else printf("%lld\n", (maxCost / (cost[0] + cost[1] + cost[2]) + 1) % P);
		}else if (sum1 == 2 && sum2 == 2) {
			spe1();
		}else if (sum1 == 3 && sum2 == 3) {
			if (a[1] == b[1] && a[2] == b[2] && a[3] == b[3])
				printf("1\n");
			else
				printf("0\n");
		}else if (sum1 == 3 && sum2 == 2) {
			if (b[1] == b[2]) {
				maxCost -= cost[0];
				a[1] = 1; a[2] = 2;
				b[2] = b[3];
				spe1();
			}else if (b[2] == b[3]) {
				maxCost -= cost[1];
				a[1] = 0; a[2] = 2;
				spe1();
			}else {
				maxCost -= cost[2];
				a[1] = 0; a[2] = 1;
				spe1();
			}
		}else if (sum1 == 2 && sum2 == 1) {
			printf("%lld\n", spe2());
		}else if (sum1 == 3 && sum2 == 1) {
			long long ans = 0;
			maxCost -= cost[0];
			a[1] = 1; a[2] = 2;
			b[2] = b[3];
			ans += spe2();
			maxCost += cost[0];

			maxCost -= cost[1];
			a[1] = 0; a[2] = 2;
			ans += spe2();
			maxCost += cost[1];

			maxCost -= cost[2];
			a[1] = 0; a[2] = 1;
			ans += spe2();

			printf("%lld\n", ans % P);
		}
	}
}
