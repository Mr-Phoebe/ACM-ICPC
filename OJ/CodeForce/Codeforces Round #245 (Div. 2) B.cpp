#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
//	freopen("data.txt","r",stdin);
	int a[105],b[55];
	int n,k,x,top=0,ans=0,sum=0;
	scanf("%d %d %d",&n,&k,&x);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==x&&a[i-1]==x)
			b[top++]=i-1;
	}
	for(int i=0;i<top;i++)
	{
		sum=2;//cout<<b[i]<<endl;
		for(int j=b[i]-1,k=b[i]+2;j>=0,k<n;)
		{
			int l=j,r=k;
			while(a[l]==a[j]&&j>=0)
				j--;
			while(a[r]==a[k]&&k<n)
				k++;
			//	cout<<"\t"<<j<<" "<<l<<" "<<r<<" "<<k<<endl;
			if(a[k-1]!=a[j+1])
				break;
			if(l-j+k-r>=3)
				sum+=l-j+k-r;
			else
				break;
		}
		ans=max(sum,ans);
//		cout<<sum<<endl;
	}
	printf("%d\n",ans);
	return 0;
} 