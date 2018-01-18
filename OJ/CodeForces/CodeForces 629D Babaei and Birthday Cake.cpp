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
#define speed std::ios::sync_with_stdio(false);
#define eps 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LLINF 1LL<<62
#define lson id<<1, l, mid
#define rson id<<1|1, mid+1, r
#define ls id<<1
#define rs id<<1|1

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

const int MAXN = 100005;

struct Node
{
    int l, r; double Max;
};

Node tree[MAXN<<2];

void pushup(int id)
{
    tree[id].Max = max(tree[ls].Max, tree[rs].Max);
}

void build(int id, int l, int r)
{
    tree[id].l = l; tree[id].r = r;
    tree[id].Max = 0.0;
    if(l == r) return ;
    int mid = MID(l, r);
    build(lson);
	build(rson);
}

void update(int id, int pos, double val)
{
    if(tree[id].l == tree[id].r)
    {
        tree[id].Max = val;
        return ;
    }
    int mid = MID(tree[id].l, tree[id].r);
    if(pos <= mid) update(ls, pos, val);
    else update(rs, pos, val);
    pushup(id);
}

double query(int id, int L, int R)
{
    if(tree[id].l == L && R == tree[id].r)
        return tree[id].Max;
    int mid = MID(tree[id].l, tree[id].r);
    if(R <= mid) return query(ls, L, R);
    else if(L > mid) return query(rs, L, R);
    else return max(query(ls, L, mid), query(rs, mid+1, R));
}

double val[MAXN], rec[MAXN];

int main()
{
	int n;
	read(n);
	for(int i = 0; i < n; i++)
	{
		double r, h;
		scanf("%lf %lf", &r, &h);
		val[i] = rec[i+1] = PI * r * r * h;
	}
    sort(rec+1, rec+n+1);
    int top = unique(rec+1, rec+n+1) - rec;
    double ans = 0; build(1, 0, n);
    for(int i = 0; i < n; i++)
    {
        int pos = lower_bound(rec, rec+top, val[i]) - rec;
        double res = query(1, 0, pos-1) + val[i];
        update(1, pos, res);
		ans = max(ans, res);
    }
    printf("%.12lf\n", ans);
	return 0;
}
