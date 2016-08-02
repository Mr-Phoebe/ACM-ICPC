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

int a[5][5], b[5][5], n, d[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };

void dfs(int i, int j);
bool check(int i, int j);

int main()
{
    scanf("%d", &n);
    repp(i, 1, n) repp(j, 1, n) scanf("%d", &b[i][j]);
    dfs(1,1);
    puts("NO SOLUTION");
    return 0;
}

void dfs(int i, int j)
{
    if(j == n + 1) i++, j=1;
    if(i == n + 1)
    {
        repp(ii, 1, n) if(!check(n, ii)) return ;
        repp(ii, 1, n) repp(jj, 1, n)
        printf("%d%c", a[ii][jj], jj == n ? '\n' : ' ');
        exit(0);
    }
    rep(ii, 0, 10)
    {
        a[i][j] = ii;
        if(!(i-1) || check(i-1, j)) dfs(i, j+1);
    }
}

bool check(int i, int j)
{
    int ans = 0;
    rep(ii, 0, 4)
    if(a[i][j] < a[i+d[ii][0]][j+d[ii][1]]) ans++;
    return ans == b[i][j];
}
