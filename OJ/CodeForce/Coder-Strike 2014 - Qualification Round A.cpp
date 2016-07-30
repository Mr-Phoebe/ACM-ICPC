#include<iostream>
#include<string>

using namespace std;

int main()
{
	string str;
	bool a=false,A=false,n=false;
	cin>>str;
	if(str.length()<5)
	{
		cout<<"Too weak"<<endl;
		return 0;
	}
	for(int i=0;i<str.length();i++)
	{
		if(str.at(i)<='z'&&str.at(i)>='a')
			a=true;
		else if(str.at(i)<='Z'&&str.at(i)>='A')
			A=true;
		else if(str.at(i)>='0'&&str.at(i)<='9')
			n=true;
	}
	if(n&&A&&a)
		cout<<"Correct"<<endl;
	else
		cout<<"Too weak"<<endl;
	return 0; 
} 