#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int money[1111];
	int i,j,n;
	int max=0,num=1;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>money[i];
		if(money[i]>max)
		{
			num=i+1;
			max=money[i];
		}
	}
	sort(money,money+n);
	cout<<num<<" "<<money[n-2]<<endl;
	return 0;
} 