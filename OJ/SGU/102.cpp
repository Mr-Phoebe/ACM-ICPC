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

int gcd(int a, int b)
{
    return b!=0 ? gcd(b, a%b) : a;
}

int main()
{
    int n;
    scanf("%d", &n);
    int ans = 1;
    rep(i, 2, n) if(gcd(n, i) == 1) ans++;
    printf("%d\n", ans);
}
