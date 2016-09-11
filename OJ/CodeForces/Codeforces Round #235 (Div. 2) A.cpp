#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int n,x;
	int sum=0;
	cin>>n>>x;
	for(int i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		sum+=temp;
	}
	sum=fabs(sum);
	if(sum%x==0)
		cout<<sum/x<<endl;
	else
		cout<<sum/x+1<<endl;
	return 0;
} 