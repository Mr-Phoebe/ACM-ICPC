#include <cstdio>
#include <iostream>
#define pos(Tw, w) ((((Tw) | mask1) << bit2) | mask2 | (w))
using namespace std;
typedef long long ll;

int Rp = 0, n, m, x, y, T, mask1, mask2, bit2;
ll a[8388609];
char RF[14500001];
inline void Read(ll &a) {
    for (; RF[Rp] != '-' && RF[Rp] < '0'; ++Rp);
    bool f = RF[Rp] == '-'; Rp += f;
    a = 0; for (; RF[Rp] >= '0'; ++Rp) a = a * 10 + RF[Rp] - '0';
    if (f) a = -a;
}
inline void Read(int &a) {
    for (; RF[Rp] != '-' && RF[Rp] < '0'; ++Rp);
    bool f = RF[Rp] == '-'; Rp += f;
    a = 0; for (; RF[Rp] >= '0'; ++Rp) a = a * 10 + RF[Rp] - '0';
    if (f) a = -a;
}
inline ll gcd(ll a, ll b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    for (ll c; b; c=a%b,a=b,b=c);
    return a;
}
inline void Build1() {
    for (int i=mask1-1; i; --i)
        for (int j=mask2 | (m-1); j; --j)
            a[(i << bit2) | j] = gcd(a[(i << 1+bit2) | j], a[((i<<1)+1 << bit2) | j]);
}
inline void Build2(int mask) {
    for (int i=mask2-1; i; --i)
        a[mask | i] = gcd(a[mask | (i << 1)], a[mask | ((i << 1) | 1)]);
}
inline ll lQ(int mask, int x1, int x2) {
    mask <<= bit2;
    ll ans = gcd(a[mask | x1], a[mask | x2]);
    for (; x1>>1!=x2>>1; x1>>=1,x2>>=1) {
        if (!(x1 & 1)) ans = gcd(ans, a[mask | (x1 ^ 1)]);
        if (  x2 & 1 ) ans = gcd(ans, a[mask | (x2 ^ 1)]);
    }
    return ans;
}
inline ll Q(int x1, int y1, int x2, int y2) {
    x1 |= mask1, x2 |= mask1;
    y1 |= mask2, y2 |= mask2;
    ll ans = gcd(lQ(x1, y1, y2), lQ(x2, y1, y2));
    for (; x1>>1!=x2>>1; x1>>=1,x2>>=1) {
        if (!(x1 & 1)) ans = gcd(ans, lQ(x1 ^ 1, y1, y2));
        if (  x2 & 1 ) ans = gcd(ans, lQ(x2 ^ 1, y1, y2));
    }
    return ans;
}
inline void M(int x, int y, ll c) {
    if (x<0 || y<0 || x>=n || y>=m) return;
    int mask = (mask1 | x) << bit2;
    a[pos(x, y)] += c;
    for (int j = (mask2 | y) >> 1; j; j >>= 1)
        a[mask | j] = gcd(a[mask | (j << 1)], a[mask | (j << 1) | 1]);
    for (int i = (mask1 | x) >> 1; i; i >>= 1)
        for (int j = mask2 | y; j; j >>= 1)
            a[(i << bit2) | j] = gcd(a[(i << bit2+1) | j], a[((i<<1)+1 << bit2) | j]);
}
void init() {
    Read(n); Read(m);
    Read(x); Read(y);
    Read(T);
    for (mask1=1; mask1<n; mask1<<=1);
    for (mask2=1, bit2=1; mask2<m; mask2<<=1, ++bit2);
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j)
            Read(a[pos(i, j)]);
    --x, --y;
    for (int i=0; i<x; ++i)
        for (int j=0; j<y; ++j)
            a[pos(i, j)] += a[pos(i+1, j+1)] - a[pos(i, j+1)] - a[pos(i+1, j)];
    for (int i=n-1; i>x; --i)
        for (int j=0; j<y; ++j)
            a[pos(i, j)] += a[pos(i-1, j+1)] - a[pos(i, j+1)] - a[pos(i-1, j)];
    for (int i=0; i<x; ++i)
        for (int j=m-1; j>y; --j)
            a[pos(i, j)] += a[pos(i+1, j-1)] - a[pos(i, j-1)] - a[pos(i+1, j)];
    for (int i=n-1; i>x; --i)
        for (int j=m-1; j>y; --j)
            a[pos(i, j)] += a[pos(i-1, j-1)] - a[pos(i, j-1)] - a[pos(i-1, j)];
    for (int i=0; i<x; ++i)
        a[pos(i, y)] -= a[pos(i+1, y)];
    for (int i=n-1; i>x; --i)
        a[pos(i, y)] -= a[pos(i-1, y)];
    for (int j=0; j<y; ++j)
        a[pos(x, j)] -= a[pos(x, j+1)];
    for (int j=m-1; j>y; --j)
        a[pos(x, j)] -= a[pos(x, j-1)];
    for (int i=0; i<n; ++i)    
        Build2((mask1 | i) << bit2);
    Build1();
}
void run() {
    int type, x1, x2, y1, y2;
    ll c, ans;
    for (; T; --T) {
        Read(type);
        Read(x1); Read(y1); Read(x2); Read(y2);
        if (type) {
            //Modify
            --x1, --x2, --y1, --y2;
            Read(c);
            if (x1<=x && y1<=y) M(x1-1, y1-1,  c); else
            if (x1> x && y1> y) M(x1  , y1  ,  c); else
            if (x1<=x && y1> y) M(x1-1, y1  , -c); else
            if (x1> x && y1<=y) M(x1  , y1-1, -c);
            
            if (x2< x && y2< y) M(x2  , y2  ,  c); else
            if (x2>=x && y2>=y) M(x2+1, y2+1,  c); else
            if (x2< x && y2>=y) M(x2  , y2+1, -c); else
            if (x2>=x && y2< y) M(x2+1, y2  , -c);
            
            if (x1<=x && y2>=y) M(x1-1, y2+1,  c); else
            if (x1> x && y2< y) M(x1  , y2  ,  c); else
            if (x1<=x && y2< y) M(x1-1, y2  , -c); else
            if (x1> x && y2>=y) M(x1  , y2+1, -c);
            
            if (x2< x && y1> y) M(x2  , y1  ,  c); else
            if (x2>=x && y1<=y) M(x2+1, y1-1,  c); else
            if (x2< x && y1<=y) M(x2  , y1-1, -c); else
            if (x2>=x && y1> y) M(x2+1, y1  , -c);
            
            if (x1<=x && x2>=x) {
                if (y1<=y) M(x, y1-1, -c); else
                           M(x, y1  ,  c);
                if (y2>=y) M(x, y2+1, -c); else
                           M(x, y2  ,  c);
            }
            if (y1<=y && y2>=y) {
                if (x1<=x) M(x1-1, y, -c); else
                           M(x1  , y,  c);
                if (x2>=x) M(x2+1, y, -c); else
                           M(x2  , y,  c);
            }
            if (x1<=x && x2>=x && y1<=y && y2>=y)
                M(x, y, c);
        }
        else {
            //Query
            x1 = x - x1, y1 = y - y1;
            x2 = x + x2, y2 = y + y2;
            printf("%lld\n", Q(x1, y1, x2, y2));
        }
    }
}
int main() {
    //freopen("chess.in", "r", stdin);
    //freopen("chess.out", "w", stdout);
    fread(RF, 1, 14500000, stdin);
    init();
    run();
    return 0;
}