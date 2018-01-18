#include<iostream>
#include<algorithm>

using namespace std;

int f[200001];
long int sum[200001],a[200001],g[200001];

int main()
{
	int i,j,k,n;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	f[1]=1;
	g[1]=a[1];
	for(i=1;i<=n;i++)
	{
		j=i-1;
		while(sum[i]-sum[j]<g[j])
			j--;
		f[i]=f[j]+1;
		g[i]=sum[i]-sum[j];
	}
	cout<<n-f[n]<<endl;
	return 0;
}