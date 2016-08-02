//      whn6325689
//		Mr.Phoebe
//		http://blog.csdn.net/u013007900
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
#include <functional>
#include <numeric>
#pragma comment(linker, "/STACK:1024000000,1024000000")


using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;

#define CLR(x,y) memset(x,y,sizeof(x))
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define lowbit(x) (x&(-x))
#define MID(x,y) (x+((y-x)>>1))
#define speed std::ios::sync_with_stdio(false);
#define eps 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LLINF 1LL<<62

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

int n,q,c;
double p;
bool vis[111][111][15],hsh[111];

struct Node
{
    int id,rank;
    double sc;
    Node() {}
    Node(int id,int rank,double s):id(id),rank(rank),sc(s) {}
} a[111];

int cmp1(Node a,Node b)
{
    return a.sc>b.sc;
}

int cmp2(Node a,Node b)
{
    return a.id<b.id;
}

int main()
{
    //freopen("data.txt","r",stdin);
    int T;
    read(T);
    while(T--)
    {
        scanf("%d %d %lf %d",&n,&q,&p,&c);
        for(int i=1; i<=n; i++)
            a[i]=Node(i,1,p);
        int atk,def,sev,k,x;
        while(c--)
        {
            read(k);
            CLR(vis,0);
            while(k--)
            {
                read(atk),read(def),read(sev);
                if(vis[atk][def][sev])
                    continue;
                vis[atk][def][sev]=true;
            }
            for(int i=1; i<=q; i++)
                for(int j=1; j<=n; j++)
                {
                    int cnt=0;
                    for(int k=1; k<=n; k++)
                        if(vis[k][j][i])
                            cnt++;
                    if(!cnt)    continue;
                    double ss=1.0*(n-1)/cnt;
                    a[j].sc-=(n-1);
                    for(int k=1; k<=n; k++)
                        if(vis[k][j][i])
                            a[k].sc+=ss;
                }
            for(int i=1; i<=q; i++)
            {
                CLR(hsh,false);
                int cnt=0;
                for(int j=1; j<=n; j++)
                {
                    read(x);
                    if(x)
                    {
                        hsh[j]=true;
                        cnt++;
                    }
                    else
                    {
                        hsh[j]=false;
                        a[j].sc-=(n-1);
                    }
                }
                if(cnt==n) continue;
                double ss=1.0*(n-1)/cnt;
                ss*=(n-cnt);
                for(int j=1; j<=n; j++)
                    if(hsh[j])
                        a[j].sc+=ss;
            }
            sort(a+1,a+n+1,cmp1);
            a[1].rank=1;
            for(int i=2; i<=n; i++)
                if(abs(a[i].sc-a[i-1].sc)<eps)
                    a[i].rank=a[i-1].rank;
                else
                    a[i].rank=i;
            sort(a+1,a+n+1,cmp2);
            read(k);
            while(k--)
            {
                read(x);
                printf("%f %d\n",a[x].sc,a[x].rank);
            }
        }
    }
    return 0;
}
