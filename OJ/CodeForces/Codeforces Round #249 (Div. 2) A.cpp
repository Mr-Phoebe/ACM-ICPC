#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int n,m;
	int temp,ans=1;
	scanf("%d %d",&n,&m);
	temp=m;
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		if(temp<a)
		{
			ans++;
			temp=m-a;
		}
		else
			temp-=a;
	}
	printf("%d\n",ans);
	return 0;
}