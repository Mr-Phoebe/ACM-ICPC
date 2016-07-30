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

const int MAXN=300010;
struct Node
{
	int idx;
	ll low,ans;
	bool operator < (const Node &b) const
	{
		return low<b.low;
	}
}a[MAXN];

bool cmp(Node i,Node j)
{
	return i.idx<j.idx;
}

int main()
{
	int n;
	read(n);
	for(int i=1;i<=n;i++)
	{
		read(a[i].low);a[i].idx=i;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(a[i-1].ans<a[i].low)
			a[i].ans=a[i].low;
		else
			a[i].ans=a[i-1].ans+1;
	} 
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)	
		write(a[i].ans),putchar(' ');
	putchar('\n');
	return 0;
}