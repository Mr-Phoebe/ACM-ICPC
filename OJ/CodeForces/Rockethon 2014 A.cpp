#include<iostream>
#include<string>

using namespace std;

string str;

int main()
{
	int ans=0,i;
	int len=1;
	cin>>str;
	for(i=1;i<str.length();i++)
	{
		if(str.at(i)!=str.at(i-1))
		{
			if(!(len&1))
			{
				ans++;
				len=1;
			}
		}	
		else
			len++;
	}
	if(!(len&1))
		ans++;

	cout<<ans<<endl;
	return 0;
}
 