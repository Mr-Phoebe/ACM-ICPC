#include<stdio.h>
int main()
{
	freopen("data.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,k;
	while(~scanf("%i %i",&n,&k))
	{
		printf("%d %d\n",n,k);
		int a=1,b=1+k;
		while(a<b) printf("%i %i ",a++,b--);
		if(a==b) printf("%i ",a);
		for(int i=2+k;i<=n;i++) printf("%i ",i);
		puts("");
	}
	return 0;
}