#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

int main()
{
	int i,k=0;
	string s;
	while(getline(cin,s))
	{
		for(i=0;i<s.length();i++) if(s[i]!=' ') break;
		if(i==s.length() || s[i]!='#')
		{
			if(k==2) cout<<endl;
			for(i=0;i<s.length();i++) if(s[i]!=' ') cout<<s[i];
			k=1;
		}
		else
		{
			if(k) cout<<endl;
			cout<<s;
			k=2;
		}
	}
	cout<<endl;
	return 0;
}
