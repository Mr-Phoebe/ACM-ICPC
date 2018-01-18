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
#include <ctime>
#include <set>
#include <map>
#include <cmath>
#define CLR(x,y) memset(x,y,sizeof(x))
#define mp(x,y) make_pair(x,y)
#define eps 1e-9
#define INF 0x3f3f3f3f
#define LLINF 1LL<<62

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

const int N=2500;
const int M=2000000;
int b[501][501];

struct Edge
{
	int u,v,next;
}edge[M];
struct Node
{
	int s,e,len;
}a[N];
int first[N],DFN[N],divi[N],LOW[N],instack[N],stack[N];
int cnt,cnt_edge,top,nowt;

inline void addedge(int u,int v)
{
	edge[cnt_edge].v=v;
	edge[cnt_edge].next=first[u];
	first[u]=cnt_edge++;
}

void tarjan(int u)
{
	int v;
	DFN[u]=LOW[u]=++nowt;
	stack[++top]=u;
	instack[u]=1;
	for(int cur=first[u];~cur;cur=edge[cur].next)
	{
		int v=edge[cur].v;
		if(!DFN[v])
		{
			tarjan(v);
			LOW[u]=min(LOW[u],LOW[v]);
		}
		else if(instack[v])
			LOW[u]=min(LOW[u],DFN[v]);
	}
	if(DFN[u]==LOW[u])
	{
		++cnt;
		do
		{
			v=stack[top--];
			instack[v]=0;
			divi[v]=cnt;
		}
		while(u!=v);
	}
}

void init()
{
	CLR(first,-1);
	CLR(instack,0);
	CLR(divi,0);
	CLR(DFN,0);
	CLR(LOW,0);
	nowt=cnt=top=0;
	cnt_edge=0;
}

bool judege(int n)
{
	for(int i=0;i<2*n;i++)
		if(!DFN[i])
			tarjan(i);
	for(int i=0;i<n;i++)
		if(divi[i]==divi[n+i])
			return 0;
	return 1;
}

bool build(int n)
{
	for(int k=0;k<32;k++)
	{
		init();
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
			{
				int w=(b[i][j]>>k)&1;
				if(i%2==1 && j%2==1)
				{
					if(!w)
					{
						addedge(i,j);addedge(j+n,i+n);
						addedge(i+n,j+n);addedge(j,i);
						addedge(i+n,j);addedge(j+n,i);
					}
					else
					{
						addedge(i,j+n);addedge(j,i+n);
					}
				}
				else if(i%2==0 && j%2==0)
				{
					if(!w)
					{
						addedge(i+n,j);addedge(j+n,i);
					}
					else
					{
						addedge(i,j);addedge(j+n,i+n);
						addedge(i+n,j+n);addedge(j,i);
						addedge(i,j+n);addedge(j,i+n);
					}
				}
				else
				{
					if(!w)
					{
						addedge(i,j);addedge(j+n,i+n);
						addedge(i+n,j+n);addedge(j,i);
					}
					else
					{
						addedge(i,j+n);addedge(j,i+n);
						addedge(i+n,j);addedge(j+n,i);
					}
				}
			}
		if(!judege(n))
			return false;
	}
	return true;
}

bool ok(int n)
{
    for(int i=0;i<n;i++)
	{
        if(b[i][i]!=0)
			return false;
        for(int j=i+1;j<n;j++)
            if(b[i][j] != b[j][i])
                return false;
    }
    return true;
}

int main()
{
	int n;
	while(read(n))
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				read(b[i][j]);
		if(!ok(n))
		{
			puts("NO");
			continue;
		}
		if(build(n))
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
