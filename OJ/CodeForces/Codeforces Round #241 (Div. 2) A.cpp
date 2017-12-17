#include<iostream>
#include<cstring> 

using namespace std;

string a,c;
int b;
const int inf=0x4f4f4f4f;


int main()
{
	int n,ans1=-inf,ans2=inf;
	cin>>n;
	while(n--)
	{
		cin>>a>>b>>c;
//		cout<<" "<<a<<" "<<b<<" "<<c<<endl;
		if(a.length()==1)
		{
			if(a[0]=='<')
			{
				if(c[0]=='Y')
					ans2=min(b-1,ans2);
				else
					ans1=max(b,ans1);
			}
			else
			{
				if(c[0]=='Y')
					ans1=max(b+1,ans1);
				else
					ans2=min(b,ans2);
			}
		}
		else
		{
			if(a[0]=='<')
			{
				if(c[0]=='Y')
					ans2=min(b,ans2);
				else
					ans1=max(b+1,ans1);
			}
			else
			{
				if(c[0]=='Y')
					ans1=max(b,ans1);
				else
					ans2=min(b-1,ans2);
			}
		}
	}
	if(ans1<=ans2)
		cout<<ans1<<endl;
	else
		cout<<"Impossible"<<endl;
	return 0;
	
}