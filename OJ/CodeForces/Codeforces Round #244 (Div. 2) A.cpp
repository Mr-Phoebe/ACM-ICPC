#include<iostream>

using namespace std;

int main()
{
	int sum=0,ans=0,n;
	cin>>n;
	int temp;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		if(sum+temp<0)
			ans++;
		else
			sum+=temp;
	}
	cout<<ans<<endl;
	return 0;
} 