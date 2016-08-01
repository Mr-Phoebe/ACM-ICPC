#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	long int n,b,x;
	long int i,j,t=0,s=0;
	long int a[10001];
	cin>>n>>b;
	memset(a,0,sizeof(a));
	for(i=0;i<n;i++)
	{
		cin>>x;a[x]++;	
	} 
	for(i=10000;i>=1&&s<b;i--)
		if(a[i]!=0)
		{
			for(j=1;j<=a[i]&&s<b;j++)
				{
					s+=i;
					t++;
				}
		}
		cout<<t<<endl;
	return 0;
}