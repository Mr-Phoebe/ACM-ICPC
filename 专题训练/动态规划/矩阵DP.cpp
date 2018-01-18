#include<iostream>
#include<cstring>

using namespace std;

int map[111][111];
int sum[111];
int dp[111];

int main()
{
	int n,maxn=0;
//	freopen("data.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>map[i][j];
	for(int i=0;i<n;i++)
	{
		memset(sum,0,sizeof(sum));
		for(int j=i;j<n;j++)
			for(int k=0;k<n;k++)
			{
				sum[k]+=map[j][k];
				if(sum[k]+dp[k-1]>0)
					dp[k]=sum[k]+dp[k-1];
				else
					dp[k]=0;
				if(dp[k]>maxn)
					maxn=dp[k];
			}
	}
	cout<<maxn<<endl;
	return 0;	
} 