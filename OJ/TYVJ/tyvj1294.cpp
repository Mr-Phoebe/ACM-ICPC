#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
	int i,n,sum=0,a[301]={0};
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(i=0;i<n/2;i++)
		sum+=fabs(a[n-i-1]-a[i])*2;
	cout<<sum<<endl;
	return 0;
}