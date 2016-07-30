#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

const int inf=111111111;

struct fri
{
	int x,k,m[22];
	bool operator < (fri b) const
	{
		return k<b.k;
	}
}a[111];


int main()
{
	int n,m,d,mi,temp,mat=-inf;
	scanf("%d %d %d",&n,&m,&d);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d",&a[i].x,&a[i].k,&mi);
		for(int j=0;j<mi;j++)
		{
			scanf("%d",&temp);
			a[i].m[temp]++;
		}
	}
	sort(a,a+n);
	for(int i=0;i<n;i++)
		cout<<a[i].x<<" "<<a[i].k<<endl;
		
		
	return 0;
}