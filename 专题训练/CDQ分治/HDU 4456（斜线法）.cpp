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

const int MAXN=80010;
const int POS=10000;

struct Node
{
	int kind,idx;
	int x,y,z;
}ask[MAXN],tmp1[MAXN],tmp2[MAXN];
int n,m;
ll ans[MAXN],c[MAXN];

bool cmp1(Node a,Node b)
{
	return a.x+a.y<=b.x+b.y;
}

bool cmp2(Node a,Node b)
{
	return a.x+a.y+a.z<=b.x+b.y+b.z;
}

bool cmp3(Node a,Node b)
{
	return a.x+a.y-a.z<=b.x+b.y-b.z;
}

void update(int i,int v)
{
	for(;i<MAXN;i+=lowbit(i))
		c[i]+=v;
}

ll getsum(int i)
{
	ll sum=0;
	for(;i>0;i-=lowbit(i))
		sum+=c[i];
	return sum;
}

void clr(int i)
{
	for(;i<MAXN;i+=lowbit(i))
		c[i]=0;
}

void cdq(int l,int r)
{
	if(l==r)	return;
	int mid=MID(l,r);
	int l1=0,l2=0;
	cdq(l,mid);
	for(int i=l;i<=r;i++)
 	{
        if(i<=mid && ask[i].kind==1) tmp1[l1++]=ask[i];
        else if(i> mid && ask[i].kind==2) tmp2[l2++]=ask[i];
    }
    sort(tmp1,tmp1+l1,cmp1);
    sort(tmp2,tmp2+l2,cmp2);
    for(int i=0,j=0;i<l2;i++)
    {
    	int lim=tmp2[i].x+tmp2[i].y+tmp2[i].z;
    	while(j<l1 && tmp1[j].x+tmp1[j].y<=lim)
    	{
	    	update(tmp1[j].x-tmp1[j].y+POS,tmp1[j].z);j++;
	    }
	    ans[tmp2[i].idx]+=getsum(tmp2[i].x-tmp2[i].y+tmp2[i].z+POS)-getsum(tmp2[i].x-tmp2[i].y-tmp2[i].z-1+POS);
    }
    for(int i=0;i<l1;i++)
    	clr(tmp1[i].x-tmp1[i].y+POS);
   	sort(tmp2,tmp2+l2,cmp3);
   	for(int i=0,j=0;i<l2;i++)
   	{
	   	int lim=tmp2[i].x+tmp2[i].y-tmp2[i].z-1;
	   	while(j<l1 && tmp1[j].x+tmp1[j].y<=lim)
	   	{
	   		update(tmp1[j].x-tmp1[j].y+POS,tmp1[j].z);j++;
	   	}
	   	ans[tmp2[i].idx]-=getsum(tmp2[i].x-tmp2[i].y+tmp2[i].z+POS)-getsum(tmp2[i].x-tmp2[i].y-tmp2[i].z-1+POS);
  	}
  	for(int i=0;i<l1;i++)
  		clr(tmp1[i].x-tmp1[i].y+POS);
	cdq(mid+1,r);
}

int main()
{
	while(read(n)&&n)
	{
		read(m);
		CLR(ans,0);CLR(c,0);
		for(int i=1;i<=m;i++)
		{
			read(ask[i].kind),read(ask[i].x),read(ask[i].y),read(ask[i].z);
			ask[i].idx=i;
		}
		cdq(1,m);
		for(int i=1;i<=m;i++)
			if(ask[i].kind==2)
				printf("%lld\n",ans[i]);
	}
	return 0;
}
