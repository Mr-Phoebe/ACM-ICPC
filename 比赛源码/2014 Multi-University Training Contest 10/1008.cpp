#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#define eps 1e-8
#define pi acos(-1)

using namespace std;

int dcmp(double x) {return x < -eps ? -1 : x > eps; }

struct point {
    double x, y;
    point() {}
    point(double _x, double _y) : x(_x), y(_y) {}
    point operator - (const point &p) {return point(x - p.x, y - p.y);}
    point operator + (const point &p) {return point(x + p.x, y + p.y);}
    point operator / (double d){return point(x / d, y / d);}
    point operator * (double d){return point(x * d, y * d);}
    double arc() {return atan2(y, x);}
    point rotate(double phi) {
        return point(x * cos(phi) - y * sin(phi), x * sin(phi) - y * cos(phi));
    }
    bool operator < (const point& p) const {
        return dcmp(x - p.x) < 0 || (dcmp(x - p.x) == 0 && dcmp(y - p.y) < 0);
    }
    bool operator == (const point& p) {
        return dcmp(x - p.x) == 0 && dcmp(y - p.y) == 0;
    }
    double operator * (const point &p) {return x * p.y - y * p.x;} //²æ»ý
    double operator & (const point &p) {return x * p.x + y * p.y;} //µã»ý
    double dis(const point &p) {return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));}
    void input() {scanf("%lf%lf", &x, &y);}
    void output() {printf("%.2lf %.2lf\n", x, y);}
} p[55], q[55];

int n, t, l;

//边上有点，更改<= 为 < 去掉
int ConvexHull(point p[], int n, point q[]) {
    sort(p, p + n);
    int m = 0;
    for (int i = 0; i < n; i ++ ) {
        while (m > 1 && dcmp((q[m - 1] - q[m - 2]) * (p[i] - q[m - 2])) <= 0) m -- ;
        q[m ++] = p[i];
    }

    if (n < 3) return n;
    int k = m;
    for (int i = n - 2; i >= 0; i -- ) {
        while (m > k && dcmp((q[m - 1] - q[m - 2]) * (p[i] - q[m - 2])) <= 0) m -- ;
        q[m ++ ] = p[i];
    }
    if (n > 1) m -- ;
    return m;
}

int main() {
    scanf("%d", &t);
    for (int ca = 1; ca <= t; ca ++ ) {
        scanf("%d%d", &n, &l);
        for (int i = 0; i < n; i ++ )
            p[i].input();
        int m = ConvexHull(p, n, q);
        double ans = q[0].dis(q[m - 1]);
        for (int i = 1; i < m; i ++ )
            ans += q[i].dis(q[i - 1]);
        printf("Case #%d: %.4lf\n", ca, ans / pi / l);
    }
    return 0;
}
