#include<iostream>

using namespace std;

int main()
{
	int n,i,k=0;
	long int v=0;
	int a[10000];
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		v+=a[i];
	}
	v/=n;
	for(i=0;i<n-1;i++)
		if(a[i]!=v)
		{
		a[i+1]+=a[i]-v;
		k++;
		}
	cout<<k<<endl;
	return 0;
}
 
 