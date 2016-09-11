#include <iostream>
#include <cstdio>

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
#define rep(i,initial_n,end_n) for(int (i)=(initial_n);(i)<(end_n);i++)
#define repp(i,initial_n,end_n) for(int (i)=(initial_n);(i)<=(end_n);(i)++)
#define reep(i,initial_n,end_n) for((i)=(initial_n);(i)<(end_n);i++)
#define reepp(i,initial_n,end_n) for((i)=(initial_n);(i)<=(end_n);(i)++)
#define eps 1.0e-9
#define MAX_N 1010

using namespace std;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef __int64 ll;
typedef unsigned __int64 ull;

int main() {
    int time[50010] = { 0 }, m, n, cost[50010][5];
    scanf("%d%d", &m, &n);
    rep(i, 0, m) {
        rep(j, 0, n) {
            scanf("%d", &cost[i][j]);
        }
    }
    rep(i, 0, n) {
        rep(j, 0, m) {
            if(j != 0 && time[j - 1] > time[j]) time[j] = time[j - 1] + cost[j][i];
            else time[j] += cost[j][i];
        }
    }
    rep(i, 0, m) printf("%d%c", time[i], i == m-1 ? '\n' : ' ');
    return 0;
}