#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;


int main()
{
	int n,a[111],mi=111111111;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int j=0;j<n;j++)
	{
		int sum=0,temp;
		for(int i=0;i<a[j];i++)
		{
			scanf("%d",&temp);
			sum+=temp*5;
			sum+=15;
		}
		mi=min(mi,sum);
	}
	printf("%d\n",mi);
	return 0;
} 