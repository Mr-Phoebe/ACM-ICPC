#include<iostream>
#include<string>
#include<ctype.h>

using namespace std;

string stick;

int main()
{
	int pos;
	long long left=0,right=0;
	cin>>stick;
	pos=stick.find('^');
	for(int i=0;i<pos;i++)
		if(isdigit(stick.at(i)))
			left+=((int)stick.at(i)-48)*(pos-i);
	int len=stick.length();
	for(int i=pos+1;i<len;i++)
		if(isdigit(stick.at(i)))
			right+=((int)stick.at(i)-48)*(i-pos);
	if(right==left)
		cout<<"balance"<<endl;
	else if(right>left)
		cout<<"right"<<endl;
	else
		cout<<"left"<<endl;
	return 0;
} 