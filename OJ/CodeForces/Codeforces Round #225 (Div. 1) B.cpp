#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
const int N = 100005;

struct state {
	int x, y;
}blo[N], rec[N], cur[N];
ll n, m;

inline bool cmp (const state& a, const state& b) {
	if (a.y == b.y) return a.x < b.x;
	return a.y < b.y;
}

void init () {
	cin >> n >> m;

	int xx, yy;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &xx, &yy);
		blo[i].x = xx; blo[i].y = yy;
	}
}

bool judge () {
//	if (n > m) return true;

	sort(blo, blo + m, cmp);
	int cnt = 1;
	rec[0].x = 1, rec[0].y = 1;

	for (int i = 0; i < m; i++) {
		if (blo[i].y != blo[i-1].y + 1) {
			cnt = 1;
			rec[0].y = n;
		}

		int k, tmp = 0, c = 0;
		for (k = i + 1; blo[k].y == blo[i].y; k++); k--;

		for (int j = i; j <= k; j++) {
			if (blo[j].x > tmp + 1) {
				cur[c].x = tmp + 1; cur[c].y = blo[j].x - 1;
				c++;
			}
			tmp = blo[j].x;
		}
		if (n > tmp) {
			cur[c].x = tmp + 1; cur[c].y = n; c++;
		}
		
		int t = 0;
		for (int i = 0; i < cnt; i++) {
			while (cur[t].x <= rec[i].y && t < c) {
				if (cur[t].y >= rec[i].x) {
					cur[t].x = max(cur[t].x, rec[i].x);
				} else {
					cur[t].x = cur[t].y = -1;
				}
				t++;
			}
			if (t >= c) break;
		}
		
		cnt = 0;
		for (int i = 0; i < t; i++) if (cur[i].x != -1 && cur[i].y != -1) {
			rec[cnt].x = cur[i].x; rec[cnt].y = cur[i].y;  cnt++;
		}
		if (cnt == 0) return false;
		i = k;
	}

	if (blo[m-1].y != n) return true;
	if (rec[cnt-1].y == n) return true;
	return false;
}

int main () {
	init();
	if (judge()) cout << 2 * n - 2 << endl;
	else printf("-1\n");
	return 0;
}
