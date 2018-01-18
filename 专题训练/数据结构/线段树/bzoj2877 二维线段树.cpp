#include <cstdio>
#include <algorithm>

//------Common things & Memory pool
inline long long gcd(long long a, long long b)
{
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    for (long long r; b; a = b, b = r) r = a%b;
    return a;
}
const int MAXN = 500002;
char _memory[1<<26], *_memory_top = _memory;
template<typename T> inline T* newmemory(const size_t length)
{
    _memory_top += length * sizeof(T);
    return reinterpret_cast<T*>(_memory_top - length * sizeof(T));
}

//------1D Segment Class
class SegmentTree
{
    int n, st, ed, mul;
    long long *s, x;
    void build(const int p, const int lef, const int rig, const long long *a)
    {
        if (lef == rig)
        {
            s[p] = a[lef];
            return;
        }
        const int mid = (lef+rig)/2;
        build(p*2, lef, mid, a);
        build(p*2+1, mid+1, rig, a);
        s[p] = gcd(s[p*2], s[p*2+1]);
    }
    long long query(const int p, const int lef, const int rig)
    {
        if (st <= lef && rig <= ed) return s[p];
        const int mid = (lef+rig)/2;
        long long res = 0;
        if (st <= mid) res = query(p*2, lef, mid);
        if (mid+1 <= ed) res = gcd(res, query(p*2+1, mid+1, rig));
        return res;
    }
    void modify(const int p, const int lef, const int rig)
    {
        if (lef == rig)
        {
            s[p] = s[p]*mul+x;
            return;
        }
        const int mid = (lef+rig)/2;
        if (st <= mid) modify(p*2, lef, mid);
        else modify(p*2+1, mid+1, rig);
        s[p] = gcd(s[p*2], s[p*2+1]);
    }
public:
    SegmentTree(const int length, const long long* a): n(length), s(newmemory<long long>((n+1)*4))
    {
        build(1, 1, n, a);
    }
    long long Query(const int lef, const int rig)
    {
        st = lef, ed = rig;
        return query(1, 1, n);
    }
    void Modify(const int pos, const long long value)
    {
        st = pos, x = value, mul = 0;
        modify(1, 1, n);
    }
    void Add(const int pos, const long long value)
    {
        st = pos, x = value, mul = 1;
        modify(1, 1, n);
    }
};

//------2D Matrix & Segment Class
typedef long long** Matrix;
class SegmentTree2D
{
    int n, m, stx, sty, edx, edy;
    long long x;
    SegmentTree* s;
    void build(const int p, const int lef, const int rig, const Matrix& mat)
    {
        if (lef == rig)
        {
            s[p] = SegmentTree(m, mat[lef]);
            return;
        }
        const int mid = (lef+rig)/2;
        build(p*2, lef, mid, mat);
        build(p*2+1, mid+1, rig, mat);
        long long *tmp = newmemory<long long>(m+1);
        for (int i = 1; i <= m; ++i) tmp[i] = gcd(s[p*2].Query(i, i), s[p*2+1].Query(i, i));
        s[p] = SegmentTree(m, tmp);
    }
    long long query(const int p, const int lef, const int rig)
    {
        if (stx <= lef && rig <= edx) return s[p].Query(sty, edy);
        const int mid = (lef+rig)/2;
        long long res = 0;
        if (stx <= mid) res = query(p*2, lef, mid);
        if (mid+1 <= edx) res = gcd(res, query(p*2+1, mid+1, rig));
        return res;
    }
    void modify(const int p, const int lef, const int rig)
    {
        if (lef == rig)
        {
            s[p].Add(sty, x);
            return;
        }
        const int mid = (lef+rig)/2;
        if (stx <= mid) modify(p*2, lef, mid);
        else modify(p*2+1, mid+1, rig);
        s[p].Modify(sty, gcd(s[p*2].Query(sty, sty), s[p*2+1].Query(sty, sty)));
    }
public:
    SegmentTree2D(const int a, const int b, const Matrix& mat): n(a), m(b), s(newmemory<SegmentTree>(4*(n+1)))
    {
        build(1, 1, n, mat);
    }
    long long Query(const int x1, const int y1, const int x2, const int y2)
    {
        stx = x1, sty = y1, edx = x2, edy = y2;
        return query(1, 1, n);
    }
    void Modify(const int i, const int j, const long long value)
    {
        if (i < 1 || j < 1 || i > n || j > m) return;
        stx = edx = i, sty = edy = j, x = value;
        modify(1, 1, n);
    }
};

