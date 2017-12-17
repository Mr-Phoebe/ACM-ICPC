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
#define LLINF 1LL<<62

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



const int maxn = 51111 ;
int f[maxn] , n , m , num[maxn] ;

struct Edge
{
    int t , next , v ;
} edge[maxn<<1] ;
int head[maxn] , tot ;

struct Deque
{
    int val[2][maxn], pos[2][maxn];
    int star[2] , tail[2] ;
    void init ()
    {
        star[0] = 1 ;
        tail[0] = 0 ;
        star[1] = 1 ;
        tail[1] = 0 ;
    }
    int judge (int c, int v)
    {
        return c ^ (val[c][tail[c]] < v);
    }
    void push (int id, int v)
    {
        int i ;
        for ( i = 0 ; i < 2 ; i ++ )
        {
            while ( star[i] <= tail[i] && judge ( i , v ) )
                tail[i] -- ;
            val[i][++tail[i]] = v ;
            pos[i][tail[i]] = id ;
        }
    }
    void pop ( int c )
    {
        if ( star[c] <= tail[c] ) star[c] ++ ;
    }
    int gao ( int k , int last )
    {
        while ( val[0][star[0]] - val[1][star[1]] > k )
        {
            if ( pos[1][star[1]] < pos[0][star[0]] )
            {
                last = pos[1][star[1]] ;
                pop ( 1 ) ;
            }
            else if ( pos[1][star[1]] == pos[0][star[0]] )
            {
                last = pos[1][star[1]] ;
                pop ( 1 ) ;
                pop ( 0 ) ;
            }
            else
            {
                last = pos[0][star[0]] ;
                pop ( 0 ) ;
            }
        }
        return last ;
    }
} q ;

void new_edge ( int a , int b , int c )
{
    edge[tot].t = b ;
    edge[tot].next = head[a] ;
    edge[tot].v = c ;
    head[a] = tot ++ ;
}

int mx ;
int rt ;

void dfs ( int u , int fa , int cnt )
{
    if ( cnt >= mx )
    {
        rt = u ;
        mx = cnt ;
    }
    int i ;
    for ( i = head[u] ; i != -1 ; i = edge[i].next )
    {
        int v = edge[i].t ;
        if ( v == fa ) continue ;
        dfs ( v , u , cnt + edge[i].v ) ;
    }
}

void dfs1 ( int u , int fa , int cnt )
{
    int i ;
    for ( i = head[u] ; i != -1 ; i = edge[i].next )
    {
        int v = edge[i].t ;
        if ( v == fa ) continue ;
        num[v] = max ( num[v] , cnt + edge[i].v ) ;
        dfs1 ( v , u , cnt + edge[i].v ) ;
    }
}


int main ()
{
    int i , j ;
    while ( read(n) && read(m) && ( n + m ))
    {
        tot = 0 ;
        CLR ( head , -1 ) ;
        CLR ( num , -1 ) ;
        for ( i = 1 ; i < n ; i ++ )
        {
            int a , b , c ;
            read(a) , read(b) , read(c) ;
            new_edge ( a , b , c ) ;
            new_edge ( b , a , c ) ;
        }
        mx = 0 ;
        dfs ( 1 , 0 , 0 ) ;
        dfs1 ( rt , 0 , 0 ) ;
        int k = 1 ;
        for ( i = 1 ; i <= n ; i ++ )
            if ( num[i] > num[k] )
                k = i ;
        dfs1 ( k , 0 , 0 ) ;
        while ( m -- )
        {
            int k ;
            q.init () ;
            read(k) ;
            int ans = 0 ;
            int last = 0 ;
            for ( i = 1 ; i <= n ; i ++ )
            {
                q.push ( i , num[i] ) ;
                last = q.gao ( k , last ) ;
                ans = max ( ans , i - last ) ;
            }
            write(ans) , putchar ('\n') ;
        }
    }
    return 0 ;
}
