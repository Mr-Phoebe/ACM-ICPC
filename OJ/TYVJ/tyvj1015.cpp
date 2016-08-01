#include<iostream>

using namespace std;

int main()
{
	int n,i,j,min;
	int a[11],p[102]={0};
	for(i=1;i<=10;i++)
		cin>>a[i];
	cin>>n;
	p[1]=a[1];
	for(i=1;i<=n;i++)
	{
		min=5000000;
		for(int j=1;j<=10;j++)
			if(i>=j&&p[i-j]+a[j]<min)
				min=p[i-j]+a[j];
		p[i]=min;
	}

	cout<<p[n]<<endl;
	return 0;
} 