#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

int n, m, mi3[20], ss[177147];
long long ans[150000];
long long dp[177147][23], dp1[177147][23];
char s[150000];

void Work1(int n, int m) {
	memset(ss, 0, sizeof ss);
	for (int i = 1; i <= n; i++) {
		int now = 0;
		for (int j = 1; j <= m; j++) {
			now *= 3;
			char k;
			for (k = getchar(); k <= 32; k = getchar());
			now += k - '0';
		}
		ss[now]++;
	}
	mi3[0] = 1;
	for (int i = 1; i <= m; i++)	mi3[i] = mi3[i - 1] * 3;
	memset(dp1, 0, sizeof dp1);
	memset(dp, 0, sizeof dp);
	for (int i = 0; i < mi3[m]; i++)	dp1[i][0] = ss[i];
	for (int i = 0; i < m; i++) {
		// memcpy(dp, dp1, sizeof dp);
		if (i % 2 == 0) {
			for (int j = 0; j < mi3[m]; j++)
				for (int t = 0; t <= 2 * i + 2; t++)
					dp[j][t] = dp1[j][t];
			for (int j = 0; j < mi3[m]; j++) {
				int s1 = j / mi3[i] % 3, s2 = j - s1 * mi3[i];
				for (int t = 0; t < 3 * mi3[i]; t += mi3[i])
					if (t != s1 * mi3[i])
					for (int p = 0; p <= 2 * i; p++)	dp[s2 + t][p + abs(s1 - t / mi3[i])] += dp1[j][p];
			}
		}else {
			for (int j = 0; j < mi3[m]; j++)
				for (int t = 0; t <= 2 * i + 2; t++)
					dp1[j][t] = dp[j][t];
			for (int j = 0; j < mi3[m]; j++) {
				int s1 = j / mi3[i] % 3, s2 = j - s1 * mi3[i];
				for (int t = 0; t < 3 * mi3[i]; t += mi3[i])
					if (t != s1 * mi3[i])
					for (int p = 0; p <= 2 * i; p++)	dp1[s2 + t][p + abs(s1 - t / mi3[i])] += dp[j][p];	
			}
		}
		// for (int j = 0; j < mi3[m]; j++)
		// 	for (int t = 0; t <= 2 * i + 2; t++)
		// 		dp1[j][t] = dp[j][t];
		// memcpy(dp1, dp, sizeof dp);
	}
	if (m % 2 == 0) {
		for (int i = 0; i < mi3[m]; i++)
			for (int p = 0; p <= 2 * m; p++)
				ans[p] += 1LL * ss[i] * dp1[i][p];
	}else {
		for (int i = 0; i < mi3[m]; i++)
			for (int p = 0; p <= 2 * m; p++)
				ans[p] += 1LL * ss[i] * dp[i][p];
	}
	ans[0] = ans[0] - n;
	for (int i = 0; i <= m * 2; i++)	ans[i] /= 2;
}

int main() {
	// freopen("r.in", "r", stdin);
	// freopen("a.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i <= 2 * m; i++)
			ans[i] = 0;
		Work1(n, m);
		for (int i = 0; i <= 2 * m; i++)	printf("%lld\n", ans[i]);
	}
}
