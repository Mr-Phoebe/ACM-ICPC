#include<iostream>

using namespace std;

int max(int a,int b)
{
	return a>b?a:b;
}

int main()
{
	int a[111][111]={0},f[111][111]={0};
	int n,i,j;
	cin>>n;
	for(i=0;i<n;i++)
		for(j=0;j<=i;j++)
			cin>>a[i][j];
	for(i=0;i<n;i++)
		f[n-1][i]=a[n-1][i];
	for(i=n-2;i>=0;i--)
		for(j=0;j<=i;j++)
			f[i][j]=max(f[i+1][j],f[i+1][j+1])+a[i][j];
	cout<<f[0][0]<<endl;
	return 0;
}