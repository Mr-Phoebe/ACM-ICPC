#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;

const int m=9901;
	int a[1000],f[1000][1000];
int main()
{
	int n,i,j,x,ans=0;

	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	memset(f,0,sizeof(f));
	for(i=0;i<n;i++)
	{
		ans++;	
		for(j=i-1;j>=0;j--)
		{
			x=a[i]-a[j];
			f[i][x]=f[j][x]+1;
			ans+=f[i][x];
		}
		
	}
	cout<<ans<<endl;
	return 0;
}