#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define max(a,b)((a)>(b)?(a):(b))
#define min(a,b)((a)<(b)?(a):(b))
#define N 2005
#define M 500005
#define INF 1000000007
#define EPS 1e-8
struct edge
{
	int u;
	int v;
	int w;
	int next;
}e[M];
vector<pair<int,int > >ee[N];
int eid;
int nod[N];
int tnod[N];
int level[N];
queue<int>q;
bool in[N];
int dis[N];
int cnt[N];
int n,m;
int max_flow;
int add_flow;
void add_edge(int x,int y,int z)
{
	e[eid].u=x;
	e[eid].v=y;
	e[eid].w=z;
	e[eid].next=nod[x];
	nod[x]=eid++;
}
bool bfs(int src,int tc)
{
	int u,v,i;
	memset(level,-1,sizeof(level));
	memset(in,false,sizeof(in));
	while(!q.empty())q.pop();
	q.push(src);
	in[src]=true;
	level[src]=0;
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		in[u]=false;
		i=nod[u];
		while(i!=-1)
		{
			v=e[i].v;
			if(e[i].w>0&&level[v]==-1)
			{
				level[v]=level[u]+1;
				q.push(v);
				in[v]=true;
				if(v==tc)return true;
			}
			i=e[i].next;
		}
	}
	return false;
}
void find(int src,int tc)
{
	vector<int>road;
	int temp_flow;
	int u,i,k;
	road.clear();
	add_flow=0;
	u=src;
	while(tnod[src]!=-1)
	{
		i=tnod[u];
		if(u!=tc&&i!=-1&&e[i].w>0&&level[u]+1==level[e[i].v])
		{
			road.push_back(i);
			u=e[i].v;
		}
		else if(u==tc)
		{
			temp_flow=INF;
			for(i=0;i<(int)road.size();++i)
			{
				k=road[i];
				temp_flow=min(temp_flow,e[k].w);
			}
			for(i=(int)road.size()-1;i>=0;--i)
			{
				k=road[i];
				e[k].w-=temp_flow;
				e[k^1].w+=temp_flow;
				if(e[k].w==0)
				{
					while((int)road.size()>i)road.pop_back();
					u=e[k].u;
				}
			}
			add_flow+=temp_flow;
		}
		else
		{
			while((int)road.size()>0&&u!=src&&tnod[u]==-1)
			{
				road.pop_back();
				u=e[road[road.size()]].u;
			}
			tnod[u]=e[tnod[u]].next;
		}
	}
	return;
}
void Dinic(int src,int tc)
{
	max_flow=0;
	while(bfs(src,tc))
	{
		for(int i=0;i<=n;++i)tnod[i]=nod[i];
		find(src,tc);
		max_flow+=add_flow;
	}
	return;
}
void spfa(int src,int tc)
{
	memset(in,false,sizeof(in));
	while(!q.empty())q.pop();
	for(int i=0;i<N;++i)
	{
		dis[i]=INF;
		cnt[i]=INF;
	}
	q.push(src);
	in[src]=true;
	dis[src]=0;
	cnt[src]=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		in[u]=false;
		for(int i=0;i<(int)ee[u].size();++i)
		{
			int v=ee[u][i].first;
			if(dis[v]==dis[u]+ee[u][i].second)cnt[v]=min(cnt[v],cnt[u]+1);
			if(dis[v]>dis[u]+ee[u][i].second)
			{
				
				dis[v]=dis[u]+ee[u][i].second;
				cnt[v]=cnt[u]+1;
				if(!in[v])
				{
					q.push(v);
					in[v]=true;
				}
			}
		}
	}
	return;
}
void build_graph()
{
	eid=0;
	memset(nod,-1,sizeof(nod));
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<(int)ee[i].size();++j)
		{
			int v=ee[i][j].first;
			if(dis[i]+ee[i][j].second==dis[v])
			{
				add_edge(i,v,1);
				add_edge(v,i,0);
			}
		}
	}
	return;
}
int main()
{
	//freopen("2.in","r",stdin);
	//freopen("2.out","w",stdout);
	int u,v,l;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=0;i<N;++i)ee[i].clear();
		for(int i=0;i<m;++i)
		{
			scanf("%d%d%d",&u,&v,&l);
			ee[u].push_back(make_pair<int,int>(v,l));
			ee[v].push_back(make_pair<int,int>(u,l));
		}
		spfa(1,n);
		
		build_graph();

		Dinic(1,n);
		printf("%d %d\n",max_flow,m-cnt[n]);
	}
	return 0;
}
