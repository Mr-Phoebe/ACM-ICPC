#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int a,n,k,ans=0;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		a=5-a;
		if(a>=k)
			ans++;
	}
	ans/=3;
	printf("%d\n",ans);
	return 0;
} 