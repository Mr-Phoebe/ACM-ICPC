#include<iostream>
#include<string>

using namespace std;

int main()
{
	string numt,slt;
	cin>>numt>>slt;
	int hour,minute;
	minute=10*((int)numt.at(3)-48)+(int)numt.at(4)-48-10*((int)slt.at(3)-48)-(int)slt.at(4)+48;
	hour=10*((int)numt.at(0)-48)+(int)numt.at(1)-48-10*((int)slt.at(0)-48)-(int)slt.at(1)+48;
	if(minute<0)
	{
		minute+=60;
		hour--;
	}
	if(hour<0)
		hour+=24;
	numt.at(0)=hour/10+48;numt.at(1)=hour%10+48;
	numt.at(3)=minute/10+48;numt.at(4)=minute%10+48;
	cout<<numt<<endl;
	return 0;
} 