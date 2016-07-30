#include<iostream>
#include<cstdio>

using namespace std;

int n,t,c,a,num=0,ans=0;

int main()
{
	scanf("%d %d %d",&n,&t,&c);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		if(a>t)
		{
			ans+=max(num-c+1,0);
			num=0;
		}
		else
			num++;
	}
	ans+=max(num-c+1,0);
	printf("%d\n",ans);
	return 0;
} 