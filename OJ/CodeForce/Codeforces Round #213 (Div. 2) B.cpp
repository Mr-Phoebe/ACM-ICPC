#include<iostream>

using namespace std;

int num[111111],ans,k;

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>num[i];
	ans=min(2,n);
	k=2;
	for(int j=2;j<n;j++)
	{
		if(num[j-2]+num[j-1]==num[j])
			k++;
		else
			k=2;
		ans=max(ans,k);
	}
	cout<<ans<<endl;
	return 0;
}