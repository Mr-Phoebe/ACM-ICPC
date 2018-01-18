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
#define INF 2000000000001

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


const ll MAXE=400010;

bool vis[MAXE];
ll fa[MAXE];//×?D?éú3éê÷
ll dis[MAXE];
ll first[MAXE],tot=1;
ll n,m,q;

struct Edge
{
	ll u;
	ll l,s;
    ll next;
}e[MAXE];

struct edge
{
    ll u,v;
	ll l,s;
}ed[MAXE];

struct node
{
	ll u;
	ll dis;
	bool operator < (const node &a) const
	{
		return dis > a.dis;
	}
};
priority_queue<node>Q; //node類型的優先隊列


ll find_fa(ll x)
{
	if(fa[x]==x)
		return x;
	else
		return fa[x]=find_fa(fa[x]);
}

void Merge(ll x,ll y)
{
	fa[find_fa(x)]=find_fa(y);
}

void Dijkstra(ll x,ll mm)
{
	for(ll i = 1; i <= n; i++)
	{
		vis[i] = false;
		dis[i] = INF;  //初始最短路程
	}
	dis[x] = 0;
	node pre, next;
	pre.u = x;
	pre.dis = 0;
	Q.push(pre);
	while(!Q.empty())
	{
		pre = Q.top();
		Q.pop();
		if(vis[pre.u])//除去同時進幾次的
			continue;
		vis[pre.u] = true;
		dis[pre.u] = pre.dis;
		for(ll i = first[pre.u]; i != -1; i = e[i].next)
		{
			next.u = e[i].u;
			if(!vis[next.u] && e[i].s<=mm && dis[e[i].u] > dis[pre.u] + e[i].l)
			{
				next.dis = pre.dis + e[i].l;
				Q.push(next);
			}
		}
	}
}

bool cmp(edge a,edge b)
{
	return a.s<b.s;
}

void solve(ll x,ll y)
{
    for(ll i=1;i<=n;i++)
        fa[i]=i;
	for(ll i=0;i<m;i++)
	{
		ll xx=find_fa(ed[i].u),yy=find_fa(ed[i].v),ss=ed[i].s;
		if(xx!=yy)
            Merge(xx,yy);
		if(find_fa(x)==find_fa(y))
		{
//		    cout<<x<<" "<<y<<" "<<i<<endl;
			Dijkstra(x,ss);
			printf("%lld %lld\n",dis[y],ss);
            return;
		}
	}
	return;
}

void add(ll x,ll  y,ll  le,ll  ss)
{
    e[tot].u=y;
    e[tot].l=le;
    e[tot].s=ss;
    e[tot].next=first[x];
    first[x]=tot++;
}


int main()
{
//    freopen("data.txt","r",stdin);
	while(read(n)&&read(m)&&read(q)&&n&&m&&q)
    {
        CLR(first,-1);
        tot=1;
        ll x,y,le,ss;
        for(ll i=0;i<m;i++)
        {
            read(x),read(y),read(le),read(ss);
            ed[i].u=x;ed[i].v=y;ed[i].l=le;ed[i].s=ss;
            add(x,y,le,ss);
            add(y,x,le,ss);
        }
        sort(ed,ed+m,cmp);//for(int i=1;i<tot;i++) cout<<i<<" : "<<e[i].u<<" "<<e[i].next<<endl;
/*        for(int i=1;i<=n;i++)
        {
            cout<<i<<":"<<first[i]<<"       ";
            for(int j=first[i];j!=-1;j=e[j].next)
                cout<<e[j].u<<" ";
            cout<<endl;
        }*/
        while(q--)
        {
            read(x),read(y);
            solve(x,y);
        }
    }

}
