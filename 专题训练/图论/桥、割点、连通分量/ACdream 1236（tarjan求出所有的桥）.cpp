//      whn6325689
//		Mr.Phoebe
//		http://blog.csdn.net/u013007900
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

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;

#define CLR(x,y) memset(x,y,sizeof(x))
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define lowbit(x) (x&(-x))
#define MID(x,y) (x+((y-x)>>1))
#define eps 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LLINF 1LL<<62

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

const int N = 10010;
const int M = 100010;

struct Node
{
    int next;
    int to;
    int d;
}e[M << 2];

int head[N];
int DFN[N];
int low[N];
bool instack[N];
int bridge[M << 2];
int tot, cnt, res, n, m;

void addedge(int from, int to, int d)
{
    e[tot].to = to;
    e[tot].d = d;
    e[tot].next = head[from];
    head[from] = tot++;
}

void tarjan(int u, int fa)
{
    DFN[u] = low[u] = ++cnt;
    instack[u] = 1;
    for (int i=head[u]; ~i; i=e[i].next)
    {
        int v = e[i].to;
        if(e[i].d == fa)
            continue;
        if(!DFN[v])
        {
            tarjan(v, e[i].d);
            low[u] = min(low[u], low[v]);
            if(low[v] > DFN[u])
                bridge[res++] = e[i].d;
        }
        else if(instack[v])
            low[u] = min(low[u], DFN[v]);
    }
}

int main()
{
    while (read(n)&&read(m))
    {
        CLR(head,-1);
        CLR(instack,0);
        CLR(DFN,0);
        cnt = tot = res = 0;
        int u, v;
        for(int i=1; i<=m; i++)
        {
            read(u),read(v);
            addedge(u, v, i);
            addedge(v, u, i);
        }
        for(int i=1; i<=n; i++)
            if(DFN[i]==0)
                tarjan(i, -1);
        sort(bridge, bridge+res);
        printf("%d\n",res);
        if(!res)
            continue;
        for(int i=0; i<res; i++)
            printf("%d%c",bridge[i],i==res-1?'\n':' ');
    }
    return 0;
}
