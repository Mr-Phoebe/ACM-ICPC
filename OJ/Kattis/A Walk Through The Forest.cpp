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
#include <list>
#include <ctime>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <functional>
#include <numeric>
#pragma comment(linker, "/STACK:1024000000,1024000000")


using namespace std;
#define eps 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LLINF 1LL<<50
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
#define debug(a) cout << #a" = " << (a) << endl;
#define debugarry(a, n) for (int i = 0; i < (n); i++) { cout << #a"[" << i << "] = " << (a)[i] << endl; }

#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define lowbit(x) (x&(-x))

#define MID(x,y) (x+((y-x)>>1))
#define getidx(l,r) (l+r | l!=r)
#define ls getidx(l,mid)
#define rs getidx(mid+1,r)
#define lson l,mid
#define rson mid+1,r

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

const int N = 1010;

struct node{
    int v,d;
    node(int a,int b){
        v=a;d=b;
    }
};
vector<node>V[N];
int vis[N],d[N];
int v;
int n,m;
int ans[N];
void dij(int s)
{
    memset(vis,0,sizeof(vis));
    for(int i=0;i<=n;i++)
        d[i]=INF;
    d[s]=0;
    queue<int>Q;
    Q.push(s);
    vis[s]=1;
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        vis[u]=0;
        int m=V[u].size();
        for(int i=0;i<m;i++){
            int v=V[u][i].v;
            int w=V[u][i].d;
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                if(!vis[v]){
                    vis[v]=1;
                    Q.push(v);
                }
            }
        }
    }
}
int dfs(int u)
{
    if(u==2) return 1;
    if(ans[u]!=0) return ans[u];
    int m=V[u].size();
    int cnt=0;
    for(int i=0;i<m;i++){
        int v=V[u][i].v;
        int w=V[u][i].d;
        if(d[v]<d[u])
            cnt+=dfs(v);
    }
    return ans[u]=cnt;
}
int main(void)
{
    int a,b,c;
    while(scanf("%d",&n),n)
    {
        scanf("%d",&m);
        memset(ans,0,sizeof(ans));
        for(int i=0;i<=n;i++) V[i].clear();
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&c);
            V[a].push_back(node(b,c));
            V[b].push_back(node(a,c));
        }
        dij(2);
        printf("%d\n",dfs(1));
    }
    return 0;
}