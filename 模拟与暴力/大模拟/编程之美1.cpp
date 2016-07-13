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
#define speed std::ios::sync_with_stdio(false);
#define eps 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LLINF 1LL<<62

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

char mon[12];
char monc[12][12]= {"January","February"};
int day;
ll year;
ll conv()
{
    int ans=year+1;
    if(strcmp(monc[0],mon)==0||strcmp(monc[1],mon)==0)
    {
        ans--;
    }
    return ans;
}
bool isgapyear(ll ayear)
{
    return ayear%4==0&&(ayear%100!=0||ayear%400==0);
}
int main()
{
    int T;
    cin>>T;
    for(int ti=1; ti<=T; ti++)
    {
        char ch;
        cin>>mon>>day>>ch>>year;
        ll syear=conv();
        cin>>mon>>day>>ch>>year;
        ll eyear=conv();
        if(day!=29||strcmp(mon,monc[1])!=0)eyear--;
        ll ans=0;
        if(syear<=eyear)
        {
            syear=syear+(syear%4==0?0:4-syear%4);
            eyear=eyear-eyear%4;
            ans=(eyear-syear)/4+1-eyear/100+syear/100-(syear%100==0?1:0)+eyear/400-syear/400+(syear%400==0?1:0);
        }
        cout<<"Case #"<<ti<<": "<<ans<<endl;
    }
    return 0;
}
