#include<stdio.h>
#include<string.h>

int a[1111][1111];

int main()
{

	int i,l,p,n;
	bool ok;
    scanf("%d",&n);
	memset(a,0,sizeof(a));
	for(i=1;i<=n;i++)
		scanf("%d",&a[1][i]);
	l=n;p=2;
	while(1)
	{
		for(i=1;i<=l-1;i++)
			a[p][i]=a[p-1][i+1]-a[p-1][i];
		l--;
		ok=true;
		for(i=2;i<=l;i++)
			if(a[p][i]!=a[p][i-1])
			{
				ok=false;
				break;
			}
		if(ok)
			break;
		p++;
	}
	for(i=p;i>=1;i--)
	{
		l++;
		a[i][l]=a[i][l-1]+a[i+1][l-1];
	}
	printf("%d\n",a[1][l]);
    return 0;   
}