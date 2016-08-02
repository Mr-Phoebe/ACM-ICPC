
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
#include <ctime>
#include <set>
#include <map>
#include <cmath>
#include <functional>
#include <numeric>
#pragma comment(linker, "/STACK:1024000000,1024000000")


using namespace std;

#define eps 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LLINF 1LL<<62
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

struct gtr
{
    ll x;
    int y;
    const bool operator<(const gtr &b) const
    {
        return x > b.x || (x == b.x && y > b.y);
    }

    const bool operator==(const gtr &b) const
    {
        return x == b.x && y == b.y;
    }

    gtr(ll x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

set<gtr> ss;

struct gtr2
{
    int a, b;
    ll c;
    gtr2(int a, int b, ll c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

vector<gtr2> dhvan;

bool cmp(const gtr2 &a, const gtr2 &b)
{
    return a.a < b.a || (a.a == b.a && a.b < b.b);
}

int prevv[100100];
int root;
int nextt[100100];
int n;
ll a[100100];

void rem(int i)
{
    if(prevv[i] == -1)
    {
        root = nextt[i];
        prevv[root] = -1;
    }
    else
    {
        nextt[prevv[i]] = nextt[i];
        prevv[nextt[i]] = prevv[i];
    }
}

ll sum = 0;

int main()
{
    freopen("magic.in", "r", stdin);
    freopen("magic.out", "w", stdout);
    scanf("%d", &n);
    root = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i]);
        ss.insert(gtr(a[i], i));
        sum += a[i];
        nextt[i] = i + 1;
        prevv[i] = i - 1;
    }
    nextt[n - 1] = -1;
    prevv[0] = -1;

    //solve

    int fir = 0;
    int sec = 1;
    int th = 0;
    int aaaa;
    while(true)
    {
        set<gtr>::iterator it = ss.begin();
        if(fir == -1 || nextt[fir] == -1)
        {
            th = -1;
            break;
        }
        if(it->x * 2 >= sum)
        {
            th = 1;
            break;
        }
        //cout << ss.size() << " " << ss.begin()->x << endl;
        if(it->y == fir || it->y == sec)
            it++;
        if(it->y == fir || it->y == sec)
            it++;
        if(it == ss.end())
        {
            th = 2;
            break;
        }

        ll aaa = it->x;
        if(sum > 2*aaa)
        {
            ll bb = sum - 2 * aaa;
            bb = (bb + 1) / 2;
            if(bb > a[fir] || bb > a[sec])
                bb = min(a[fir], a[sec]);
            ll a1 = a[fir], a2 = a[sec];
            a[fir] -= bb;
            a[sec] -= bb;
            ss.erase(ss.find(gtr(a1, fir)));
            ss.erase(ss.find(gtr(a2, sec)));
            dhvan.push_back(gtr2(fir, sec, bb));
            sum -= 2 * bb;
            if(a[fir] == 0 && a[sec] > 0)
            {
                ss.insert(gtr(a[sec], sec));
                rem(fir);
                fir = root;
                sec = nextt[fir];

            }
            else if(a[fir] > 0 && a[sec] == 0)
            {
                ss.insert(gtr(a[fir], fir));
                rem(sec);
                sec = nextt[sec];

            }
            else if(a[fir] == 0 && a[sec] == 0)
            {
                rem(fir);
                rem(sec);
                fir = root;
                if(fir != -1)
                    sec = nextt[fir];
            }
        }
    }

    if(th == 1)
    {
        ll mmax = -1;
        int vt;
        for(int i = 0; i < n; i++)
            if(a[i] > mmax)
            {
                mmax = a[i];
                vt = i;
            }
        for(int i = 0; i < n; i++)
            if(i != vt && a[i] > 0)
            {
                if(i < vt)
                    dhvan.push_back(gtr2(i, vt, a[i]));
                else dhvan.push_back(gtr2(vt, i, a[i]));
            }
    }
    else if(th == 2)
    {
        int vt1, vt2;
        for(vt1 = 0; vt1 < n; vt1++)
            if(a[vt1] > 0)
                break;
        for(vt2 = n - 1; vt2 >= 0; vt2--)
            if(a[vt2] > 0)
                break;
        ll mmin = min(a[vt1], a[vt2]);
        dhvan.push_back(gtr2(vt1, vt2, mmin));
    }
    sort(dhvan.begin(), dhvan.end(), cmp);
    printf("%d\n", dhvan.size());
    for(int i = 0; i < dhvan.size(); i++)
        printf("%d %d %I64d\n", dhvan[i].a + 1, dhvan[i].b + 1, dhvan[i].c);

}
