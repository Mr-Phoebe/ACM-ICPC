#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	int a,b,x,y,n,ans=0;
	int i,j;
	cin>>a>>b>>x>>y>>n;
	for(i=1;i<=a;i++)
		for(j=1;j<=b;j++)
			if(fabs(x-i)+fabs(y-j)<=n)
				ans++;
	cout<<ans<<endl;
}
