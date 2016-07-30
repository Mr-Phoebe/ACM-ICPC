#include<iostream>

using namespace std;

int num[4444];

int main()
{
	int x,k;
	int kind;
	cin>>x>>k;
	for(int i=0;i<k;i++)
	{
		cin>>kind;
		if(kind==1)
		{
			int a,b;
			cin>>a>>b;
			num[a]++;
			num[b]++;
		}
		else
		{
			int a;
			cin>>a;
			num[a]++;
		}
	}
	int con=0;
	int mi=0,ma=0;
	for(int i=1;i<x;i++)
	{
		if(!num[i])
		{
			con++;
			ma++;
		}
		else
		{
			if(!(con&1))
				mi+=con/2;
			else
				mi+=con/2+1;
			con=0;
		}
	}
	if(!(con&1))
		mi+=con/2;
	else
		mi+=con/2+1;
	cout<<mi<<" "<<ma<<endl;
	return 0;
}