#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 200005;

int np, pri[maxn], vis[maxn];
void prime_table(int n) {
    np = 0;
    for (int i = 2; i <= n; i++) {
        if (vis[i]) continue;
        pri[np++] = i;

        for (int j = i * 2; j <= n; j += i)
            vis[j] = 1;
    }
    vis[1] = 1;
}

#define lowbit(x) ((x)&(-x))

struct Seg {
    int l, r, id;
    Seg (int l = 0, int r = 0, int id = 0) {
        this->l = l;
        this->r = r;
        this->id = id;
    }
    friend bool operator < (const Seg& a, const Seg& b) {
        return a.r < b.r;
    }
};

int N, M, L[maxn], P[maxn];
int fenw[maxn], ans[maxn];
vector<int> g[maxn];
vector<Seg> vec, que;

inline void add (int x, int d) {
    if (x <= 0)
        return;
    while (x <= N) {
        fenw[x] += d;
        x += lowbit(x);
    }
}

inline int sum (int x) {
    int ret = 0;
    while (x) {
        ret += fenw[x];
        x -= lowbit(x);
    }
    return ret;
}

void init () {
    vec.clear();
    que.clear();

    int x;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &x);
        g[i].clear();
        for (int j = 0; j < np; j++) {
            if (x % pri[j] == 0) {
                g[i].push_back(pri[j]);
                while (x % pri[j] == 0)
                    x /= pri[j];
            }

            if (vis[x] == 0) {
                g[i].push_back(x);
                break;
            }
        }
    }

    for (int i = 0; i < maxn; i++) P[i] = 0;
    for (int i = 1; i <= N; i++) {
        int tmp = 0;
        for (int j = 0; j < g[i].size(); j++) {
            tmp = max(tmp, P[g[i][j]]);
            P[g[i][j]] = i;
        }
        L[i] = tmp;
        vec.push_back(Seg(tmp, i, 0));
    }

    for (int i = 0; i < maxn; i++) P[i] = N + 1;
    for (int i = N; i; i--) {
        int tmp = N + 1;
        for (int j = 0; j < g[i].size(); j++) {
            tmp = min(tmp, P[g[i][j]]);
            P[g[i][j]] = i;
        }
        vec.push_back(Seg(i, tmp, 1));
    }

    int l, r;
    for (int i = 1; i <= M; i++) {
        scanf("%d%d", &l, &r);
        que.push_back(Seg(l, r, i));
    }
}

void solve () {
    sort(que.begin(), que.end());
    sort(vec.begin(), vec.end());
    memset(fenw, 0, sizeof(fenw));

    int mv = 0;
    for (int i = 0; i < que.size(); i++) {
        while (mv < vec.size() && vec[mv].r <= que[i].r) {
            add(vec[mv].l, 1);
            if (vec[mv].id)
                add(L[vec[mv].l], -1);
            mv++;
        }
        int tmp = sum(que[i].r) - sum(que[i].l - 1);
        ans[que[i].id] = que[i].r - que[i].l + 1 - tmp;
    }
}

int main () {
    freopen("data.txt","r",stdin);
    freopen("out2.txt","w",stdout);
    prime_table(maxn);
    while (scanf("%d%d", &N, &M) == 2 && N + M) {
        init();
        solve();
        for (int i = 1; i <= M; i++)
            printf("%d\n", ans[i]);
    }
    return 0;
}
