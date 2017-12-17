#include<iostream>
#include<algorithm>

using namespace std;

int cmp(const void* a,const void* b)
{
	return *(int*)a-*(int*)b;
}


int main()
{
	long int lev[10000],diff[10000]={0};
	int n,k,ans=0;
	int i;
	cin>>n>>k;
	for(i=0;i<n;i++)
		cin>>lev[i];
	qsort(lev,n,sizeof(long int),cmp);
	for(i=1;i<n;i++)
		diff[i]=lev[i]-lev[i-1];
	qsort(diff,n,sizeof(long int),cmp);
	for(i=0;i<=k;i++)
		ans+=diff[i];
	cout<<ans<<endl;
	return 0;
}