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

struct line
{
    double x, y, h;
    int c;
    line() {}
    line(double _x, double _y, double _h, int _c): x(_x), y(_y), h(_h), c(_c) {}
    bool operator < (const line &a) const
    {
        return h < a.h;
    }
};

#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1

line l[2200];
double lisan[2200];
double sum[2100<<2];
int cnt[2100<<2];

inline void push_up(int l, int r, int rt)
{
    if(cnt[rt])
        sum[rt] = lisan[r+1] - lisan[l];
    else if(l == r)
        sum[rt] = 0;
    else
        sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}

void update(int _l, int _r, int c, int l, int r, int rt)
{
    if(_l <= l && r <= _r)
    {
        cnt[rt] += c;
        push_up(l, r, rt);
        return ;
    }
    int m = (l+r)>>1;
    if(_l <= m) update(_l, _r, c, lson);
    if(m < _r) update(_l, _r, c, rson);
    push_up(l, r, rt);
}

int main()
{
    int n, ccnt = 1;
    while(scanf("%d", &n) && n)
    {
        int len = 0;
        while(n--)
        {
            double x1, x2, y1, y2;
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            lisan[len] = x1;
            l[len++] = line(x1, x2, y1, 1);
            lisan[len] = x2;
            l[len++] = line(x1, x2, y2, -1);
        }
        sort(lisan, lisan+len);
        sort(l, l+len);
        int new_len = unique(lisan, lisan+len) - lisan;
        double ret = 0;
        memset(cnt, 0, sizeof cnt);
        memset(sum, 0, sizeof sum);
        for(int i = 0; i < len; ++i)
        {
            int ll = lower_bound(lisan, lisan+new_len, l[i].x) - lisan;
            int rr = lower_bound(lisan, lisan+new_len, l[i].y) - lisan;
            if(ll < rr)
                update(ll, rr-1, l[i].c, 0, new_len-1, 1);
            ret += sum[1] * (l[i+1].h - l[i].h);
        }
        printf("Test case #%d\nTotal explored area: %.2f\n\n",ccnt++, ret);
    }
    return 0;
}
