#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 0x3f3f3f3f
#define LL long long
#define eps 1e-8
#define lson (pos << 1)
#define rson (pos << 1 | 1)

template<class T> void checkMax(T &a, T b)
{
    a = max(a, b);
}
template<class T> void checkMin(T &a, T b)
{
    a = min(a, b);
}

const int N = 50005;
struct Node
{
    int l, r, delta;
    LL val, sum;
    int mid()
    {
        return (l + r) / 2;
    }
};
Node tree[4 * N];
int n, m;
LL cnt[N], add[N];
void push_up(int pos)
{
    tree[pos].val = max(tree[lson].val, tree[rson].val);
    tree[pos].sum = tree[lson].sum + tree[rson].sum;
}
void push_down(int pos)
{
    if(tree[pos].delta)
    {
        tree[lson].val = tree[lson].val << tree[pos].delta;
        tree[rson].val = tree[rson].val << tree[pos].delta;
        tree[lson].sum = tree[lson].sum << tree[pos].delta;
        tree[rson].sum = tree[rson].sum << tree[pos].delta;
        tree[pos].delta = 0;
    }
}
void build(int pos, int l, int r)
{
    tree[pos].l = l;
    tree[pos].r = r;
    tree[pos].delta = 0;
    int mid = tree[pos].mid();
    if(l == r)
    {
        tree[pos].val = tree[pos].sum = 1;
        return ;
    }
    build(lson, l, mid);
    build(rson, mid + 1, r);
    push_up(pos);
}

LL getSum(int pos, int idx)
{
    if(tree[pos].l == tree[pos].r)
        return tree[pos].sum;
    int mid = tree[pos].mid();
    push_down(pos);
    if(idx > mid)
        return tree[lson].sum + getSum(rson, idx);
    else
        return getSum(lson, idx);
}
int getIdx(int pos, LL sum)
{
    if(tree[pos].l == tree[pos].r)
        return tree[pos].r;
    push_down(pos);
    if(tree[lson].sum < sum)
        return getIdx(rson, sum - tree[lson].sum);
    else
        return getIdx(lson, sum);
}
void addVal(int pos, int idx, LL val)
{
    if(tree[pos].l == tree[pos].r)
    {
        tree[pos].val += val;
        tree[pos].sum += val;
        return ;
    }
    int mid = tree[pos].mid();
    push_down(pos);
    if(idx <= mid)  addVal(lson, idx, val);
    else            addVal(rson, idx, val);
    push_up(pos);
}
LL queryMax(int pos, int l, int r)
{
    if(l <= tree[pos].l && tree[pos].r <= r)
        return tree[pos].val;
    int mid = tree[pos].mid();
    LL ret = 0;
    push_down(pos);
    if(l <= mid)    checkMax(ret, queryMax(lson, l, r));
    if(r > mid)     checkMax(ret, queryMax(rson, l, r));
    return ret;
}
int main()
{
    int t, cas = 1, i;
    LL l, r;
    char op[2];
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        build(1, 1, n);
        printf("Case #%d:\n", cas++);
        while(m--)
        {
            scanf("%s%I64d%I64d", op, &l, &r);
            if(op[0] == 'D')
            {
                LL pre = l - 1, cur;
                int idx = getIdx(1, l);
                int start = idx, end;
                for(i = idx; i <= n && r > pre; i++)
                {
                    cur = getSum(1, i);
                    add[i] = min(cur, r) - pre;
                    //addVal(1, i, min(cur, r) - pre);
                    end = i;
                    pre = cur;
                }
                for(i = start; i <= end; i++)
                    addVal(1, i, add[i]);
            }
            else
            {
                int lx = getIdx(1, l);
                int rx = getIdx(1, r);
                LL ans = 0;
                if(lx == rx)
                {
                    ans = r - l + 1;
                }
                else
                {
                    ans = max(getSum(1, lx) - l + 1, r - getSum(1, rx - 1));
                    if(lx + 1 <= rx - 1)
                        checkMax(ans, queryMax(1, lx + 1, rx - 1));
                }
                printf("%I64d\n", ans);
            }
        }
    }
    return 0;
}
