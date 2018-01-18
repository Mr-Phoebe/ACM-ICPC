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
#define debug(a) cout << #a" = " << (a) << endl;
#define debugarry(a, n) for (int i = 0; i < (n); i++) { cout << #a"[" << i << "] = " << (a)[i] << endl; }

#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define lowbit(x) (x&(-x))

#define MID(x,y) (x+((y-x)>>1))
#define ls (idx<<1)
#define rs (idx<<1|1)
#define lson ls,l,mid
#define rson rs,mid+1,r

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

const ll MOD=999983;
const int seed=10007;
char str[55];
ll base[55];
map<ll,int> dp;
vector<int> ans;
vector<ll> ve[MOD];

int find(ll sta)
{
    int h=(sta%MOD+MOD)%MOD;
    int sz=ve[h].size();
    for(int i=0; i<sz; i++)
        if(ve[h][i]==sta)   return true;
    return false;
}

void insert(ll sta)
{
    int h=(sta%MOD+MOD)%MOD;
    ve[h].pb(sta);
}

//dp = 1 赢
//   = 2 输

int dfs(ll sta,int len)
{
    //cout<<sta<<endl;
    if(!find(sta)) return 0;
    if(dp[sta]) return dp[sta];
    ll next=0;
    int con;
    for(int i=33; i<=126; i++)
    {
        if(dfs(sta*seed+i,len+1)==1 || dfs(i*base[len]+sta,len+1)==1)
            return dp[sta]=2;
    }
    //下面都是必败
    return dp[sta]=1;
}

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    base[0]=1;
    for(int i=1; i<55; i++)
        base[i]=base[i-1]*seed;
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%s",str);
        int len=strlen(str);
        ll ans=0;
        for(int j=len-1; j>=0; j--)
        {
            ans=0;
            for(int k=j; k<len; k++)
            {
                ans=ans*seed+str[k];
                if(!find(ans))
                    insert(ans);
            }
        }
        dp[ans]=2;
    }
    for(int i=33; i<=126; i++)
    {
        if(dfs(i,1)==1) ans.pb(i);
    }
    if(ans.size())
    {
        puts("First");
        for(int i=0; i<ans.size(); i++)
            printf("%c",ans[i]);
        putchar('\n');
    }
    else
    {
        puts("Second");
    }
    return 0;
}
