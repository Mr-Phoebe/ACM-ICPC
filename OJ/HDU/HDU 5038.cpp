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

const int maxn=1000005;
int a[maxn],s[maxn];
int fre[10001];
vector<int> ans;

int t,cas,n;
int main()
{
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        memset(fre,0,sizeof(fre));
        ans.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        int maxn=-1,num=0;
        for(int i=1;i<=n;i++)
        {
            s[i]=10000-(100-a[i])*(100-a[i]);//10000 - (100 - w)^2
            if(!fre[s[i]])
                num++;
            fre[s[i]]++;
            maxn=max(maxn,fre[s[i]]);
        }
        for(int i=0;i<=10000;i++)
            if(fre[i] == maxn)
                ans.push_back(i);
        printf("Case #%d:\n",cas);
        if(ans.size()==num && num!=1)
            puts("Bad Mushroom");
        else
        {
            cout<<ans[0];
            for(int i=1;i<ans.size();i++)
                printf(" %d",ans[i]);
            cout<<endl;
        }
    }
    return 0;
}