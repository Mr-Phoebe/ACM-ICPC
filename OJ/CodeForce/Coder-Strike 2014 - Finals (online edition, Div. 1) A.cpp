#include<iostream>
#include<string>

using namespace std;

string a;
int b[30];
// AHOIUYTWXVM
int main()
{
	cin>>a;
	bool f=true;
	b[0]=1;b['H'-'A']=1;b['O'-'A']=1;b['I'-'A']=1;b['U'-'A']=1;
	b['Y'-'A']=1;b['T'-'A']=1;b['W'-'A']=1;b['X'-'A']=1;b['V'-'A']=1;b['M'-'A']=1;
	for(int i=0,j=a.length()-1;i<a.length()&&i<=j;i++,j--)
	{
		if(a.at(i)!=a.at(j)||!b[a.at(i)-'A']||!b[a.at(j)-'A'])
		{
			f=false;break;
		}	
	}
	if(f)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
} 