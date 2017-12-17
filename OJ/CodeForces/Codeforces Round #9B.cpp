#include<iostream>
#include<algorithm>

using namespace std;

int max(int a,int b)
{
	return a>b?a:b;
}


int main()
{
	int i,j,n,num,T,ans=0;
	int t[100];
	cin>>n;
	for(i=0;i<n;i++)
		cin>>t[i];
	cin>>T;
	sort(t,t+n);
	for(i=0;i<n;i++)
	{
		j=i;
		while(t[j]-t[i]<=T&&j<n)
			j++;
		ans=max(ans,j-i);
		if(j==n)
			break;
	}
	cout<<ans<<endl;
	return 0;
} 