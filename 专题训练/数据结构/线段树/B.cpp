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
#define LLINF 1LL<<62

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

#define MID(l,r) (l+((r-l)>>1))

const int MAXN=500010;
int n,ans[MAXN];
int x[MAXN];

struct Node
{
    int l,r;
    int col;
} a[MAXN],t[MAXN<<1];

void build(int id,int l,int r)
{
    t[id].l=l,t[id].r=r;
    t[id].col=1;
    if(l==r)
        return;
    int mid=MID(l,r);
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
}

void update(int id,int l,int r,int v)
{
    if(t[id].l>=l && t[id].r<=r)
    {
        t[id].col=v;
        return;
    }
    if(t[id].col==v)
        return;
    if(t[id].col>=0)
    {
        t[id<<1].col=t[id<<1|1].col=t[id].col;
        t[id].col=-1;                                                   // 混杂色
    }
    int mid=MID(t[id].l,t[id].r);
    if( l <= mid )
        update(id<<1,l,r,v);
    if( r > mid )
        update(id<<1|1,l,r,v);
}

void query(int id,int l,int r)
{
    if(t[id].col>=0)
    {
        for(int i=t[id].l; i<=t[id].r; i++)
                  ans[i] = t[id].col;
        return ;
    }
    int mid=MID(t[id].l,t[id].r);
    if( l <= mid )
        query(id<<1,l,r);
    if( r > mid )
        query(id<<1|1,l,r);
}


int main()
{
    while(read(n))
    {
        CLR(t,0);
        for(int i=0; i<10000; i++)
            ans[i]=1;
        int cnt=0;
        char w;
        a[0].l=0;
        a[0].r=1000000000;
        a[0].col=1;
        x[cnt++]=a[0].l;x[cnt++]=a[0].r;
        for(int i=1; i<=n; i++)
        {
            read(a[i].l),read(a[i].r);
            w=getchar();
            x[cnt++]=a[i].l;
            x[cnt++]=a[i].r;
            if(w=='w')
                a[i].col=1;
            else
                a[i].col=0;
        }
        sort(x,x+cnt);
        cnt=unique(x,x+cnt)-x;
        int tt=cnt;
        for(int i=1;i<tt;i++)
            if(x[i]>x[i-1]+1)
                x[cnt++]=x[i-1]+1;
        sort(x,x+cnt);
        build(1,0,cnt);
        for(int i=1; i<=n; i++)
        {
            int xx=lower_bound(x,x+cnt,a[i].l)-x;
            int yy=lower_bound(x,x+cnt,a[i].r)-x;
            update(1,xx+1,yy,a[i].col);
        }
        query(1,0,cnt);
        int i=0,maxx=-1,ans_x=0,ans_y=cnt-1;
    /*
        for(int i=0;i<cnt;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
        for(int i=0;i<cnt;i++)
            cout<<x[i]<<" ";
        cout<<endl;
        */
        while(i<cnt)
        {
            if(ans[i]==1)
            {
                int j = i+1;
                while(ans[j]==1 && j<cnt)++j;
                --j;
                int ll=x[j]-x[i-1];
                if(ll > maxx)
                {
                    maxx=ll;
                    ans_x=i-1;
                    ans_y=j;
                }
                i = j;
            }
            ++i;
        }
        printf("%d %d\n",x[ans_x], x[ans_y]);
    }
    return 0;
}
