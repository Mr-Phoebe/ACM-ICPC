#include<iostream>
#include<stdio.h>
#include<set>
#include<algorithm>
#include<cmath>
#include<vector>
#include<ctime>
using namespace std;

typedef double db;
typedef long long LL;
#define pb push_back

const db EPS = 1e-8;
const int MAXN = 50015 ;
db sqr(db x){return x * x;}
inline int sign(db x) {return x < - EPS ? - 1 : x > EPS;}

inline int readT(){
    char c;
    int ret = 0,flg = 0;
    while(c = getchar(),  (c < '0' || c > '9') && c != '-');
    if(c == '-') flg = 1; else ret = c ^ 48;
    while( c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c ^ 48);
    return flg ? - ret : ret;
}

struct TCircle{
    int r,ox,oy;
    db get_y(db x,int n){
        db c = sqr((db)r) - sqr(.0+x - ox);
        return  n ? sqrt(c) + oy : - sqrt(c) + oy;
    }
    void get(){ox = readT(); oy = readT(); r = readT(); }
    bool inside( TCircle c) {
         return sign(r + sqrt(0.0+((db)ox-c.ox)*((db)ox-c.ox)+((db)oy-c.oy)*((db)oy-c.oy)) - c.r) < 0;
    }
    bool apart( TCircle c) {
         return sign(r + c.r - sqrt(0.0+((db)ox-c.ox)*((db)ox-c.ox)+((db)oy-c.oy)*((db)oy-c.oy))) < 0;
    }
    void out(){
        cout << "("<<ox<<","<<oy<<") : " << r << endl;
    }
}C[MAXN];

db now;
struct node{
    int id,ty;
    node(){}
    node(int _id,int _ty):id(_id),ty(_ty){}
    bool operator<(const node nn)const{
        db y0 = C[id].get_y(now, ty), y1 = C[ nn.id ].get_y(now, nn.ty);
        return sign(y0 - y1)>0 || (fabs(y0 - y1)<EPS && ty > nn.ty);
    }
};

struct Eve{
    int x,y,ty,id;
    Eve(){}
    Eve(int _x,int _y,int _ty,int _id):x(_x),y(_y),ty(_ty),id(_id){}
    bool operator<(const Eve e)const{
        return x < e.x || (x == e.x && y > e.y) || (x == e.x && y == e.y && ty > e.ty); //1-erase
    }
};

int root;
int n;
vector< int > e[ MAXN ];
int fa[ MAXN ];
set<node> S;
typedef set<node>::iterator IT;
vector<Eve> E;

int dfs(int x, int fa) {
	 int sg = 0;
	 for(int i=0;i<e[x].size();++i){
	 		if(e[x][i] != fa) {
	   			sg ^= (dfs( e[x][i], x ) + 1);
	   		}
	 }
	 return sg ;
}


void init(){
    S.clear();
    E.clear();
    for(int i=0;i<=n;++i) e[i].clear(), fa[i] = -1;
}

inline void add(int a, int b) {
     e[a].pb( b );
     e[b].pb( a );
}

bool get(){
    if(EOF == scanf("%d",&n)) return 0;
    for(int i = 0; i < n; ++ i) {
        C[i].get() ;
    }
    return 1;
}

void ot(int x, int f) {
    cout <<"x = " << x << endl;
    for(int i=0;i<e[x].size();++i) if( e[x][i] != f) cout << e[x][i] <<" "; cout << endl;
    for(int i=0;i<e[x].size();++i) if( e[x][i] != f) ot( e[x][i], x);
}

