#include <cstdio>

typedef long long lli;

int bc[1<<20], sum[1<<20], tmp[1<<20];
int C[21][21];
lli f[21][21], fact[21];

lli gcd(lli a, lli b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

void init()
{
	int i, j;
	bc[0] = 0;
	for (i=1; i<(1<<20); i++) bc[i] = bc[i^(i&-i)] + 1;
	fact[0] = 1;
	for (i=1; i<=20; i++) fact[i] = fact[i-1] * i;
	C[0][0] = 1;
	for (i=1; i<=20; i++)
	{
		C[i][0] = C[i][i] = 1;
		for (j=1; j<i; j++) C[i][j] = C[i-1][j] + C[i-1][j-1];
	}
	f[0][0] = f[0][1] = 1;
	for (i=1; i<=20; i++)
	{
		f[i][0] = 1;
		for (j=1; j<i; j++) f[i][j] = f[i-1][j] + f[i][j-1];
		f[i][i] = f[i][i+1] = f[i][i-1];
	}
}

int main()
{
	lli a, b, d;
	int p, n, m, t, i;
	init();
	scanf("%d", &t);
	while (t --)
	{
		scanf("%d %d %d", &p, &n, &m);
		for (i=0; i<m; i++) scanf("%d", &tmp[1<<i]);
		sum[0] = 0;
		for (i=1; i<(1<<m); i++) sum[i] = sum[i^(i&-i)] + tmp[i&-i];
		a = 0;
		for (i=0; i<(1<<m); i++)
		{
			if (sum[i] >= p && bc[i] <= n + 1)
			{
				a += C[n][bc[i]-1] * f[bc[i]-1][bc[i]] * fact[bc[i]-1] * fact[bc[i]] * fact[n+m-2*bc[i]+1];
				if (bc[i] == m && bc[i] < n + 1) a += f[n][m] * fact[n] * fact[m]; 
			}
		}
		b = fact[n+m];
		d = gcd(a, b);
		printf("%I64d/%I64d\n", a / d, b / d);
	}
	return 0;
}
