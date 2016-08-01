#include <cstdio>
using namespace std;

int T, n;
int s[2][3], used[10][10], sum[2][3], du[10][2];
int ss[3100];
bool Find;

void doit(int x) {
	if (s[x][2] == n) {
		for (int i = 1; i < n; i++)
			printf("%d %d %d\n", ss[i], ss[i + 1], x);
		printf("%d %d %d\n", ss[1], ss[n], x);
	}else {
		for (int i = 1; i <= s[x][2] + 1; i++)
			printf("%d %d %d\n", ss[i], ss[i + 1], x);
		for (int i = 3; i <= s[x][1]; i += 2)
			printf("%d %d %d\n", ss[s[x][2] + i], ss[s[x][2] + i + 1], x);
	}
}

void dfs(int x, int y) {
	if (x > n) {
		for (int i = 1; i <= n; i++)
			if (du[i][0] > 2 || du[i][1] > 2) return ;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 3; j++)
				sum[i][j] = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < 2; j++)
				sum[j][du[i][j]]++;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 3; j++)
				if (sum[i][j] != s[i][j]) return ;
		Find = true;
		printf("%d\n", s[0][2] + s[0][1] / 2 + s[1][2] + s[1][1] / 2);
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				if (used[i][j] != 2)
					printf("%d %d %d\n", i, j, used[i][j]);
	}else if (y > n) dfs(x + 1, x + 2);
	else {
		used[x][y] = 0;
		du[x][0]++;
		du[y][0]++;
		dfs(x, y + 1);
		du[x][0]--;
		du[y][0]--;
		if (Find)
			return ;

		used[x][y] = 1;
		du[x][1]++;
		du[y][1]++;
		dfs(x, y + 1);
		du[x][1]--;
		du[y][1]--;
		if (Find)
			return ;
		used[x][y] = 2;
		dfs(x, y + 1);
		if (Find)
			return ;
	}
}

int main() {
	// freopen("c.in", "r", stdin);
	// freopen("a.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d%d%d%d", &s[0][0], &s[0][1], &s[0][2], &s[1][0], &s[1][1], &s[1][2]);
		if (s[0][1] % 2 != 0 || s[1][1] % 2 != 0) {
			printf("-1\n");
			continue;
		}
		n = s[0][0] + s[0][1] + s[0][2];
		if (s[0][0] + s[0][1] + s[0][2] <= 4) {
			Find = false;
			dfs(1, 2);
			if (!Find)
				printf("-1\n");
		}else {
			printf("%d\n", s[0][2] + s[0][1] / 2 + s[1][2] + s[1][1] / 2);
			if (n % 2 == 1) {
				for (int i = 1; i <= n; i++)
					ss[i] = i;
				doit(0);
				int len = 0;
				for (int i = 1; i <= n; i += 2)
					ss[++len] = i;
				for (int i = 2; i < n; i += 2)
					ss[++len] = i;
				doit(1);
			}else {
				for (int i = 1; i <= n; i++)
					ss[i] = i;
				doit(0);
				int len = 0;
				for (int i = 1; i <= n; i += 2)
					ss[++len] = i;
				ss[++len] = 2;
				for (int i = n; i >= 4; i -= 2)
					ss[++len] = i;
				doit(1);
			}
		}
	}
}
