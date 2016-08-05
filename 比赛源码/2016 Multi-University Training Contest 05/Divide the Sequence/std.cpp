#include <bits/stdc++.h>
using LL = long long ;
#define ALL(v) (v).begin(),(v).end()
#define showtime printf("time = %.15f\n",clock() / (double)CLOCKS_PER_SEC)

const int N = 1000000 + 5;
int n;
int A[N];

int work() {
    int ret = 0;
    for (int i = n - 1,j = i; i >= 0; i = j) {
        LL sum = A[i];
        for (j = i - 1; j >= 0 && sum < 0; sum += A[j--]);
        assert(sum >= 0);
        ret ++;
    }
    return ret;
}

int main() {
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    while (scanf("%d",&n) == 1) {
        assert(1 <= n && n <= 1000000);
        for (int i = 0; i < n; ++ i) {
            scanf("%d",A + i);
            assert(std::abs(A[i]) <= 10000);
        }
        printf("%d\n",work());
    }
}
