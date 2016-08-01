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

int cal(int n)
{
    int sum = n;
    while(n) sum += n%10, n/=10;
    return sum % 64;
}

int main()
{
    int n, m = 0, a[1000000], tmp;
    bool flag[64] = { false };
    scanf("%d", &n);
    repp(i, 1, n)
    {
        if(!flag[i%64])
        {
            a[m++] = i;
        }
        flag[i%64] = false;
        flag[cal(i)] = true;
    }
    printf("%d\n", m);
    scanf("%d", &m);
    rep(i, 0, m)
    {
        scanf("%d", &n);
        printf("%d%c", a[n-1], i == m - 1 ? '\n' : ' ');
    }
    return 0;
}
