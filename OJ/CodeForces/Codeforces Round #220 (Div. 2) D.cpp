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
#define lowbit(x) (x&(-x))
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

const int MAXN=1000100;

int a[MAXN],c[MAXN];
int ans[MAXN],p[MAXN];
int n,m;

void update(int i,int v)
{
    for(; i<MAXN; i+=lowbit(i))
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
    freopen("data.txt","r",stdin);
    read(n),read(m);
    for(int i=1; i<=m; i++)
        read(a[i]);
    int len=0,tot=0,x;
    while(n--)
    {
        read(x);
        if(x<0)
        {
            if(a[1]>len)
                continue;
            int l=1,r=m,mid;
            while(l<=r)         //二分查找不能返回mid
            {
                mid=(l+r)>>1;
                if(a[mid]<=len)
                    l=mid+1;
                else
                    r=mid-1;
            }
            int po=r;
            len-=po;
            for(int i=1; i<=po; i++)
            {
                l=1,r=tot;
                while(l<=r)
                {
                    mid=(l+r)>>1;
                    if( getsum(mid) >= a[i] )
                        r=mid-1;
                    else
                        l=mid+1;
                }
                p[i]=l;
            }
            for(int i=1; i<=po; i++)
            {
                ans[p[i]]=-1;
                update(p[i],-1);
            }
        }
        else
        {
            ans[++tot]=x;
            update(tot,1);
            len++ ;
        }
    }
    if(!len)
        puts("Poor stack!");
    else
        for(int i=1; i<=tot; i++)
            if(ans[i]>=0)
                write(ans[i]);
    putchar('\n');
    return 0;
}
