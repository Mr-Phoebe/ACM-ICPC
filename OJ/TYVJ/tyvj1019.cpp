#include<stdio.h>
#include<math.h>
#include<stdlib.h>


int cmp(const void*a,const void* b)
{	return (*(int*)a-*(int*)b);}



int main()
{
	int a[10000],b[10000];
	int n,i,sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);
	qsort(a,n,sizeof(a[0]),cmp);
	qsort(b,n,sizeof(a[0]),cmp);
	for(i=0;i<n;i++)
		sum+=fabs(a[i]-b[n-1-i]);
	printf("%d\n",sum);
	return 0;
}