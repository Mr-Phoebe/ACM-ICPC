#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

int t, n, d[100010];

int main() {
    scanf("%d", &t);
    for (int ca = 1; ca <= t; ca ++ ) {
        scanf("%d", &n);
        d[0] = 0;
        int cnt = 0;
        bool flag = false;
        for (int i = 1; i <= n; i ++ ) {
            scanf("%d", &d[i]);
            if ((d[i] == d[i - 1] && d[i] != 1) || abs(d[i] - d[i - 1]) > 3) flag = true;
            if ((long long) d[i] * d[i - 1] == 2) cnt ++ ;
        }
        printf("Case #%d: ", ca);
        if (flag) {
            printf("0\n");
            continue;
        }
        if (d[n] == 0) printf("%d\n", cnt + 1);
        else printf("%d\n", cnt * 2 + 2);
    }
    return 0;
}
