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
typedef long long ll;
typedef unsigned long long ull;

int fastpow(int a, int b, int k)
{
    if(b == 0) return 1%k;
    int tmp = fastpow(a, b>>1, k);
    tmp = tmp*tmp%k;
    if(b&1) tmp = (ll) tmp*a%k;
    return tmp;
}

int main()
{
    int n, m, mod, cnt = 0, tmp;
    scanf("%d%d%d", &n, &m, &mod);
    while(n--)
    {
        scanf("%d", &tmp);
        if(!fastpow(tmp, m, mod)) cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
