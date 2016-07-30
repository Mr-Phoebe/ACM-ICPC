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
#define eps 1e-9
#define INF INT_MAX

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
char Map[2010][2010];

const int MAXN = 2000*2000+10;

int Top_Edge = -1;

struct N
{
    int v,next;
}Edge[MAXN];

int head[MAXN];

void link(int u,int v)
{
    Edge[++Top_Edge].v = v;
    Edge[Top_Edge].next = head[u];
    head[u] = Top_Edge;
}

bool id[MAXN],od[MAXN],mv[MAXN];

int Ans = 0,MaxDepth = -1;

int dfs(int s,int h)
{
    mv[s] = true;

    int TD,MD = 1,ans = 0;

    for(int p = head[s]; p != -1; p = Edge[p].next)
    {
        if(mv[Edge[p].v] == false)
        {
            TD = dfs(Edge[p].v,h+1);
            if(TD+1 > MD)
            {
                MD = TD+1;
                ans = 1;
            }
            else if(TD+1 == MD)
                ans++;
        }
        else
            return -1;
    }


    while(h==1 && ans--)
        if(MD > MaxDepth)
        {
            MaxDepth = MD;
            Ans = 1;
        }
        else if(MD == MaxDepth)
            Ans++;

    return MD;
}

int main()
{
    int top,n,m,i,j,ans = 0;
    read(n),read(m);
    for(i = 1;i <= n; ++i)
       gets(Map[i]+1);

    top = n*m;

    memset(id,false,sizeof(bool)*(top+2));
    memset(od,false,sizeof(bool)*(top+2));
    memset(mv,false,sizeof(bool)*(top+2));
    memset(head,-1,sizeof(int)*(top+2));

    for(i = 1;i <= n; ++i)
    {
        for(j = 1;j <= m; ++j)
        {
            if(Map[i][j] == '>')
            {
                ans++;
                link((i-1)*m+j+1,(i-1)*m+j);
                od[(i-1)*m+j+1] = true;
                id[(i-1)*m+j] = true;
            }
            else if(Map[i][j] == '<')
            {
                ans++;
                link((i-1)*m+j-1,(i-1)*m+j);
                od[(i-1)*m+j-1] = true;
                id[(i-1)*m+j] = true;
            }
            else if(Map[i][j] == '^')
            {
                ans++;
                link((i-2)*m+j,(i-1)*m+j);
                od[(i-2)*m+j] = true;
                id[(i-1)*m+j] = true;
            }
            else if(Map[i][j] == 'v')
            {
                ans++;
                link(i*m+j,(i-1)*m+j);
                od[i*m+j] = true;
                id[(i-1)*m+j] = true;
            }
        }
    }

    for(i = 1;i <= top; ++i)
    {
        if(od[i] && id[i] == false)
        {
            //cout<<i<<endl;
            dfs(i,1);
            ans++;
        }
    }

    for(i = 1;i <= top; ++i)
        if(mv[i])
            ans--;

    if(ans != 0)
        printf("-1\n");
    else
    {
        if(Ans >= 2)
            printf("%d\n",MaxDepth*2-2);
        else if(Ans == 0)
            printf("%d\n",0);
        else
            printf("%d\n",MaxDepth*2-3);
    }

    return 0;
}
