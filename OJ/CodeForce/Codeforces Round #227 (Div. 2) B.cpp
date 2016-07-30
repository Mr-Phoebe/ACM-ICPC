#include<iostream>
#include<algorithm>

using namespace std;

const int maxn=3333;

int main()
{
	int a[maxn],b[maxn];
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<m;i++)
		cin>>b[i];
	sort(a,a+n);
	sort(b,b+m);
	int com=0,cur=0;
	for(int i=0;i<m;i++)
		if(b[i]>=a[cur])
		{
			com++;
			if(++cur==n)
				break;
		}
	cout<<n-com<<endl;
	return 0;
	
} 

