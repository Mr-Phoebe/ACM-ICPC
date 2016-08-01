#include<stdio.h>
#include<string.h>

int main()
{
	int a,b;
	scanf("%d",&a);
	printf("1 %d ",a);
	if(a%2==0)
	{
		for(b=1;b<=(a-2)/2-1;b++)
			printf("%d %d ",1+b,a-b);
		printf("%d %d",a/2,a/2+1);
	}
	else
	{
		for(b=1;b<=(a-1)/2-1;b++)
			printf("%d %d",1+b,a-b);
		printf("%d",(a+1)/2);
	}

	printf("\n");
    return 0;   
}