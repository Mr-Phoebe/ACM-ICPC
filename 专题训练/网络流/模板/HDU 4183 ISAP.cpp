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
#define CLR(x,y) memset(x,y,sizeof(x))
#define eps 1e-9
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

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
template <class T>
inline void write(T n)
{
    if(n < 0)
    {
        putchar('-');
        n = -n;
    }
    int len = 0,data[20];
    while(n)
    {
        data[len++] = n%10;
        n /= 10;
    }
    if(!len) data[len++] = 0;
    while(len--) putchar(data[len]+48);
}
//-----------------------------------

const int N = 1010;
const int M = 1000100;
const double ss=400.0;
const double tt=789.0;


struct nedge
{
	int u,v,next;
	ll c;
};

struct ISAP
{
	nedge e[M*2];
	int head[N],tot,n;
	int ss,tt;

	void Resize(int n)
	{
		this->n=n;
	}

	void Clearall()
	{
		tot=1;
		CLR(head,0);
	}

	void Addedge(int u,int v,ll w)
	{
		e[++tot].v=v;
		e[tot].u=u;
		e[tot].c=w;
		e[tot].next=head[u];
		head[u]=tot;
		e[++tot].v=u;
		e[tot].u=v;
		e[tot].c=0;
		e[tot].next=head[v];
		head[v]=tot;
	}

	int dep[N],gap[N];

	void bfs()
	{
		CLR(dep,-1);
		CLR(gap,0);
		queue<int> que;
		gap[0]=1;
		dep[tt]=0;
		que.push(tt);
		while(!que.empty())
		{
			int u=que.front();que.pop();
			for(int i=head[u];i;i=e[i].next)
				if(dep[e[i].v]==-1)
				{
					que.push(e[i].v);
					dep[e[i].v]=dep[u]+1;
					++gap[dep[e[i].v]];
				}
		}
	}

	int res,cur[N],num[N];
 	int top;
 	int MaxFlow(int s,int t)
 	{
 		this->ss=s;this->tt=t;
	 	bfs();
	 	top=res=0;
	 	memcpy(cur,head,sizeof(head));
	 	int u=ss,i;
	 	while(dep[ss]<n)
	 	{
	 		if(u==tt)
	 		{
		 		int temp=INF;
		 		int inser;
		 		for(i=0;i<top;i++)
		 			if(temp>e[num[i]].c)
		 			{
			 			temp=e[num[i]].c;
			 			inser=i;
			 		}
		 		for(i=0;i<top;i++)
		 		{
		 			e[num[i]].c-=temp;
		 			e[num[i]^1].c+=temp;
		 		}
		 		res+=temp;
		 		top=inser;
		 		u=e[num[top]].u;
		 	}
		 	if(u!=tt && gap[dep[u]-1]==0)
		 		break;
	 		for(i=cur[u];i;i=e[i].next)
		 		if(e[i].c != 0 && dep[u]==dep[e[i].v]+1)
		 			break;
 			if(i)
 			{
				cur[u]=i;
				num[top++]=i;
				u=e[i].v;
		 	}
		 	else
		 	{
	 			int mi=n;
	 			for(i=head[u];i;i=e[i].next)
	 				if(e[i].c>0 && mi>dep[e[i].v])
				 	{
			 			mi=dep[e[i].v];
			 			cur[u]=i;
			 		}
		 		--gap[dep[u]];
		 		dep[u]=mi+1;
		 		++gap[dep[u]];
		 		if(u!=ss)
		 			u=e[num[--top]].u;
	 		}
	 	}
	 	return res;
 	}
};

struct Point
{
	double f,x,y,r;
	void input()
	{
		scanf("%lf%lf%lf%lf",&f,&x,&y,&r);
	}
}p[333];

int dcmp(double a)
{
    return a<-eps ? -1:a>eps ? 1:0;
}

double dis(Point a,Point b)
{
    return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}

bool inter(Point a,Point b)
{
	double d=dis(a,b);
	return dcmp(d-a.r-b.r)<=0;
}

ISAP g;

int main()
{
	int T,s,t,n;
	read(T);
	while(T--)
	{
		g.Clearall();
		read(n);
		for(int i=1;i<=n;i++)
		{
			p[i].input();
			if(dcmp(p[i].f-tt)==0){	t=i;	}
			else if(dcmp(p[i].f-ss)==0){ s=i;	}
		}
		if(inter(p[s],p[t]))
		{
			 puts("Game is VALID");
			 continue;
		}
		for(int i=1;i<=n;i++)
		{
			if(i==s)
				g.Addedge(i,i+n,INF);
			else
				g.Addedge(i,i+n,1);
			for(int j=1;j<=n;j++)
			{
				if(i==j || !inter(p[i],p[j]))	continue;
				if(dcmp(p[i].f-p[j].f)<0)
					g.Addedge(i+n,j,1);
			}
		}
		g.Resize(2*n+2);
		int flow=g.MaxFlow(s,t);
		if(flow>=2)
			puts("Game is VALID");
		else
			puts("Game is NOT VALID");
	}
	return 0;
}
