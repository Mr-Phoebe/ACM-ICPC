#include<stdio.h>
#include<math.h>

int mersenne(int n)
{
	int i,k;
	for(n=n+1;1;n++)
	{
		k=(int)(floor(sqrt(n)));
		for(i=2; i<=k; i++)
				if((n%i) == 0)
					break;
		if(i>=(k+1))
			break;
	}
	return n;
}

int main()
{
	int i,n,temp,k;
	int result1=0,result2=0;
	scanf("%d",&n);
	while(n--)
	{
		i=1;
		scanf("%d",&k);
		temp=k;
		while(temp!=1)
		{
			i=mersenne(i);
			while(temp%i==0)
				temp/=i;
		}
		if(i>result2)
		{
			result2=i;
			result1=k;
		}
	}
	printf("%d\n",result1);
	return 0;
}