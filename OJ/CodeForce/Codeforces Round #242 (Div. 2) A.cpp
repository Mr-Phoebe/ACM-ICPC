#include<iostream>
#include<string>
#include<cstdio> 

using namespace std;

string a;

int main()
{
	int n,ans,X=0,temp=0;
	cin>>n;
	cin>>a;
	for(int i=0;i<a.length();i++)
		if(a.at(i)=='X')
			X++; 
	ans=n/2-X;
	for(int i=0;ans>0&&i<n&&temp<ans;i++)
	{
		if(a.at(i)=='x')
		{
			a.at(i)='X';
			temp++;
		}	
	}
	for(int i=0;ans<0&&i<n&&temp>ans;i++)
	{
		if(a.at(i)=='X')
		{
			a.at(i)='x'; 
			temp--;
		}
	}
	cout<<(ans>0?ans:-ans)<<endl;
	cout<<a<<endl;
	return 0;
}