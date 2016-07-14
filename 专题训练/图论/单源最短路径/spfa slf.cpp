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

const int MAXN=1000;

struct shortest_path
{
	shortest_path(){}
	struct Edge
	{
		int to,next,dis;
	}e[2*MAXN];
	int head[MAXN],tot;
	struct Node
    {
        int v,dis;
        Node(const int a,const int b):v(a),dis(b){}
        Node(){}
        bool operator < (const Node& b) const
        {
            return dis>b.dis;
        }
    }a[MAXN];
	priority_queue<Node> Q;


	void init()
	{
		CLR(head,-1);tot=0;
	}

	void add_edge(int u,int v,int w)
	{
		e[tot].to=v;
		e[tot].dis=w;
		e[tot].next=head[u];
		head[u]=tot++;
	}

	int spfa(int s,int t,int n)
	{
		for(int i=1;i<=n;i++)
			a[i].v=i,a[i].dis=INF;
		a[s].dis=0;
		Node temp(s,0),nxt;
		Q.push(temp);
		while(!Q.empty())
		{
			temp=Q.top();Q.pop();
			int u=temp.v;
			if(u==t)
				return temp.dis;
			for(int i=head[u];i!=-1;i=e[i].next)
			{
				if(a[e[i].to].dis>temp.dis+e[i].dis)
				{
					a[e[i].to].dis=nxt.dis=temp.dis+e[i].dis;
					nxt.v=e[i].to;
					Q.push(nxt);
				}
			}
		}
		return INF;
	}
};

shortest_path g;

int main()
{
	freopen("data.txt","r",stdin);
	int n,m;
	while(read(n))
	{
		int w;
		g.init();
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				cin>>w;
				if(i==j)	continue;
				g.add_edge(i,j,w);
			}
		write(g.spfa(1,n,n));putchar('\n');
	}
	return 0;
}
