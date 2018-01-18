#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

const int N = 100000;
const int MOD = (int)1e9 + 7;

int power(int a, int n)
{
    if (n < 0) {
        return 0;
    }
    int result = 1;
    for (; n; n >>= 1) {
        if (n & 1) {
            result = (long long)result * a % MOD;
        }
        a = (long long)a * a % MOD;
    }
    return result;
}

int n, a[N], b[N], order[N];

void uniquify(std::vector <int> &value)
{
    std::sort(value.begin(), value.end());
    value.erase(std::unique(value.begin(), value.end()), value.end());
}

int product[N + 1 << 1], sum[N + 1 << 1];

int get_index(int l, int r)
{
    return l + r | l != r;
}

void build(int l, int r)
{
    int i = get_index(l, r);
    product[i] = 1;
    if (l < r) {
        int m = l + r >> 1;
        build(l, m);
        build(m + 1, r);
        sum[i] = (sum[get_index(l, m)] + sum[get_index(m + 1, r)]) % MOD;
    }
}

void multiply(int l, int r, int a, int c)
{
    if (a <= r) {
        int i = get_index(l, r);
        if (a <= l) {
            sum[i] = (long long)sum[i] * c % MOD;
            product[i] = (long long)product[i] * c % MOD;
        } else {
            int m = l + r >> 1;
            multiply(l, m, a, c);
            multiply(m + 1, r, a, c);
            sum[i] = (long long)(sum[get_index(l, m)] + sum[get_index(m + 1, r)]) * product[i] % MOD;
        }
    }
}

bool by_a(int i, int j)
{
    return a[i] < a[j];
}

int main()
{
    while (scanf("%d", &n) == 1) {
        std::vector <int> a_value(n + 1), b_value(n + 1);
        for (int i = 0; i < n; ++ i) {
            scanf("%d%d", a + i, b + i);
            a_value[i] = a[i];
            b_value[i] = b[i];
        }
        a_value[n] = b_value[n] = -1;
        uniquify(a_value);
        uniquify(b_value);
        int m = b_value.size();
        for (int i = 0; i < m; ++ i) {
            int result = power(3, b_value[i]);
            if (i + 1 < m) {
                (result += MOD - power(3, b_value[i + 1])) %= MOD;
            }
            sum[get_index(i, i)] = result;
        }
        build(0, m - 1);
        for (int i = 0; i < n; ++ i) {
            order[i] = i;
        }
        std::sort(order, order + n, by_a);
        int result = 0;
        for (int i = 0, j = 0; i < (int)a_value.size(); ++ i) {
            while (j < n && a_value[i] == a[order[j]]) {
                multiply(0, m - 1, (int)(std::lower_bound(b_value.begin(), b_value.end(), b[order[j ++]]) - b_value.begin()), 2);
            }
            int scale = power(2, a_value[i]);
            if (i + 1 < (int)a_value.size()) {
                (scale += MOD - power(2, a_value[i + 1])) %= MOD;
            }
            (result += (long long)scale * sum[get_index(0, m - 1)] % MOD) %= MOD;
        }
        printf("%d\n", result);
    }
    return 0;
}
