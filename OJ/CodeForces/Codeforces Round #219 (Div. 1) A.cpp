#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;


int a[500010];
int n;

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	int mid=n/2,top=n-1;
	for(int i=mid-1;i>=0;i--)
	{
		if(2*a[i]<=a[top])
			top--;		
	}
	cout<<top+1<<endl;
	return 0;
}
 