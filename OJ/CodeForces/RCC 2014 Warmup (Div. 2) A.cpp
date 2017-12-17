#include<iostream>
#include<cstdio>


using namespace std;
int main () {
    int c, d, n, m, k, ans = 0;
    scanf("%d%d%d%d%d", &c, &d, &n, &m, &k);
    int need = n * m - k;
    if(need <= 0) { puts("0"); return 0; }
    double r1 = (double) c / n, r2 = d * 1.0;
    if(r2 - r1 < 1e-9)
		ans = need * d;
    else
		ans = need/n * c + ((need % n) * d < c ? (need%n) *d : c);
    printf("%d\n", ans);
    return 0;
}
