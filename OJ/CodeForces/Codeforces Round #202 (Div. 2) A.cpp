#include<iostream>
#include<cstdio>

using namespace std;

int rest[3]={0};
int mon;
bool ok;

int main()
{
	int n;
	cin>>n;
	ok=true;
	for(int i=0;i<n;i++)
	{
		cin>>mon;
		if(mon==100)
		{
			rest[2]++;
			if(rest[1]==0&&rest[0]>=3)
			{
				rest[0]-=3;
			}
			else
			{
				rest[0]--;rest[1]--;
			}
			if(rest[1]<0||rest[0]<0)
				ok=false;
		}
		else if(mon==25)
			rest[0]++;
		else if(mon==50)
		{
			rest[0]--;
			rest[1]++;
			if(rest[0]<0)
				ok=false;
		}
	}
	if(ok)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
