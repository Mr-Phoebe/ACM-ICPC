#include<iostream>

using namespace std;
	
long int g[30001],f[300001];

int max(long int x,long int y)
{
	return x>y? x:y;
}

int main()
{
	long int i,j,m,s,t;
	cin>>m>>s>>t;
	for(i=1;i<=t;i++)
	{
		f[i]=max(f[i-1],g[i-1])+17;
		if(m>=10)
		{
			m-=10;
			g[i]=g[i-1]+60;
		}
		else
		{
			g[i]=g[i-1];
			m+=4;
		}
		if(f[i]>=s || g[i]>=s)
		{
			cout<<"Yes"<<endl;
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<"No"<<endl;
	cout<<max(f[t],g[t])<<endl;
	return 0;
} 