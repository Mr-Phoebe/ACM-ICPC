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
#define lowbit(x) ((x)&(-x))

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

//BY Phoebe

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
    int l,r;
    int id;
    Node(int ll=0,int rr=0,int idd=0):l(ll),r(rr),id(idd) {}
} q[MAXN];

vector<Node> a;
vector<int> g[MAXN];
int mapp[MAXN];
int n,m,ans[MAXN];
int r[MAXN],L[MAXN];

void update(int i,int k)
{
    if(i<=0)
        return;
    for(; i<MAXN; i+=lowbit(i))
        r[i]+=k;
}

int getsum(int i)
{
    int sum=0;
    for(; i>0; i-=lowbit(i))
        sum+=r[i];
    return sum;
}

int np,p[MAXN],is[MAXN];
void prime(int n)
{
    np=0;
    for(int i=2;i<n;i++)
	{
        if(is[i]) continue;
        p[np++]=i;
        for(int j=i*2; j<n; j+=i)
            is[j]=1;
    }
    is[1]=1;
}

bool cmp(Node a,Node b)
{
    if(a.r==b.r)
        return a.l<b.l;
    return a.r<b.r;
}

int main()
{
	freopen("data.txt","r",stdin);
	freopen("out1.txt","w",stdout);
    prime(MAXN);
    while(read(n)&&read(m)&&(n+m))
    {
        CLR(r,0);a.clear();
        int x;
        for(int i=1; i<=n; i++)
        {
            read(x);
            g[i].clear();
            for(int j=0; j<np; j++)
            {
                if(x%p[j] == 0)
                {
                    g[i].push_back(p[j]);
                    while(x % p[j] == 0)
                        x/=p[j];
                }
                if(!is[x])
                {
                    g[i].push_back(x);
                    break;
                }
            }
        }
        int tmp=0;
        CLR(mapp,0);
        for(int i=1; i<=n; i++)
        {
            tmp=0;
            for(int j=0; j<g[i].size(); j++)
            {
                tmp=max(tmp,mapp[g[i][j]]);
                mapp[g[i][j]]=i;
            }
            L[i]=tmp;
            a.push_back(Node(tmp,i,0));
        }
        CLR(mapp,n+1);
        for(int i=n; i>=1; i--)
        {
            tmp=n+1;
            for(int j=0; j<g[i].size(); j++)
            {
                tmp=min(tmp,mapp[g[i][j]]);
                mapp[g[i][j]]=i;
            }
            a.push_back(Node(i,tmp,1));
        }
        for(int i=1; i<=m; i++)
        {
            read(q[i].l),read(q[i].r);
            q[i].id=i;
        }
        sort(a.begin(),a.end(),cmp);
        sort(q+1,q+m+1,cmp);
        tmp=0;
        for(int i=1; i<=m; i++)
        {
            while(tmp<a.size() && a[tmp].r<=q[i].r)
            {
                update(a[tmp].l,1);
                if(a[tmp].id)
                    update(L[a[tmp].l],-1);
                tmp++;
            }
            ans[q[i].id]=q[i].r-q[i].l+1-getsum(q[i].r)+getsum(q[i].l-1);
        }
        for (int i=1; i <=m; i++)
            write(ans[i]),putchar('\n');
    }
    return 0;
}
