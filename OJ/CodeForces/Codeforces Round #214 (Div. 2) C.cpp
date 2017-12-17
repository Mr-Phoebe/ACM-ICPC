#include <iostream>
#include <cstdio>

using namespace std;

const int f=100250;
const int m=2*f;
const int inf=0x4f4f4f4f;
int dp[m];
int a[111],b[111],c[111];

int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
		c[i]=k*b[i]-a[i];
	}
	for(int i=0;i<=m;i++)
		 dp[i]=-inf;
 	dp[f]=0;
 	for(int i=0;i<n;i++)
 	{
	 	if(c[i]<0)
	 		for(int j=-100000;j<=100000+c[i];j++)
	 			dp[j+f]=max(dp[j+f],dp[j+f-c[i]]+a[i]);
	 	else
	 		for(int j=100000;j>=-100000+c[i];j--)
	 			dp[j+f]=max(dp[j+f],dp[j+f-c[i]]+a[i]);
	}
	if(!dp[0+f])
		dp[0+f]=-1; 
	cout<<dp[f]<<endl;
	return 0;
}