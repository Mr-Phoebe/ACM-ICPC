#include <iostream>
#include <cstdio>

using namespace std;

int c[100010];
int main()
{
    int n, k, i, x;
    scanf("%d%d", &n, &k);
    for (i = 0; i < n; i++)
	{
        scanf("%d", &x);
        c[i % k] += x;
    }
    x = 0;
    for (i = 0; i < k; i++)
        if (c[i] < c[x])
			x = i;
    printf("%d\n", x + 1);
    return 0;
}