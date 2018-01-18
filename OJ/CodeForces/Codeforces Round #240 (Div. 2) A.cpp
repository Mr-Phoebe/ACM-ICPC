#include<iostream>

using namespace std;

int b[111],a[111];

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>b[i];
	for(int i=1;i<=m;i++)
	{
		for(int j=b[i];j<=n&&a[j]==0;j++)
		{
			a[j]=b[i];
		}
	}
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
} 