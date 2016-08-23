#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <utility>
#include <map>
#include <set>
#include <cctype>
#include <climits>
#include <stack>
#include <cmath>
#include <bitset>
#include <numeric>
#include <functional>

using namespace std;

#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1

struct line
{
    int x, y;
    int h;
    int c;
    line() {}
    line(int _x, int _y, int _h, int _c) : x(_x), y(_y), h(_h), c(_c) {}
    bool operator < (const line a) const
    {
        return h < a.h;
    }
};

line l[10010];
int len_cover[20010<<2], seg_cnt[20010<<2], len[20010<<2];
bool lc[20010<<2], rc[20010<<2];

inline void push_up(int l, int r, int rt)
{
    if(len_cover[rt])
    {
        lc[rt] = rc[rt] = true;
        len[rt] = r - l + 1;
        seg_cnt[rt] = 1;
    }
    else if(l == r)
    {
        len[rt] = seg_cnt[rt] = lc[rt] = rc[rt] = 0;
    }
    else
    {
        lc[rt] = lc[rt<<1];
        rc[rt] = rc[rt<<1|1];
        len[rt] = len[rt<<1] + len[rt<<1|1];
        seg_cnt[rt] = seg_cnt[rt<<1] + seg_cnt[rt<<1|1];
        if(rc[rt<<1] && lc[rt<<1|1])
            --seg_cnt[rt];
    }
}

void update(int _l, int _r, int c, int l, int r, int rt)
{
    if(_l <= l && r <= _r)
    {
        len_cover[rt] += c;
        push_up(l, r, rt);
        return ;
    }
    int m = (l+r) >> 1;
    if(_l <= m) update(_l, _r, c, lson);
    if(m < _r) update(_l, _r, c, rson);
    push_up(l, r, rt);
}

int main()
{
    int n;
    while(scanf("%d", &n) > 0)
    {
        int ll = 0;
        int lbd = 10000, rbd = -10000;
        for(int i = 0; i < n; ++i)
        {
            int x1, x2, y1, y2;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            lbd = min(lbd, x1);
            rbd = max(rbd, x2);
            l[ll++] = line(x1, x2, y1, 1);
            l[ll++] = line(x1, x2, y2, -1);
        }
        sort(l, l+ll);
        int ret = 0, pre = 0;
        for(int i = 0; i < ll; ++i)
        {
            if(l[i].x < l[i].y)
                update(l[i].x, l[i].y-1, l[i].c, lbd, rbd-1, 1);
            ret += seg_cnt[1] * (l[i+1].h - l[i].h) * 2;
            ret += abs(len[1] - pre);
            pre = len[1];
        }
        printf("%d\n", ret);
    }
    return 0;
}
