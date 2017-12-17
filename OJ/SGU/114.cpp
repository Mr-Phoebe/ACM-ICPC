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

pii a[15010];

int main()
{
    int n;
    scanf("%d", &n);
    int minn = INT_MAX, maxx = INT_MIN;
    rep(i, 0, n)
    {
        scanf("%d%d", &a[i].first, &a[i].second);
        if(minn > a[i].first) minn = a[i].first;
        if(maxx < a[i].first) maxx = a[i].first;
    }
    double b = minn, e = maxx, m = (b+e)/2, mm = (m+e)/2, ans;
    while(b - e < -eps)
    {
        double tmp = 0, tmpp = 0;
        rep(i, 0, n)
        {
            tmp += fabs(a[i].first - m) * 1.0 * a[i].second, tmpp += fabs(a[i].first - mm) * 1.0 * a[i].second;
        }
        if(tmp - tmpp < -eps) e = mm, ans = tmp;
        else b = m, ans = tmpp;
        m = (b+e)/2, mm = (m+e)/2;
    }
    printf("%f\n", m);
    return 0;
}
