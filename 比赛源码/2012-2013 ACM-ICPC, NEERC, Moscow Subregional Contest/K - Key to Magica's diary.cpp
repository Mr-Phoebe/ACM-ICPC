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

set<string> m;
string str[4005];
ll tot=0;
map<string,ll> cnt;
map<pair<string,string>,ll> cntp;
string pre,now;
int main()
{
//freopen("data.txt","r",stdin);
    speed
    int n,k,q;
    cin>>n;getline(cin,now);
    for(int i=1;i<=n;i++)
    {
        getline(cin,str[i]);
        for(int j=0;j<str[i].length();j++)
        {
            if('A'<=str[i][j] && str[i][j]<='Z')
                str[i][j]-='A'-'a';
            if(!(str[i][j]>='a'&&str[i][j]<='z'))
                str[i][j]=' ';
        }
    }
    cin>>k;
    while(k--)
    {
        cin>>now;
        m.insert(now);
    }
    stringstream ss;
    bool first=1;
    for(int i=1;i<=n;i++)
    {
        ss.str(str[i]);
        while(ss>>now)
        {
            if(m.find(now)==m.end())
            {
                tot++;
                cnt[now]++;
                if(first)
                    first=0;
                else
                {
                    cntp[mp(pre,now)]++;
                    cntp[mp(now,pre)]++;
                }
                pre=now;
            }
        }
        ss.clear();
    }
    cin>>q;
    while(q--)
    {
        cin>>pre>>now;
        if(cntp.find(mp(pre,now))!=cntp.end())
        {
            double ans=1.0*tot*tot*(cntp[mp(pre,now)])/(1.0*cnt[pre]*cnt[now]*(tot-1));
            if(pre==now)    ans/=2.0;
            cout<<setiosflags(ios::fixed)<<setprecision(10)<<ans<<endl;
        }
        else
            cout<<"0.0000000000"<<endl;
    }
    return 0;
}
