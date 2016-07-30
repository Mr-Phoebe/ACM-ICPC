#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int n;
	char ch;
	__int64 ans=0;
	cin>>n;
	getchar();
	for(int i=0;i<n;i++)
	{
		ch=getchar();
		if(ch=='B')
			ans+=((__int64)1)<<i;
	}
	cout<<ans<<endl;
	return 0;
} 