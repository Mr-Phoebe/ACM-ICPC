#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int T,n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		if(n==1||n==3)
			cout<<"Alice"<<endl;
		else if(n==2)
			cout<<"Bob"<<endl;
		else if(n&1)
			cout<<"Bob"<<endl;
		else	
			cout<<"Alice"<<endl;
	}
	return 0;
}