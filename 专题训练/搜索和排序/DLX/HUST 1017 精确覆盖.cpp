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
const int N = 1010;
const int MaxN = 1010;
const int MaxM = 1010;
const int maxnode = MaxN*MaxM + 10;

struct DLX
{
	int n,m,size;
	int U[maxnode],D[maxnode],R[maxnode],L[maxnode],Row[maxnode],Col[maxnode];
	int H[MaxN],S[MaxM];
	int ansd,ans[MaxN];
	void init(int _n,int _m)
	{
		n = _n;
		m = _m;
		for(int i = 0;i <= m;i++)
		{
			S[i] = 0;
			U[i] = D[i] = i;
			L[i] = i-1;
			R[i] = i+1;
		}
		R[m] = 0; L[0] = m;
		size = m;
		for(int i = 1;i <= n;i++)H[i] = -1;
	}
	void Link(int r,int c)
	{
		++S[Col[++size]=c];
		Row[size] = r;
		D[size] = D[c];
		U[D[c]] = size;
		U[size] = c;
		D[c] = size;
		if(H[r] < 0)H[r] = L[size] = R[size] = size;
		else
		{
			R[size] = R[H[r]];
			L[R[H[r]]] = size;
			L[size] = H[r];
			R[H[r]] = size;
		}
	}
	void remove(int c)
	{
		L[R[c]] = L[c]; R[L[c]] = R[c];
		for(int i = D[c];i != c;i = D[i])
			for(int j = R[i];j != i;j = R[j])
			{
				U[D[j]] = U[j];
				D[U[j]] = D[j];
				--S[Col[j]];
			}
	}
	void resume(int c)
	{
		for(int i = U[c];i != c;i = U[i])
			for(int j = L[i];j != i;j = L[j])
				++S[Col[U[D[j]]=D[U[j]]=j]];
		L[R[c]] = R[L[c]] = c;
	}
	bool Dance(int d)
	{
		if(R[0] == 0)
		{
			write(d),putchar(' ');
			for(int i = 0;i < d; i++)
				write(ans[i]),putchar(" \n"[i==d-1]);
			return true;
		}
		int c = R[0];
		for(int i = R[0];i != 0;i = R[i])
			if(S[i] < S[c])
				c = i;
		remove(c);
		for(int i = D[c];i != c;i = D[i])
		{
			ans[d] = Row[i];
			for(int j = R[i];j != i;j = R[j])remove(Col[j]);
			if(Dance(d+1)) 		return true;
			for(int j = L[i];j != i;j = L[j])resume(Col[j]);
		}
		resume(c);
		return false;
	}
}dlx;

int main()
{
//	freopen("data.txt","r",stdin);
	int n,m;
	while(read(n)&&read(m))
	{
		dlx.init(n,m);
		for(int i=1,num,cc;i<=n;i++)
		{
			read(num);
			for(int j=0;j<num;j++)
			{
				read(cc);
				dlx.Link(i,cc);
			}
		}
		if(dlx.Dance(0))
			continue;
		else
			puts("NO");
	}
	return 0;
}