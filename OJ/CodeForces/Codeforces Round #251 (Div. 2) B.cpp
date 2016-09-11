#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include <algorithm>
#include<cstring>
#include<string>

using namespace std;

const int MAXN=100010;
int c[MAXN],n,x;
long long sum=0;

int main()
{
	scanf("%d %d",&n,&x);
	for(int i=0;i<n;i++)
		scanf("%d",&c[i]);
	sort(c,c+n);
	for(int i=0;i<n;i++)
	{
		sum+=(long long)c[i]*(long long)x;
		x--;
		x=max(1,x);
	}
	printf("%I64d\n",sum);
	return 0;
} 
