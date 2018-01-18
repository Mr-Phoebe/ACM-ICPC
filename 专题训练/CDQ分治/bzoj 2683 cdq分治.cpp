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

const int M=500500;

struct Query
{
    int x,y,type;
    //type>0 修改
    //type==-1 查询 正
    //type==-3 查询 负
    Query(int xx=0,int yy=0,int k=0):
        x(xx),y(yy),type(k) {}
} mempool[800800],*q[800800],*nq[800800];
int n,m,ans[800800];
int s[200200],top;
bool Compare(Query *q1,Query *q2)
{
    return q1->x < q2->x;
}
namespace BIT
{
    int c[M],tim[M],T;
    inline void Update(int x,int y)
    {
        for(; x<=n; x+=x&-x)
        {
            if(tim[x]!=T)
                tim[x]=T,c[x]=0;
            c[x]+=y;
        }
    }
    inline int Get_Ans(int x)
    {
        int re=0;
        for(; x; x-=x&-x)
            if(tim[x]==T)
                re+=c[x];
        return re;
    }
}
void CDQ_Divide_And_Conquer(int l,int r)
{
    using namespace BIT;
    int i,j,mid=MID(l,r);
    if(l==r)
        return ;
    int l1=l,l2=mid+1;
    for(i=l; i<=r; i++)
        if(q[i]-mempool<=mid)
            nq[l1++]=q[i];
        else
            nq[l2++]=q[i];
    memcpy(q+l,nq+l,sizeof(q[0])*(r-l+1) );
    CDQ_Divide_And_Conquer(l,mid);
    for(++T,j=l,i=mid+1; i<=r; i++)
    {
        for(; j<=mid&&q[j]->x<=q[i]->x; j++)
            if(q[j]->type>0)
                Update(q[j]->y,q[j]->type);
        if(q[i]->type<0)
            ans[q[i]-mempool]+=Get_Ans(q[i]->y)*(q[i]->type+2);
    }
    CDQ_Divide_And_Conquer(mid+1,r);
    l1=l,l2=mid+1;
    for(i=l; i<=r; i++)
    {
        if(l2>r||l1<=mid&&Compare(q[l1],q[l2]))
            nq[i]=q[l1++];
        else
            nq[i]=q[l2++];
    }
    memcpy(q+l,nq+l,sizeof(q[0])*(r-l+1) );
}
int main()
{
    int i,j,x,y,z,x1,y1,x2,y2,p;
    scanf("%d",&n);
    while(1)
    {
        scanf("%d",&p);
        if(p==1)
        {
            scanf("%d%d%d",&x,&y,&z);
            ++m,q[m]=&(mempool[m]=Query(x,y,z));
        }
        else if(p==2)
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            s[++top]=m;
            ++m,q[m]=&(mempool[m]=Query(x1-1,y1-1,-1));
            ++m,q[m]=&(mempool[m]=Query(x1-1,y2,-3));
            ++m,q[m]=&(mempool[m]=Query(x2,y1-1,-3));
            ++m,q[m]=&(mempool[m]=Query(x2,y2,-1));
        }
        else
            break;
    }
    CDQ_Divide_And_Conquer(1,m);
    for(i=1; i<=top; i++)
    {
        int temp=0;
        for(j=1; j<=4; j++)
            temp+=ans[s[i]+j];
        printf("%d\n",temp);
    }
    return 0;
}
