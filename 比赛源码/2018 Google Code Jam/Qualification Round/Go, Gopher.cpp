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

const int MAXN = 1010;

bool p[MAXN][MAXN];
int num[MAXN][MAXN];
int dx[3] = {1, 0, -1};
int dy[3] = {1, 0, -1};

int main()
{
    int T, a, n, x, y;
    read(T);
    while(T--)
    {
        CLR(p, 0);
        CLR(num, 0);
        read(a);
        if(a == 20)
            n = 6;
        else
            n = 15;
        printf("%d %d\n", 2, 2);
        fflush(stdout);
        while(read(x) && read(y))
        {
            if((x == 0 && y == 0) || (x == -1 && y == -1))
                break;
            x--, y--;
            if(!p[x][y])
            {
                p[x][y] = true;
                num[x / 3][y / 3]++;
            }
            bool flag = true;
            for(int i = 0; i < n / 3 && flag; i++)
                for(int j = 0; j < n / 3 && flag; j++)
                    if(num[i][j] < 8)
                    {
                        printf("%d %d\n", i * 3 + 2, j * 3 + 2);
                        flag = false;
                    }
            for(int i = 1; i < n - 1 && flag; i++)
                for(int j = 1; j < n - 1 && flag; j++)
                {
                    int c = 0;
                    for(int k = 0; k < 3; k++)
                        for(int d = 0; d < 3; d++)
                        {
                            int xx = i + dx[k], yy = j + dy[d];
                            c += p[xx][yy];
                        }
                    if(c < 9)
                    {
                        printf("%d %d\n", i + 1, j + 1);
                        flag = false;
                    }
                }
            fflush(stdout);
        }
    }
    return 0;
}