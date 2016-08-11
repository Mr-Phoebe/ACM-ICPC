#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <algorithm>

using namespace std;

const int MAXN = 100000;
int n;
int x[MAXN];
int sta[3][MAXN], top[3];

void work()
{
	top[0] = top[1] = top[2] = 0;
	for (int i = 0; i < n; ++i) {
		char op[10], s[5];
		scanf("%s%s", op, s);
		int a = s[0] - 'A';
		if (op[1] == 'u') {
			scanf("%d", &x[i]);
			sta[a][top[a]++] = i;
		} else if (op[1] == 'o') {
			if (!top[a]) a = 2;
			printf("%d\n", x[sta[a][--top[a]]]);
		} else {
			scanf("%s", s);
			top[2] = merge(sta[0], sta[0] + top[0],
			               sta[1], sta[1] + top[1],
			               sta[2] + top[2]) - sta[2];
			top[0] = top[1] = 0;
		}
	}
}

int main()
{
	int cas = 0;
	while (scanf("%d", &n), n > 0) {
		printf("Case #%d:\n", ++cas);
		work();
	}
}
