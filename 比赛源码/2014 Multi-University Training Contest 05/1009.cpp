#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>

const int L = 300;
const int B = 10000;

struct BigInteger {
    BigInteger(int number = 0) : length(!!number) {
        assert(0 <= number && number < B);
        memset(digit, 0, sizeof(digit));
        digit[0] = number;
    }

    BigInteger normalize() {
        while (length && !digit[length - 1]) {
            length --;
        }
        return *this;
    }

    int operator[](int index) const {
        return digit[index];
    }

    int& operator[](int index) {
        return digit[index];
    }

    int length, digit[L];
};

bool operator < (const BigInteger &a, const BigInteger &b)
{
    if (a.length != b.length) {
        return a.length < b.length;
    }
    for (int i = 0; i < a.length; ++ i) {
        if (a[i] != b[i]) {
            return a[i] < b[i];
        }
    }
    return false;
}

BigInteger operator + (const BigInteger &a, const BigInteger &b)
{
    BigInteger c;
    c.length = std::max(a.length, b.length) + 1;
    for (int i = 0, delta = 0; i < c.length; ++ i) {
        delta += a[i] + b[i];
        c[i] = delta % B;
        delta /= B;
    }
    return c.normalize();
}

BigInteger operator - (const BigInteger &a, int b)
{
    assert(0 <= b && b < B);
    BigInteger c;
    c.length = a.length;
    for (int i = 0, delta = -b; i < a.length; ++ i) {
        delta += a[i];
        c[i] = delta;
        delta = 0;
        if (c[i] < 0) {
            c[i] += B;
            delta = -1;
        }
    }
    return c.normalize();
}

BigInteger operator * (const BigInteger &a, const BigInteger &b)
{
    BigInteger c;
    c.length = a.length + b.length;
    for (int i = 0; i < a.length; ++ i) {
        for (int j = 0, delta = 0; j <= b.length; ++ j) {
            delta += a[i] * b[j] + c[i + j];
            c[i + j] = delta % B;
            delta /= B;
        }
    }
    return c.normalize();
}

BigInteger operator / (const BigInteger &a, int b)
{
    assert(0 <= b && b < B);
    BigInteger c;
    c.length = a.length;
    for (int i = c.length - 1, delta = 0; i >= 0; -- i) {
        delta = delta * B + a[i];
        c[i] = delta / b;
        delta %= b;
    }
    return c.normalize();
}

const int N = 500;

char buffer[N + 1];

std::map <BigInteger, BigInteger> memory;

BigInteger solve(const BigInteger &n)
{
    if (!memory.count(n)) {
        BigInteger &result = memory[n];
        BigInteger n2 = n / 2;
        if (n[0] % 2) {
            result = solve(n2) * 4 + n2 * 6;
        } else {
            result = solve(n2) * 2 + solve(n2 - 1) * 2 + n2 * 4 - 4;
        }
    }
    return memory[n];
}

BigInteger contribution(const BigInteger &n, const BigInteger &coefficient) {
    BigInteger result;
    if (n[0] % 2) {
        result = (n / 2) * 6;
    } else {
        result = n * 2 - 4;
    }
    return result * coefficient;
}

int main()
{
    memory[0] = memory[1] = 0;
    while (scanf("%s", buffer) == 1) {
        BigInteger n;
        int length = strlen(buffer);
        for (int i = 0; i < length; ++ i) {
            int index = (length - 1 - i) / 4;
            n.length = std::max(n.length, index + 1);
            n[index] = n[index] * 10 + buffer[i] - '0';
        }
        BigInteger result = 0;
        std::vector <BigInteger> coefficient;
        coefficient.push_back(1);
        coefficient.push_back(0);
        while (n.length) {
            result = result + contribution(n, coefficient[0]) + contribution(n + 1, coefficient[1]);
            std::vector <BigInteger> new_coefficient;
            if (n[0] % 2) {
                n = n / 2;
                new_coefficient.push_back((coefficient[0] * 4) + (coefficient[1] * 2));
                new_coefficient.push_back((coefficient[1] * 2));
            } else {
                n = (n / 2) - 1;
                new_coefficient.push_back((coefficient[0] * 2));
                new_coefficient.push_back((coefficient[0] * 2) + (coefficient[1] * 4));
            }
            coefficient = new_coefficient;
        }
        printf("%d", result[result.length - 1]);
        for (int i = result.length - 2; i >= 0; -- i) {
            printf("%04d", result[i]);
        }
        puts("");
    }
    return 0;
}
