#include<iostream>

using namespace std;

int main()
{
	int n,i,j,k,min=0;
	int a[100],f[101][101]={0};
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=n-2;i>=0;i--)
		for(j=i+2;j<n;j++)
		{
			min=2147483647;
			for(k=i+1;k<=j-1;k++)
				if(min>f[i][k]+f[k][j]+a[i]*a[j]*a[k])
					min=f[i][k]+f[k][j]+a[i]*a[j]*a[k];
			f[i][j]=min;
		}
	cout<<f[0][n-1]<<endl;
	return 0;
} 