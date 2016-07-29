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


int main()
{
	int x,y;
	while(read(x)&&read(y))
	{
		if(x>y)
		{
			puts("-1");
			continue;
		}
		int cnt=x-1;		// 最少加的次数
		double k=(1.0*y+1.0-eps)/(double)x; // 预先处理的系数
		double temp=1.0;
		for(int i=1;i<=x;i++)		// i 表示数量 
		{
			double t=i*k;			// 数量为 i 时候单价上限 
			int u=t-temp;			// 单价最多增加的值
			temp+=u;
			temp*=(1.0*i+1.0)/i;	// 总价增加 
			cnt+=u; 
		}
		write(cnt),putchar('\n');
	}
	return 0;
}
