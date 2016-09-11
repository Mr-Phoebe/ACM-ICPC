#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 100005;

struct node
{
	int len,id,num;
}a[100100];

int fa[100010];
vector < pair <int, int> > edge;

bool cmp(node a,node b)
{
	return a.len<b.len;	
}

int find_father(int x)
{
	if(fa[x]==x)
		return fa[x];
	else
		return fa[x]=find_father(fa[x]);
}

void Merge(int x,int y)
{
	int xx=find_father(x);
	int yy=find_father(y);
	if(a[xx].len<a[yy].len)  //节点高的为父节点 
		fa[yy]=xx;
	else
		fa[xx]=yy;
}

int main()
{
	int n,k;
	bool ok=true;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].len;
		a[i].num=k-1;
		a[i].id=i;
		fa[i]=i;
	}
	sort(a+1,a+n+1,cmp);
	a[1].num=k;
	edge.clear();
	int pos1=0,pos2=1;
	if(a[1].len!=0)
		ok=false;
	for(int i=2;i<=n&&ok;i++)
	{
		if(a[i].len!=a[i-1].len&&a[i].len!=a[i-1].len+1)
		{
			ok=false;
		}
		else if(a[i].len==a[i-1].len+1)
		{
			pos1=pos2;
			pos2=i;
		}
		while(a[pos1].num==0&&pos1<=pos2)
			pos1++;
		if(pos1>=pos2)
		{
			ok=false;
		}	
		edge.push_back(make_pair(a[pos1].id,a[i].id));
		a[pos1].num--;
	}
	if(!ok)
		cout<<"-1"<<endl;
	else
	{
		cout<<edge.size()<<endl;
		for(int i=0;i<edge.size();i++)
			cout<<edge[i].first<<" "<<edge[i].second<<endl;
	} 
}