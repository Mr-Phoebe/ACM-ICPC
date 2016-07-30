#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<ctime>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define red(i, a, b) for (int i = (a); i >= (b); --i)
#define clr( x , y ) memset(x,y,sizeof(x))
#define mp make_pair
#define pb push_back
#define sqr(x) ((x) * (x))
#define x first
#define y second
typedef long long lint;
int n , M , p , q1[201000] , q2[201000];
lint ans , mm = 1000000000000000LL;
pair < int , int > a[201000];

void init()
{
    scanf("%d%d",&n,&M);
    rep(i,1,n) scanf("%d%d",&a[i].x,&a[i].y);
    a[0].x = -2;
    sort(a+1,a+n+1);
    p = a[ n - M + 1 ].x + 2;
    rep(i,1,n) q1[i] = a[i].y;
    sort(q1+1,q1+n+1);
}

void deal(int p)
{
    int x = 0 , y = 0 , s1 = 1 , s2 = 1 , m = M;
    lint sum = 0;
    rep(i,1,n) {
        if ( a[i].x == p || a[i].x == p - 1 ) q1[++x] = a[i].y;
            else q2[++y] = a[i].y;
        if ( a[i].x > p ) m --;
    }
    m --;
    if ( x - m > p ) return;
    if ( x ) sort( q1 + 1 , q1 + x + 1 );
    if ( y ) sort( q2 + 1 , q2 + y + 1 );
    rep(i,1,p) if ( i <= x - m ) sum += q1[s1++]; else {
        if ( s1 <= x && ( s2 > y || q1[s1] < q2[s2] ) ) 
            sum += q1[s1++];
        else 
            sum += q2[s2++];
    }
    if ( sum < ans ) ans = sum;
}

void work()
{
    ans = mm;
    if ( p <= n ) {
       ans = 0; 
       rep(i,1,p) ans += q1[i];
    }
    p --;
    if ( p <= n ) deal( p );
    p --;
    if ( p <= n ) deal( p );
    cout << ( ans == mm ? -1 : ans ) << endl;
}

int main()
{
    init();
    work();
    return 0;
}