int rd(int m){
    return rand()%m + 1;
}
void work(){
    int i;
    init();

    for(i = 0; i < n; ++ i) {
        E.pb ( Eve(C[i].ox - C[i].r, C[i].oy, 0 , i) );
        E.pb ( Eve(C[i].ox + C[i].r, C[i].oy, 1 , i) );
    }

    sort(E.begin(), E.end() );

    root = n ; //[0..n], n is root

    for(i = 0; i < E.size(); ++ i){
        now = E[i].x ;
        if(E[i].ty){
            S.erase( node(E[i].id , 0) );
            S.erase( node(E[i].id , 1) );
        }else{
            IT p = S.insert( node(E[i].id, 0) ).first;
            IT s = p, t = p;
            if(s -- == S.begin() || ++ t == S.end()) { //not included
                 add( root, p -> id );
                 fa[ p -> id] = root;
            }else{
                if(s->id == t->id) { // directly inside
                    add( p->id, s ->id);
                    fa[ p->id] = s -> id;
                }else {
                      if( fa[s->id] == fa[t->id] ) { // two nei
                          add( p->id, fa[s->id] );
                          fa[ p->id] = fa[s->id];
                      }else {
                          if( C[s->id].r > C[t->id].r) { //one nei & one fa
                              add(p->id, s->id);
                              fa[p->id]=s->id;
                          }else {
                              add(p->id, t->id);
                              fa[p->id]=t->id;
                          }
                      }
                }
            }
            S.insert( node(E[i].id, 1) );
        }
    }

    //ot(root,-1);

    for(int i=0;i<n;++i){
        bool ok = 1;
        for(int j=0;j<n;++j) if(i!=j && C[i].inside( C[j] )) {
               if(C[j].r >= C[ fa[i] ] .r ) ; else {
                      cerr <<"i = " << i << " j = " << j <<" C[j].r = " << C[j].r <<" opt = " << fa[i] <<" opt.r = " << C[ fa[i] ].r << endl;
                      ok = 0;
               }
               if(!ok) break;
        }
        if(!ok) {
              cerr <<"error!" <<endl;
              for(int j=0;j<n;++j) C[j].out();
              //ot( root, -1);
              while(1);
        }
    }
    static int cas = 0;
    ++ cas ;
    cerr <<"Correct! " << cas <<" @n = "<<n << endl;
    printf("%s\n", dfs( root, -1) ? "Alice" : "Bob");
}

bool gen(bool gn = true, bool force_lost = false) {
     if( gn) n = rd(50);
     int m = 0;
     const int MAX_POS = 5000;
     const int MAX_R = 1000;
     while(m < n) {
           int px, py, pr;
           px = rand() % MAX_POS ; py = rand() % MAX_POS; pr = rand()% MAX_R + 1;
           if( rand()%2) px *= -1; if( rand()%2 ) py *= -1;
           bool ok = 1;
           TCircle now_c;
           now_c.ox=px, now_c.oy=py, now_c.r=pr;
           for(int i=0; i<m;++i){
                if( C[i].ox == px && C[i].oy == py && C[i].r == pr) {ok=0; break;}
                if(C[i].inside(now_c) || now_c.inside(C[i]) ) continue;
                if( C[i].apart(now_c) ) continue;
                ok=0; break;
           }
           if( ok) {
               C[m++]=now_c;
           }
     }
     cerr <<"done! " << n <<" " << m << endl;
     if(force_lost) {
     	work();
     	int sg = dfs( root, -1);
     	if( sg ) {
     		n += sg;
     		TCircle cc;
     		cc.ox = 16000, cc.oy = 16000, cc.r = sg + 1;
     		while(sg --) {
     			C[m ++] = cc; -- cc.r;
     		}
     	}
     }
     return true;
}

void sc(int x){
     char in[]="0.in";
     char out[]="0.out";
     in[0]=out[0]='0'+x;

     int _n[] = {1000, 1000, 1000, 1000, 10000, 10000, 10000, 10000, 10000, 10000};

     freopen(in,"w", stdout);
     cerr <<"ok " << in << endl;
     int T = 20;
     cout << T << endl;
     while(T --){
          if(T <=3)
               n = _n[ x ], gen(false, rand()%2);
          else gen();

          cout << n << endl;
          for(int i=0;i<n;++i) printf("%d %d %d\n", C[i].ox, C[i].oy, C[i].r);
     }
}

void gao() {


     int T;
     cin >> T;
     while( T -- ) get(),  work();
}

int main(){
   gao();
    return 0;
}

/*
2
1
0 0 1
6
-100 0 90
-50 0 1
-20 0 1
100 0 90
47 0 1
23 0 1

*/