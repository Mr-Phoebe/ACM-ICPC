#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <ctime>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define setIO(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
const int P = 1e9 + 7 , N = 4 , M = 1<<N , L = 10 , K = 40;
int cnt[M] , cost[M] , n;
map<vi,int> Mp;
vector<vi> States;
#define lb(i) (i&-i)
int id(vi&x){
    if(Mp.find(x) == Mp.end()){
        Mp[x] = sz(States);
        States.pb(x);
    }
    return Mp[x];
}
int dis[M] , vis[M];
int go[2200][M] , Cost[2200][M];
void bfs(vi&v,int u){
    rep(i,0,1<<n) dis[i] = v[i];
    rep(i,0,1<<n) rep(j,0,1<<n) dis[i] = min(dis[i] , dis[j] + cnt[(j^i)&i]);
    rep(mask,0,1<<n){
        int Min = 1<<30;
        rep(i,0,1<<n) Min = min(Min , dis[i] + cost[i^mask]);
        vi nv;rep(i,0,1<<n) nv.pb(dis[i] + cost[i^mask] - Min);int v = id(nv);
        go[u][mask] = v;Cost[u][mask] = Min;
    }
}
void pp(int &x,int d){x += d;if(x >= P) x -= P;}
int f[2][K+1][2200];
int g[N+1][L+1][K+1];
void run(){
    States.clear();Mp.clear();
    vi ini;rep(i,0,1<<n) ini.pb(cnt[i]);id(ini);
    rep(i,0,sz(States)) bfs(States[i],i);

    int c = 0;int UpK = n*L + 1;
    rep(i,0,UpK) rep(j,0,sz(States)) f[c][i][j] = 0;f[c][0][0] = 1;
    rep(i,0,L){
        c ^= 1;rep(i,0,UpK) rep(j,0,sz(States)) f[c][i][j] = 0;
        rep(j,0,UpK) rep(k,0,sz(States)) rep(mask,0,1<<n) if(f[c^1][j][k]){
            int jj = Cost[k][mask] + j , kk = go[k][mask];
            if(jj < UpK) pp(f[c][jj][kk] , f[c^1][j][k]);
        }
        rep(j,0,UpK){
            g[n][i+1][j] = j ? g[n][i+1][j-1] : 0;
            rep(k,0,sz(States)) pp(g[n][i+1][j] , f[c][j][k]);
        }
    }
}

int main(){
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);
    db t1 = clock();
    rep(i,1,M) cnt[i] = cnt[i^lb(i)]+1;
    rep(i,1,M) cost[i] = cost[i^lb(i)] + (i&(lb(i)<<1) ? 0 : 1);
    for(n=1;n<=4;++n) run();
   // cerr << (clock() - t1) / CLOCKS_PER_SEC << endl;
    int T,n,m,k;scanf("%d",&T);
    rep(i,1,T+1) scanf("%d%d%d",&n,&m,&k) , printf("Case #%d: %d\n",i,g[n][m][k]);
    return 0;
}
