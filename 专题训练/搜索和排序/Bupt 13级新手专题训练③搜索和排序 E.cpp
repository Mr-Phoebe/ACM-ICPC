#include <stdio.h>

int main ()
{
	long t,a[52],num,i,j,temp;
	scanf("%ld", &t);
	while(t)
	{
		scanf("%ld",&num);
		for (i=0;i<num;i++)
			scanf("%ld", &a[i]);
		int count=0;
		for(i=0;i<num;i++)
			for(j=i+1;j<num;j++)
				if(a[i]>a[j])
				{
					temp=a[i];
					a[i]=a[j];
					a[j]=temp;
					count++;
				}
		printf("Optimal train swapping takes %ld swaps.\n", count);
		t--;
	}
	return 0;
}