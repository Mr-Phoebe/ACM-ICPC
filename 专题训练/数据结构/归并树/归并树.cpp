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

const int MAXN=220000;

int tree[30][MAXN],Q,N,A[MAXN];

void build(int l,int r,int p)
{
    //  printf("[%d,%d,%d]\n",l,r,p);
    if(l==r)
    {
        tree[p][l]=A[l];
        return;
    }
    int mid=l+r>>1;
    build(l,mid,p+1);
    build(mid+1,r,p+1);
    for(int i=l,j=mid+1,k=l; i<=mid||j<=r;)
    {
        while(j<=r&&(i>mid||tree[p+1][j]<=tree[p+1][i]))
        {
            tree[p][k]=tree[p+1][j];
            j++;
            k++;
        }
        tree[p][k++]=tree[p+1][i++];
    }
}

int query(int p,int l,int r,int a,int b,int k)
{
    if(a<=l&&r<=b)
    {
        if(k<=tree[p][l])
            return abs(tree[p][l]-k);
        else if(k>=tree[p][r])
            return abs(tree[p][r]-k);
        else
        {
            int pos=lower_bound(tree[p]+l,tree[p]+r+1,k)-tree[p];
            if(tree[p][pos]==k)
                return 0;
            else if(pos>l && k-tree[p][pos-1]<tree[p][pos]-k)
                return k-tree[p][pos-1];
            else
                return tree[p][pos]-k;
        }
    }
    int mid=MID(l,r);
    if(mid>=b)return query(p+1,l,mid,a,b,k);
    else if(a>mid)return query(p+1,mid+1,r,a,b,k);
    else return min(query(p+1,l,mid,a,b,k),query(p+1,mid+1,r,a,b,k));
}

int main()
{
    int T,cas=1;
    read(T);
    while(T--)
    {
        read(N),read(Q);
        for(int i=1; i<=N; i++)
            read(A[i]);
        build(1,N,1);
        printf("Case #%d:\n",cas++);
        for(int i=0,l,r,k; i<Q; i++)
        {
            read(l),read(r),read(k);
            int ans=query(1,1,N,l,r,k);
            write(ans),putchar('\n');
        }
    }
    return 0;
}
