#include <cstdio>
using namespace std;

int T, n, m, a, b, ans, du[10];
int ed[10][10];

void dfs(int x, int y) {
	if (x > n) ans++;
	else if (y > n) {
		if (du[x]) return ;
		dfs(x + 1, x + 2);
	}else {
		if (ed[x][y]) {
			du[x]++; du[y]++;
			dfs(x, y + 1);
			du[x] -= 2; du[y] -= 2;
			dfs(x, y + 1);
			du[x]++; du[y]++;
		}else dfs(x, y + 1);
	}
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				ed[i][j] = 0;
		while (m--) {
			scanf("%d%d", &a, &b);
			ed[a][b] = ed[b][a] = 1;
		}
		ans = 0;
		dfs(1, 2);
		printf("%d\n", ans);
	}
}
