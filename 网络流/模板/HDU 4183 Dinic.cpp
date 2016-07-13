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

const int maxn = 1010;
const double ss=400.0;
const double tt=789.0;

struct Edge
{
    int to,cap,flow,next;
    Edge(){}
    Edge(int to,int cap,int flow,int next):to(to),cap(cap),flow(flow),next(next){}
}edges[maxn<<1];
int head[maxn],cur[maxn],d[maxn],nEdge,n;
void AddEdges(int from,int to,int cap)
{
    edges[nEdge]=Edge(to,cap,0,head[from]);
    head[from]=nEdge++;
    edges[nEdge]=Edge(from,0,0,head[to]);
    head[to]=nEdge++;
}
bool BFS(int s,int t)
{
    memset(d,0xff,sizeof(d));
    d[s]=0;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(int k=head[u];k!=-1;k=edges[k].next)
        {
            Edge e=edges[k];
            if(d[e.to]==-1&&e.cap>e.flow)
            {
                d[e.to]=d[u]+1;
                q.push(e.to);
            }
        }
    }
    return d[t]!=-1;
}
int DFS(int u,int a,int t)
{
    if(u==t||a==0) return a;
    int flow=0,f;
    for(int &k=cur[u];k!=-1;k=edges[k].next)
    {
        Edge e =edges[k];
        if(d[e.to]==d[u]+1&&(f=DFS(e.to,min(a,e.cap-e.flow),t))>0)
        {
            edges[k].flow+=f;
            edges[k^1].flow-=f;
            flow+=f;a-=f;
            if(a==0) break;
        }
    }
    return flow;
}
int MaxFlow(int s,int t)
{
    int flow=0;
    while(BFS(s,t))
    {
        for(int i=1;i<n*2+1;++i) cur[i]=head[i];
        flow+=DFS(s,INF,t);
    }
    return flow;
}

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

int main()
{
	int T,s,t;
	read(T);
	while(T--)
	{
		memset(head,0xff,sizeof(head));
        nEdge=0;
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
				AddEdges(i,i+n,INF);
			else
				AddEdges(i,i+n,1);
			for(int j=1;j<=n;j++)
			{
				if(i==j || !inter(p[i],p[j]))	continue;
				if(dcmp(p[i].f-p[j].f)<0)
					AddEdges(i+n,j,1);
			}
		}
		int flow=MaxFlow(s,t);
		if(flow>=2)
			puts("Game is VALID");
		else
			puts("Game is NOT VALID");
	}
	return 0;
}
