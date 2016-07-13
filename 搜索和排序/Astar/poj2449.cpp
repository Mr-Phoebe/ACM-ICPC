#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <cmath>

using namespace std;

template<class T>
inline bool read(T &n)
{
    T x = 0, tmp = 1; char c = getchar();
    while((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();
    if(c == EOF) return false;
    if(c == '-') c = getchar(), tmp = -1;
    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c = getchar();
    n = x*tmp;
    return true;
}
const int MAXN =1005;
const int MAXM=500005;
const int INF=0x3f3f3f3f;
int n,m,k,tot=0,rtot=0,T,S;
int h[MAXN],rh[MAXN];
int d[MAXN];
bool vis[MAXN];

struct Node
{
	int f,g,to;
	bool operator < (const Node b) const
	{
		return f>b.f;
	}	
};

struct Edge
{
	int to,next,l;
}e[MAXM],re[MAXM];

void add(int x,int y,int l)
{
	tot++;
	e[tot].to=y;
	e[tot].l=l;
	e[tot].next=h[x];
	h[x]=tot;
}

void radd(int x,int y,int l)
{
	rtot++;
	re[rtot].to=y;
	re[rtot].l=l;
	re[rtot].next=rh[x];
	rh[x]=rtot;
}

void spfa()
{
	memset(vis,0,sizeof(vis)); 
	queue<int> q;
	for(int i=1;i<=n;i++)
		d[i]=INF;
	d[T]=0;vis[T]=1;
	q.push(T);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		vis[x]=0;    //³öÕ»¿É·ÃÎÊ
		for(int i=rh[x];i!=-1;i=re[i].next)
		{
			int y=re[i].to;
			if(d[y]>d[x]+re[i].l)
			{
				d[y]=d[x]+re[i].l;
				if(!vis[y])
				{
					q.push(y);
					vis[y]=1;
				}
			}
		} 
	}
}

int Astar()
{
	int cnt=0;
	priority_queue<Node> heap;
	Node t;
	if(S==T)
		k++;
	if(d[S]==INF)
		return -1;
	t.f=d[S],t.g=0,t.to=S;
	heap.push(t);
	while(!heap.empty())
	{
		Node x=heap.top();
		heap.pop();
		if(x.to==T)
			cnt++;
		if(cnt==k)
			return x.g;
		for(int i=h[x.to];i!=-1;i=e[i].next)
		{
			t.g=x.g+e[i].l;
			t.f=t.g+d[e[i].to];
			t.to=e[i].to;
			heap.push(t);
		}
	}
	return -1;
}

int main()
{
	while(read(n)&&read(m))
	{
		memset(rh,-1,sizeof(rh));
		memset(h,-1,sizeof(h));
		for(int i=0;i<m;i++)
		{
			int u,v,l;
			read(u);read(v);read(l);
			add(u,v,l);
			radd(v,u,l);
		}
		read(S);read(T);read(k);
		spfa();
		printf("%d\n",Astar());
	}
	return 0;
}