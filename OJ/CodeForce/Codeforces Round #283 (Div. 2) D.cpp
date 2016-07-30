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

const int MAXN=100010;

int a[MAXN],b[MAXN],tail1,tail2;
int suma[MAXN],sumb[MAXN];
int n;
vector<pii> ans;

int main()
{
	read(n);
	for(int i=1,t;i<=n;i++)
	{
		read(t);
		if(t==1)
			a[tail1++]=i;		//	 记录1 2 胜利的位置 
		else
			b[tail2++]=i;
		suma[i+1]=suma[i]+(t==1);
		sumb[i+1]=sumb[i]+(t==2);
	}
	for(int t=1;t<=n;t++)
	{
		int win1=0,win2=0;			//	赢的set取最大值，同时最后一盘需要大的那个赢
		int cnt1=1,cnt2=1;
		bool flag=true;
		for(int now=1;now<=n;now++)
		{
			int po1,po2;
			if(suma[now]+t-1>=tail1)
				po1=INF;
			else
				po1=a[suma[now]+t-1];
			if(sumb[now]+t-1>=tail2)
				po2=INF;
			else
				po2=b[sumb[now]+t-1];
			now=min(po1,po2);
//			cout<<now<<endl;
			if(now>n)
			{
				flag=0;
				break;
			}
			else if(now==n)
			{
				if(win1>win2 && po1>po2)		//	1 赢了 2 但是输了最后一次 
					flag=0;
				if(win1<win2 && po1<po2) 
					flag=0;
				break;
			}
//			cout<<win1<<" "<<win2<<endl;
			if(po1<po2)
				win1++;
			else
				win2++;
		}
		if(flag)
			ans.pb(mp(max(win1,win2)+1,t));
	}
	sort(ans.begin(),ans.end());
	write(ans.size()),putchar('\n');
	for(int i=0;i<ans.size();i++)
		write(ans[i].first),putchar(' '),write(ans[i].second),putchar('\n');
	return 0;
}