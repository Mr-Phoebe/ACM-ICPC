#include <bits/stdc++.h>
using LL = long long ;
#define ALL(v) (v).begin(),(v).end()
#define showtime fprintf(stderr,"time = %.15f\n",clock() / (double)CLOCKS_PER_SEC)

const int N = 100000 + 5;
int n,A[N];
int ls[N],rs[N],lg[N],rg[N];
int tot;

struct Fenwick {
    int C[N];

    void clear() {
        std::fill(C,C + tot,0);
    }
    void modify(int p,int dt) {
        for (int i = p; i < tot; i += ~i & i + 1) C[i] += dt;
    }
    int query(int p) {
        int ret = 0;
        for (int i = p; i >= 0; i -= ~i & i + 1) ret += C[i];
        return ret;
    }
} bit;

LL brute() {
    LL ret = 0;
    for (int i = 0; i < n; ++ i) {
        for (int j = i + 1; j < n; ++ j) {
            if (A[i] >= A[j]) continue;
            for (int k = 0; k < n; ++ k) {
                if (k == i || k == j) continue;
                for (int r = k + 1; r < n; ++ r) {
                    if (r == i || r == j) continue;
                    if (A[k] <= A[r]) continue;
                    ret ++;
                }
            }
        }
    }
    return ret;
}

int main() {
    while (scanf("%d",&n) == 1) {
        assert(1 <= n && n <= 50000);
        for (int i = 0; i < n; ++ i) {
            scanf("%d",A + i);
            assert(0 <= A[i] && A[i] <= (int)1e9);
        }
        std::vector<int> ss(A,A + n);
        std::sort(ALL(ss));
        ss.erase(std::unique(ALL(ss)),ss.end());
        for (int i = 0; i < n; ++ i) {
            A[i] = std::lower_bound(ALL(ss),A[i]) - ss.begin();
        }
        tot = ss.size();
        bit.clear();
        for (int i = 0; i < n; ++ i) {
            ls[i] = bit.query(A[i] - 1);
            lg[i] = i - bit.query(A[i]);
            bit.modify(A[i],1);
        }
        bit.clear();
        for (int i = n - 1; i >= 0; -- i) {
            rs[i] = bit.query(A[i] - 1);
            rg[i] = n - 1 - i - bit.query(A[i]);
            bit.modify(A[i],1);
        }
        LL result = 0,allg = std::accumulate(rs,rs + n,0ll);
        for (int i = 0; i < n; ++ i) {
            result += rg[i] * 1ll * (allg - lg[i] - rs[i]) - (lg[i] + rs[i]) * 1ll * ls[i];
        }
        printf("%I64d\n",result);
        //assert(result == brute());
        //printf("brute = %I64d\n",brute());
    }
    showtime;
}
