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

using namespace std;
const int maxn = 5*1e5;
typedef long long ll;

ll s[maxn], del[maxn], mark[maxn];

void build (int u, int l, int r)
{
    if (l < r)
	{
        int mid = (l + r)/2;
        build(u*2, l, mid);
        build(u*2+1, mid+1, r);
    }
	else
        mark[u] = l;
}

ll query (int u, int l, int r, int x, int y)
{
    if (y < l || x > r)
        return 0;

    if (x <= l && r <= y)
        return s[u];

    int mid = (l + r) / 2;
    ll L = query(u*2, l, mid, x, y);
    ll R = query(u*2+1, mid+1, r, x, y);
    return L + R + max(0, min(r, y) - max(l, x) + 1) * del[u];
}

void clear (int u, int l, int r, int z)
{
    if (mark[u])
	{
        del[u] += abs(mark[u]-z);
        s[u] += 1LL * (r-l+1) * abs(mark[u]-z);
        mark[u] = 0;
    }
	else
	{
        if (l == r)
            return;
        int mid = (l + r) / 2, lc = u*2, rc = u*2+1;
        clear(lc, l, mid, z);
        clear(rc, mid+1, r, z);
        s[u] = s[lc] + s[rc] + 1LL * (r-l+1) * del[u];
    }
}

void modify (int u, int l, int r, int x, int y, int z)
{
    //    printf("%d %d %d %d %d %d\n", u, l, r, x, y, z);
    if (y < l || x > r)
        return;

    if (x <= l && r <= y)
	{
        clear(u, l, r, z);
        mark[u] = z;
        return;
    }

    int mid = (l + r) / 2, lc = u*2, rc = u*2+1;
    if (mark[u])
	{
        mark[lc] = mark[rc] = mark[u];
        mark[u] = 0;
    }
    modify(lc, l, mid, x, y, z);
    modify(rc, mid+1, r, x, y, z);
    s[u] = s[lc] + s[rc] + 1LL * (r-l+1) * del[u];
}

int main ()
{
    int n, m;
    scanf("%d%d", &n, &m);
    /*
       memset(sum, 0, sizeof(sum));
       memset(del, 0, sizeof(del));
       memset(mark, 0, sizeof(mark));
       */

    build(1, 1, n);

    int type, x, y, z;;
    for (int i = 0; i < m; i++)
	{
        scanf("%d%d%d", &type, &x, &y);
        if (type == 1)
		{
            scanf("%d", &z);
            modify(1, 1, n, x, y, z);
        }
		else
            printf("%I64d\n", query(1, 1, n, x, y));
    }
    return 0;
}