
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

int n, T, ans;

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		ans = 0;
		for (int i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			if (x > 6000) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
