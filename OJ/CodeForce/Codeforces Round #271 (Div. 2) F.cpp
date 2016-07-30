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

#define ls id<<1
#define rs id<<1|1

int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}

const int MAXN=100010;

int a[MAXN];
int n,q;
int minv,minn,ming;

struct Node
{
	int l,r;
	int num,minv,gc;
}t[MAXN<<2];

void build(int id,int l,int r)
{
	t[id].l=l,t[id].r=r;
	t[id].num=1;t[id].minv=t[id].gc=0;
	if(l==r)
	{
		t[id].gc=t[id].minv=a[l];
		return;
	}
	int mid=MID(l,r);
	build(ls,l,mid);
	build(rs,mid+1,r);
	if(t[ls].minv<t[rs].minv)  
    {  
        t[id].minv=t[ls].minv;  
        t[id].num=t[ls].num;  
    }  
    else if(t[ls].minv>t[rs].minv)  
    {  
        t[id].minv=t[rs].minv;  
        t[id].num=t[rs].num;  
    }  
    else  
    {  
        t[id].minv=t[ls].minv;  
        t[id].num=t[ls].num+t[rs].num;  
    }  
    t[id].gc=gcd(t[ls].gc,t[rs].gc);  
}

void query(int id,int l,int r)
{
	if(l<=t[id].l && t[id].r<=r)  
    {  
        if(minv>t[id].minv)  
        {  
           minv=t[id].minv;  
           minn=t[id].num;  
        }  
        else if(minv==t[id].minv)  
            minn+=t[id].num;   
        ming=gcd(ming,t[id].gc);
//        cout<<"("<<t[id].l<<" , "<<t[id].r<<")\n";
//        cout<<"minv: "<<minv<<" minn: "<<minn<<" ming: "<<ming<<endl; 
        return;  
    }  
    int mid=MID(t[id].l,t[id].r);  
    if(l<=mid)  
        query(ls,l,r);   
    if(r>mid)  
        query(rs,l,r);  
}

int main()
{
	int l,r;
	read(n);
	for(int i=1;i<=n;i++)
		read(a[i]);
	build(1,1,n);
	read(q);
	while(q--)
	{
		read(l),read(r);
		minv=INF;
		minn=0;
		ming=a[l];
		query(1,l,r);
		if(ming==minv)
			write(r-l+1-minn),putchar('\n');
		else
			write(r-l+1),putchar('\n');
	}
	return 0;
}