#include <bits/stdc++.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
#define rep(i,initial_n,end_n) for(int (i)=(initial_n);(i)<(end_n);i++)
#define repp(i,initial_n,end_n) for(int (i)=(initial_n);(i)<=(end_n);(i)++)
#define reep(i,initial_n,end_n) for((i)=(initial_n);(i)<(end_n);i++)
#define reepp(i,initial_n,end_n) for((i)=(initial_n);(i)<=(end_n);(i)++)
#define eps 1.0e-9

using namespace std;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef __int64 ll;
typedef unsigned __int64 ull;
const double pi = acos(-1);

inline double format(double a)
{
    return fabs(a)<1e-7?0:a;
}

int main()
{
    int n, n1, n2;
    pdd point[151], p1, p2;
    scanf("%d%d%d", &n, &n1, &n2);
    scanf("%lf%lf%lf%lf", &p1.first, &p1.second, &p2.first, &p2.second);
    if(n1 > n2) swap(n1, n2), swap(p1, p2);
    pdd m, o;
    m.first = (p1.first + p2.first)/2;
    m.second = (p1.second + p2.second)/2;
    o.first = m.first + (p2.second - p1.second) / tan(pi * (n2-n1) / n) / 2;
    o.second = m.second - (p2.first - p1.first) / tan(pi * (n2-n1) / n) / 2;
    point[n1].first = p1.first -= o.first, point[n1].second = p1.second -= o.second;
    double sinn = sin(pi*2/n), coss = cos(pi*2/n);
    pdd tmp = p1;
    for(int j = n1 + 1; ; j++)
    {
        if(j > n) j -= n;
        if(j == n1) break;
        point[j].first = tmp.first*coss + tmp.second*sinn;
        point[j].second = -tmp.first*sinn + tmp.second*coss;
        tmp = point[j];
    }
    repp(i, 1, n)
    {
        printf("%.6lf %.6lf\n", point[i].first + o.first, point[i].second + o.second);
    }
}
