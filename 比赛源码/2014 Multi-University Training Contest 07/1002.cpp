#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <queue>
#include <map>
#include <set>

using namespace std;

#define eps 1e-20
#define mo 1000000009
#define inf 100

const int MAXN = 21;

double A[MAXN][MAXN];
double X[MAXN];
bool free_x[MAXN];

inline int sgn(double a, double b) {
    if(fabs(a - b) < eps) return 0;
    else if(a + eps < b) return -1;
    else return 1;
}

int Gauss(int equ, int var) {
    int k, col = 0, max_r;
    double tb;
    for(int i = 0; i <= var; i++) {
        X[i] = 0; free_x[i] = 1;
    }
    for(k = 0; k < equ && col < var; k++, col++) {
        max_r = k;
        for(int i = k + 1; i < equ; i++) {
            if(fabs(A[i][col]) > fabs(A[max_r][col])) max_r = i;
        }
        if(max_r != k) for(int j = k; j <= var; j++) swap(A[k][j], A[max_r][j]);
        if(sgn(A[k][col], 0) == 0) {
            k--; continue;
        }
        for(int i = k + 1; i < equ; i++) {
            if(sgn(A[i][col], 0) != 0) {
                tb = A[i][col] / A[k][col];
                for(int j = col; j <= var; j++) {
                    A[i][j] -= A[k][j] * tb;
                }
            }
        }
    }
    for(int i = k - 1; i >= 0; i--) {
            double temp = A[i][var];
            for(int j = i + 1; j < var; j++) {
                if(sgn(A[i][j], 0) != 0) temp -= X[j] * A[i][j];
            }
            X[i] = temp / A[i][i];
    }
}



struct state {
    int o;
    int num[21];
    void order() {
        sort(num + 1, num + 1 + o);
    }
    bool operator == (const state & a) const {
        if(a.o != o) return 0;
        for(int i = 1; i <= o; i++) {
            if(a.num[i] != num[i]) return 0;
        }
        return 1;
    }
}tmp, temp;

state g[10000];
vector < state > type[22];

int get_hash(state a) {
    int x = 1;
    for(int i = 1; i <= a.o; i++) {
        x = (a.num[i] * i * 10007 + i * 1379 + a.num[i] * a.o) % 10000;
    }
    while(g[x].o != 0 && !(g[x] == a)) {x = (x + 1) % 10000;}
    g[x] = a;
    return x;
}

int n;
double p[22];
double dp[22][10011];

vector <int> to[22];
map <int, int> can;
map <int, int>::iterator it;

void dfs(int a, int b, int c) {
    if(b == n) {
        type[c].push_back(tmp);
        return ;
    }
    for(int i = a; i <= n; i++) {
        if(b + i <= n) {
            tmp.num[++tmp.o] = i;
            dfs(i, b + i, c + 1);
            tmp.o--;
        }
    }
}

void init() {
    for(int i = 0; i < 22; i++) {
        type[i].clear();
    }
    for(int i = 0; i < 10000; i++) {
        g[i].o = 0;
    }
    tmp.o = 0;
    for(int i = 1; i < 22; i++) {
        to[i].clear();
    }
    memset(dp,0,sizeof(dp));
}

int T;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int cas = 1;
    scanf("%d", &T);
    while(T--) {
        init();

        scanf("%d", &n);

        dfs(1, 0, 0);

        for(int i = 1; i <= n; i++) {
            scanf("%lf", &p[i]);
        }

        for(int i = 1, a; i <= n; i++) {
            scanf("%d", &a);
            for(int j = 1, b; j <= a; j++) {
                scanf("%d", &b);
                to[i].push_back(b);
            }
        }

        int total = n * (n - 1) / 2;

        tmp.o = 1;
        tmp.num[1] = n;
        int xx = get_hash(tmp);
        int sum = 0;
        for(int i = 2; i <= n; i++) {
            for(int j = 0; j < type[i].size(); j++) {

                can.clear();
                tmp = type[i][j];
                xx = get_hash(tmp);
                sum = 0;

                for(int u = 1; u <= tmp.o; u++) {
                    sum += tmp.num[u] * (tmp.num[u] - 1) / 2;
                }
                for(int u = 1; u <= tmp.o; u++) {
                    for(int k = u + 1; k <= tmp.o; k++) {
                        temp = tmp;
                        int te = tmp.num[u] * tmp.num[k];
                        temp.num[k] = temp.num[u] + temp.num[k];
                        temp.num[u] = inf;
                        temp.order();
                        temp.num[temp.o] = 0;
                        temp.o--;
                        int xx = get_hash(temp);
                        can[xx] += te;
                    }
                }

                memset(A,0,sizeof(A));
                memset(free_x,0,sizeof(free_x));

                double lr;

                for(int u = 1; u <= n; u++) {
                    lr = 0;
                    for(it = can.begin(); it != can.end(); ++it) {
                        int to_x = it->first; int way = it->second;
                        int nu = to[u].size();
                        for(int k = 0; k < nu; k++) {
                            int v = to[u][k];
                            lr += way * p[u] * (dp[v][to_x] + 1) / (nu * total);
                        }
                    }

                    int nu = to[u].size();

                    for(int k = 0; k < nu; k++) {
                        int v = to[u][k];
                        A[u - 1][v - 1] -= ((1 - p[u]) + p[u] * sum / total) / nu;
                    }

                    A[u - 1][n] += lr + (1 - p[u]) + p[u] * sum / total;
                    A[u - 1][u - 1] += 1;
                }

                Gauss(n, n);

                for(int i = 0; i < n; i++) {
                    dp[i + 1][xx] = X[i];
                }
            }
        }

        tmp.o = n;

        for(int i = 1; i <= n; i++) {
            tmp.num[i] = 1;
        }

        int yy = get_hash(tmp);

        printf("Case #%d: %.6f\n", cas++, dp[1][yy]);
    }
    return 0;
}
