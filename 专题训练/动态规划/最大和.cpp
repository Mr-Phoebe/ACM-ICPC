#include<iostream>

using namespace std;


int main()
{
	int a[100],f[10000];
	int i,n,m,j;
	cin>>n;cin>>m;
	for(i=0;i<n;i++)
		cin>>a[i];
	f[0]=0;
	memset(f,0,10000);
	for(i=0;i<n;i++)
		{
			for(j=m;j>=a[i]+1;j--)
				if(f[j-a[i]]>0)
					f[j]=f[j-a[i]]+f[j];
			if(f[a[i]]==0)
				f[a[i]]=1;
			else
				f[a[i]]++;
		}
	cout<<f[m]<<endl;
	return 0;
}