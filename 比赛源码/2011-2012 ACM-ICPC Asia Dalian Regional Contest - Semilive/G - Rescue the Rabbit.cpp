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

const int MAXN=100010;
const int MAC=4;

int val[MAXN],dp[2][1010][(1<<10)+5];
char str[111];

inline int idx(char ch)
{
    switch(ch)
    {
    case 'A':   return 0;
    case 'T':   return 1;
    case 'C':   return 2;
    case 'G':   return 3;
    }
    return 0;
}

int get(int state,int n)
{
    int ans=0;
    for(int i=0; i<n; i++)
        if(state&(1<<i))
            ans+=val[i];
    return ans;
}

struct AC
{
    int ch[MAXN][MAC],f[MAXN],size;
    int st[MAXN];

    void init()
    {
        size=0;
        f[0]=0;
        newnode();
    }
    int newnode()
    {
        CLR(ch[size],0);
        st[size]=0;f[size]=0;
        return size++;
    }
    void insert(char *S,int id)
    {
        int u=0,x;
        for(char *sp=S; *sp; sp++)
        {
            x=idx(*sp);
            if(!ch[u][x])   ch[u][x]=newnode();
            u=ch[u][x];
        }
        st[u]|=(1<<id);
    }
    int que[MAXN];
    void getfail()
    {
        int u,cur;
        int head=0,tail=0;
        que[tail++]=0;
        while(head<tail)
        {
            cur=que[head++];
            for(int i=0; i<MAC; i++)
            {
                if(ch[cur][i]==0)
                    ch[cur][i]=ch[f[cur]][i];
                else
                {
                    int u=ch[cur][i];
                    if(cur)
                        f[u]=ch[f[cur]][i];
                    st[u] |= st[f[u]];
                    que[tail++]=u;
                }
            }
        }
    }
    int solve(int n,int m)
    {
        int cur=0,next=1;
        CLR(dp,0);
        dp[0][0][0]=1;
        for(int i=1; i<=m; i++)
        {
            CLR(dp[next],0);
            for(int j=0; j<size; j++)
                for(int k=0; k<MAC; k++)
                    for(int r=0; r<(1<<n); r++)
                        if(dp[cur][j][r])
                            dp[next][ch[j][k]][r|st[ch[j][k]]]=1;
            cur=next;
            next^=1;
        }
        int ans=-INF;
        for(int j=0; j<(1<<n); j++)
            for(int i=0; i<size; i++)
                if(dp[cur][i][j])
                {
                    ans=max(ans,get(j,n));
                    break;
                }
        return ans;
    }
} ac;

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        ac.init();
        for(int i=0; i<n; i++)
        {
            scanf("%s%d",str,&val[i]);
            ac.insert(str,i);
        }
        ac.getfail();
        int ans=ac.solve(n,m);
        if(ans<0)
            puts("No Rabbit after 2012!");
        else
            printf("%d\n",ans);
    }
    return 0;
} 