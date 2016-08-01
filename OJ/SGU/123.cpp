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
    int tmp[3], n, sum = 2;
    scanf("%d", &n);
    if(n == 1)
    {
        puts("1");
        exit(0);
    }
    if(n == 2)
    {
        puts("2");
        exit(0);
    }
    tmp[0] = tmp[1] = 1;
    rep(i, 2, n)
    {
        tmp[i%3] = tmp[(i+2)%3]+tmp[(i+1)%3];
        sum+=tmp[i%3];
    }
    printf("%d\n", sum);
    return 0;
}
