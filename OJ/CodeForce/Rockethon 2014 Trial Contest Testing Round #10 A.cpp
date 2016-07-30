#include<iostream>

using namespace std;

int  a[1000010];
int n,q;
int ans=0;

int main()
{
	cin>>n>>q;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		a[x]++;
	}
	for(int i=0;i<=q/2;i++)
	{
		if(i==q-i)
		{
			ans+=a[i]/2; 
			break;
		}
		int m=min(a[q-i],a[i]);
		ans+=m;
		a[i]-=m;
		a[q-i]-=m;
	}
	cout<<ans<<endl;
	return 0;
}