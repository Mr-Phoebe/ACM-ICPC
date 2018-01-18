#include <cstdio>
#include <cstring>

using namespace std;

const int MAXNODE = 4005;
const int MAXM = 65;
const int MAXN = 65;
const int INF = 0x3f3f3f3f;

int K;

struct DLX
{

    int n, m, size;

    int U[MAXNODE], D[MAXNODE], R[MAXNODE], L[MAXNODE], row[MAXNODE], col[MAXNODE];
    int H[MAXN], S[MAXM];
    int ansd, ans[MAXN];

    void init(int n, int m)
    {
        this->n = n;
        this->m = m;
        ansd = INF;
        for(int i = 0; i <= m; i++)
        {
            S[i] = 0;
            U[i] = D[i] = i;
            L[i] = i - 1;
            R[i] = i + 1;
        }
        R[m] = 0;
        L[0] = m;
        size = m;
        for(int i = 1; i <= n; i++)
            H[i] = -1;
    }

    void Link(int r, int c)
    {
        ++S[col[++size] = c];
        row[size] = r;
        D[size] = D[c];
        U[D[c]] = size;
        U[size] = c;
        D[c] = size;
        if(H[r] < 0) H[r] = L[size] = R[size] = size;
        else
        {
            R[size] = R[H[r]];
            L[R[H[r]]] = size;
            L[size] = H[r];
            R[H[r]] = size;
        }
    }

    void remove(int c)
    {
        for(int i = D[c]; i != c; i = D[i])
        {
            L[R[i]] = L[i];
            R[L[i]] = R[i];
        }
    }

    void resume(int c)
    {
        for(int i = U[c]; i != c; i = U[i])
            L[R[i]] = R[L[i]] = i;
    }

    bool v[MAXNODE];

    int f()
    {
        int ret = 0;
        for(int c = R[0]; c != 0; c = R[c]) v[c] = true;
        for(int c = R[0]; c != 0; c = R[c])
        {
            if(v[c])
            {
                ret++;
                v[c] = false;
                for(int i = D[c]; i != c; i = D[i])
                    for(int j = R[i]; j != i; j = R[j])
                        v[col[j]] = false;
            }
        }
        return ret;
    }

    bool Dance(int d)
    {
        if(d + f() > K) return false;
        if(R[0] == 0)
        {
            return d <= K;
        }
        int c = R[0];
        for(int i = R[0]; i != 0; i = R[i])
        {
            if(S[i] < S[c])
                c = i;
        }
        for(int i = D[c]; i != c; i = D[i])
        {
            remove(i);
            for(int j = R[i]; j != i; j = R[j]) remove(j);
            ans[d] = row[i];
            if (Dance(d + 1)) return true;
            for(int j = L[i]; j != i; j = L[j]) resume(j);
            resume(i);
        }
        return false;
    }
} gao;

typedef long long ll;

int T, n;

const int N = 65;

struct City
{
    ll x, y;
    void read()
    {
        scanf("%I64d%I64d", &x, &y);
    }
} c[N];

ll dis(City a, City b)
{
    ll dx = a.x - b.x;
    if (dx < 0) dx = -dx;
    ll dy = a.y - b.y;
    if (dy < 0) dy = -dy;
    return dx + dy;
}

int main()
{
    int cas = 0;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &K);
        for (int i = 1; i <= n; i++) c[i].read();
        ll l = 0, r = 100000000000LL;
        while (l < r)
        {
            ll mid = (l + r) / 2;
            gao.init(n, n);
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (dis(c[i], c[j]) <= mid)
                        gao.Link(i, j);
                }
            }
            if (gao.Dance(0)) r = mid;
            else l = mid + 1;
        }
        printf("Case #%d: %I64d\n", ++cas, l);
    }
    return 0;
}
