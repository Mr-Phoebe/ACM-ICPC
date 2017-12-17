#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int N = 3e5 + 5;

int n, p, d[N], b[N], x[N];
ll ans, a[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> p;
	for (int i = 0; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		if (u > v)
			swap(u, v);
		d[u]++, d[v]++;
		a[i] = 1ll * u * n + v;
	}
	copy(d, d + n, b);
	sort(b, b + n);
	for (int i = 0; i < n; i++)
		ans += b + n - lower_bound(b + i + 1, b + n, p - b[i]);
	{
		sort(a, a + n);
		int cnt = 1;
		for (int i = 1; i < n; i++)
			if (a[i] == a[cnt - 1])
				x[cnt - 1]++;
			else
				a[cnt++] = a[i];
		for (int i = 0; i < cnt; i++) {
			int u = a[i] / n, v = a[i] % n;
			if (d[u] + d[v] >= p && d[u] + d[v] - x[i] - 1 < p)
				ans--;
		}
	}
	cout << ans << '\n';
	return 0;
}