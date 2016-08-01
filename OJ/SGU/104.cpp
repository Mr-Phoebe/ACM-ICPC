#include <bits/stdc++.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
#define rep(i,initial_n,end_n) for(int (i)=(initial_n);(i)<(end_n);i++)
#define repp(i,initial_n,end_n) for(int (i)=(initial_n);(i)<=(end_n);(i)++)
#define reep(i,initial_n,end_n) for((i)=(initial_n);(i)<(end_n);i++)
#define reepp(i,initial_n,end_n) for((i)=(initial_n);(i)<=(end_n);(i)++)
#define eps 1.0e-9
#define MAX_N 500

using namespace std;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef long long ll;
typedef unsigned long long ull;

int dp[110][110] = { { 0 } }, n, m, martix[110][110];
vector<int> ans[110][110];

int main()
{
    scanf("%d%d", &n, &m);
    repp(i, 1, n) repp(j, 1, m) scanf("%d", &martix[i][j]);
    repp(i, 1, n)
    {
        dp[i][i-1] = INT_MIN;
        repp(j, i, m)
        {
            if(dp[i-1][j-1] + martix[i][j] > dp[i][j-1])
            {
                dp[i][j] = dp[i-1][j-1] + martix[i][j];
                ans[i][j] = ans[i-1][j-1];
                ans[i][j].push_back(j);
            }
            else
                dp[i][j] = dp[i][j-1], ans[i][j] = ans[i][j-1];
        }
    }
    printf("%d\n", dp[n][m]);
    rep(i, 0, n) printf("%d%c", ans[n][m][i], i == n - 1 ? '\n' : ' ');
    return 0;
}
