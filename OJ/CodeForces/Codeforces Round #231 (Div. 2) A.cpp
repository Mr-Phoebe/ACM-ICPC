#include<iostream>
#include<string>

using namespace std;

string str;

int main()
{
	while(cin>>str)
	{
		int p=str.find('+');
		int num1=p;
		int e=str.find('=');
		int num2=e-p-1;
		int num3=str.length()-e-1;
		if(num3==num2+num1)
			cout<<str<<endl;
		else if(num3>num1+num2)
		{
			int temp=num3-num1-num2;
			if(temp>2||temp&1)
				cout<<"Impossible"<<endl;
			else
			{
				num1+=temp/2;
				num3-=temp/2;
				for(int i=0;i<num1;i++)
					cout<<"|";
				cout<<"+";
				for(int i=0;i<num2;i++)
					cout<<"|";
				cout<<"=";
				for(int i=0;i<num3;i++)
					cout<<"|";
				cout<<endl;
			}
		}
		else if(num3<num2+num1)
		{
			int temp=num2+num1-num3;
			if(temp&1||temp>2)
				cout<<"Impossible"<<endl;
			else
			{
				if(num2>num1)
					num2-=temp/2;
				else
					num1-=temp/2;
				num3+=temp/2;
				for(int i=0;i<num1;i++)
					cout<<"|";
				cout<<"+";
				for(int i=0;i<num2;i++)
					cout<<"|";
				cout<<"=";
				for(int i=0;i<num3;i++)
					cout<<"|";
				cout<<endl;
			}				
		}
		str.clear();
	}
	return 0;
}