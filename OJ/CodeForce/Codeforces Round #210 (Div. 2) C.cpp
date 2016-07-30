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

const int MAXN=5010;

int a[MAXN],t[MAXN],l[MAXN],r[MAXN],s[MAXN],d[MAXN];
int n,m;

bool judge()
{
    for(int i=0;i<m;i++)
    {
        if(t[i]==1)
            for(int j=l[i];j<=r[i];j++)
                a[j]+=d[i];
        else
        {
            int maxx=a[l[i]];
            for(int j=l[i]+1;j<=r[i];j++)
                maxx=max(maxx,a[j]);
            if(d[i]!=maxx)
                return false;
        }
    }
    return true;
}

int main()
{
    read(n),read(m);
    for(int i=1;i<=n;i++)
        a[i]=1000000000;
    for(int i=0;i<m;i++)
    {
        read(t[i]),read(l[i]),read(r[i]),read(d[i]);
        if(t[i]==1)
            for(int j=l[i];j<=r[i];j++)
                s[j]+=d[i];
        else
            for(int j=l[i];j<=r[i];j++)
                a[j]=min(a[j],d[i]-s[j]);
    }
    memcpy(s,a,sizeof(a));
    if(judge())
    {
        puts("YES");
        for(int i=1;i<=n;i++)
            write(s[i]),putchar(' ');
        putchar('\n');
    }
    else
        puts("NO");
    return 0;
}
