#include<iostream>
#include<algorithm> 

using namespace std;
long long int a[10000],sum=0;
static int k=0;

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++)
		for(int j=i;j<n;j++)
			sum+=a[j]-a[i];		

	cout<<sum*2;
	return 0;
} 





