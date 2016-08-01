#include<iostream>

using namespace std;

int main()
{
	int budget[12];
	int save=0,cash=0,mon,i,temp;//save单位是100元
	bool overdraft=false;
	for(i=0;i<12;i++)
	{
		cin>>budget[i];
		if(budget[i]>(cash+=300)&&!overdraft)
		{
			overdraft=true;
			mon=i+1;
		}
		else
		{
			temp=save;
			save+=(cash-budget[i])/100;
			cash-=(save-temp)*100+budget[i];
		}
	}
	if(overdraft)
		cout<<"-"<<mon<<endl;
	else
	{
		save*=120;
		cout<<save+cash<<endl;
	}
	return 0;

}

