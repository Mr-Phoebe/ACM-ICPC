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

const int MAXN=200005;
#define lowbit(x) x&(-x)

int n,m;
int a[MAXN],b[MAXN];
int v[2*MAXN];
int C[2][MAXN*2];
map<int,int> Map;
int ansa,ansb;


void add(int* C,int x,int d)
{
    while(x<MAXN*2)
    {
        C[x]+=d;
        x+=lowbit(x);
    }
}
int sum(int* C,int x)
{
    int ret=0;
    while(x)
    {
        ret+=C[x];
        x-=lowbit(x);
    }
    return ret;
}
int main()
{
//	freopen("input.txt","r",stdin);
    read(n);
    v[0]=0;
    for(int i=1; i<=n; i++)
    {
        read(a[i]);
        v[++v[0]]=a[i];
    }
    read(m);
    for(int i=1; i<=m; i++)
    {
        read(b[i]);
        v[++v[0]]=b[i];
    }
    v[++v[0]]=0;
    int cnt=0;
    sort(v+1,v+1+v[0]);
    v[0]++;
    v[v[0]]=v[v[0]-1]+1;
//	for(int i=1;i<=v[0];i++)cout<<v[i]<<endl;
    for(int i=1; i<=v[0]; i++)
            if(!Map.count(v[i]))
                Map[v[i]]=++cnt;
    for(int i=1; i<=n; i++)
        add(C[0],Map[a[i]],1);
    for(int i=1; i<=m; i++)
        add(C[1],Map[b[i]],1);
    int ans=-INF;
    for(int i=1; i<=v[0]; i++)
    {
        int num1=sum(C[0],Map[v[i]]);
        int a=num1*2+(n-num1)*3;
        int num2=sum(C[1],Map[v[i]]);
        int b=num2*2+(m-num2)*3;
        if((a-b>ans)||(a-b==ans&&a>ansa))
        {
            ans=a-b;
            ansa=a;
            ansb=b;
        }
    }
    printf("%d:%d\n",ansa,ansb);
}
