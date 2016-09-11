#include<iostream>

using namespace std;

int main()
{
	int a,b;
	cin>>b>>a;
	if(b>a+1)
		cout<<"-1"<<endl;
	else if((double)a/2.0>b+1)
		cout<<"-1"<<endl;
	else
	{
		while(a&&b)
		{
			if(a>b+1)
			{
				if(a>=2)
				{
					cout<<"11";
					a-=2;
				}
				else
				{
					cout<<"1";
					a--;
				}	
				cout<<'0';
				b--;		
			}
			else
			{
				if(a>b) 
					cout<<"10";
				else
					cout<<"01";
				a--;b--;
			}
		}
		for(int i=1;i<=a;i++)
			cout<<"1";
		for(int i=1;i<=b;i++)
			cout<<"0";	
		cout<<endl;
	}
	return 0;
} 