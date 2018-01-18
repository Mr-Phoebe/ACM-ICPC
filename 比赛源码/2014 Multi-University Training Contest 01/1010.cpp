#include <cstdio>
#include <cassert>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>

//#define READ_FROM_FILE 1

const int N = 210;

int n;
std::map<std::pair<int, int>, int> S;
double p, a[N][N], b[N];

#define FOREACH(i, v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)

void dfs(int x, int y) {
    if(x != 20 && !S.count(std::make_pair(x, y))) {
        S[std::make_pair(x, y)] = n++;
        dfs(std::max(x, std::min(y + 1, 20)), std::min(x, std::min(y + 1, 20)));
        dfs(x, std::max(y - 2, 0));
    }
}

int at(int x, int y) {
    int s = std::max(x, y);
    int t = std::min(x, y);
    if(s == 20) {
        return -1;
    }
    return S[std::make_pair(s, t)];
}

const int MAXN = 210;
const double EPS = 1e-10;

int r[MAXN], c[MAXN];

void LU(int n, double a[MAXN][MAXN], int r[MAXN], int c[MAXN]) {
    for (int i = 0; i < n; ++i) {
        r[i] = c[i] = i;
    }
    for (int k = 0; k < n; ++k) {
        int ii = k, jj = k;
        for (int i = k; i < n; ++i) {
            for (int j = k; j < n; ++j) {
                if (fabs(a[i][j]) > fabs(a[ii][jj])) {
                    ii = i;
                    jj = j;
                }
            }
        }
        std::swap(r[k], r[ii]);
        std::swap(c[k], c[jj]);
        for (int i = 0; i < n; ++i) {
            std::swap(a[i][k], a[i][jj]);
        }
        for (int j = 0; j < n; ++j) {
            std::swap(a[k][j], a[ii][j]);
        }
        if (fabs(a[k][k]) < EPS) {
            continue;
        }
        for (int i = k + 1; i < n; ++i) {
            a[i][k] = a[i][k] / a[k][k];
            for (int j = k + 1; j < n; ++j) {
                a[i][j] -= a[i][k] * a[k][j];
            }
        }
    }
}

void solve(int n, double a[MAXN][MAXN], int r[MAXN], int c[MAXN], double b[MAXN]) {
    static double x[MAXN];
    for (int i = 0; i < n; ++i) {
        x[i] = b[r[i]];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            x[i] -= a[i][j] * x[j];
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = n - 1; j > i; --j) {
            x[i] -= a[i][j] * x[j];
        }
        if (fabs(a[i][i]) >= EPS) {
            x[i] /= a[i][i];
        }  else assert(fabs(x[i]) < EPS);
    }
    for (int i = 0; i < n; ++i) {
        b[c[i]] = x[i];
    }
}

int main() {
#ifdef READ_FROM_FILE
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);
#endif
    n = 0;
    dfs(0, 0);
    while(scanf("%lf", &p) == 1) {
        assert(0.3 <= p && p <= 1.0);
        memset(a, 0, sizeof(a));
        FOREACH(iter, S) {
            int x = (iter->first).first;
            int y = (iter->first).second;
            int from = iter->second;
            int to = at(x, std::min(y + 1, 20));
            if(to != -1) {
                a[from][to] = p;
            }
            to = at(x, std::max(y - 2, 0));
            if(to != -1) {
                a[from][to] = (1 - p);
            }
            b[from] = -1;
        }
        for(int i = 0; i < n; ++i) {
            a[i][i] -= 1;
        }
        LU(n, a, r, c);
        solve(n, a, r, c, b);
        printf("%lf\n", b[0]);
    }
    return 0;
}
