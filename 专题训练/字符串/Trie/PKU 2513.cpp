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

const int MAXN=500005;
struct Trie
{
	int child[MAXN*10][26],root;
	int flag[MAXN*10];
	int sz;
	int idx(char c) { return c-'a'; }
	Trie()
	{
		root=sz=1;CLR(child[1],0);flag[1]=0;
	}
	void insert(const char *str,const int v)
	{
		int *cur=&root;
		for(const char *p=str;*p;p++)
		{
			cur=&child[*cur][idx(*p)];
			if(*cur==0)
			{
				*cur=++sz;
				CLR(child[sz],0);
				flag[*cur]=0;
			}
		}
		flag[*cur]=v;
	}
	int find(const char *str)
 	{
    	int *cur=&root;
    	for(const char *p=str;*p && *cur;p++)
			cur=&child[*cur][idx(*p)];
        if(*cur==0)
            return 0;
    	return flag[*cur];
  	}
}trie;

int fa[MAXN];
int find_fa(int x)
{
	if(fa[x]==x)
		return x;
	else
		return fa[x]=find_fa(fa[x]);
}

void Merge(int x,int y)
{
	int xx=find_fa(x),yy=find_fa(y);
	fa[xx]=yy;
}

char a[20],b[20];
int deg[MAXN];

void init()
{
	for(int i=1;i<MAXN;i++)
		fa[i]=i,deg[i]=0;
}

bool check(int cnt)
{
	int euler=0;
    int father=0,fath=find_fa(1);
    for(int i=1;i<cnt;i++)
	{
        euler+=(deg[i]&1);
        father+=( find_fa(i)!=fath );
    }
    return father || euler>2;
}

int main()
{
//    freopen("data.txt","r",stdin);
	int cnt=1;
	init();
	while(scanf("%s %s",a,b)!=EOF)
 	{
 		int s=trie.find(a);
 		if(!s)
 		{
		 	trie.insert(a,cnt);
		 	s=cnt++;
		}
 		int t=trie.find(b);
		if(!t)
		{
			trie.insert(b,cnt);
			t=cnt++;
		}
		if(find_fa(s)!=find_fa(t))
			Merge(s,t);
		deg[s]++;
		deg[t]++;
 	}
 	if(check(cnt))
		puts("Impossible");
	else
		puts("Possible");
	return 0;
}
