#include <bits/stdc++.h>
using LL = long long ;
#define ALL(v) (v).begin(),(v).end()
#define showtime fprintf(stderr,"time = %.15f\n",clock() / (double)CLOCKS_PER_SEC)

const int N = 2000 + 5;

struct Point {
    int x,y;
    Point(int _x = 0,int _y = 0) : x(_x),y(_y) {}
    Point operator + (const Point &rhs) const {
        return Point(x + rhs.x,y + rhs.y);
    }
    Point operator - (const Point &rhs) const {
        return Point(x - rhs.x,y - rhs.y);
    }
    void read() {
        scanf("%d%d",&x,&y);
    }
    void show() const {
        printf("%d %d\n",x,y);
    }
} points[N];

int n;

LL det(const Point &a,const Point &b) {
    return a.x * 1ll * b.y - a.y * 1ll * b.x;
}

LL dot(const Point &a,const Point &b) {
    return a.x * 1ll * b.x + a.y * 1ll * b.y;
}

bool polar_cmp(const Point &a,const Point &b) {
    if (a.y * 1ll * b.y <= 0) {
        if (a.y > 0 || b.y > 0) return a.y < b.y;
        if (a.y == 0 && b.y == 0) return a.x < b.x;
    }
    return det(a,b) > 0;
}

LL brute() {
    int ret = 0;
    for (int i = 0; i < n; ++ i) {
        for (int j = i + 1; j < n; ++ j) {
            for (int k = j + 1; k < n; ++ k) {
                if (dot(points[i] - points[k],points[j] - points[k]) > 0
                        && dot(points[j] - points[i],points[k] - points[i]) > 0
                        && dot(points[i] - points[j],points[k] - points[j]) > 0)
                    ret ++;
            }
        }
    }
    return ret;
}

LL work() {
    LL cq = 0,cqc = 0;
    std::vector<Point> vec;
    for (int core = 0; core < n; ++ core) {
        vec.clear();
        for (int i = 0; i < n; ++ i) {
            if (i != core) 
                vec.emplace_back(points[i] - points[core]);
        }
        std::sort(ALL(vec),polar_cmp);
        vec.insert(vec.end(),ALL(vec));
        for (int i = 0,j = 0,k = 0,r = 0; i < n - 1; ++ i) {
            while (j < i + n - 1 && det(vec[i],vec[j]) == 0 && dot(vec[i],vec[j]) > 0) ++ j;
            k = std::max(k,j);
            while (k < i + n - 1 && det(vec[i],vec[k]) > 0 && dot(vec[i],vec[k]) > 0) ++ k;
            r = std::max(r,k);
            while (r < i + n - 1 && det(vec[i],vec[r]) > 0) ++ r;
            cq += k - j;
            cqc += r - k;
        }
    }
    LL result = (cq - 2 * cqc) / 3;
    //assert(result == brute());
    return result;
}

int main() {
//    freopen("data.in","r",stdin);
//    freopen("data.out","w",stdout);
    while (scanf("%d",&n) == 1) {
        for (int i = 0; i < n; ++ i) {
            points[i].read();
        }
        printf("%I64d\n",work());
    }
    showtime;
}
