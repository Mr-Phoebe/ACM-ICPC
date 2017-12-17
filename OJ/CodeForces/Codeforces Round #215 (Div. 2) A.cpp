#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int n,m,d;
	long long sum;
	int a[111];
	cin>>n>>d;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	cin>>m;
	sum=m>n?(n-m)*d:0;
	for(int i=0;i<m&&i<n;i++)
		sum+=a[i];
	cout<<sum<<endl;
	return 0;
} 