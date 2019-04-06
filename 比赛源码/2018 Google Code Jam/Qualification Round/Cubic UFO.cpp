//      whn6325689
//      Mr.Phoebe
//      http://blog.csdn.net/u013007900
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
#include <list>
#include <ctime>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <functional>
#include <numeric>
#pragma comment(linker, "/STACK:1024000000,1024000000")


using namespace std;
#define eps 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LLINF 1LL<<50
#define speed std::ios::sync_with_stdio(false);

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;

#define CLR(x,y) memset(x,y,sizeof(x))
#define CPY(x,y) memcpy(x,y,sizeof(x))
#define clr(a,x,size) memset(a,x,sizeof(a[0])*(size))
#define cpy(a,x,size) memcpy(a,x,sizeof(a[0])*(size))
#define debug(a) cout << #a" = " << (a) << endl;
#define debugarry(a, n) for (int i = 0; i < (n); i++) { cout << #a"[" << i << "] = " << (a)[i] << endl; }

#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define lowbit(x) (x&(-x))

#define MID(x,y) (x+((y-x)>>1))
#define getidx(l,r) (l+r | l!=r)
#define ls getidx(l,mid)
#define rs getidx(mid+1,r)
#define lson l,mid
#define rson mid+1,r

template<class T>
inline bool read(T &n)
{
    T x = 0, tmp = 1;
    char c = getchar();
    while((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();
    if(c == EOF) return false;
    if(c == '-') c = getchar(), tmp = -1;
    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c = getchar();
    n = x*tmp;
    return true;
}
template <class T>
inline void write(T n)
{
    if(n < 0)
    {
        putchar('-');
        n = -n;
    }
    int len = 0,data[20];
    while(n)
    {
        data[len++] = n%10;
        n /= 10;
    }
    if(!len) data[len++] = 0;
    while(len--) putchar(data[len]+48);
}
//-----------------------------------

typedef long double Double;
typedef pair<Double,Double> dd;
#define Dsin   sinl
#define Dcos   cosl
#define Datan2 atan2l
#define Dhypot hypotl
#define Dfabs  fabsl

typedef vector<Double> Coord;

vector<Coord> corners(8, Coord(3));

const Double PI = 3.14159265358979323846;

inline Double deg2rad(Double deg)
{
    return deg * PI / 180.0;
}
inline Double rad2deg(Double rad)
{
    return rad / PI * 180.0;
}

void _init()
{
    int _corners[8][3] =
    {
        {1, 1, 1}, {1, -1, 1}, {-1, -1, 1}, {-1, 1, 1},
        {1, 1, -1}, {1, -1, -1}, {-1, -1, -1}, {-1, 1, -1}
    };

    for(int c = 0; c < 8; c++)
        for(int i = 0; i < 3; i++)
            corners[c][i] = 0.5 * _corners[c][i];
}

inline Coord dot(Double R[][3], Coord& x)
{
    Coord y(3, 0.0);
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            y[i] += R[i][j] * x[j];
    return y;
}

Coord _rx(Coord& p, Double th)
{
    Double R[3][3];
    R[0][0] = 1;
    R[0][1] = 0;
    R[0][2] =  0;
    R[1][0] = 0;
    R[1][1] = Dcos(th);
    R[1][2] = -Dsin(th);
    R[2][0] = 0;
    R[2][1] = Dsin(th);
    R[2][2] =  Dcos(th);
    return dot(R, p);
}

Coord _ry(Coord& p, Double th)
{
    Double R[3][3];
    R[0][0] =  Dcos(th);
    R[0][1] = 0;
    R[0][2] = Dsin(th);
    R[1][0] =  0;
    R[1][1] = 1;
    R[1][2] = 0;
    R[2][0] = -Dsin(th);
    R[2][1] = 0;
    R[2][2] = Dcos(th);
    return dot(R, p);
}

Coord _rz(Coord& p, Double th)
{
    Double R[3][3];
    R[0][0] = Dcos(th);
    R[0][1] = -Dsin(th);
    R[0][2] = 0;
    R[1][0] = Dsin(th);
    R[1][1] =  Dcos(th);
    R[1][2] = 0;
    R[2][0] = 0;
    R[2][1] =  0;
    R[2][2] = 1;
    return dot(R, p);
}

inline dd vec(dd& a, dd& b)
{
    return dd(b.first - a.first, b.second - a.second);
}
inline Double outer(dd& u, dd& v)
{
    return u.first * v.second - v.first * u.second;
}
inline Double vlen(dd& v)
{
    return Dhypot(v.first, v.second);
}

inline Double ccw(dd& p1, dd& p2, dd& p3)
{
    return (p2.first - p1.first)*(p3.second - p1.second)
           - (p2.second - p1.second)*(p3.first - p1.first);
}

template<typename T>
vector<T> _uniq(vector<T>& v)
{
    set<T> tmp(ALL(v));
    return vector<T>(ALL(tmp));
}

inline bool dd_eq(dd& p, dd& q)
{
    dd pq = vec(p, q);
    return vlen(pq) < eps;
}

vector<dd> uniq(vector<dd>& v)
{
    sort(v.begin(), v.end());
    vector<dd> res;
    res.pb(v[0]);
    for (int i=1; i<v.size(); ++i)
    {
        if (!dd_eq(v[i], res.back()))
        {
            res.pb(v[i]);
        }
    }
    return res;
}

vector<dd> convex_hull(vector<dd>& points_orig)
{
    vector<dd> points = uniq(points_orig);
    int N = points.size();

    Double ymin = 1e9, xmin = 1e9;
    int at = -1;
    for(int i = 0; i < N; i++) ymin = min(ymin, points[i].second);
    for(int i = 0; i < N; i++)
    {
        if (points[i].second == ymin)
        {
            if (points[i].first < xmin)
            {
                xmin = points[i].first;
                at = i;
            }
        }
    }
    vector<pair<Double, dd>> tmp(N);
    for(int i = 0; i < N; i++)
    {
        Double th;
        if (i != at)
            th = Datan2(points[i].second - ymin, points[i].first - xmin);
        else
            th = -1e9;
        tmp[i] = make_pair(th, points[i]);
    }
    sort(tmp.begin(), tmp.end());
    assert(tmp[0].second == dd(xmin, ymin));

    vector<dd> pts(N+1);
    for(int i = 0; i < N; i++) pts[1+i] = tmp[i].second;
    pts[0] = pts[N];

    int M = 1;
    for (int i=2; i<=N; ++i)
    {
        while (ccw(pts[M-1], pts[M], pts[i]) <= 0)
        {
            if (M > 1)
            {
                --M;
                continue;
            }
            else if (i == N)
            {
                break;
            }
            else
            {
                ++i;
            }
        }
        ++M;
        swap(pts[M], pts[i]);
    }

    if (M < pts.size())
    {
        pts.erase(pts.begin()+M, pts.end());
    }

    return pts;
}

Double convex_hull_area(vector<dd>& hull)
{
    int N = hull.size();
    dd m(0, 0);

    Double area = 0;
    for(int i = 0; i < N; i++)
    {
        dd p = hull[i], q = hull[(i+1)%N];
        area += 0.5 * Dfabs(outer(p, q));
    }
    return area;
}

void render_ans(Double th_x, Double th_z)
{
    for(int c = 0; c < 3; c++)
    {
        Coord p(3, 0);
        p[c] = 0.5;
        Coord r1 = _rx(p, th_x);
        Coord r2 = _rz(r1, th_z);
        printf("%.16Lf %.16Lf %.16Lf\n", r2[0], r2[1], r2[2]);
    }
}

Double rotated_shadow_area(Double th_x, Double th_z)
{
    vector<dd> points;

    for(int c = 0; c < 8; c++)
    {
        Coord r1 = _rx(corners[c], th_x);
        Coord r2 = _rz(r1, th_z);
        points.pb( dd(r2[0], r2[2]) );
    }

    vector<dd> hull = convex_hull(points);
    Double area = convex_hull_area(hull);

    return area;
}

void solve(double A)
{
    Double alpha, beta_min, beta_max;
    if (A < 1.0)
    {
        assert(false);
    }
    else if (A <= sqrt(2.0))
    {
        alpha = 0;
        beta_min = 0;
        beta_max = deg2rad(45);
    }
    else
    {
        alpha = deg2rad(45);
        beta_min = 0;
        beta_max = deg2rad(35.26438902);
    }

    Double lo = beta_min, hi = beta_max, mi;
    Double f_lo = rotated_shadow_area(alpha, lo);
    Double f_hi = rotated_shadow_area(alpha, hi);
    Double f_mi;
    for(int i = 0; i < 100; i++)
    {
        mi = (lo + hi) / 2;
        f_mi = rotated_shadow_area(alpha, mi);
        if (A < f_mi)
        {
            hi = mi;
        }
        else
        {
            lo = mi;
        }
    }

    render_ans(alpha, mi);

}

int main()
{
    _init();

    int T;
    cin >> T;
    for (int t=1; t<=T; ++t)
    {
        double A;
        cin >> A;
        printf("Case #%d:\n", t);
        solve(A);
    }
    return 0;
}