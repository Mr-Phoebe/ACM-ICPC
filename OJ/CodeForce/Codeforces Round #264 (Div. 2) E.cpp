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


const int MAX = 1e5 + 10;

struct node
{
    int fa;
    int v;
} a[MAX];
vector<int> G[MAX];
bool vis[MAX];
void dfs(int u, int f)
{
    vis[u] = true;
    a[u].fa = f;
    for(int i = 0, sz = G[u].size(); i < sz; ++i)
    {
        int v = G[u][i];
        if(vis[v]) continue;
        dfs(v,u);
    }
}
int find(int n)
{
    int value = a[n].v;
    for(int u = a[n].fa; u != -1; u = a[u].fa)
        if(__gcd(a[u].v,value) > 1)
            return u;
    return -1;
}

int main(void)
{
    //freopen("main.in","r",stdin);
    int n,q;
    int x,y;
    int id,v,w;
    read(n),read(q);
    for(int i = 1; i <= n; ++i)
        read(a[i].v);
    for(int i = 0 ; i < n-1; ++i)
    {
        read(x),read(y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dfs(1,-1);
    for(int i = 0; i < q; ++i)
    {
        read(id);
        if(id == 1)
        {
            read(v);
            printf("%d\n",find(v));
        }
        else
        {
            read(v),read(w);
            a[v].v = w;
        }
    }
    return 0;
}
