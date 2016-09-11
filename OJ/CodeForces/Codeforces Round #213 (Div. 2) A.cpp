#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int main()
{
	int n,k;
	long long ans=0;
	char ch;
	char num[11];
	cin>>n>>k;
	getchar();
	for(int i=0;i<n;i++)
	{
		int j=0;
		
		memset(num,0,sizeof(num));
		while((ch=getchar())!='\n')
		{
			int temp=(int)ch-48;
			num[temp]++;
		}
		for(;j<=k;j++)
			if(!num[j])
				break;
		if(j==k+1)
			ans++;
	}
	cout<<ans<<endl;
	return 0;
} 