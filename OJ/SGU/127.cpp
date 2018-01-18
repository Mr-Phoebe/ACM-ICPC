#include <bits/stdc++.h>
#define max(a,b) ((a)>(b))?(a):(b)
#define min(a,b) ((a)>(b))?(b):(a)
#define rep(i,initial_n,end_n) for(int (i)=(initial_n);(i)<(end_n);i++)
#define repp(i,initial_n,end_n) for(int (i)=(initial_n);(i)<=(end_n);(i)++)
#define eps 1.0E-8
#define MAX_N 1010
using namespace std;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    int n, d, a[10] = { 0 };
    char str[5];
    scanf("%d%d", &d, &n);
    rep(i, 0, n)
    {
        scanf("%s", str);
        a[str[0]-'0']++;
    }
    int ans = 2;
    rep(i, 0, 10) ans += (a[i]+d-1) / d;
    printf("%d\n", ans);
}
