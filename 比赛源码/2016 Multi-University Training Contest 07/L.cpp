#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 500010;
int n;
vector<int> p[50010];
struct sgt {
    int s;
    sgt *l, *r;
}*T[50010], pool[MAXN * 16];
int psz;
int x[50010];

sgt *newnode(int s)
{
    sgt *t = pool + psz++;
    t->s = s, t->l = 0, t->r = 0;
    return t;
}

sgt *newnode(sgt *l, sgt *r)
{
    sgt *t = pool + psz++;
    t->s = l->s + r->s, t->l = l, t->r = r;
    return t;
}

sgt *build(int l, int r)
{
    int mid = (l + r) / 2;
    if (l == r) return newnode(0);
    else return newnode(build(l, mid), build(mid + 1, r));
}

sgt *add(sgt *t, int l, int r, int x)
{
    int mid = (l + r) / 2;
    if (l == r) return newnode(t->s + 1);
    else if (x <= mid) return newnode(add(t->l, l, mid, x), t->r);
    else return newnode(t->l, add(t->r, mid + 1, r, x));
}

int query(sgt *a, sgt *b, int l, int r, int s, int t)
{
    int mid = (l + r) / 2;
    if (l == s && r == t) return a->s - b->s;
    else if (t <= mid) return query(a->l, b->l, l, mid, s, t);
    else if (s > mid) return query(a->r, b->r, mid + 1, r, s, t);
    else return query(a->l, b->l, l, mid, s, mid)
              + query(a->r, b->r, mid + 1, r, mid + 1, t);
}

void init()
{
    for (int i = 1; i <= 50000; ++i) p[i].clear();
    while (n--) {
        int x, y;
        scanf("%d%d", &x, &y);
        p[x].push_back(y);
    }
    for (int i = 1; i <= 50000; ++i) {
        sort(p[i].begin(), p[i].end());
        p[i].erase(unique(p[i].begin(), p[i].end()), p[i].end());
    }
}

bool solve()
{
    psz = 0;
    T[0] = build(1, 50000);
    memset(x, 0, sizeof(x));
    for (int i = 1; i <= 50000; ++i) {
        T[i] = T[i - 1];
        for (int j = 0; j < p[i].size(); ++j) {
            int l = j == 0 ? 0 : p[i][j - 1];
            int r = j == p[i].size() - 1 ? 50001 : p[i][j + 1];
            if (query(T[i], T[x[p[i][j]]], 1, 50000, l + 1, r - 1)) {
                return false;
            }
        }
        for (int j = 0; j < p[i].size(); ++j) {
            T[i] = add(T[i], 1, 50000, p[i][j]);
            x[p[i][j]] = i;
        }
    }
    return true;
}

int main()
{
    while (scanf("%d", &n), n > 0) {
        init();
        puts(solve() ? "YES" : "NO");
    }
}                                 
