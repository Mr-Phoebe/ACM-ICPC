#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <climits>

const int N = 1000000;

char buffer[N + 1];
int down[N + 1], up[N + 1];

int main()
{
    while (scanf("%s", buffer) == 1) {
        int n = strlen(buffer);
        down[n] = up[n] = 0;
        bool none = false;
        for (int i = n - 1; i >= 0 && !none; -- i) {
            down[i] = INT_MAX;
            up[i]   = INT_MIN;
            if (buffer[i] != ')') {
                down[i] = std::min(down[i], down[i + 1] - 1);
                up[i]   = std::max(up[i],   up[i + 1]   - 1);
            }
            if (buffer[i] != '(') {
                down[i] = std::min(down[i], down[i + 1] + 1);
                up[i]   = std::max(up[i],   up[i + 1]   + 1);
            }
            while (down[i] < 0) {
                down[i] += 2;
            }
            if (up[i] < 0) {
                none = true;
            }
        }
        if (none || down[0]) {
            puts("None");
        } else {
            int delta = 0;
            bool unique = true;
            for (int i = 0; i < n && unique; ++ i) {
                char type = buffer[i];
                if (type == '?') {
                    int mask = 0;
                    if (down[i + 1] <= delta + 1 && delta + 1 <= up[i + 1]) {
                        mask |= 1;
                    }
                    if (delta && down[i + 1] <= delta - 1 && delta - 1 <= up[i + 1]) {
                        mask |= 2;
                    }
                    assert(mask != 0);
                    if (mask == 1) {
                        type = '(';
                    } else if (mask == 2) {
                        type = ')';
                    } else {
                        unique = false;
                    }
                }
                delta += type == '(' ? +1 : -1;
            }
            puts(unique ? "Unique" : "Many");
        }
    }
    return 0;
}
