/*author: birdstorm*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <complex>
#include <set>
#include <algorithm>
#include <climits>
#include <cfloat>

#define MAXN 300005
//#define n 105
#define inf 1.0e20
//#define eps 1.0e-8
#define MOD 1000000007

#define pb push_back
#define mp make_pair
#define next(i) (i+1)%sz

#define For(i,m,n) for(int i=(m);i<(n);i++)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define rep(i,m,n) for(int i=(m);i<=(n);i++)
#define repd(i,m,n) for(int i=(m);i>=(n);i--)
#define LL long long
#define test

using namespace std;

const double eps=1.0e-8;
const double pi=acos(-1.0);

typedef complex<double> point;
typedef vector<point> polygon;

struct line : public vector<point> {
    line() {}
    line(const point& a, const point& b) { push_back(a); push_back(b); }
};

struct Edge{
    int v;
    double d;
    Edge(int v=0, double d=0):v(v),d(d) {}
};

namespace std{
    bool operator<(const point& a, const point& b) {
        return a.real()!=b.real()?a.real()<b.real():a.imag()<b.imag();
    }
}

point unit(const point& v) { return v/abs(v);}
point ortho(const point& v) { return v*point(0,1);}
inline point vec(const line& l) { return l[1]-l[0];}
bool equal(const double a, const double b) { return abs(a-b)<eps;}
bool equal(const point& a, const point& b) { return abs(a-b)<eps;}
inline double dot  (const point& a, const point& b) { return (a*conj(b)).real();}
inline double cross(const point& a, const point& b) { return (conj(a)*b).imag();}

typedef vector<line> Obstacle;
typedef vector<Edge> Graph;
Graph graph[MAXN];
point Alice, Bob;
vector<Obstacle> obstacles;
vector<point> points;
//vector<point> p1;
int n;

inline int ccw(const point& a, const point& b, const point& c) {
    point u=b-a, v=c-a;
    if(cross(u,v)>0) return 1;
    if(cross(u,v)<0) return -1;
    if(dot(u,v)<0) return 2;
    if(abs(u)<abs(v)) return -2;
    return 0;
}

void add_Edge(int u, int v, double w)
{
    graph[u].push_back(Edge(v, w));
    graph[v].push_back(Edge(u, w));
}

inline int ccw(const line& s, const point& p) {
    return ccw(s[0], s[1], p);
}

point projection(const line &l, const point &p) {
  double t = dot(p-l[0], l[0]-l[1]) / norm(l[0]-l[1]);
  return l[0] + t*(l[0]-l[1]);
}

bool intersectLP(const line& l, const point& p) {
    return abs(cross(l[1]-p, l[0]-p)) < eps;
}

inline bool intersectSP(const line& s, const point& p) {
    return abs(s[0]-p)+abs(s[1]-p) < abs(s[1]-s[0])+eps;
}

bool intersectLL(const line& l, const line& m) {
    return cross(vec(l), vec(m)) > eps || cross(vec(l), m[0]-l[0]) < eps;
}

bool intersectLS(const line& l, const line& s) {
    return cross(vec(l),s[0]-l[0]) * cross(vec(l),s[1]-l[0]) <= 0;
}

bool intersectSS(const line& s, const line& t) {
    return ccw(s,t[0])*ccw(s,t[1]) <= 0 && ccw(t,s[0])*ccw(t,s[1]) <= 0;
}

point crosspoint(const line& l, const line& m) {
    double A = cross(vec(l), vec(m));
    double B = cross(vec(l), l[1]-m[0]);
    if(abs(A)<eps) {    // parallel
        return m[0];    // sameline
    }
    return m[0] + B/A*vec(m);
}

line generateSP(const line &s, const point &p) {
  const point r = projection(s, p);
  if(intersectSP(s, r)) return line(r, p);
  else{
    if(abs(s[0]-p) < abs(s[1] - p)) return line(s[0], p);
    else return line(s[1], p);
  }
  return s;
}

double distanceSP(const line &s, const point &p) {
  const point r = projection(s, p);
  if (intersectSP(s, r)) return abs(r - p);
  return min(abs(s[0] - p), abs(s[1] - p));
}

bool isSameLine(const point& a, const point& b, const line& l)
{
    double x = distanceSP(l, a);
    double y = distanceSP(l, b);
    return x < eps && y < eps;
}

bool comp(const point& a, const point& b)
{
    return abs(a-b) < eps;
}

vector<point> crosspointSO(const line& sight, const vector<line>& obstacle)
{
    vector<point> res;
    for(int i=0; i<obstacle.size(); i++) {
        if(intersectSS(sight, obstacle[i]))
            res.push_back(crosspoint(sight, obstacle[i]));
    }
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end(), comp), res.end());
    if(res.size() <= 1) return vector<point>();
    for(int i=0; i<obstacle.size(); i++) {
        if(isSameLine(res[0], res[1], obstacle[i])) return vector<point>();
    }
    return res;
}

line calcSight(const line& sight)
{
    vector<pair<double,point> > res;
    for(int i=0; i<obstacles.size(); i++) {
        vector<point> p = crosspointSO(sight, obstacles[i]);
        for(int j=0; j<p.size(); j++) {
            res.push_back(make_pair(abs(p[j]-sight[0]), p[j]));
        }
    }

    sort(res.begin(), res.end());
    if(res.size() == 0) return sight;
    return line(sight[0], res[0].second);
}

bool reachable(const line& sight)
{
    for(int i=0; i<obstacles.size(); i++) {
        vector<point> p = crosspointSO(sight, obstacles[i]);
        if(p.size() != 0) return false;
    }
    return true;
}
