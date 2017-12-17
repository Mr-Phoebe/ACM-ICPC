#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
#define MAXN 111
#define inf 1000000000

struct circle
{
	double x,y,z,r;
}a[MAXN];

struct edge
{
	int s,e;
	double dis;
}ed[MAXN*MAXN];

int n,father[MAXN];
 

double pow2(double x)
{
	return x*x;
}

double dist_r(circle a, circle b)
{
    return sqrt(pow2(a.x-b.x)+pow2(a.y-b.y)+pow2(a.z-b.z));
}

double dist_c(circle a, circle b)
{
	double temp=dist_r(a,b)-a.r-b.r;
	if(temp<eps)
		return 0.0;
	else
    	return temp;
}

int find_fa(int x)
{
	if(father[x]==x)
		return x;
	else
		return father[x]=find_fa(father[x]);
}

bool merge(int a,int b)  
{  
    int x=find_fa(a);
	int y=find_fa(b);  
    if(x!=y)  
	{
		father[x]=y;
		return true; 
	}	   
    else  
		return false;   
} 

bool cmp(edge a,edge b)  
{  
    return a.dis<b.dis;      
}  


double Kruskal(int tot)
{
	double ans=0;
	int i;
	sort(ed,ed+tot,cmp);
	for(i=0;i<tot;i++)
		if(merge(ed[i].s,ed[i].e))
			ans+=ed[i].dis;
	return ans;
}

int main()
{
	int i;
	while(scanf("%d",&n)==1&&n)
	{
		int tot=0;
		for(i=0;i<n;i++)
		{
			scanf("%lf %lf %lf %lf",&a[i].x,&a[i].y,&a[i].z,&a[i].r);
			father[i]=i;
			for(int j=0;j<i;j++,tot++)
			{
				ed[tot].s=j;
				ed[tot].e=i;
				ed[tot].dis=dist_c(a[i],a[j]);
			}
		}
		printf("%.3lf\n",Kruskal(tot)); 
	}
	return 0;
} 