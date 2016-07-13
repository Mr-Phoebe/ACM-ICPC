#include <stdio.h>
int main()
{
    int n, m, i, s = 0;
    printf ("N M = ");
    scanf("%d%d", &n, &m);
    for (i = 2; i <= n; i++)
    {
        s = (s + m) % i;
    }
    printf ("\nThe winner is %d\n", s+1);
}

#include<iostream>
#include<cstdio>

using namespace std;

const int maxn=10000+2;
int f[maxn];

int main
{
	int n,k,m;
	while(scanf("%d,%d,%d",&n,&k,&m)==3&&n)
	{
		f[1]=0;
		for(int i=2;i<=2;i++)
			f[i]=(f[i-1]+k)%i;
		int ans=(m-k+1+f[n])%n;
		if(ans<=0)
			ans+=n;
		printf("%d\n",ans);
	}
	return 0;
} 