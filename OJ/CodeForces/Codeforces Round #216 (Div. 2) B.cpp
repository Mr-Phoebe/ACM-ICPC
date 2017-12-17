#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int main()
{
    int n, k, l, r, sall, sk, i;
    while (scanf("%d%d%d%d%d%d", &n, &k, &l, &r, &sall, &sk) != EOF)
    {
        vector<int> res(n,l); 
        sk -= k * l;   
        sall -= n * l + sk; 
        for (i = 0; i < k; i++)
            res[i] += sk/k; 
        for (i = 0; i < sk%k; i++) 
            res[i]++;
        if (sall)
        {
            for (i = k; i < n; i++)
                res[i] += sall / (n-k);
            for (i = k; i < k+sall%(n-k); i++)
                res[i]++;
        }
        for (i = 0; i < res.size(); i++)
            printf("%d ", res[i]);
        printf("\n");
    }
    return 0;
}