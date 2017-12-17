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
#include <cmath>
#define CLR(x,y) memset(x,y,sizeof(x))
#define mp(x,y) make_pair(x,y)
#define eps 1e-9
#define INF 0x3f3f3f3f
#define LLINF 1LL<<62

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

const int MAXN=10010;

struct DisjointSet
{
    vector<int> fa,rank;
    DisjointSet(int n):fa(n),rank(n) {}
    void clear()
    {
        rank.clear();
        for(int i=0; i<fa.size(); i++)
            fa[i]=i;
    }
    int find(int v)
    {
        return fa[v] = fa[v]==v? v:find(fa[v]);
    }

    void merge(int a,int b)
    {
        if(rank[a]<rank[b])
            fa[a]=b;
        else
        {
            fa[b]=a;
            if(rank[b]==rank[a])
                rank[a]++;
        }
    }
};

struct Point
{
    int x;
    int y;
} p[55];

struct Edge
{
    int x;
    int y;
    double value;
} e[MAXN];

DisjointSet g(MAXN);
int n,P,Q,pos;

void init(double &ans)
{
    pos=0;
    for(int i=1 ; i<n ; i++)
    {
        for(int j=i+1 ; j<=n ; j++)
        {
            double tmp=sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y));
            e[pos].x=i,e[pos].y=j;
            e[pos++].value=tmp;
            if(i==P && j==Q)
                ans=tmp;
        }
    }
}

bool cmp(Edge a, Edge b)
{
    return a.value < b.value;
}

double Kruskal()
{
    double ans=0.0;
    init(ans);
    g.clear();
    sort(e,e+pos,cmp);
    g.merge(P,Q);
    for(int i=0 ; i<pos ; i++)
    {
        int xx=g.find(e[i].x);
        int yy=g.find(e[i].y);
        if(xx!=yy)
        {
            ans+=e[i].value;
            g.merge(xx,yy);
        }
    }
    return ans;
}


int main()
{
    while(read(n) && n)
    {
        read(P),read(Q);
        if(P>Q)
            swap(P,Q);
        for(int i=1 ; i<=n ; i++)
            read(p[i].x),read(p[i].y);
        printf("%0.2f\n",Kruskal());
    }
    return 0;
}
