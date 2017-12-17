#include <bits/stdc++.h>
#define max(a,b) ((a)>(b))?(a):(b)
#define min(a,b) ((a)>(b))?(b):(a)
#define rep(i,initial_n,end_n) for(int (i)=(initial_n);(i)<(end_n);i++)
#define repp(i,initial_n,end_n) for(int (i)=(initial_n);(i)<=(end_n);(i)++)
#define eps 1.0E-8
#define MAX_N 1010
#define INF 1 << 30
using namespace std;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    int day, month, year = 2001, monthday[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    scanf("%d%d", &day, &month);
    if(month > 12 || day > monthday[month])
    {
        puts("Impossible");
        exit(0);
    }
    if (month<3)
    {
        month += 12;
        year--;
    }
    int ans = (day + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400 + 1) % 7;
    printf("%d\n", ans == 0 ? 7 : ans);
    return 0;
}
