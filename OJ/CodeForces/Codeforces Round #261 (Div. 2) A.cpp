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

int main()
{
    int x1, x2, x3, x4, y1, y2, y3, y4;
    read(x1),read(y1),read(x2),read(y2);
    if(x1 == x2)
    {
        printf("%d %d %d %d\n", x1+abs(y2-y1), y1, x2+abs(y2-y1), y2);
        return 0;
    }
    else if(y1 == y2)
    {
        printf("%d %d %d %d\n", x1, y1+abs(x1-x2), x2, y2+abs(x1-x2));
        return 0;
    }
    else
    {
        if(abs(x1-x2) != abs(y1-y2))
        {
            puts("-1");
            return 0;
        }
        else
        {
            printf("%d %d %d %d\n", x1, y2, x2, y1);
            return 0;
        }
    }
    return 0;
}
