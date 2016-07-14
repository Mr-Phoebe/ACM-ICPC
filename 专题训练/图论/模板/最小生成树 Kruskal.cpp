#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>

using namespace std;

int father[111];
int n;
double x[111],y[111];
struct dis
{
	int u,v;
	double dd;
}d[10010];

bool cmp(dis a,dis b)
{
	return a.dd<b.dd;
}

int find_set(int a)
{
  return a==father[a]?a:father[a]=find_set(father[a]);
}


void Merge(int x,int y)
{
	int xx=find_set(x);
	int yy=find_set(y);
	if(xx!=yy)
		father[xx]=yy;
}

double Kruskal(int m)
{
	double s=0;
	sort(d,d+m,cmp);
	for(int i=0;i<m;i++)
		if(find_set(d[i].u)!=find_set(d[i].v))
		{
			s+=d[i].dd;
			Merge(d[i].u,d[i].v);
		}
	return s;
}


int main()
{
	int k=0;
	while(cin>>n)
	{
		k=0;
		for(int i=0;i<n;i++)
		{
			cin>>x[i]>>y[i];
			father[i]=i;
		}	
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
			{
				d[k].u=i,d[k].v=j;
				double xx=x[i]-x[j],yy=y[i]-y[j];
    			d[k++].dd=sqrt(xx*xx+yy*yy);
			}
		printf("%.2lf\n",Kruskal(k));
		}
	return 0;
}