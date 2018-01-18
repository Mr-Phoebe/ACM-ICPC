#include<iostream>
#include<algorithm>


using namespace std;

int a[200000];

int main()
{
	int n,i,num,temp=0;
	bool ok=true;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(i=0;i<n;i++)
	{
		num=upper_bound(a,a+n,a[i])-lower_bound(a,a+n,a[i]);
		cout<<a[i]<<' '<<num<<endl;
		i+=num-1;		
	}	
	
	return 0;
}
