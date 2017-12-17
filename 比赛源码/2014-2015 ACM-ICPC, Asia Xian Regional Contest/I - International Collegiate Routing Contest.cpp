//      whn6325689
//      Mr.Phoebe
//      http://blog.csdn.net/u013007900
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
#include <functional>
#include <numeric>
#pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;

#define eps 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LLINF 1LL<<62
#define speed std::ios::sync_with_stdio(false);

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;

#define CLR(x,y) memset(x,y,sizeof(x))
#define CPY(x,y) memcpy(x,y,sizeof(x))
#define clr(a,x,size) memset(a,x,sizeof(a[0])*(size))
#define cpy(a,x,size) memcpy(a,x,sizeof(a[0])*(size))

#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define lowbit(x) (x&(-x))

#define MID(x,y) (x+((y-x)>>1))
#define ls (idx<<1)
#define rs (idx<<1|1)
#define lson ls,l,mid
#define rson rs,mid+1,r
#define root 1,1,n

template<class T>
inline bool read(T &n)
{
    T x = 0, tmp = 1;
    char c = getchar();
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

const int MAXN=30010;
const int MAX_NODE=MAXN*33;
const int MAXC=2;

struct Node
{
	int num[4],l;
	int ip[33];
	Node()
	{
	    CLR(ip,0);CLR(num,0);l=0;
	}
	void change()
	{
		for(int j=0;j<4;j++)
			for(int i=7;i>=0;i--)
			{
				ip[j*8+7-i]=(num[j]>>i)&1;
			}
	}
	void change2()
	{
		for(int j=0;j<4;j++)
		{
			num[j]=0;
			for(int i=7;i>=0;i--)
			{
				num[j]|=ip[j*8+7-i]<<i;
			}
			//cout<<num[j]<<endl;
		}
	}
	void print()
	{
		for(int i=0;i<32;i++)
		{
			write(ip[i]);
			if((i+1)%8==0)
				putchar('.');
		}
		puts("");
	}
	void print2()
	{
		printf("%d.%d.%d.%d/%d\n",num[0],num[1],num[2],num[3],l);
	}
}a[MAXN];
vector<Node> ans;
int n;

int nowstr[MAX_NODE];

struct Trie
{
	int tot,rot,next[MAX_NODE][MAXC];
	bool flag[MAX_NODE];
	Trie()
	{
		CLR(next[1],0);
		flag[1]=false;
		rot=tot=1;
	}
	void init()
	{
		CLR(next[1],0);
		flag[1]=false;
		rot=tot=1;
	}
	void insert(const int *str,int len)
	{
		int *cur=&rot;
		for(int p=0;p<len;p++)
		{
			cur=&next[*cur][str[p]];
			if(*cur==0)
			{
				*cur=++tot;
				CLR(next[tot],0);
				flag[tot]=false;
			}
		}
		flag[*cur]=true;
	}
	void dfs(int u,int dep)
	{
	    if(flag[u]) return;
		int son=(next[u][0]!=0)+(next[u][1]!=0);
		//cout<<u<<" "<<son<<endl;
		if(son==0)	return;
		if(son==2)
		{
			nowstr[dep+1]=0;
			dfs(next[u][0],dep+1);
			nowstr[dep+1]=1;
			dfs(next[u][1],dep+1);
			return;
		}
		Node temp;
		if(next[u][0])
		{
			nowstr[dep+1]=1;
			for(int i=1;i<=dep+1;i++)
				temp.ip[i-1]=nowstr[i];
			temp.l=dep+1;
			ans.pb(temp);
			nowstr[dep+1]=0;
			dfs(next[u][0],dep+1);
		}
		else
		{
			nowstr[dep+1]=0;
			for(int i=1;i<=dep+1;i++)
				temp.ip[i-1]=nowstr[i];
			temp.l=dep+1;
			ans.pb(temp);
			nowstr[dep+1]=1;
			dfs(next[u][1],dep+1);
		}
	}
}g;


int main()
{
	int T,cas=1;
	read(T);
	while(T--)
	{
		g.init();ans.clear();CLR(a,0);
		read(n);
		printf("Case #%d:\n",cas++);
		if(n==0)
		{
			printf("1\n0.0.0.0/0\n");
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%d.%d.%d.%d/%d",&a[i].num[0],&a[i].num[1],&a[i].num[2],&a[i].num[3],&a[i].l);
			a[i].change();//a[i].print();
			g.insert(a[i].ip,a[i].l);
		}
		g.dfs(1,0);
		write(ans.size()),putchar('\n');
		for(int i=0;i<ans.size();i++)
		{
			ans[i].change2();
			ans[i].print2();
		}

	}
	return 0;
}
