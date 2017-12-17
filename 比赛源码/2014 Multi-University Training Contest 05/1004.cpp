#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <complex>
#include <vector>

typedef std::complex <double> Complex;

const double PI = acos(-1.);

void FFT(Complex* P, int n, int oper)
{
    for (int i = 1, j = 0; i < n - 1; i++) {
        for (int s = n; j ^= s >>= 1, ~j & s;);
        if (i < j) {
            std::swap(P[i], P[j]);
        }
    }
    Complex unit_p0;
    for (int d = 0; (1 << d) < n; d++) {
        int m = 1 << d, m2 = m * 2;
        double p0 = PI / m * oper;
        unit_p0 = Complex(cos(p0), sin(p0));
        for (int i = 0; i < n; i += m2) {
            Complex unit = 1;
            for (int j = 0; j < m; j++) {
                Complex &P1 = P[i + j + m], &P2 = P[i + j];
                Complex t = unit * P1;
                P1 = P2 - t;
                P2 = P2 + t;
                unit = unit * unit_p0;
            }
        }
    }
}

typedef std::vector <int> Polynomial;

const int N   = 1 << 16;
const int MOD = 119;

Complex A[N], B[N];
int n, a, b, p, q;

void add(int &x, int a)
{
    x += a;
    if (x >= MOD) {
        x -= MOD;
    }
}

Polynomial operator * (const Polynomial &u, const Polynomial &v)
{
    int n = 1;
    while (n <= q + q - 2) {
        n <<= 1;
    }
    for (int i = 0; i < n; ++ i) {
        A[i] = i < q ? u[i] : 0;
    }
    FFT(A, n, 1);
    for (int i = 0; i < n; ++ i) {
        B[i] = i < q ? v[i] : 0;
    }
    FFT(B, n, 1);
    for (int i = 0; i < n; ++ i) {
        A[i] *= B[i];
    }
    FFT(A, n, -1);
    Polynomial w(q + q - 1);
    for (int i = 0; i < (int)w.size(); ++ i) {
        w[i] = ((int)(A[i].real() / n + 0.5)) % MOD;
    }
    for (int i = (int)w.size() - 1; i >= q; -- i) {
        add(w[i - p], (long long)a * w[i] % MOD);
        add(w[i - q], (long long)b * w[i] % MOD);
    }
    w.resize(q);
    return w;
}

int main()
{
    while (scanf("%d%d%d%d%d", &n, &a, &b, &p, &q) == 5) {
        n += q - 1;
        a %= MOD;
        b %= MOD;
        Polynomial product(q);
        product[0] = 1;
        Polynomial base(q);
        base[1] = 1;
        for (; n; n >>= 1) {
            if (n & 1) {
                product = product * base;
            }
            base = base * base;
        }
        int result = 0;
        for (int i = 0; i < q; ++ i) {
            add(result, product[i]);
        }
        printf("%d\n", result);
    }
    return 0;
}

