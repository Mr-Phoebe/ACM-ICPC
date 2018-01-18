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

char s[105];
int a[105][105];
int dx[8]= {1,0,-1,0};
int dy[8]= {0,1,0,-1};
int main()
{
    int n, m;
    read(n);
    for(int i=0; i<n; i++)
    {
        gets(s);
        for(int j=0; j<n; j++)
            a[i][j]=s[j]=='o'?1:0;
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int cnt=0;
            for(int k=0; k<4; k++)
            {
                int x=i+dx[k], y=j+dy[k];
                if(x>=0&&x<n&&y>=0&&y<n&&a[x][y]==1)
                {
                    cnt++;
                }
            }
            if(cnt&1) goto notfound;
        }
    }
    printf("YES\n");
    return 0;
notfound:
    printf("NO\n");
    return 0;
}
