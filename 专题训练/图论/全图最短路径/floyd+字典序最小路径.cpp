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



const int N = 50+10;
int path[N][N],g[N][N];
int b[N];
inline void init(int n)
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&g[i][j]);
            path[i][j]=j;
        }
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
}
inline void floyd(int n)
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
        {
            if(i==k || g[i][k]==-1) continue;
            for(int j=1;j<=n;j++)
            {
                if(i==j || j==k) continue;
                if(g[k][j]==-1)
                    continue;
                int newdis=g[i][k]+g[k][j]+b[k];
                if(g[i][j]==-1 || g[i][j]>newdis)
                {
                    g[i][j]=newdis;
                    path[i][j]=path[i][k];
                }
                else if(g[i][j]==newdis && path[i][j]>path[i][k])
                    path[i][j]=path[i][k];
            }
        }
}
inline void printpath(int s,int t)
{
    printf("Path: %d",s);
    while(path[s][t]!=t)
    {
        printf("-->%d",path[s][t]);
        s=path[s][t];
    }
    printf("-->%d\n",t);
}
int main()
{
    int n,s,t;
    while(scanf("%d",&n)==1 && n)
    {
        init(n);
        floyd(n);
        while(scanf("%d %d",&s,&t)==2)
        {
            if(s==-1 && t==-1)
                break;
            printf("From %d to %d :\n",s,t);
            if(s==t)
            {
                printf("Path: %d\n",s);
                printf("Total cost : 0\n\n");
                continue;
            }
            printpath(s,t);
            printf("Total cost : %d\n\n",g[s][t]);
        }
    }
    return 0;
}