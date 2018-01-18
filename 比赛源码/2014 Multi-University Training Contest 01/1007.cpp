#include <iostream>
#include <cmath>
#include <cstdio>
#include <map>
#include <ctime>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <cstring>
using namespace std;

#define mp make_pair
#define pb push_back
#define lson(x) ((x)<<1)
#define rson(x) ((x)<<1|1)

typedef double db;
typedef long long LL ;

const int P = 1000000007 ;
const int MAXN = 10001 ;
const int MAXLEN = 220;
const int MAXM = 10 ; // 0<=x_i<2^30

typedef short Node;
typedef pair<short,int> CNode;

CNode M[ MAXN << 2 ][ MAXLEN ];
int Mlen[ MAXN << 2 ];
int ID[ MAXN ] ;

vector< short > split( int n ) {
	int a[ MAXM ];
	vector< short > ret ;
	for(int i = 0; i < MAXM; ++ i) a[i] = ((n & (1<<i)) != 0);
	LL pre = 0;
	for(int i = MAXM - 1; i >= 0; -- i) {
		pre <<= 1;
		if( a[i]) {
			ret.pb( pre<<4|i);  // pre, len
			pre |= 1;
		}
	}
	ret.pb( pre<<4) ;
	return ret;
}

short llen ;
inline short merge( short a, short b ) {
	short ra = a&0xf, rb=b&0xf;
	short c=max( ra, rb);
	llen = min(ra,rb);
	a>>=4; b>>=4;
	a >>= (c-ra);
	b >>= (c-rb);
	return (a^b)<<4|c;
}

int a[ MAXN ];
int max_size ;

CNode tM[ MAXLEN*MAXLEN];

void merge( CNode a[], int alen,  CNode b[], int blen,
		   CNode c[], int &k){
	k = 0;
	int tlen = 0;
	for( int i = 0; i < alen; ++ i) {
		short pre = a[i].first, now ;
		LL A = a[i].second;
		for(int j = 0; j < blen; ++ j) {
			now = merge( b[j].first, pre );
			int B = b[j].second;
			tM[tlen ++] = mp( now, (A *(1<<llen)%P)*B%P);
		}
	}
	sort( tM, tM + tlen );
	for(int i=0;i<tlen;++i){
		if(!i || tM[i].first != tM[i-1].first) {
			c[k++] = tM[i];
		}else c[k-1].second = (c[k-1].second + tM[i].second)%P;
	}
}

int msz;

void build(int x, int l, int r){
	int m=(l+r)>>1;
	Mlen[x] = 0;
	if(l+1==r){
		ID[l]=x;
		vector< Node > v=split( a[l] );
		for(int i = 0; i < v.size(); ++ i) M[ x ][ Mlen[x] ++ ] = mp(v[i],1);
		msz=max(msz,Mlen[x]);
		return ;
	}
	build( lson(x), l, m);
	build( rson(x), m, r);
	
	merge( M[lson(x)], Mlen[lson(x)], M[rson(x)], Mlen[rson(x)], M[x],Mlen[x]);
	msz=max(msz,Mlen[x]);
}

LL f[ MAXN ][ 2 ][ 2 ];

LL g(int p, int b, int n , int a[]) {
	memset( f, 0, sizeof f );
	f[0][0][0]=1;
	for(int i = 0; i < n; ++ i) {
		for(int j = 0; j < 2; ++ j) for(int k = 0; k < 2; ++ k) if( f[i][j][k]) {
			if((1<<p)&a[i]) {
				// choose 1
				f[i+1][j^1][k]=(f[i+1][j^1][k]+f[i][j][k]*(a[i]+1-(1<<p)))%P;
				// not choose 1
				
				if(!k) f[i+1][j][1]=(f[i+1][j][1] + f[i][j][k]) % P;
				else f[i+1][j][1] = (f[i+1][j][1] + f[i][j][k]*(1<<p))%P;
			}else {
				f[i+1][j][k]=(f[i+1][j][k]+f[i][j][k]*(a[i]+1))%P;
			}
		}
	}
	return f[ n ][ b ][ 1 ];
}

int solve(int a[], int n, int k){
	LL ans = 0;
	for(int i = MAXM - 1; i >= -1; -- i) {
   	    if(i == -1) {
			++ ans;
			break;
		}
		int b=!!(k&(1<<i));
		ans = (ans + g( i , b, n, a )) % P;
		int t=0;
		for(int j = 0; j < n; ++ j) {
			int c = !!(a[j]&(1<<i));
			t ^= c; a[j] -= c<<i;
		}
		if(t!=b) break;
	}
	return ans;
}

