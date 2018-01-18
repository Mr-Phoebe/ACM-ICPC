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
#define lowbit(x) (x)&(-x)

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

const int MAXN=200010;

struct Node
{
    int x,y;
} a[MAXN];
int c[MAXN],ans[MAXN];
int n;

void update(int i,int v)
{
    for(; i<=n; i+=lowbit(i))
        c[i]+=v;
}

int getsum(int i)
{
    int sum=0;
    for(; i>0; i-=lowbit(i))
        sum+=c[i];
    return sum;
}

int main()
{
//    freopen("data.txt","r",stdin);
    while(read(n))
    {
        for(int i=1; i<=n; i++)
            read(a[i].x),read(a[i].y);
        memset(c,0,sizeof(int)*(n+1));
        int last=0;
        for(int i=n; i>=1; i--)
        {
            int l=1,h=n,m;
            while(l<h)
            {
                m=(h+l)>>1;
                //printf("%d %d %d\n",i,mid,getsum(mid));
                if(m-getsum(m)>=a[i].x+1)
                    h=m;
                else
                    l=m+1;
            }
            ans[l]=a[i].y;
            update(l,1);
        }
        write(ans[1]);
        for(int i=2; i<=n; i++)
        {
            putchar(' ');
            write(ans[i]);
        }
        putchar('\n');
    }
    return 0;
}
