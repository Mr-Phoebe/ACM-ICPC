#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long int64;
int64 a, b, ans;

void solve(){
    int rec = 1;
    ans = a * a - b * b;
    for (int i = 2; i <= b; i++) {
        if (i - 1 > a) continue;
        int64 x = b % i, y = i - x;
        int64 cost = y * (b / i) * (b / i) + x * (b / i + 1) * (b / i + 1);
        cost = i - 2 - cost + (a - i + 2) * (a - i + 2);
        if (cost > ans) {
            rec = i;
            ans = cost;
        }
    }
    cout << ans << endl;
    if (rec == 1) {
        for (int i = 0; i < a; i++)putchar('o');
        for (int i = 0; i < b; i++)putchar('x');
        return;
    }
    int64 x = b % rec, y = rec - x;
    for (int i = 0; i < rec; i++) {
        if (i < x) {
            for (int j = 0; j < b / rec + 1; j++)putchar('x');
        }
        else {
            for (int j = 0; j < b / rec; j++)putchar('x');
        }
        if (i + 1 < rec) {
            if (i == 0) {
                for (int j = 0; j < a - rec + 2; j++)putchar('o');
            }
            else putchar('o');
        }
    }
    puts("");
}

int main(){
	while (cin >> a >> b) solve();
    return 0;
}
