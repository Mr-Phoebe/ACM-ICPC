#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include <algorithm>
#include<cstring>
#include<string>
using namespace std;

int main()
{
	int n, d,a[101];
	int i,total,left,sum;
	scanf("%d %d", &n, &d);
	total = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		total += a[i];
		total += 10;
	}
	total -= 10;
	if (total>d)
		printf("-1\n");
	else
	{
		left = d - total;
		sum = left / 5;
		sum += 2 * (n - 1);
		printf("%d\n", sum);
	}
	return 0;
}
