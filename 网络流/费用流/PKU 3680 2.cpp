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
#define CLR(x,y) memset(x,y,sizeof(x))
#define mp(x,y) make_pair(x,y)
#define eps 1e-9
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

template<class T>
inline bool read(T &n)
{
    T x = 0, tmp = 1; char c = getchar();
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


const int N=440, M=N*2;

struct Edge
{
    int t, u, c;
    Edge *next, *pair;
    Edge() {}
    Edge(int T, int U, int C, Edge* N): t(T), u(U), c(C), next(N) {}
    void* operator new(unsigned, void* p){return p;}
} *e[N], Te[M*2], *Pe;

int S, T, n, piS, cost;
bool v[N];

void addedge(int s, int t, int c, int u)
{
    e[s] = new(Pe++) Edge(t, +u, c, e[s]);
    e[t] = new(Pe++) Edge(s, -u, 0, e[t]);
    e[s]->pair = e[t];
    e[t]->pair = e[s];
}

int aug(int no, int m)
{
    if (no == T) return cost += piS * m, m;
    v[no] = true;
    int l = m;
    for (Edge *i = e[no]; i; i = i->next)
        if (i->c && !i->u && !v[i->t])
        {
            int d = aug(i->t, l < i->c ? l : i->c);
            i->c -= d, i->pair->c += d, l -= d;
            if (!l) return m;
        }
    return m - l;
}

bool modlabel()
{
    static int d[N]; memset(d, 0x3F, sizeof(d)); d[T] = 0;
    static deque<int> Q; Q.push_back(T);
    while(Q.size())
    {
        int dt, no = Q.front(); Q.pop_front();
        for(Edge *i = e[no]; i; i = i->next)
            if(i->pair->c && (dt = d[no] - i->u) < d[i->t])
                (d[i->t] = dt) <= d[Q.size() ? Q.front() : 0]
                    ? Q.push_front(i->t) : Q.push_back(i->t);
    }
    for(int i = 0; i < n; ++i)
        for(Edge *j = e[i]; j; j = j->next)
            j->u += d[j->t] - d[i];
    piS += d[S];
    return d[S] < INF;
}

int ab[N], *pab[N], w[N];

struct lt
{
    bool operator()(int* p1,int* p2) {return *p1 < *p2;}
};

int mincost_maxflow()
{
	piS = cost = 0;
	while(modlabel())
	{
		do
		{
			CLR(v,0);
		}while(aug(S, INF));
	}
    return -cost;
}

int main()
{
    int t;
    read(t);
    while(t--)
    {
        memset(e,0,sizeof(e));
        Pe = Te;
        static int m, k;
        read(m), read(k);
        int abz = 0;
        for(int i = 0; i < m; ++i)
        {
            scanf("%d", &ab[abz]),pab[abz] = &ab[abz], abz++;
            scanf("%d", &ab[abz]),pab[abz] = &ab[abz], abz++;
            scanf("%d", &w[i]);
        }
        sort(&pab[0], &pab[abz], lt());
        int c=0xDEADBEEF; n=0;
        for(int i = 0; i < abz; ++i)
        {
            if(c != *pab[i]) c = *pab[i], ++n;
            *pab[i] = n;
        }
        ++n, S = 0, T = n++;
        for(int i = 0; i < T; ++i) addedge(i, i+1, k, 0);
        for(int i = 0; i < m; ++i) addedge(ab[i+i], ab[i+i+1], 1, -w[i]);

        printf("%d\n", mincost_maxflow());
    }
    return 0;
}
