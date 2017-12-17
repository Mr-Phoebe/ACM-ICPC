#include <stdio.h>
#include <algorithm>

using namespace std;

const int MAXN = 1010;
int n, m;
int a[MAXN], p[MAXN];

bool by_a(int i, int j) { return a[i] < a[j]; }

void init()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), p[i] = i;
    sort(p + 1, p + n + 1, by_a);
}

bool check()
{
    for (int i = 1; i <= n; ++i) {
        if (a[p[i]] >= i) return false;
    }
    return true;
}

void answer()
{
    m = 0;
    for (int i = 1; i <= n; ++i) m += a[i];
    printf("%d\n", m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= a[p[i]]; ++j) {
            printf("%d %d\n", p[i], p[j]);
        }
    }
}

int main()
{
    int dat;
    scanf("%d", &dat);
    for (int cas = 1; cas <= dat; ++cas) {
        init();
        printf("Case #%d: ", cas);
        if (check()) puts("Yes"), answer();
        else puts("No");
    }
}
