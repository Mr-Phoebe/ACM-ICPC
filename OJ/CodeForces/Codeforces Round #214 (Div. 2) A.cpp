#include<iostream>

using namespace std;

const int inf=11111111;

int main()
{
	int n,num=0,mi=inf;
	int a[4][4];
	cin>>n;
	for(int i=0;i<4;i++)
	{
		int temp=0;
		for(int j=0;j<4;j++)
			cin>>a[i][j];
		temp=min(a[i][0]+a[i][2],a[i][0]+a[i][3]);
		temp=min(temp,a[i][1]+a[i][2]);
		temp=min(temp,a[i][1]+a[i][3]);
		if(temp<mi&&temp<=n)
		{
			num=i+1;
			mi=temp;
		}
	}
	if(mi==inf)
		cout<<"-1"<<endl;
	else	
		cout<<num<<" "<<min(a[num-1][0],a[num-1][1])<<" "<<n-min(a[num-1][0],a[num-1][1])<<endl;
	return 0;
} 