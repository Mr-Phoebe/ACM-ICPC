//By LH
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

#define eps 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LLINF 1LL<<62
#define speed std::ios::sync_with_stdio(false);

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef vector<int> vi;

#define CLR(x,y) memset(x,y,sizeof(x))
#define CPY(x,y) memcpy(x,y,sizeof(x))
#define clr(a,x,size) memset(a,x,sizeof(a[0])*(size))
#define cpy(a,x,size) memcpy(a,x,sizeof(a[0])*(size))

#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define lowbit(x) (x&(-x))

#define MID(x,y) (x+((y-x)>>1))
#define ls (idx<<1)
#define rs (idx<<1|1)
#define lson ls,l,mid
#define rson rs,mid+1,r
#define root 1,1,n

template<class T>
inline bool read(T &n)
{
    T x = 0, mmp = 1;
    char c = getchar();
    while((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();
    if(c == EOF) return false;
    if(c == '-') c = getchar(), mmp = -1;
    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c = getchar();
    n = x*mmp;
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
int n, m, nn, mm, ans;

int main()
{
	scanf("%d%d%d%d", &n, &m, &nn, &mm);
	if (n <= nn && m <= mm) ans = 1;
	else if (n > nn && m <= mm)
	{
		if (n % nn == 0) ans = n/nn;
		else ans = n/nn+1;
	}
	else if (n <= nn && m > mm)
	{
		if (m % mm == 0) ans = m/mm;
		else ans = m/mm+1;
	}
	else
	{
		ans = (n/nn)*(m/mm);
		if (n%nn == 0 && m%mm != 0)
		{
			int leave = m%mm, num, need;
			num = mm/leave; need = n/nn;
			if (need%num == 0) ans += need/num;
			else ans +=(need/num+1);
		}
		else if (n%nn != 0 && m%mm == 0)
		{
			int leave = n%nn, num, need;
			num = nn/leave; need = m/mm;
			if (need%num == 0) ans += need/num;
			else ans +=(need/num+1);
		}
		else if (n%nn != 0 && m%mm != 0)
		{
			int leave1 = n%nn, leave2 = m%mm, num1, num2, need1, need2;
			bool flag = false;
			num1 = nn/leave1; need1 = m/mm;
			num2 = mm/leave2; need2 = n/nn;
			if (need1%num1 == 0) ans += need1/num1;
			else
			{
				ans +=(need1/num1+1);
				flag = true;
			}
			if (need2%num2 == 0) ans += need2/num2;
			else
			{
				ans +=(need2/num2+1);
				flag = true;
			}
			if (!flag) ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
