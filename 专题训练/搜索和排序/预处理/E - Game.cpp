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


ll isnum,isstar;
int tot=0;
struct Node
{
    char t[3][3];
    int step;
    ll h;
    int cal()
    {
        ll l=0;
        int ret=0;
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
            {
                l=(l<<4LL)+t[i][j];
                ret=ret*10+t[i][j];
            }
        h=l;
        return ret;
    }
    bool compare()
    {
        if(((isnum^h)&isstar)==0)return true;
        return false;
    }
}q[200000];

set<int> st;

struct PPP
{
    int x,y;
} P[12][3][3];

char str[3][3][100];

int gao()
{
    char mark[10];
    for(int i=0,v; i<3; i++)
        for(int j=0; j<3; j++)
        {
            scanf("%d",&v);
            mark[v]=i*3+j;
        }
    isnum=0;
    isstar=0;
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            scanf("%s",str[i][j]);

    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
        {
            isnum<<=4;
            isstar<<=4;
            if(str[i][j][0]!='*')
            {
                isstar+=15;
                isnum+=(mark[str[i][j][0]-'0']);
            }
        }
    for(int i=0; i<tot; i++)
        if(q[i].compare())
            return q[i].step;
    return -1;
}
void solve()
{
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            q[0].t[i][j]=i*3+j;
    q[0].step=0;
    int l=0,r=1;
    st.clear();
    st.insert(q[0].cal());
    while(l<r)
    {
        for(int k=0; k<12; k++)
        {
            for(int i=0; i<3; i++)
                for(int j=0; j<3; j++)
                    q[r].t[i][j]=q[l].t[P[k][i][j].x][P[k][i][j].y];
            q[r].step=q[l].step+1;
            int tmp=q[r].cal();
            if(st.find(tmp)==st.end())
            {
                st.insert(tmp);
                r++;
            }
        }
        l++;
    }
    tot=r;
}
void init()
{
    for(int k=0; k<12; k++)
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
            {
                P[k][i][j].x=i;
                P[k][i][j].y=j;
            }
    int tot=0;
    for(int i=0; i<3; i++)
    {
        swap(P[tot][i][0],P[tot][i][2]);
        swap(P[tot][i][1],P[tot][i][2]);
        tot++;
    }
    for(int i=0; i<3; i++)
    {
        swap(P[tot][i][0],P[tot][i][2]);
        swap(P[tot][i][0],P[tot][i][1]);
        tot++;
    }

    for(int i=0; i<3; i++)
    {
        swap(P[tot][0][i],P[tot][2][i]);
        swap(P[tot][1][i],P[tot][2][i]);
        tot++;
    }
    for(int i=0; i<3; i++)
    {
        swap(P[tot][0][i],P[tot][2][i]);
        swap(P[tot][0][i],P[tot][1][i]);
        tot++;
    }
}
int main()
{
    init();
    solve();
    int T,cas=1;
    scanf("%d",&T);
    while(T--)
    {
        int ans = gao();
        printf("Case #%d: ",cas++);
        if(ans==-1)printf("No Solution!\n");
        else printf("%d\n",ans);
    }
    return 0;
}
