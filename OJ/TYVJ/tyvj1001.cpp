#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstdio>
#define size 10000

using namespace std;


int cmp (const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}

int is_prime(int x)
{
	int i,m;
	m=floor(sqrt(x)+0.5);
	for(i=2;i<=m;i++)
		if(x%i==0)
			return 0;
	return 1;
}

int main()
{

    int i;
    int a[size];
	int n,k;

	while(scanf("%d %d",&n,&k)!=EOF)
    {
		for (i=0;i<n;i++)
			cin>>a[i];
		qsort(a,n,sizeof(a[0]),cmp);


		i=a[n-k]-a[k-1];
		if(i<2)
		{cout<<"NO"<<endl<<i<<endl;return 0;}
		if(is_prime(i))
			cout<<"YES"<<endl<<i;
		else
			cout<<"NO"<<endl<<i;
		cout<<endl;
	}
    

   
	return 0;
}
