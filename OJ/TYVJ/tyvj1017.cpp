#include<iostream>

using namespace std;

int main()
{
	int n,m,a,b,i,j,k,max=0;
	int f[1000]={0};
	cin>>n>>m;
	for(i=0;i<m;i++)
		f[i]=i+1;
	for(i=0;i<n;i++)
	{
		cin>>a>>b;
		if(f[a-1]==f[b-1])
			max++;
		else
		{
			k=f[b-1];
			for(j=0;j<m;j++)
				if(f[j]==k)
					f[j]=f[a-1];
		}
	}
	cout<<max<<endl;
	return 0;
}