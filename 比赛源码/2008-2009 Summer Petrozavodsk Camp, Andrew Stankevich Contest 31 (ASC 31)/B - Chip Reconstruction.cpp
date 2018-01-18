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

int a[555],rest[555];
int bot,quant;
int bot2,quant2;
char result[555][555];

struct Line
{
    int num,idx;
    void input(int i)
    {
        read(num);
        idx=i;
    }
    bool operator < (const Line& b) const
    {
        return num<b.num;
    }
};
priority_queue<Line> b;
queue<Line> que;

int main()
{
freopen("chip.in","r",stdin);
freopen("chip.out","w",stdout);

    int n,m,h;
    while(read(m)&&read(n)&&read(h))
    {
        while(!b.empty())   b.pop();
        while(!que.empty()) que.pop();
        bot=0;
        for(int i=0; i<m; i++)
        {
            read(a[i]);
            bot+=a[i];
            rest[i]=n-a[i];
        }

        quant=0;
        for(int i=0; i<n; i++)
        {
            Line temp;
            temp.input(i);
            if(temp.num!=0) b.push(temp);
            quant+=temp.num;
        }
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                result[i][j]='*';
        bot2=m*n;
        bool inConsistent=false;
        quant2=0;
        for(int i=0; i<m && !inConsistent; i++)
        {
            while(rest[i]>0)
            {
                if(i+h-1>=m || b.empty())
                {
                    inConsistent=true;
                    break;
                }
                Line cur=b.top();b.pop();
                while(result[i][cur.idx]=='+' || result[i][cur.idx]=='|')
                {
                    if(b.empty())
                    {
                        inConsistent=true;
                        break;
                    }
                    que.push(cur);
                    cur=b.top();b.pop();
                }
                if(!inConsistent)
                {
                    for(int j=i; j<i+h; j++)
                    {
                        if(j==i) 			result[j][cur.idx] ='+';
                        else if(j==i+h-1) 	result[j][cur.idx] ='+';
                        else				result[j][cur.idx] ='|';
                        bot2--;
                        rest[j]--;
                    }
                    quant2++;
                    cur.num--;
                    if(cur.num!=0) b.push(cur);
                    while(!que.empty())
                    {
                        b.push(que.front());
                        que.pop();
                    }
                }
                else
                    break;
            }
        }
        if(inConsistent || bot!=bot2 || quant!=quant2 || (h*quant+bot)!=m*n)
        {
            puts("inconsistent");
        }
        else
        {
            for(int i=0; i<m; i++)
            {
                for(int j=0; j<n; j++)
                    putchar(result[i][j]);
                putchar('\n');
            }
        }
    }
    return 0;
}
