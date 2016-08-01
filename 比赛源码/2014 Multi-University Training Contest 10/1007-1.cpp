#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define MP make_pair
#define PB push_back
#define eps 1e-8
#define pi acos(-1)
#define A first
#define B second

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
};

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

int m, r, n, t;
point p[100010], q[100010], o;

point intersection(point u1, point u2, point v1, point v2){
	double t = ((u1 - v1) * (v1 - v2))
             / ((u1 - u2) * (v1 - v2));
	return u1 + (u2 - u1) * t;
}

int intersection_line_circle(point c, double r, point l1, point l2, point& p1, point& p2) {
    point p = c;
    double t;
    p.x += l1.y - l2.y;
    p.y += l2.x - l1.x;
    p = intersection(p, c, l1, l2);
    int cnt = dcmp(r - p.dis(c)) + 1;
    if (cnt == 0) return cnt;
    if (cnt == 1) {
        p1 = p2 = p;
        return 1;
    }
    t = sqrt(r * r - p.dis(c) * p.dis(c)) / l1.dis(l2);
    p1 = p + (l2 - l1) * t;
    p2 = p - (l2 - l1) * t;
    return cnt;
}

vector<pair<double, double> > sgt;

void check(point u, point v) {
    double a1, a2, d1, d2, b1, b2;
    d1 = u.dis(o);
    d2 = v.dis(o);
    b1 = asin(sqrt(3.0) * r / 2 / d1) - pi / 6;
    b2 = asin(sqrt(3.0) * r / 2 / d2) - pi / 6;
    a1 = atan2(u.y, u.x);
    a2 = atan2(v.y, v.x);
    if (a1 > a2) {
        swap(a1, a2);
        swap(b1, b2);
    }
    while (a2 - a1 > pi)
        a1 += pi * 2;
    if (a1 > a2) {
        swap(a1, a2);
        swap(b1, b2);
    }
    sgt.PB(MP(a2 - b2, a1 + b1));
}

struct node {
    double p;
    int k;
    bool operator < (const node &q) const {
        return dcmp(p - q.p) < 0 || (dcmp(p - q.p) == 0 && k < q.k);
    }
} ans[100010];

int main() {
    o.x = o.y = 0;
    scanf("%d", &t);
    bool flag = false;
    for (int ca = 1; ca <= t; ca ++ ) {
        scanf("%d%d", &m, &r);
        flag = false;
        for (int i = 0; i < m; i ++ ) {
            p[i].input();
            if (p[i].dis(o) > r * sqrt(3.0) + eps) flag = true;
        }
        printf("Case #%d: ", ca);
        if (flag) {
            printf("NO\n");
            continue;
        }
        n = ConvexHull(p, m, q);
        sgt.clear();
        for (int i = 0; i < n; i ++ ) {
            int j = i + 1;
            if (j > n) j = 0;
            point o1, o2;
            if (dcmp(q[i].dis(o) - r) <= 0 && dcmp(q[j].dis(o) - r) <= 0) continue;
            int cnt = intersection_line_circle(o, r, q[i], q[j], o1, o2);
            if (cnt == 0
                || ((dcmp((q[i] - o1) & (q[j] - o1)) >= 0)
                    && (dcmp((q[i] - o2) & (q[j] - o2)) >= 0))) {
                check(q[i], q[j]);
                continue;
            }
            if (dcmp(q[i].dis(o) - r) > 0)
                if (dcmp(q[i].dis(o1) - q[i].dis(o2)) < 0)
                    check(q[i], o1);
                else
                    check(q[i], o2);
            if (dcmp(q[j].dis(o) - r) > 0)
                if (dcmp(q[j].dis(o1) - q[j].dis(o2)) < 0)
                    check(q[j], o1);
                else
                    check(q[j], o2);
        }
        double le = 0, ri = 2 * pi / 3;
        flag = false;
        int m = sgt.size(), cnt = 0;
        for (int i = 0; i < sgt.size(); i ++ ) {
            //if (ca == 4) cout<<sgt[i].A<<"<->"<<sgt[i].B<<endl;
            if (dcmp(sgt[i].A - sgt[i].B) > 0) {
                flag = true;
                break;
            }
            if (dcmp(sgt[i].B - sgt[i].A - pi / 3) >= 0) {
                m -- ;
                continue;
            }
            for (int j = 0; j < 7; j ++ ) {
                ans[cnt].p = sgt[i].A + j * pi / 3;
                ans[cnt ++ ].k = 1;
                ans[cnt].p = sgt[i].B + j * pi / 3;
                ans[cnt ++ ].k = 2;
            }
        }
        if (flag) {
            printf("Failed.\n");
            continue;
        }
        sort(ans, ans + cnt);
        flag = false;
        for (int i = 0; i < cnt; i ++ ) {
            if (ans[i].k == 1) m -- ;
            else m ++ ;
            if (m <= 0) {
                flag = true;
                break;
            }
            //if (ca == 4) cout<<ans[i].p<<" "<<ans[i].k<<" "<<m<<endl;
        }
        if (m <= 0) flag = true;
        if (flag) printf("Succeeded.\n");
        else printf("Failed.\n");
    }
    return 0;
}
