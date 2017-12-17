#include<iostream>

using namespace std;

int father[200020];
long long sum=0;

struct edge
{
	int u,v,w;	
}a[200020];


int findfather(int x)
{
	if(father[x]!=x)
		return father[x]=findfather(father[x]);
	else
		return father[x];
}

void Merge(int a,int b)
{
	int ra=findfather(a);
	int rb=findfather(b);
	father[rb]=ra;
}

void qsort(int l,int r)
{
	int i=l,j=r,m=a[(l+r)>>1].w;
	struct edge t;
	while(i<=j)
	{
		while(a[i].w<m)
			i++;
		while(a[j].w>m)
			j--;
		if(i<=j)
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
			i++;j--;
		}
	}
	if(i<r)
		qsort(i,r);
	if(l<j)
		qsort(l,j);
}


void Kruskal(int m)
{
	qsort(1,m);
	for(int i=1;i<=m;i++)
		if(findfather(a[i].u)!=findfather(a[i].v))
		{
			Merge(a[i].u,a[i].v);
			sum+=a[i].w;
		}
}


int main()
{
	int n,m,k,num=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i].u>>a[i].v>>a[i].w;
		father[i]=i;
	}	
	qsort(1,m);
	Kruskal(m);
	int f=findfather(k);
	for(int i=1;i<=n;i++)
		if(findfather(i)!=f)
			num++;
	if(num==0)
		cout<<sum<<endl;
	else
		cout<<num<<endl;
	return 0;
} 