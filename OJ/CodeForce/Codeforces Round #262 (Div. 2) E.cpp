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

struct Node
{
    int x,y,z;
}p[300];
int xt[300],yt[300],xa[300],ya[300];
int d,n,r,maxi;
bool cmp(Node a,Node b)
{
    return a.z>b.z;
}

void dfs(int l,int cnt)
{
    int i,j;
    if(cnt==n)
    {
        int x=0;

        for(i=0; i<cnt; i++)
            for(j=i+1; j<cnt; j++)
                x+=(xt[i]-xt[j])*(xt[i]-xt[j])+(yt[i]-yt[j])*(yt[i]-yt[j]);

        if(x>maxi)
        {
            maxi=x;
            for(i=0; i<cnt; i++)
            {
                xa[i]=xt[i];
                ya[i]=yt[i];
            }
        }
        return;
    }

    for(i=l; i<d; i++)
    {
        xt[cnt]=p[i].x;
        yt[cnt]=p[i].y;
        dfs(i,cnt+1);
    }
}

int main()
{
    while(read(n)&&read(r))
    {
        int i,j;
        CLR(p,0);
        d=0;
        maxi=0;
        int rm=r*r;
        int rs=(r-1)*(r-1);
        for(i=-r; i<=r; i++)
            for(j=-r; j<=r; j++)
            {
                int x=i*i+j*j;
                if(x<=rm&&x>rs)
                {
                    p[d].x=i;
                    p[d].y=j;
                    p[d++].z=x;
                }
            }
        sort(p,p+d,cmp);
        d=17;//d=30-2*n;
        dfs(0,0);

        printf("%d\n",maxi);
        for(i=0; i<n; i++)
            printf("%d %d\n",xa[i],ya[i]);
    }
    return 0;
}
