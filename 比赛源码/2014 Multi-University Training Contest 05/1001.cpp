#include <algorithm>
#include <cstdio>
#include <cstring> 
#include <vector>
#include <iostream>

const int N = 100000;

int n, m, a[N], count[N];

int main()
{
    while (scanf("%d%d", &n, &m) == 2) {
        std::vector <int> value;
        for (int i = 0; i < n; ++ i) {
            scanf("%d", a + i);
            value.push_back(a[i]);
        }
        std::sort(value.begin(), value.end());
        value.erase(std::unique(value.begin(), value.end()), value.end());
        for (int i = 0; i < n; ++ i) {
            a[i] = std::lower_bound(value.begin(), value.end(), a[i]) - value.begin();
        }
        memset(count, 0, sizeof(count));
        long long result = 0;
        for (int i = 0; i < n; ++ i) {
            for (int j = a[i] + 1; j < n; j += ~j & j + 1) {
                result += count[j];
            }
            for (int j = a[i]; j >= 0; j -= ~j & j + 1) {
                count[j] ++;
            }
        }
        std::cout << std::max(result - m, 0LL) << std::endl;
    }
    return 0;
}
