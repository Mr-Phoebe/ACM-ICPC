#include<iostream>
#include<cstdlib>

using namespace std;

long min(long a,long b)
{
	return a<b? a:b;
}

int main()
{
	long int i,j,n,x;
	long int a[101][2],c[101],f[101][2];
	cin>>n;
	memset(f,sizeof(f),0);
	for(i=1;i<=n;i++)
		{
		for(j=0;j<2;j++)
			cin>>a[i][j];
		cin>>c[i];
		}
	f[0][1]=0;
	for(i=1;i<=n;i++)
		for(j=0;j<2;j++)
		{
			f[i][j]=min(f[i][j],f[i-1][j]+a[i][j]);
			f[i][j]=min(f[i][j],f[i-1][1-j]+c[i]+a[i][j]);
		}
	cout<<min(f[n][0],f[n][1])<<endl;
}