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

const int MAXN=200100;

struct Node
{
	int cnt, len;
    Node(int cnt=0, int len=0): cnt(cnt), len(len) {}
    Node(const Node &a): cnt(a.cnt),len(a.len){}
    bool operator < (const Node b) const
    {
	    if(cnt != b.cnt)
            return cnt < b.cnt;
	    else
	        return len < b.len;
    }
}dp[MAXN];
bool vis[MAXN];
vector<int> G[MAXN];
int n,m,head[MAXN];
int ptr=1,top;
map<string,int> mapp;
string str,str2;

Node transfer(string &str)
{
    int len=str.length();
    int cnt=0;
    for(int j=0; j<len; j++)
    {
    	if(str[j]<'a')
			str[j]+=32;
        if(str[j]=='r')
			cnt++;
    }
    return Node(cnt, len);
}

void dfs(int u)
{
	if(vis[u])
		return;
	vis[u]=true;
	int sz=G[u].size();
	for(int i=0;i<sz;i++)
	{
		dfs(G[u][i]);
		dp[u]=min(dp[u],dp[G[u][i]]);
	}
}

int main()
{
//	freopen("data.txt","r",stdin);
//	freopen("out1.txt","w",stdout);
	read(n);
	for(int i=0;i<n;i++)
	{
		cin>>str;
		Node temp=transfer(str);
		if(!mapp.count(str))
        {
            mapp[str]=ptr;
            dp[ptr++]=temp;
        }
        head[top++]=mapp[str];
	}
	read(m);
	for(int i=0;i<m;i++)
	{
		cin>>str>>str2;
		Node temp=transfer(str);
		Node tmp=transfer(str2);
		if(!mapp.count(str))
        {
            mapp[str]=ptr;
            dp[ptr++]=temp;
        }
        if(!mapp.count(str2))
        {
            mapp[str2]=ptr;
            dp[ptr++]=tmp;
        }
        G[mapp[str]].push_back(mapp[str2]);
	}
//	for(int i=1;i<ptr;i++)
//	{
//	    cout<<i<<":"<<endl;
//	    for(int j=0;j<G[i].size();j++)
//            cout<<G[i][j]<<" ";
//        cout<<endl;
//	}

	for(int i=0;i<top;i++)
	{
		int u=head[i];
		dfs(u);
	}
	CLR(vis,0);
	ll ans1=0,ans2=0;
	for(int i=0; i<top; i++)
    {
        int u=head[i];
        dfs(u);
        ans1+=(ll)dp[u].cnt;
        ans2+=(ll)dp[u].len;
    }
    write(ans1),putchar(' '),write(ans2),putchar('\n');
	return 0;
}
