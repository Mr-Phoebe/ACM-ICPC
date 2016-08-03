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
struct node
{
	double now, cap;
}p[10005];
int n, m, st, ed, sum;
int deg[10005];
vector<int> a[10005];
int q[10005];

void topsort()
{
	int head, tail;
	p[st].now += sum;
	head = 1; tail = 1; q[1] = st;
	for (int i = 1; i <= n; i++)
	if (deg[i] == 0 && i != st)
	{
		tail++;
		q[tail] = i;
	}
	while(head <= tail)
	{
        int x = q[head];
        node &tmp = p[x];
        if(tmp.now - tmp.cap > 0)
		{
            if(a[x].size())
			{
                double delta = (tmp.now-tmp.cap)/a[x].size();
                 tmp.now = tmp.cap;
                for(int i = 0; i < a[x].size(); i++)
				{
                    int v = a[x][i];
                    p[v].now += delta;
					deg[v]--;
                    if(deg[v] == 0)
					{
						tail++;
						q[tail] = v;
					}
                }
            }
			else tmp.now = tmp.cap;
        }
		head++;
    }
}
int main()
{
    scanf("%d%d",&n, &m);
    for(int i = 1; i <= n; i++) scanf("%lf%lf",&p[i].cap,&p[i].now);
	memset(deg, 0, sizeof(deg));
    for(int i = 0; i < m; i++)
	{
        int u,v;
		scanf("%d%d",&u,&v);
        a[u].push_back(v);
        deg[v]++;
    }
    scanf("%d%d%d",&st, &sum, &ed);
	topsort();
    printf("%lf",p[ed].now);
    return 0;
}
