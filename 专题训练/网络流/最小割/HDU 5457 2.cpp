#include <bits/stdc++.h>
using namespace std ;

typedef long long LL ;

#define clr( a , x ) memset ( a , x , sizeof a )
#define cpy( a , x ) memcpy ( a , x , sizeof a )

const int MAXN = 100005 ;
const int MAXE = 200005 ;
const int INF = 0x3f3f3f3f ;

struct Edge {
    int v , c , n ;
    Edge () {}
    Edge ( int v , int c , int n ) : v ( v ) , c ( c ) , n ( n ) {}
} ;

Edge E[MAXE] ;
int H[MAXN] , cntE ;
int d[MAXN] , cur[MAXN] , pre[MAXN] , gap[MAXN] ;
int Q[MAXN] , head , tail ;
int s , t , nv ;
int flow ;
int n , m ;

int nxt[MAXN][2] ;
int cost[MAXN][2] ;
int word[MAXN][2] ;
int num[MAXN] ;
char S[MAXN] ;
int root1 , root2 ;
int P ;

void init () {
    cntE = 0 ;
    clr ( H , -1 ) ;
}

void addedge ( int u , int v , int c ) {
    E[cntE] = Edge ( v , c , H[u] ) ;
    H[u] = cntE ++ ;
    E[cntE] = Edge ( u , 0 , H[v] ) ;
    H[v] = cntE ++ ;
}

void rev_bfs () {
    head = tail = 0 ;
    clr ( d , -1 ) ;
    clr ( gap , 0 ) ;
    Q[tail ++] = t ;
    d[t] = 0 ;
    gap[0] = 1 ;
    while ( head != tail ) {
        int u = Q[head ++] ;
        for ( int i = H[u] ; ~i ; i = E[i].n ) {
            int v = E[i].v ;
            if ( ~d[v] ) continue ;
            d[v] = d[u] + 1 ;
            gap[d[v]] ++ ;
            Q[tail ++] = v ;
        }
    }
}

int isap () {
    rev_bfs () ;
    cpy ( cur , H ) ;
    flow = 0 ;
    int u = pre[s] = s , i ;
    while ( d[s] < nv ) {
        if ( u == t ) {
            int f = INF ;
            for ( i = s ; i != t ; i = E[cur[i]].v ) {
                if ( f > E[cur[i]].c ) {
                    f = E[cur[i]].c ;
                    u = i ;
                }
            }
            for ( i = s ;i != t ; i = E[cur[i]].v ) {
                E[cur[i]].c -= f ;
                E[cur[i] ^ 1].c += f ;
            }
            flow += f ;
            flow = min ( flow , INF ) ;
        }
        for ( i = cur[u] ; ~i ; i = E[i].n ) {
            if ( E[i].c && d[u] == d[E[i].v] + 1 ) break ;
        }
        if ( ~i ) {
            cur[u] = i ;
            pre[E[i].v] = u ;
            u = E[i].v ;
        } else {
            if ( 0 == -- gap[d[u]] ) break ;
            int minv = nv ;
            for ( i = H[u] ; ~i ; i = E[i].n ) {
                if ( E[i].c && minv > d[E[i].v] ) {
                    minv = d[E[i].v] ;
                    cur[u] = i ;
                }
            }
            d[u] = minv + 1 ;
            gap[d[u]] ++ ;
            u = pre[u] ;
        }
    }
    return flow ;
}

int newnode () {
    for ( int i = 0 ; i < 2 ; ++ i ) {
        nxt[P][i] = 0 ;
        cost[P][i] = INF ;
    }
    return P ++ ;
}

int insert ( char s[] , int root ) {
    int now = root ;
    for ( int i = 0 ; s[i] ; ++ i ) {
        int x = s[i] - '0' ;
        if ( nxt[now][x] == 0 ) nxt[now][x] = newnode () ;
        now = nxt[now][x] ;
    }
    return now ;
}

void update ( char s[] , int root , int w ) {
    int now = root ;
    for ( int i = 0 ; s[i] ; ++ i ) {
        int x = s[i] - '0' ;
        if ( nxt[now][x] == 0 ) return ;
        if ( s[i + 1] == 0 ) cost[now][x] = min ( cost[now][x] , w ) ;
        else now = nxt[now][x] ;
    }
}

void build1 ( int o ) {
    for ( int i = 0 ; i < 2 ; ++ i ) {
        if ( !nxt[o][i] ) continue ;
        addedge ( o , nxt[o][i] , cost[o][i] ) ;
        build1 ( nxt[o][i] ) ;
    }
}

void build2 ( int o ) {
    for ( int i = 0 ; i < 2 ; ++ i ) {
        if ( !nxt[o][i] ) continue ;
        addedge ( nxt[o][i] , o , cost[o][i] ) ;
        build2 ( nxt[o][i] ) ;
    }
}


void solve () {
    char op ;
    int w ;
    scanf ( "%d%d" , &n , &m ) ;
    init () ;
    P = 0 ;
    root1 = newnode () ;
    root2 = newnode () ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &num[i] ) ;
        int x = num[i] ;
        for ( int j = 7 ; j >= 0 ; -- j ) {
            S[j] = ( x & 1 ) + '0' ;
            x >>= 1 ;
        }
        S[8] = 0 ;
        word[i][0] = insert ( S , root1 ) ;
        cout<<word[i][0]<<endl;
        x = num[i] ;
        for ( int j = 0 ; j <= 7 ; ++ j ) {
            S[j] = ( x & 1 ) + '0' ;
            x >>= 1 ;
        }
        S[8] = 0 ;
        word[i][1] = insert ( S , root2 ) ;
        cout<<word[i][1]<<endl;
    }
    for ( int i = 0 ; i < m ; ++ i ) {
        scanf ( " %c%s%d" , &op , S , &w ) ;
        if ( op == 'S' ) {
            int l = strlen ( S ) ;
            reverse ( S , S + l ) ;
        }
        update ( S , op == 'P' ? root1 : root2 , w ) ;
    }
    s = P ;
    t = s + 1 ;
    nv = t + 1 ;
    addedge ( s , root1 , INF ) ;
    addedge ( root2 , t , INF ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        addedge ( word[i][0] , word[i][1] , INF ) ;
    }
    build1 ( root1 ) ;
    build2 ( root2 ) ;
    isap () ;
    if ( flow == INF ) printf ( "-1\n" ) ;
    else printf ( "%d\n" , flow ) ;
}

int main () {
	freopen("data.txt","r",stdin); 
	freopen("out.txt","w",stdout);
    int T ;
    scanf ( "%d" , &T ) ;
    for ( int i = 1 ; i <= T ; ++ i ) {
        printf ( "Case #%d: " , i ) ;
        solve () ;
    }
    return 0 ;
}