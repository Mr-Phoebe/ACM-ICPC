#include<iostream>

using namespace std;

struct edge
{
	int u,v,w;
}a[10011],b[10011];

int n,m,sum=0;
int father[2222];


int findfather(int x)
{
	if(father[x]!=x)
		return father[x]=findfather(father[x]);
	else
		return father[x];
}

void Merge(int a,int b)
{
	int fa=findfather(a),fb=findfather(b);
	father[fa]=fb;
}

bool cmp(struct edge a,struct edge b)
{
	return a.w>b.w;
}

void sort(int l,int r)
{
	int i=l,j=r,x;
	struct edge t;
	x=b[(i+j)>>1].w;
	while(i<=j)
	{
		while(b[i].w<x)
			i++;
		while(b[j].w>x)
			j--;
		if(i<=j)
		{
			t=b[i];b[i]=b[j];b[j]=t;
			i++;j--;
		}
	}
	if(i<r)
		sort(i,r);
	if(l<j)
		sort(l,j);
}

void init(int m)
{
	sum=0;
	for(int i=1;i<=n;i++)
		father[i]=i;
	for(int i=1;i<=m;i++)
	{
		sum+=a[i].w;
		if(father[a[i].u]!=father[a[i].v])
			Merge(a[i].u,a[i].v);
	}
	
}

void kruscal(int m)
{
	sort(1,m);
	for(int i=1;i<=m;i++)
	{
		if(findfather(b[i].u)!=findfather(b[i].v))
		{
			sum+=b[i].w;
			Merge(b[i].v,b[i].u);
		}
	}
	return;
}

int main()
{
	int j=1,k=1;
	freopen("data.txt","r",stdin);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int p;
		cin>>p;
		if(p==1)
			cin>>a[j].u>>a[j].v>>a[j++].w;
		else
			cin>>b[k].u>>b[k].v>>b[k++].w;
	}
	init(j);
	kruscal(k);
	cout<<sum<<endl;
	return 0;
}