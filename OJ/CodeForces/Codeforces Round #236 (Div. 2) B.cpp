#include<iostream>

using namespace std;

int main()
{
	int n,k,mi=11111111,po;
	int a[1010];
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
	{
		int sum=0,j;
		for(j=0;j<n;j++)
		{
			int temp=a[i]+(j-i)*k;
			if(temp<=0)
				break;
			if(temp!=a[j])
				sum++;
		}
		if(sum<mi&&j==n)
		{
			mi=sum;
			po=i;
		}
	}
	cout<<mi<<endl;
	for(int i=0;i<n;i++)
	{
		int temp=a[po]+(i-po)*k;
		if(temp>a[i])
			cout<<"+ "<<i+1<<" "<<temp-a[i]<<endl;
		else if(temp<a[i])
			cout<<"- "<<i+1<<" "<<a[i]-temp<<endl;
	}
	return 0;
}
