#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdlib> 

using namespace std;

int x[111],y[111];
int n;
int h,v;

int main()
{
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y));
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		x[a]++;
		y[b]++;
	}
	for(int i=0;i<111;i++)
	{
		if(x[i]!=0)
			v++;
		if(y[i]!=0)
			h++;
	}
	cout<<min(v,h)<<endl;
} 