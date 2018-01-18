#include <cstdio>

typedef long long lli;

lli gcd(lli a, lli b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main()
{
	lli a, b, d;
	int n, m;
	while (scanf("%d %d", &n, &m), n > 0)
	{
		a = 1LL * (m - 1) * n;
		b = 1LL * m * m;
		d = gcd(a, b);
		printf("%I64d/%I64d\n", a / d, b / d);
	}
	return 0;
}
