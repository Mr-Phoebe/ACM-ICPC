#include <cstdlib>
#include <cmath>
#include <iostream>
#include <memory>
#include <string>
#include <cstdio>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))

const int lim = 10000000;
int occ[lim + 1];
int cnt[lim + 1];
bool npr[lim + 1];


int main()
{
	int n, x, y, m;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &x);
		++occ[x];
	}

	for (int i = 2; i * i <= lim; ++i)
		if (!npr[i])
			for (int j = i * i; j <= lim; j += i)
				npr[j] = true;

	for (int i = 2; i <= lim; ++i)
	{
		cnt[i] = cnt[i - 1];
		if (!npr[i])
			for (int j = i; j <= lim; j += i)
				cnt[i] += occ[j];
	}
	scanf("%d", &m);
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d", &x, &y);
		printf("%d\n", cnt[min(lim, y)] - cnt[min(lim, x - 1)]);
	}
}