#include<iostream>

using namespace std;

typedef long long ll;

ll a[1000000];
const int mod=1000000000;

int main()
{
	ll n;
	cin>>n;
	a[1]=1;
	a[2]=2;
	for(ll i=3;i<=n;i++)
		if(i&1)
			a[i]=a[i-1]%mod;
		else
			a[i]=(a[i-2]+a[i/2])%mod;
	cout<<a[n]<<endl;
	return 0;
} 