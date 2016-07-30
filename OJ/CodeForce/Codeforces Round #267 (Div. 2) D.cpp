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

#define MAXN 200100

struct NODE
{
    int cnt, len;
    NODE(int cnt=0, int len=0): cnt(cnt), len(len) {}
};
NODE dp[MAXN];
bool vis[MAXN];
vector<int> G[MAXN];
int m, n, ptr;
char str1[3*MAXN], str2[3*MAXN];
map<string, int> mp;
int sta[MAXN], top;

NODE Transfer(char str[])
{
    int len = strlen(str);
    int cnt = 0;
    for(int j=0; j<len; j++)
    {
        if(str[j] < 'a') str[j] += 32;
        if(str[j] == 'r') cnt++;
    }
    return NODE(cnt, len);
}

void input()
{
    ptr = 0, top = 0;
    mp.clear();
    memset(G, 0, sizeof(G));
    bool flag1 = false, flag2 = false;
    for(int i=0; i<m; i++)
    {
        scanf("%s", str1);
        NODE tmp = Transfer(str1);
        if(!mp.count(str1))
        {
            mp[str1] = ++ptr;
            dp[ptr] = tmp;
        }
        sta[top++] = mp[str1];
    }
    cin>>n;
    for(int i=0; i<n; i++)
    {
        scanf("%s %s", str1, str2);
        NODE t1 = Transfer(str1);
        NODE t2 = Transfer(str2);
        if(!mp.count(str1))
        {
            mp[str1] = ++ptr;
            dp[ptr] = t1;
        }
        if(!mp.count(str2))
        {
            mp[str2] = ++ptr;
            dp[ptr] = t2;
        }
        G[mp[str1]].push_back(mp[str2]);
    }
    for(int i=1;i<=ptr;i++)
	{
	    cout<<i<<":"<<endl;
	    for(int j=0;j<G[i].size();j++)
            cout<<G[i][j]<<" ";
        cout<<endl;
	}
}

NODE MIN(NODE a, NODE b)
{
    NODE c;
    if(a.cnt < b.cnt) c = a;
    else if(a.cnt > b.cnt) c = b;
    else
    {
        if(a.len < b.len) c = a;
        else              c = b;
    }
    return c;
}

void dfs(int u)
{
    if(vis[u]) return;
    vis[u] = true;
    for(int i=0; i<G[u].size(); i++)
    {
        int v = G[u][i];   //cout<<u<<" edge "<<v<<endl;
        cout<<v<<endl;
        dfs(v);
        dp[u] = MIN(dp[u], dp[v]);
    }
}

void solve()
{
    ll anscnt = 0;
    ll anslen = 0;
    memset(vis, 0, sizeof(vis));
    for(int i=0; i<top; i++)  //cout<<dp[i].cnt<<" "<<dp[i].len<<endl;
    {
        int u = sta[i];
        dfs(u);  //cout<<dp[i].cnt<<" "<<dp[i].len<<endl;
    }
    memset(vis, 0, sizeof(vis));
    for(int i=0; i<top; i++)  //cout<<dp[i].cnt<<" "<<dp[i].len<<endl;
    {
        int u = sta[i];
        dfs(u);  //cout<<dp[i].cnt<<" "<<dp[i].len<<endl;
        anscnt += dp[u].cnt;
        anslen += dp[u].len;
    }
    cout<<anscnt<<" "<<anslen<<endl;
}

int main()
{
//    freopen("/home/acm/code/input.txt","r", stdin);
    freopen("data.txt","r",stdin);
	freopen("out2.txt","w",stdout);
    while(cin>>m)
    {
        input();
        solve();
    }
}
