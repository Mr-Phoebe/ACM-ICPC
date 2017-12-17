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

const int maxn=2000800;
const int star=1000040;

char str[maxn];
int vis[maxn];
int len;

bool judge(int obs)
{
    int pos = star;
    int llef = pos,rrig = pos;
    memset(vis,0,sizeof(vis));
    vis[star] = 1;
    for(int i = 0; i < len; i++)
    {
        if(str[i] == 'R' && (pos+1 != obs)) pos++;
        if(str[i] == 'L' && (pos-1 != obs)) pos--;
        vis[pos]++;
    }
    if(vis[pos] == 1 && pos != obs)
        return 1;
    return 0;
}
int main()
{
    while(scanf("%s",str)!=EOF)
    {
        len = strlen(str);
        int pos = star;
        memset(vis,0,sizeof(vis));
        vis[star] = 1;
        int lef = star,rig = star;
        for(int i = 0; i < len; i++)
        {
            if(str[i] == 'R')   pos++;
            else pos--;
            vis[pos]++;
            if(pos > rig)    rig = pos;
            if(pos < lef)    lef = pos;
        }
        if(vis[pos] == 1)
        {
            printf("1\n");
            continue;
        }
        int ans = 0;
        int l = lef,r = star - 1;
        int ppp = star;
        while(l <= r)
        {
            int mid =l + ((r-l) >> 1);
            if(judge(mid))
            {
                ppp = mid;
                r = mid - 1;
            }
            else l = mid+1;
        }
        ans += star - ppp;
        l = star + 1,r = rig;
        int pp = star;
        while(l <= r)
        {
            int mid =l + ((r-l) >> 1);
            if(judge(mid))
            {
                pp = mid;
                l = mid+1;
            }
            else r = mid - 1;
        }
        ans += pp - star;
        write(ans);
        putchar('\n');
    }
    return 0;
}
