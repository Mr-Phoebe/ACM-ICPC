#include<iostream>
#include<algorithm>

using namespace std;

int max(int a,int b)
{
	return a>b?a:b;
}


int w[2010],f[2010][510];

int main()
{
//	freopen("data.txt","r",stdin);
//	freopen("data2.txt","w",stdout);
	int i,j,n,m;
	
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>w[i];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			f[i][j]=max(f[i-1][j-1]+w[i],f[i][j]);
			if(i>j)
				f[i][0]=max(f[i-j][j],f[i][0]);
			f[i][0]=max(f[i-1][0],f[i][0]);
		}
	}
	cout<<f[n][0]<<endl;

	return 0;
}