//------Main program & functions
int n, m, t, x, y;
long long c;
int main()
{
//    freopen("bzoj2877.in", "r", stdin);
//    freopen("bzoj2877.out", "w", stdout);
    scanf("%d%d%d%d%d", &n, &m, &x, &y, &t);
    Matrix mat = newmemory<long long*>(n+1);
    for (int i = 0; i <= n; ++i) mat[i] = newmemory<long long>(m+1);

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%I64d", &mat[i][j]);
    for (int i = 1; i < x; ++i)
    {
        for (int j = 1; j < y; ++j) mat[i][j] += mat[i+1][j+1]-mat[i][j+1]-mat[i+1][j];
        for (int j = m; j > y; --j) mat[i][j] += mat[i+1][j-1]-mat[i][j-1]-mat[i+1][j];
    }
    for (int i = n; i > x; --i)
    {
        for (int j = 1; j < y; ++j) mat[i][j] += mat[i-1][j+1]-mat[i][j+1]-mat[i-1][j];
        for (int j = m; j > y; --j) mat[i][j] += mat[i-1][j-1]-mat[i][j-1]-mat[i-1][j];
    }
    for (int i = 1; i < y; ++i) mat[x][i] -= mat[x][i+1];
    for (int i = m; i > y; --i) mat[x][i] -= mat[x][i-1];
    for (int i = 1; i < x; ++i) mat[i][y] -= mat[i+1][y];
    for (int i = n; i > x; --i) mat[i][y] -= mat[i-1][y];
    SegmentTree2D seg(n, m, mat);

    for (int i = 0, op, x1, y1, x2, y2; i < t; ++i)
    {
        scanf("%d%d%d%d%d", &op, &x1, &y1, &x2, &y2);
        if (op == 0)
            printf("%I64d\n", seg.Query(x-x1, y-y1, x+x2, y+y2));
        else
        {
            scanf("%I64d", &c);
            if (x1<=x && y1<=y) seg.Modify(x1-1, y1-1,  c);
            else if (x1> x && y1> y) seg.Modify(x1  , y1  ,  c);
            else if (x1<=x && y1> y) seg.Modify(x1-1, y1  , -c);
            else if (x1> x && y1<=y) seg.Modify(x1  , y1-1, -c);

            if (x2< x && y2< y) seg.Modify(x2  , y2  ,  c);
            else if (x2>=x && y2>=y) seg.Modify(x2+1, y2+1,  c);
            else if (x2< x && y2>=y) seg.Modify(x2  , y2+1, -c);
            else if (x2>=x && y2< y) seg.Modify(x2+1, y2  , -c);

            if (x1<=x && y2>=y) seg.Modify(x1-1, y2+1,  c);
            else if (x1> x && y2< y) seg.Modify(x1  , y2  ,  c);
            else if (x1<=x && y2< y) seg.Modify(x1-1, y2  , -c);
            else if (x1> x && y2>=y) seg.Modify(x1  , y2+1, -c);

            if (x2< x && y1> y) seg.Modify(x2  , y1  ,  c);
            else if (x2>=x && y1<=y) seg.Modify(x2+1, y1-1,  c);
            else if (x2< x && y1<=y) seg.Modify(x2  , y1-1, -c);
            else if (x2>=x && y1> y) seg.Modify(x2+1, y1  , -c);

            if (x1<=x && x2>=x)
            {
                if (y1<=y) seg.Modify(x, y1-1, -c);
                else seg.Modify(x, y1  ,  c);
                if (y2>=y) seg.Modify(x, y2+1, -c);
                else seg.Modify(x, y2  ,  c);
            }
            if (y1<=y && y2>=y)
            {
                if (x1<=x) seg.Modify(x1-1, y, -c);
                else seg.Modify(x1  , y,  c);
                if (x2>=x) seg.Modify(x2+1, y, -c);
                else seg.Modify(x2  , y,  c);
            }

            if (x1<=x && x2>=x && y1<=y && y2>=y) seg.Modify(x, y, c);
        }
    }
}
