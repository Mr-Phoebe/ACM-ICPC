#include <cstdio>
#include <algorithm>
using namespace std;

int x, y, T, b[100], a[110000];

bool calc(int x) {
	int len = 0;
	while (x) {
		b[++len] = x % 10;
		x /= 10;
	}
	sort(b + 1, b + len + 1);
	for (int i = 1; i < len; i++)
		if (b[i] == b[i + 1]) return false;
	return true;
}

int main() {
	// freopen("o.in", "r", stdin);
	// freopen("o.out", "w", stdout);
	for (int i = 1; i <= 100000; i++)
		a[i] = a[i - 1] + calc(i);
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &x, &y);
		printf("%d\n", a[y] - a[x - 1]);
	}
}