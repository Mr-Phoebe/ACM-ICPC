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
#define LLINF 1LL<<62

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

const int M=4000010;

struct POS
{
    int left, right, col;
} tree[M];
bool color[33];

void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

void build(int l, int r, int now)
{
    tree[now].left = l;
    tree[now].right = r;
    tree[now].col = 2;
    int mid = (l + r) / 2;
    if (r > l)
    {
        build(mid + 1, r, now * 2 + 1);
        build(l, mid, now * 2);
    }
}

void inseart(int a, int b, int val, int now)
{
    if (tree[now].left >= a && tree[now].right <= b)
    {
        tree[now].col = val;
        return;
    }
    if (tree[now].col > 0)
    {
        tree[now * 2].col = tree[now].col;
        tree[now * 2 + 1].col = tree[now].col;
    }
    tree[now].col = -1;
    int mid = (tree[now].left + tree[now].right) / 2;
    if (b <= mid)
        inseart(a, b, val, now * 2);
    else if (a > mid)
        inseart(a, b, val, now * 2 + 1);
    else
    {
        inseart(a, mid, val, now * 2);
        inseart(mid + 1, b, val, now * 2 + 1);
    }
}

void find(int a, int b, int now)
{
    if (tree[now].col > 0)
    {
        color[tree[now].col] = true;
        return;
    }
    if (tree[now].left < tree[now].right)
    {
        int mid = (tree[now].left + tree[now].right) / 2;
        if (b <= mid)
            find(a, b, now * 2);
        else if (a > mid)
            find(a, b, now * 2 + 1);
        else
        {
            find(a, mid, now * 2);
            find(mid + 1, b, now * 2 + 1);
        }
    }
}

int main()
{
    int i, l, t, o, a, b, val;
    char c[2];
    while (scanf("%d %d", &l, &o) == 2 && (l || o))
    {
        build(1, l, 1);
        while (o--)
        {
            scanf(" %s", &c);
            if (c[0] == 'P')
            {
                scanf(" %d %d %d", &a, &b, &val);
                if (a > b)
                    swap(a, b);
                inseart(a, b, val, 1);
            }
            else
            {
                scanf(" %d %d", &a, &b);
                if (a > b)
                    swap(a, b);
                memset(color, false, sizeof (color));
                find(a, b, 1);
                int ans=0;
                for (i = 1; i <= 30; i++)
                    if (color[i])
                        ans++;
                for (i = 1; i <= 30; i++)
                    if (color[i])
                    {
                        write(i);
                        if(--ans)
                            putchar(' ');
                    }
                putchar('\n');
            }
        }
    }
    return 0;
}
