#include <cstdio>
#include <string.h>
using namespace std;

long long k;
int a[31][31];
int T;

int main() {
	scanf("%d", &T);
	while (T--) {
		memset(a, 0, sizeof a);
		scanf("%lld", &k);
		printf("28 21\n");
		for (int i = 1; i <= 8; i++)
			for (int j = 1; j <= 8; j++)
				a[i][j] = 1;
		for (int i = 9; i <= 27; i++)	a[i][i + 1] = 1;
		for (int i = 1; i <= 20; i++, k /= 8) {
			for (int j = 1; j <= k % 8; j++)
				a[j][8 + i] = 1;
		}
		for (int i = 1; i <= 28; i++) {
			for (int j = 1; j <= 28; j++)	printf("%d", a[i][j]);
			printf("\n");
		}
	}
}