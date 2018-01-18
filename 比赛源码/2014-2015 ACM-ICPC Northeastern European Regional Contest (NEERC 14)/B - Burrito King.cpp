//By LH
#pragma warning(disable:4996)
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
#include <functional>
#include <numeric>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define eps 1e-10
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

int n;
double m1, m2;
double ans[100005];
struct node
{
    double a, b, g;
    int num;
}p[100005];

int dml(double x)
{
    if(x < -eps) return -1;
    return x>eps ? 1 : 0;
}

int cmp(node p1, node p2)
{
    return (dml(p1.a*p2.b-p1.b*p2.a) == 1);
}
int main()
{
    freopen("burrito.in","r",stdin);
    freopen("burrito.out","w",stdout);
    scanf("%d %lf %lf", &n, &m1, &m2);
    double now1 = 0, now2 = m2;
    int cnt = 0;
    memset(ans, 0, sizeof(ans));
    for (int i = 1; i <= n; i++)
    {
        double tmpg, tmpa, tmpb;
        scanf("%lf %lf %lf", &tmpg, &tmpa, &tmpb);
        if (tmpb == 0)
        {
            now1 += tmpa*tmpg;
            ans[i] = tmpg;
        }
        else
        {
            cnt++;
            p[cnt].g = tmpg;
            p[cnt].a = tmpa;
            p[cnt].b = tmpb;
            p[cnt].num = i;
        }
    }
    sort(p+1, p+cnt+1, cmp);
    for (int i = 1; i <= cnt; i++)
    {
        if (dml(now2) == 0) break;
        if (dml(p[i].b*p[i].g-now2) <= 0)
        {
            now2 -= p[i].b*p[i].g;
            now1 += p[i].a*p[i].g;
            ans[p[i].num] = p[i].g;
        }
        else
        {
            double tmp = now2/p[i].b;
            now2 = 0;
            now1 += p[i].a*tmp;
            ans[p[i].num] = tmp;
        }
    }
    if (dml(now1-m1) >= 0)
    {
        printf("%.8lf %.8lf\n", now1, m2-now2);
        for (int i = 1; i <= n-1; i++) printf("%.8lf ", ans[i]);
        printf("%.8lf\n", ans[n]);
    }
    else printf("-1 -1\n");
    return 0;
}