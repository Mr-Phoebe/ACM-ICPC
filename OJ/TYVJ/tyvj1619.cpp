#include<iostream>

using namespace std;

int gcd(int a,int b)
{
	int temp;
	while(b!=0)
	{	
		temp=b;
		b=a%b;
		a=temp;
	}
	return a;
}
int main()
{
	int a[500];
	int i,j,n;
	int temp;
	cin>>n;
	cin>>a[0]>>a[1];
	temp=gcd(a[0],a[1]);
	for(i=2;i<n;i++)
	{
		cin>>a[i];
		temp=gcd(a[i],temp);
	}
	cout<<temp<<endl;
	return 0;

}

