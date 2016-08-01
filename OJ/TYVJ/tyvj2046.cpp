#include<iostream>
#include<cstdio>

using namespace std;

int a[50011];
int n,sum;

void swap(int x,int y)
{
	int k;
	k=a[x];
	a[x]=a[y];
	a[y]=k;
} 

void qsort(int l,int r)
{
	int i=l,j=r,x=a[(i+j)/2];
	do
	{
		while(a[i]<x)
			i++;
		while(a[j]>x)
			j--;
		if(i<=j)
		{
			swap(i,j);
			i++;j--;
		}
	}while(i<=j);
	if(i<r)
		qsort(i,r);
	if(l<j)
		qsort(l,j);
}

int main()
{
	double ans=0;
	int k=0,p=0,i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	qsort(0,n-1);
	for(i=sum;i>=1;i--)
	{
		k++;
		if(k>a[p])
		{
			k=1;
			p++;
		}
		ans+=(double)i/(double)a[p];
	}
	printf("%.3lf\n",ans);
	return 0;
}