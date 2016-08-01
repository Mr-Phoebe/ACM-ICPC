#include<iostream>

using namespace std;

struct atp
{
	int v;
	int b;
}a[20];

int n,c,ans=0;

void swap(atp* x,atp* y)
{
	atp t;
	t=*x;*x=*y;*y=t;

}

void qs(int l,int r)
{
	int i=l,j=r,m=a[(l+r)>>1].v;
	do
	{
		while(a[i].v>m)
			i++;
		while(a[j].v<m)
			j--;
		if(i<=j)
		{
			swap(&a[i],&a[j]);
			i++;
			j--;
		}
		
	}while(i<=j);
	if(i<r)
		qs(i,r);
	if(l<j)
		qs(l,j);
}

int main()
{
	int i=0,temp=0,rest;
	cin>>n>>c;
	for(i=0;i<n;i++)
		cin>>a[i].v>>a[i].b;
	qs(0,n-1);
	for(i=0;i<n;i++)
		if(a[i].v>=c)
			{
			ans+=a[i].b;temp++;
			}
	do
	{
		rest=c;
		for(i=temp;i<n;i++)
			while(rest-a[i].v>=0&&a[i].b>0)
			{
				rest-=a[i].v;
				a[i].b--;	
			}
		for(i=n-1;i>=temp;i--)
			while(rest>0&&a[i].b>0)
			{
				rest-=a[i].v;
				a[i].b--;
			}			
		if(rest<=0)
			ans++;
	}while(rest<=0);
	cout<<ans<<endl;
	return 0;			
}