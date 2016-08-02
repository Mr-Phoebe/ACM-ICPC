#include <bits/stdc++.h>

using namespace std;

struct line
{
    int x1, x2, y, tag;
    line() {}
    line(int _x1, int _x2, int _y, int _tag):
        x1(_x1), x2(_x2), y(_y), tag(_tag) {}
    bool operator < (const line &a) const
    {
        return y < a.y;
    }
};

#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1

line l[60010<<1];
int lisan[60010<<1];
int before[120010<<2], fa[60010], change[120010<<2];
int h[60010];
long long ans[60010];

void update(int _l, int _r, int c, int l, int r, int rt)
{
    if(_l <= l && r <= _r)
    {
        if(c > 0)
        {
            ans[before[rt]] -= (long long)(lisan[r] - lisan[l-1]) * h[c];
            fa[c] = before[rt];
            before[rt] = c;
        }
        else
        {
            before[rt] = fa[-c];
        }
        change[rt] = true;
        return ;
    }
    if(change[rt])
    {
        before[rt<<1] = before[rt<<1|1] = before[rt];
        change[rt<<1] = change[rt<<1|1] = true;
        change[rt] = false;
    }
    int m = (l+r)>>1;
    if(_l <= m) update(_l, _r, c, lson);
    if(m < _r) update(_l, _r, c, rson);
}

int main()
{
    int n, W, H;
    scanf("%d%d%d", &n, &W, &H);
    int len = 0;
    for(int i = 0; i < n; ++i)
    {
        int x1, x2, y1, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if(x1 > x2)
            swap(x1, x2);
        if(y1 > y2)
            swap(y1, y2);
        lisan[len] = x1;
        l[len++] = line(x1, x2, y1, i+1);
        lisan[len] = x2;
        l[len++] = line(x1, x2, y2, -(i+1));
        h[i+1] = y2-y1;
        ans[i+1] = (long long)h[i+1] * (x2-x1);
    }
    sort(lisan, lisan+len);
    sort(l, l+len);
    int true_len = unique(lisan, lisan+len) - lisan;
    ans[0] = (long long)W*H;
    for(int i = 0; i < len; ++i)
    {
        int ll = lower_bound(lisan, lisan+true_len, l[i].x1) - lisan;
        int rr = lower_bound(lisan, lisan+true_len, l[i].x2) - lisan;
        update(ll+1, rr, l[i].tag, 1, true_len, 1);
    }
    sort(ans, ans+n+1);
    for(int i = 0; i <= n; ++i)
        printf("%I64d%c", ans[i], i == n ? '\n' : ' ');
    return 0;
}
