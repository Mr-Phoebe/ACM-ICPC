#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n;
        double p;
        scanf("%d%lf", &n, &p);
        double ans = 0, sum = 0, prod = 1, ans2 = 0;
        for(int i = 0; i < n; ++i)
            ans2 += (prod *= p) * (n - i);
        while(n--)
            ans += (sum = (sum*p + p));
        printf("%.6f\n", ans);
        printf("%.6f\n", ans2);
    }
    return 0;
}
