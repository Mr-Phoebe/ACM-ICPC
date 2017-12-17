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
struct P
{
    int a, b, c;
    P() {}
    P(int a,int b,int c):a(a),b(b),c(c) {}
};
const int N = 233;
bool g[N][N];
int n, m;
int out[N];
int a, b;
int f[N][N][2]; /// f[bob][alice][现在轮到谁走(0:alice 1:bob)] = 1 : Bob 必败
int cnt[N][N];
int main()
{
    int T,ca=1;
    cin>>T;
    while (T--)
    {
        cin>>n>>m;
        CLR(g, false);
        CLR(out, 0);
        while (m--)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            g[v][u] = true;
            out[u] ++;
        }
        cin >> a >> b;
        printf("Case #%d: ", ca++);
        queue <P> q; /// q 中是所有必败态（对于Bob来说）

        CLR(f, 0);
        CLR(cnt, 0);
        for(int i=1;i<=n;i++)
        {
            f[i][i][0] = 1;
            q.push(P(i,i,0));
            f[i][i][1] = 1;
            q.push(P(i,i,1));
        }
        for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if (i - j && out[i]==0)
        {
            f[i][j][0] = 1;
            q.push(P(i,j,0));
        }
        while (!q.empty())
        {
            P u = q.front();
            q.pop();
            int x = u.a, y = u.b, z = u.c;
            if (z == 1)   /// Last turn is Bob's turn
            {
                for(int j=1;j<=n;j++) if (g[x][j])   /// Last move : Bob : j --> x
                {
                    if ( ++cnt[j][y] == out[j])   /// (j,y)这个状态，Bob无论怎么走都是必败态
                    {
                        if (f[j][y][0]) continue;
                        f[j][y][0] = 1;
                        q.push(P(j, y, 0));
                    }
                }
            }
            else   /// Last turn is Alice's turn
            {
                for(int j=1;j<=n;j++) if (g[y][j])   /// Last move : Alice : j --> y
                {
                    if (f[x][j][1]) continue; /// Alice可以选择一条路使得Bob必败
                    f[x][j][1] = true;
                    q.push(P(x, j, 1));
                }
            }
        }
        if (f[a][b][0]) puts("No");
        else puts("Yes");
    }
    return 0;
}
