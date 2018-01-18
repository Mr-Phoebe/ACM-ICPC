#include<iostream>

using namespace std;

int main()
{
	int a,b;
	int n,m;
	long long ans=0;
	cin>>a>>b;
	n=a,m=0;
	while(n!=0||m>=b)
	{
		n--;
		ans++;
		m++;
		if(m==b)
		{
			n++;
			m=0;
		}
	}
	cout<<ans<<endl;
	return 0;
} 