#include <iostream>
#include <map>
#include <cmath>
using namespace std;
typedef long long ll;
const int MAXN = 501; const ll MOD = 1e9 + 7;
ll c[MAXN * 32][MAXN];
map<int, int> cnt;
int main()
{
	for (int i = 0; i < MAXN * 32; i++)
		for (int j = 0; j < MAXN; j++)
		{
			if (j == 0 || j == i)
				c[i][j] = 1;
			if (j > 0 && j < i)
				c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
		}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		for (int j = 2; j * j <= a; j++)
			while (a % j == 0)
			{
				a /= j;
				cnt[j]++;
			}
		if (a > 1) cnt[a]++;
	}
	ll ans = 1;
	for (map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++){
		int cur = it->second;
		ans = (ans * c[cur + n - 1][n - 1]) % MOD;
	}
	cout << ans << endl;
	return 0;
}