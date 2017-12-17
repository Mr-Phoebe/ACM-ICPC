#include <bits/stdc++.h>
using LL = long long ;
#define ALL(v) (v).begin(),(v).end()
#define showtime fprintf(stderr,"time = %.15f\n",clock() / (double)CLOCKS_PER_SEC)

const double Inf = 1e12;
const int N = 2000 + 1;
const int D = 15 + 1;
double dp[N][D];
bool vis[N][D];

double calc(int K,int W) {
    if (K == 0) {
        return 0.;
    }
    if (W == 0) {
        return Inf;
    }
    if (W == 1) {
        //return (double)((1 + K + 1) * (K + 1) / 2 - 1) / (K + 1);
    }
    if (vis[K][W]) {
        return dp[K][W];
    }
    double ret = Inf;
    for (int i = 1; i <= K; ++ i) {
        ret = std::min(ret,calc(i - 1,W - 1) * i / (K + 1) + calc(K - i,W) * (K + 1 - i) / (K + 1) + 1);
    }
    vis[K][W] = true;
    dp[K][W] = ret;
    return ret;
}

int main() {
    int K,W;
    while (scanf("%d%d",&K,&W) == 2) {
        printf("%.6f\n",calc(K,std::min(15,W)));
    }
    showtime;
}
