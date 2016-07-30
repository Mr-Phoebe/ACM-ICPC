#include<iostream>

using namespace std;

int min(int a,int b)
{
	return a>b?b:a;
}

int main()
{
	int n,c;
	int a[111]={0},diff[111];
	int m=1000;
	cin>>n>>c;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		diff[i-1]=a[i]-a[i-1];
	}
	for(int i=1;i<=n-1;i++)
		m=min(m,diff[i]);
	if(-m-c<=0)
		cout<<"0"<<endl;
	else 
		cout<<-m-c<<endl;
	return 0;
}