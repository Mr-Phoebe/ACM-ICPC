#include<iostream>

using namespace std;

int main()
{
	char str[14] ;
	int k=1;
	int sum=0;
	
	cin>>str;
	for(int i=0;i<=11;i++)
		if(str[i]!='-')
			{
			sum+=k*((int)str[i]-'0');
			k++;
			}
	sum%=11;
	if(sum==10)
		if(str[12]=='X')
		{
			cout<<"Right"<<endl;
			return 0;
		}
		else
		{
			str[12]='X';
			cout<<str<<endl;
			return 0;	
		}
	if(str[12]==sum+48)
		cout<<"Right"<<endl;
	else
	{
		str[12]=sum+48;
		cout<<str<<endl;
	}
			
	
}