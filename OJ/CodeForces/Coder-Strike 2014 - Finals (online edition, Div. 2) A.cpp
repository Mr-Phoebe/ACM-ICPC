#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int n,a,b,s[111]={0},temp;
	scanf("%d %d %d",&n,&a,&b);
	for(int i=0;i<a;i++)
	{
		scanf("%d",&temp);
		s[temp]=1;
	}
	for(int i=0;i<b;i++)
	{
		scanf("%d",&temp);
		s[temp]=2;
	}
	for(int i=1;i<=n;i++)
		printf("%d%c",s[i],i==n ? '\n':' ');
		
	return 0;	
} 