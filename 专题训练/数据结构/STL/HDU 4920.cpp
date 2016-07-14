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


const int MAXN=1000;
int n,A,B;
bitset <MAXN> a[3][MAXN],b[3][MAXN];

void init()
{
	for(int k=1;k<3;k++)
		for(int i=0;i<n;i++)
  			for(int j=0;j<n;j++)
			{
				a[k][i].reset(j);
				b[k][j].reset(i);
   			}
}

int main()
{
	while(read(n))
	{
		init();
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				read(A);
				A%=3;
				a[A][i].set(j);
			}
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				read(B);
				B%=3;
				b[B][j].set(i);
			}
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				int ans=0;
				ans+=(a[1][i] & b[1][j]).count();
				ans+=(a[1][i] & b[2][j]).count()*2;
				ans+=(a[2][i] & b[1][j]).count()*2;
				ans+=(a[2][i] & b[2][j]).count();
				write(ans%3);
				if(j==n-1)
					puts("");
				else
					putchar(' ');
			}
	}
	return 0;
} 