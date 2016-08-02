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

int gcd(int n, int m)
{
    return m == 0 ? n : gcd(m, n%m);
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    if(n < m) swap(n, m);
    if(!m)
    {
        puts("0");
        exit(0);
    }
    int sum = (n+m) / gcd(n, m);
    int ans = 0;
    while(!(sum&1))
        sum/=2, ans++;
    if(sum == 1) printf("%d\n", ans);
    else puts("-1");
    return 0;
}
