#include <bits/stdc++.h>
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

int deg[7] = { 0 }, ans[101][2], domino[101][2], anslen = 0, edge[7][7];
bool used[101] = { false };

void dfs(int now);

int main()
{
    int n;
    scanf("%d", &n);
    rep(i, 0, n)
    {
        scanf("%d%d", &domino[i][0], &domino[i][1]);
        deg[domino[i][0]]++, deg[domino[i][1]]++;
        edge[domino[i][0]][domino[i][1]]++, edge[domino[i][1]][domino[i][0]]++;
    }
    int odd = 0, mark;
    repp(i, 0, 6) if(deg[i]%2 != 0) mark = i, odd++;
    if(!odd) repp(i, 0, 6) if(deg[i])
        {
            mark = i;
            break;
        }
    if(odd != 0 && odd != 2)
    {
        puts("No solution");
        exit(0);
    }
    dfs(mark);
    if(anslen < n)
    {
        puts("No solution");
        exit(0);
    }
    for(int i = n - 1; i >= 0; i--)
    {
        rep(j, 0, n)
        {
            if(ans[i][0] == domino[j][0] && ans[i][1] == domino[j][1] && !used[j])
            {
                printf("%d +\n", j+1);
                used[j] = true;
                break;
            }
            else if(ans[i][0] == domino[j][1] && ans[i][1] == domino[j][0] && !used[j])
            {
                printf("%d -\n", j+1);
                used[j] = true;
                break;
            }
        }
    }
    return 0;
}

void dfs(int now)
{
    repp(i, 0, 6)
    {
        if(edge[now][i])
        {
            edge[now][i]--, edge[i][now]--;
            dfs(i);
            ans[anslen][0] = now;
            ans[anslen++][1] = i;
        }
    }
}
