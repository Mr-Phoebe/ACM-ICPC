#include<iostream>

using namespace std;

int n;
int a[100010],b[100010];
__int64 joy=0;


int main() 
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		cin>>b[i];
	for(int i=0;i<n;i++)
	{
		if(2*a[i]<b[i])
			joy--;
		else
		{
			__int64 u=b[i]/2,v=b[i]-u;
			if(u==0||v==0)
				joy--;
			else
				joy+=u*v;
		}
	}
	cout<<joy<<endl;
}