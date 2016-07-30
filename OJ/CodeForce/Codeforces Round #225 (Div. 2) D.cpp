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

const int N = 100005;

struct state
{
    int x, y;
} blo[N], rec[N], cur[N];
ll n, m ,cnt;

inline bool cmp (const state& a, const state& b)
{
    if (a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}

void init ()
{
    cin >> n >> m;

    int xx, yy;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &xx, &yy);
        blo[i].x = xx;
        blo[i].y = yy;
    }
}

bool judge ()
{
//  if (n > m) return true;

    sort(blo, blo + m, cmp);
    for(int i=0;i<m;i++)
        cout<<blo[i].x<<" "<<blo[i].y<<endl;
    cout<<endl;
    cnt = 1;
    rec[0].x = 1, rec[0].y = 1;

    for (int i = 0; i < m; i++)
    {
        if (blo[i].y != blo[i-1].y + 1)
        {
            cnt = 1;
            rec[0].y = n;
        }

        int k, tmp = 0, c = 0;
        for (k = i + 1; blo[k].y == blo[i].y; k++);
        k--;

        for (int j = i; j <= k; j++)
        {
            if (blo[j].x > tmp + 1)
            {
                cur[c].x = tmp + 1;
                cur[c].y = blo[j].x - 1;
                c++;
            }
            tmp = blo[j].x;
        }
        if (n > tmp)
        {
            cur[c].x = tmp + 1;
            cur[c].y = n;
            c++;
        }
        cout<<k<<endl;
        cout<<"cur:"<<endl;
        for(int i=0;i<c;i++)
            cout<<cur[i].x<<" "<<cur[i].y<<endl;

        int t = 0;
        for (int i = 0; i < cnt; i++)
        {
            while (cur[t].x <= rec[i].y && t < c)
            {
                if (cur[t].y >= rec[i].x)
                    cur[t].x = max(cur[t].x, rec[i].x);
                else
                    cur[t].x = cur[t].y = -1;
                t++;
            }
            if (t >= c) break;
        }

        cnt = 0;
        for (int i = 0; i < t; i++) if (cur[i].x != -1 && cur[i].y != -1)
            {
                rec[cnt].x = cur[i].x;
                rec[cnt].y = cur[i].y;
                cnt++;
            }
        cout<<"rec:"<<endl;
        for(int i=0;i<cnt;i++)
            cout<<rec[i].x<<" "<<rec[i].y<<endl;
        cout<<endl;
        if (cnt == 0) return false;
        i = k;
    }

    if (blo[m-1].y != n) return true;
    if (rec[cnt-1].y == n) return true;
    return false;
}

int main ()
{
    freopen("data.txt","r",stdin);
    init();
    if (judge()) cout << 2 * n - 2 << endl;
    else printf("-1\n");
    for(int i=0;i<cnt;i++)
        cout<<rec[i].x<<" "<<rec[i].y<<endl;
    return 0;
}
