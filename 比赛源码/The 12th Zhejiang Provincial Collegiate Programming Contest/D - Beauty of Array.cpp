//By LH
#pragma warning(disable:4996)
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <cmath>
#include <functional>
#include <numeric>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;

typedef long long LL;

int n, T;
LL ans;
int pre[1000005];

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		int maxx = 0;
		ans = 0;
		memset(pre, 0, sizeof(pre));
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			maxx = max(x, maxx);
			LL tmp = LL(pre[x]) * LL(i - pre[x]) * LL(x);
			ans += tmp;
			pre[x] = i;
		}
		for (int i = 1; i <= maxx; i++)
		if (pre[i] != 0)
		{
			LL tmp = LL(pre[i]) * LL(n - pre[i]+1) * LL(i);
			ans += tmp;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
