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

const int MAXN=100010;
int n,m,p,q;

struct DisjointSet
{
    vector<int> father,rank;
    DisjointSet() {}
    DisjointSet(int n):father(n+1),rank(n+1)
    {
        for(int i=1;i<=n;i++)
            father[i]=i;
    }
    void clear(int n)
    {
        father.resize(n+1);rank.resize(n+1);
        for(int i=1;i<=n;i++)
            father[i]=i, rank[i]=0;
    }
    int find(int v)
    {
        return father[v]=father[v]==v? v:find(father[v]);
    }
    void merge(int x,int y)
    {
        int a=find(x),b=find(y);
        if(a==b)
            return;
        if(rank[a]<rank[b])
        {
            father[a]=b;
        }
        else
        {
            father[b]=a;
            if(rank[b]==rank[a])
                ++rank[a];
        }
    }

};
DisjointSet d; 

struct Edge
{
	int from,to;
	ll dis;
	Edge(int u=-1,int v=-1,ll w=0):from(u),to(v),dis(w){}
}e[MAXN*2];
int tot;

void addedge(int u,int v,ll w)
{
	Edge E(u,v,w);
	e[tot++]=E;
}

set<int> cg;
set<int>::iterator po;
ll siz[MAXN];
vector<int> L,R;

struct Node
{
	int fa;
	ll val;
	Node (int a,ll b):fa(a),val(b){}
	bool operator < (const Node &x) const 
	{
		if(x.val==val)
			return x.fa<fa;
		return x.val>val;
	}
};
set<Node> way;
set<Node>::iterator it;

void init(int n)
{
	way.clear();
	L.clear();
	R.clear();
	cg.clear();
	d.clear(n+10);
	CLR(siz,0);
	tot=0;
}

void findway()
{
	it=way.begin();Node x=*it;way.erase(it);
	it=way.begin();Node y=*it;way.erase(it);
	d.merge(x.fa,y.fa);
	ll now=min((ll)INT_MAX,x.val+y.val+1);
	Node temp=Node(d.find(x.fa),x.val+y.val+now);
	way.insert(temp);
	L.push_back(x.fa);R.push_back(y.fa);
	addedge(x.fa,y.fa,1);
}

int main()
{
	while(read(n)&&read(m)&&read(p)&&read(q))
	{
		init(n);
		int u,v,w;
		for(int i=0;i<m;i++)					
		{
			read(u),read(v),read(w);
			addedge(u,v,w);
			d.merge(u,v);
		}
		for(int i=1;i<=n;i++)						//用并查集和set维护连通块 
			cg.insert(d.find(i));
		for(int i=0;i<tot;i++)
			siz[d.father[e[i].from]]+=e[i].dis;
		if(cg.size()<q)
		{
			puts("NO");
			continue;
		}
		else if(cg.size()==q)
		{
			if(p && tot==0)
				puts("NO");
			else
			{
				puts("YES");
				for(int i=0;i<p;i++)
					printf("%d %d\n",e[0].from,e[0].to);
			}
			continue;
		}
		int res=cg.size()-q;
		if(res>p)
		{
			puts("NO");continue;
		} 
		p-=res;
		
		for(po=cg.begin();po!=cg.end();po++)
			way.insert(Node(*po,siz[*po]));
		while(res--)
			findway();
		puts("YES");
        for(int i=0;i<L.size();i++)
			printf("%d %d\n",L[i],R[i]);
       	for(int i=0;i<p;i++)
			printf("%d %d\n",e[0].from,e[0].to);
			
	}
	return 0;
}