void update( int pos, int val ) {
	vector< Node > v=split( val);
	a[pos ] =val ;
	int x = ID[pos ];
	Mlen[ x ] = 0;
	for(int i = 0; i < v.size(); ++ i) M[ x ][ Mlen[ x ] ++ ] = mp(v[i],1);
	for(x >>= 1; x ; x >>= 1){
		merge( M[lson(x)], Mlen[lson(x)], M[rson(x)], Mlen[rson(x)], M[x],Mlen[x]);
	}
}

int count( int k) {
	LL ans = 0;
	for(int i = 0; i < MAXM; ++ i) {
		Node tar =  k<<4|i;
		int j = lower_bound( M[1], M[1] + Mlen[1],  mp(tar, -1)) - M[1];
		if( j<Mlen[1] && M[1][j].first == tar) {
			ans += M[ 1 ][ j].second;
			ans %= P;
		}
		k >>= 1;
	}
	return (int) ans;
}

void gen(int x){
    char in[55]="0.in";
    char out[55]="0.out";
    in[0]='0'+x;
    out[0]='0'+x;
     
	freopen(in,"w", stdout);
	
	int nn[] = {2,   40,50,   1000,1000,1000,    5000,7000,10000,10000};
	int mm[] = {3,   40,100,  100,500,1000,      5000,5000,6000,8000};
	
	int n, m;
	n = nn[x], m=mm[x];
	cout << n <<' ' << m << endl;
	for(int i=0;i<n;++i) printf("%d ", rand()%1001); puts("");
	while(m --) {
		int rd = rand() % 50;
		
		if(rd == 0) printf("C %d %d\n", rand()%n, rand()%1001);
		else printf("Q %d\n", rand()%1001);
	}
}

void init(){
     memset(Mlen, 0, sizeof Mlen);
     memset(ID,0,sizeof ID);
}

void RUN_STD(int x){
	int t0 = clock();
	char in[55]="0.in";
    char out[55]="0.out";
    in[0]='0'+x;
    out[0]='0'+x;
     
	//freopen(in,"r", stdin);freopen(out,"w", stdout);
	
	init();
	int n, m;
	cin >> n >> m;
	for(int i=0;i<n;++i) scanf("%d", a + i);
	build( 1, 0, n );
	for(int c=0;c<m;++c){
		char op[ 4 ];
		int a, b;
		scanf("%s", op);
		if(op[0] == 'C') {
			scanf("%d%d", &a, &b);
			update( a, b );
		}else{
			scanf("%d", &a);
			printf("%d\n", count(a) );
		}
		//cerr<<"c = " << c << endl;
	}
	//cout <<"times = " << (clock()-t0 + .0) / CLOCKS_PER_SEC << endl;
}

int arr[ MAXN ];

void RUN_BF(int x){
	int t0 = clock();
	char in[55]="0.in";
    char out[55]="0.bfout";
    in[0]='0'+x;
    out[0]='0'+x;
     
	//freopen(in,"r", stdin);freopen(out,"w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i=0;i<n;++i) scanf("%d", a + i);
	
	for(int c=0;c<m;++c){
		char op[ 4 ];
		int ia, ib;
		scanf("%s", op);
		if(op[0] == 'C') {
			scanf("%d%d", &ia, &ib);
			a[ia]=ib;
		}else{
			scanf("%d", &ia);
			for(int i=0;i<n;++i) arr[i] = a[ i ];
			printf("%d\n", solve( arr, n, ia) );
		}
		//cerr<<"c = " << c << endl;
	}
	//cout <<"times = " << (clock()-t0 + .0) / CLOCKS_PER_SEC << endl;
}

int main(){
    //freopen("xor.in","r",stdin);freopen("xor.out","w",stdout);
    //srand( time( NULL) ) ; for(int i=7;i<10;++i) gen(i); return 0;
    //for(int i=0;i<10;++i) RUN_STD( i ); return 0;
    //for(int i=0;i<10;++i) RUN_BF(i);
    
    //freopen("0.in","r",stdin);freopen("0.out","w",stdout);
    int n, m,T;
    cin >> T ;
	while(T--)
	{
		cin >> n >> m;
		for(int i=0;i<n;++i) scanf("%d", a + i);
		build( 1, 0, n );
		for(int c=0;c<m;++c){
			char op[ 4 ];
			int a, b;
			scanf("%s", op);
			if(op[0] == 'C') {
				scanf("%d%d", &a, &b);
				update( a, b );
			}else{
				scanf("%d", &a);
				printf("%d\n", count(a) );
			}
			//cerr<<"c = " << c << endl;
		}	
	}
    return 0;
}
