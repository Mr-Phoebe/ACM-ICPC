#include<iostream>   
#include<cstdio>
using namespace std;
    
int main()
{
	int n,k;
	while(~scanf("%d%d",&n,&k))
	{
		long t=n&k;
		if(t == k)
		printf("1\n");
		else
		printf("0\n");
	}
	return 0; 
}