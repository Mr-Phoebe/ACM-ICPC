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
#define eps 1e-5
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


int main()
{

	double s=LLINF,a1,b1;
	double n,a,b;
	scanf("%lf %lf %lf",&n,&a,&b);
	if(a*b>=6LL*n)
	{
		cout<<(ll)(a*b)<<" "<<(ll)a<<" "<<(ll)b<<endl;
		return 0;
	}
	for(double i=a;i*i<=8*n;i++)
	{
		double t=max(floor((6*n)/i-eps)+1,b);
		if(t*i<s)
		{
			s=t*i;
			a1=i,b1=t;
		}
	}
	for(double i=b;i*i<=8*n;i++)
	{
		double t=max(floor((6*n)/i-eps)+1,a);
		if(t*i<s)
		{
			s=t*i;
			a1=t,b1=i;
		}
	}
	cout<<(ll)s<<"\n"<<(ll)a1<<" "<<(ll)b1<<endl;
	return 0;
}
