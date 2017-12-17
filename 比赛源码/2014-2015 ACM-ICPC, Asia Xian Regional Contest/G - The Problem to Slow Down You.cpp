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

#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define lowbit(x) (x&(-x))

#define MID(x,y) (x+((y-x)>>1))
#define ls (idx<<1)
#define rs (idx<<1|1)
#define lson ls,l,mid
#define rson rs,mid+1,r
#define root 1,1,n

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

const int MAXN = 200005 ;
const int N = 26 ;

struct Palindromic_Tree {
    int next[MAXN][N] ;
    int fail[MAXN] ;
    int cnt[MAXN] ;
    int len[MAXN] ;
    int S[MAXN] , n ;
    int last ;
    int p ;

    int newnode ( int l ) {
        for(int i = 0;i < N; i++) next[p][i] = 0 ;
        cnt[p] = 0 ;
        len[p] = l ;
        return p ++ ;
    }

    void init () {
        p = 0 ;
        newnode (  0 ) ;
        newnode ( -1 ) ;
        last = 0 ;
        n = 0 ;
        S[n] = -1 ;
        fail[0] = 1 ;
    }

    int get_fail ( int x ) {
        while ( S[n - len[x] - 1] != S[n] ) x = fail[x] ;
        return x ;
    }

    void add ( int c ) {
        c -= 'a' ;
        S[++ n] = c ;
        int cur = get_fail ( last ) ;
        if ( !next[cur][c] ) {
            int now = newnode ( len[cur] + 2 ) ;
            fail[now] = next[get_fail ( fail[cur] )][c] ;
            next[cur][c] = now ;
        }
        last = next[cur][c] ;
        cnt[last] ++ ;
    }

    void count () {
        for(int i = p-1; i >= 0; i-- ) cnt[fail[i]] += cnt[i] ;
    }
} ;

Palindromic_Tree T1 , T2 ;
char s1[MAXN] , s2[MAXN] ;
int n1 , n2 ;
ll ans ;

void dfs(int u,int v)
{
    for(int i=0;i<26;i++)
	{
        int x=T1.next[u][i],y=T2.next[v][i];
        if (x&&y)
		{
            ans+=(ll)T1.cnt[x]*T2.cnt[y];
            dfs(x,y);
        }
    }
}

void solve () {

}

int main()
{
    int T,cas=1;
    read(T);
    while(T--)
	{
        printf("Case #%d: ",cas++) ;
        ans=0 ;
	    T1.init();T2.init();
	    scanf("%s%s",s1,s2);
	    n1=strlen(s1);
	    n2=strlen(s2);
		for(int i=0;i<n1;i++)
			T1.add(s1[i]);
		for(int i=0;i<n2;i++)
			T2.add(s2[i]);
	    T1.count();
	    T2.count();
	    dfs(0,0);
	    dfs(1,1);
	    write(ans);putchar('\n');
    }
    return 0 ;
}
