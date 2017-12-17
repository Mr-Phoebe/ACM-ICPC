#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define LOCAL
using namespace std;

int n,a[100005],f[100005];

int main()
{
//    freopen("input.txt","r",stdin);
    cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	f[1]=1;
	for (int i=2;i<=n;i++)
	{
		f[i]=1;
		if (a[i]>a[i-1]) f[i]=f[i-1]+1;
	}
	for(int i=1;i<=n;i++)cout<<f[i]<<' ';cout<<endl;
	int ans=-1;
	for (int i=n;i>=1;i--)
	{
		if(f[i]==n) ans=max(f[i],ans);
		else ans=max(ans,f[i]+1);
		if (a[i-f[i]+1]-1>a[i-f[i]-1]) ans=max(ans,f[i]+f[i-f[i]]);
		if (a[i-f[i]+2]-1>a[i-f[i]]) ans=max(ans,f[i]+f[i-f[i]]);
	}
	cout<<ans<<endl;
	return 0;
}


