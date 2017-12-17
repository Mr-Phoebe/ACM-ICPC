#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

typedef pair<int,int> pii;
pii a[100010];
int b[100010];

bool cmp(pii a,pii b)
{
	return a.second<b.second;
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d %d",&a[i].first,&a[i].second);	
//	sort(a,a+n,cmp);
//	for(int i=0;i<n;i++)
//		cout<<a[i].first<<" "<<a[i].second<<endl;

	for(int i=0;i<n;i++)
	{
		if(a[i].first>b[a[i].second])
		{
			cout<<"NO"<<endl;
			return 0;
		}
		else if(b[a[i].second]==a[i].first)
			b[a[i].second]++;
		
	}
	cout<<"YES"<<endl;
	return 0;
}