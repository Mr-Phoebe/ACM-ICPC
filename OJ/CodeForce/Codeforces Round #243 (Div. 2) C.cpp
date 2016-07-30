#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 311;
const int inf = 0x3f3f3f3f;
int a[N];
int n,k;

int ta[N],tb[N];
int get(int x,int y)
{
	int sa,sb;
	sa=sb=0;
	for(int i=1;i<=n;i++)
		if(i<x||i>y)
			ta[++sa]=a[i];
	for(int i=x;i<=y;i++)
		tb[++sb]=a[i];
	sort(ta+1,ta+sa+1);
	sort(tb+1,tb+sb+1);
	int sum=0;
	for(int i=x;i<=y;i++)
		sum+=a[i];
	for(int z=1;z<=k;z++)
		if(sa >= z && z <=sb && ta[sa-z+1]>tb[z] )
			sum += ta[sa-z+1]-tb[z];
	return sum;
}
int main()
{
	scanf("%d %d",&n,&k);
	for(int i = 1;i <= n;i++)
		scanf("%d",&a[i]);
	int ans=-inf;
	int tmp;
	for(int i=1;i<=n;i++)			//枚举起点和终点 
		for(int j=i;j<=n;j++)
			ans = max(ans,get(i,j));
	printf("%d\n",ans);
	
	return 0;
}