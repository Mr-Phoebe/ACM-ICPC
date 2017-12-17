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

#define Lowbit(x) (x&(-x)) 

const int MAX = 1010;
int c[MAX][MAX];
int n;

void Updata(int x,int y)
{
	int i,k;
	for(i=x; i<=n; i+=Lowbit(i))
		for(k=y; k<=n; k+=Lowbit(k))
			c[i][k]++;
}

int Get(int x,int y)
{
	int i,k,sum = 0;
	for(i=x; i>0; i-=Lowbit(i))
		for(k=y; k>0; k-=Lowbit(k))
			sum += c[i][k];
	return sum;
}

int main()
{
	int ncases,m;
	int x1,y1,x2,y2;
	char ch[2];
	scanf("%d",&ncases);
	while( ncases-- )
	{
		memset(c,0,sizeof(c));
		scanf("%d%d",&n,&m);
		while( m-- )
		{
			scanf("%s",ch);
			if( ch[0] == 'C' )
			{
				read(x1),read(y1),read(x2),read(y2);
				x1++; y1++; x2++; y2++;
				Updata(x2,y2);
				Updata(x1-1,y1-1);
				Updata(x1-1,y2);
				Updata(x2,y1-1);
			}
			else
			{
				read(x1),read(y1);
				write(Get(x1,y1)%2),putchar('\n');
			}
		}
		putchar('\n');
	}
	return 0;
}
