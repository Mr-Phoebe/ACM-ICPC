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
#define pi acos(-1)
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

struct _Node
{
	int x,y;
}c[200];

int n;

int main()
{
//	freopen("data.txt","r",stdin);
	while(read(n)&&n)
	{
		for(int i=1;i<=2*n;i++)
			read(c[i].x),read(c[i].y);
		int over=0;
		for(int a=0;a<=100 && !over;a++)
			for(int b=-100;b<=100 && !over;b++)
			{
				int l=0,r=0;
				for(int i=1;i<=2*n;i++)
					if(a*c[i].x+b*c[i].y<0)
						l++;
					else if(a*c[i].x+b*c[i].y>0)
						r++;
				if(l==n && r==n)
				{
					printf("%d %d\n",a,b);
					over=1;
				}
			}
	}
	return 0; 
}