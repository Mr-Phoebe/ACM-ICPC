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

const int MAXN=3000010;
const int MAC=26;

struct Trie
{
    int cnt[MAXN],vis[MAXN];
    struct Node
    {
        int ch[MAC];
        void init()
        {
            CLR(ch,0);
        }
    }t[MAXN];
    int root;
    int sz;
    int newnode()
    {
        t[sz].init();
        cnt[sz]=0;
        return sz++;
    }
    void init()
    {
        sz=0;
        root=newnode();
    }
    void insert(const char *s)
    {
        int u=root;
        for(int i=0,x; s[i]; i++)
        {
            x=(s[i]-'a');
            if(!t[u].ch[x])
                t[u].ch[x]=newnode();
            u=t[u].ch[x];
            cnt[u]++;
        }
    }
    void dfs(int u,int idx,const char* s,int res)
    {
        if(res<0)     return;
        if(vis[u]==2)    return;
        if(s[idx]=='\0')
        {
            vis[u]=2;
            return;
        }
        vis[u]=1;
        for(int i=0; i<MAC; i++)
        {
            if(t[u].ch[i])
            {
                if((s[idx]-'a')==i)
                    dfs(t[u].ch[i],idx+1,s,res);
                else
                    dfs(t[u].ch[i],idx+1,s,res-1);
                dfs(t[u].ch[i],idx,s,res-1);
            }
        }
        dfs(u,idx+1,s,res-1);
    }

    int count(int u)
    {
        if(vis[u]==2)
            return cnt[u];
        if(!vis[u])
            return 0;
        int ret=0;
        for(int i=0; i<MAC; i++)
            if(t[u].ch[i])
                ret+=count(t[u].ch[i]);
        return ret;
    }

    int find(const char* s,int tot)
    {
        CLR(vis,0);
        dfs(root,0,s,tot);
        return count(root);
    }
} g;

char str[22];
int n,m;

int main()
{
//freopen("data.txt","r",stdin);
    while(~scanf("%d",&n))
    {
        g.init();
        for(int i=1; i<=n; i++)
        {
            scanf("%s",str);
            g.insert(str);
        }
        scanf("%d",&m);
        for (int i=0,x; i<m; i++)
        {
            scanf("%s %d",str,&x);
            int ret;
            if(strlen(str)<=x) ret=n;
            else    ret=g.find(str,x);
            printf("%d\n",ret);
        }
    }
    return 0;
}