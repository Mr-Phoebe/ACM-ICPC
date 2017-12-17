#include<iostream>

using namespace std;

int main()
{
	int max=8,day=0;
	int a,b,i;
	bool un=false;
	for(i=0;i<7;i++)
	{
		cin>>a>>b;
		if(a+b>8)
			un=true;
		if(a+b>max)
		{
			max=a+b;
			day=i+1;
		}
	}
	if(un)
		cout<<day<<endl;
	else
		cout<<"0"<<endl;
	return 0;

}

