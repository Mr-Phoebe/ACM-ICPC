#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <cmath>

using namespace std;

const int maxn = 505;

int n, m;
double val[maxn];

int main ()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lf", &val[i]);

    double ans = 0, k;
    int a, b;

    for (int i = 0; i < m; i++)
	{
        scanf("%d%d%lf", &a, &b, &k);
        double tmp = (val[a] + val[b]) / k;
        ans=max(ans,tmp);
    }
    printf("%.15lf\n", ans);
    return 0;
}