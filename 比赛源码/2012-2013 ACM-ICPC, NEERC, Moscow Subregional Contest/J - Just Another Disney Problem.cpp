//      whn6325689
//      Mr.Phoebe
//      http://blog.csdn.net/u013007900
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
#define debug(a) cout << #a" = " << (a) << endl;
#define debugarry(a, n) for (int i = 0; i < (n); i++) { cout << #a"[" << i << "] = " << (a)[i] << endl; }

#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define lowbit(x) (x&(-x))

#define MID(x,y) (x+((y-x)>>1))
#define ls (idx<<1)
#define rs (idx<<1|1)
#define lson ls,l,mid
#define rson rs,mid+1,r

template<class T>
inline bool read(T &n)
{
    T x = 0, tmp = 1;
    char c = getchar();
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
int n;
vector<int> ans;

bool judge(int x,int y)
{
    string str;
    cout<<1<<" "<<x<<" "<<y<<endl;
    cout.flush();
    cin>>str;
    if(str[0]=='Y') return 1;
    return 0;
}

int main()
{
	bool flag = true;
	int l, r, mid, pos, cnt;
    scanf("%d",&n);
	ans.push_back(1);
	for (int i = 2; i <= n; i++)
	{
		cnt = 0;
		l = 0; r = i-2; pos = 0;
		while (l <= r)
		{
			mid = (l+r)>>1; cnt++;
			if (cnt > 100000)
			{
				flag = false;
				break;
			}
			if (judge(ans[mid], i))
			{
				l = mid+1;
				pos = mid+1;
			}
			else r = mid-1;
		}
		if (!flag) break;
		ans.insert(ans.begin()+pos, i);
	}
	printf("0 ");
	if (flag)
	{
		for (int i = 0; i <= n-2; i++) printf("%d ", ans[i]);
		printf("%d\n", ans[n-1]);
	}
	else
	{
		for (int i = 0; i <= n-2; i++) printf("0 ");
		printf("0\n");
	}
	//system("pause");
    return 0;
}
