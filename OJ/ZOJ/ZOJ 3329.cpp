#include <bits/stdc++.h>

using namespace std;

double aa[550], bb[550], p[20];

int main()
{
    int nn;
    scanf("%d", &nn);
    while(nn--)
    {
        int n, k1, k2, k3, a, b, c;
        scanf("%d%d%d%d%d%d%d", &n, &k1, &k2, &k3, &a, &b, &c);
        memset(p, 0, sizeof p);
        memset(aa, 0, sizeof aa);
        memset(bb, 0, sizeof bb);
        for(int i = 1; i <= k1; ++i)
            for(int j = 1; j <= k2; ++j)
                for(int k = 1; k <= k3; ++k)
                    if(i != a || j != b || k != c)
                        p[i+j+k] += 1.0 / (k1*k2*k3);
        for(int i = n; i >= 0; --i)
        {
            for(int j = 3; j <= k1+k2+k3; ++j)
                aa[i] += p[j]*aa[i+j], bb[i] += p[j]*bb[i+j];
            aa[i] += 1.0/(k1*k2*k3);
            bb[i] += 1;
        }
        printf("%.17f\n", bb[0] / (1 - aa[0]));
    }
    return 0;
}
