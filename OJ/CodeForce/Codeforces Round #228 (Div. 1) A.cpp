#include<iostream>
#include<algorithm>


using namespace std;

int main()
{
	int n,a[111];
	int res,num,ans=0;
	cin>>n;
	res=n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n&&res;i++)
	{		
		if(a[i]==-1)
			continue;
		else
		{
			num=1;a[i]=-1;res--;
		}	
		for(int j=i+1;j<n&&res;j++)
			if(a[j]>=num)
			{
				num++;res--;
				a[j]=-1;
			}
		ans++;
	}
	cout<<ans<<endl;
	return 0;
} 