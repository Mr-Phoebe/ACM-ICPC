#include<iostream>

using namespace std;

const int maxn=2500,maxm=6200*2;

int a[maxm+1],b[maxm+1],w[maxm+1];
bool h[maxn];
int f[10001],d[10001],dist[10001];


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
			int t1=a[i],t2=b[i],t3=w[i];
			a[i]=a[j];b[i]=b[j];w[i++]=w[j];
			a[j]=t1;b[j]=t2;w[j--]=t3;
		}
	}while(i<=j);
	if(i<r)
		qsort(i,r);
	if(j>l)
		qsort(l,j);
} 

void spfa(int s)
{
	int i,k;
	memset(h,false,sizeof(h));
	memset(dist,127,sizeof(dist));
	int head=0,tail=1;
	dist[s]=0;
	d[tail]=s;
	h[s]=true;
	while(head!=tail)
	{
		head++;
		int now=d[head];
		h[d[head]]=false;
		k=f[d[head]];
		i=k;
		while(a[i]==a[k])
		{
			if(dist[b[i]]>dist[now]+w[i])
			{
				dist[b[i]]=dist[now]+w[i];
				if(!h[b[i]])
				{
					tail++;
					d[tail]=b[i];
					h[b[i]]=true;			
				}
			}
			i++;
		}
	}	
}

int main()
{
	freopen("data.txt","r",stdin);
	int n,m,s,t,i;
	cin>>n>>m>>s>>t;
	for(i=1;i<=m;i++)
	{
		cin>>a[i]>>b[i]>>w[i];
		a[i+m]=b[i];
		b[i+m]=a[i];
		w[i+m]=w[i];
	}
	m*=2;
	qsort(1,m);
	i=1;f[a[i]]=1;
	do
	{
		while(a[i+1]==a[i])
			i++;
		i++;
		f[a[i]]=i;
	}while(i<m);
	spfa(s);
	cout<<dist[t]<<endl;
	return 0;
}