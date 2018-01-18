#include<iostream>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

const int INF=111111111;

int a[111];

	
int search_bin(int *t,int k,int n)
{
    int low=0,high=n-1,mid;
    while (low<=high)
    {
        mid=(low+high)/2;
        if (k==t[mid]) 
    	{
       		while(t[mid] != k)
          		mid--;
        	return mid+1;
    	}       
    	else if(k<t[mid]) high=mid-1;
    	else low=mid+1;
    }
    return low;
}

int main()
{
//	freopen("data.txt","r",stdin);
	long long sum=0,n,k,m;
	scanf("%lld",&n);
	for(long long i=1;i<100;i++)
		a[i]=(i+1)*(i+2)*(2*i+3)/6;
	for(int i=0;i<n;i++)
	{
		scanf("%lld %lld",&k,&m);
		sum+=k*m;	
	}
//	cout<<sum<<endl;
	int pos=search_bin(a,sum,100);
	pos=min(99,pos);
	printf("Team Liserious' rank is %d\n",pos);
	return 0;
} 