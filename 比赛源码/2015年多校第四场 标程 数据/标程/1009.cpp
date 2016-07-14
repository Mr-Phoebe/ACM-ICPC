#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;

int T, n, m, tx[4] = {0, 0, 1, -1}, ty[4] = {1, -1, 0, 0};
char S[1100][1100];
bool used[1100][1100];
int xx[1100000], yy[1100000];

void bfs() {
	memset(used, false, sizeof used);
	used[1][1] = true;
	int q = 1, h = 1;
	xx[q] = yy[q] = 1;
	for (; q <= h; q++)
		if (S[xx[q]][yy[q]] == '0') {
			for (int i = 0; i < 4; i++) {
				int X = xx[q] + tx[i], Y = yy[q] + ty[i];
				if (X > 0 && X <= n && Y > 0 && Y <= m && !used[X][Y]) {
					h++;
					xx[h] = X;
					yy[h] = Y;
					used[X][Y] = true;
				}
			}
		}
	if (used[n][m] && S[n][m] == '0') {
		printf("0\n");
		return ;
	}
	int ma = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (used[i][j])
				ma = max(ma, i + j);
	printf("1");
	for (int i = ma; i < n + m; i++) {
		char mi = '1';
		for (int j = 1; j <= n; j++)
			if (1 <= i - j && i - j <= m && used[j][i - j]) {
				mi = min(mi, S[j + 1][i - j]);
				mi = min(mi, S[j][i - j + 1]);
			}
		printf("%c", mi);
		for (int j = 1; j <= n; j++)
			if (1 <= i - j && i - j <= m && used[j][i - j]) {
				if (S[j + 1][i - j] == mi) used[j + 1][i - j] = true;
				if (S[j][i - j + 1] == mi) used[j][i - j + 1] = true;
			}
	}
	printf("\n");
}

int main() {
	// freopen("a.in", "r", stdin);
	// freopen("a.out", "w", stdout);
	
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			scanf("%s", S[i] + 1);
		for (int i = 0; i <= n + 1; i++)
			S[i][0] = '2', S[i][m + 1] = '2';
		for (int i = 0; i <= m + 1; i++)
			S[0][i] = '2', S[n + 1][i] = '2';
		bfs();
	}
}
