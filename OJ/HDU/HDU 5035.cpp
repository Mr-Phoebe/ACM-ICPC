#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

double a[1001];

int main()
{
	int T,n,cas=1;
	scanf("%d",&T);
	while(T--)
	{
		double sum=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%lf",&a[i]);
			sum+=a[i];
		}
		for(int i=0,temp;i<n;i++)
			scanf("%d",&temp);
		printf("Case #%d: %.6f\n",cas++,(n+1.0)/sum);
	}
	return 0;
}