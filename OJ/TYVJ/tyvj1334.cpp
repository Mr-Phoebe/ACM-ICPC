#include<iostream>

using namespace std;

int main()
{
    int i,n,a=1,b=1,c;
	int f[500]={1,1};
    cin>>n;
	for (i=2;f[i-1]<=n;i++)
	{
		f[i]=a+b;
		a=b;
		b=f[i];
	}
		cout<<f[i-3]<<" "<<f[i-2]<<endl;
	return 0;
}