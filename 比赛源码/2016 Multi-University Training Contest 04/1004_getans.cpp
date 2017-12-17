#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const int N = 21 , P = 1e9 + 7;
int Pow(int x,int t){int r=1;for(;t;t>>=1,x=(ll)x*x%P)if(t&1)r=(ll)r*x%P;return r;}
int n;
int f[2][1<<N];
void pp(int &x,int d){
    x += d;if(x >= P) x -= P;
}
int rot0(){
    int c = 0;
    int up = (1<<(n+1)) - 1;
    fill(f[c] , f[c] + up + 1 , 0);
    f[c][up] = 1;
    rep(i,0,n){
        rep(j,0,n){
            c ^= 1;fill(f[c] , f[c] + up + 1, 0);
            rep(k,0,up+1) if(f[c^1][k]){
                pp(f[c][k & (up ^ (1<<j))] , f[c^1][k]);
                if(i && j && !(k>>(j-1)&7))
                    pp(f[c][k | (7<<(j-1))] , f[c^1][k]);
            }
        }
        c ^= 1;fill(f[c] , f[c] + up + 1 , 0);
        rep(k,0,up+1) pp(f[c][(k<<1|1) & up] , f[c^1][k]);
    }
    int ret = 0;
    rep(i,0,up+1) pp(ret , f[c][i]);
    return ret;
}

bool a[N][N];
vector<vector<pii> > e;
void dfs(int c , int op){
    if(c == (int)e.size()){
        if(op == 1){
            int mask = 0;
            rep(i,0,n) mask |= a[0][i] << i;
            f[0][mask << 1 | 1]++;
        }
        else if(op == 2){
            int mask = 0;
            int t = (n+1)/2;
            for(int i=n-1;i>=t;--i) mask = mask<<1|a[i][t];
            for(int i=t+1;i<n;++i) mask = mask<<1|a[t][i];
            f[0][mask]++;
        }
        return;
    }
    dfs(c + 1 , op);
    for(pii t : e[c]) if(a[t.fi][t.se]) return;
    for(pii t : e[c]) a[t.fi][t.se] = true;
    dfs(c + 1 , op);
    for(pii t : e[c]) a[t.fi][t.se] = false;
}

int rot90(){
    if(n == 1) return 1;
    e.clear();int L , R;
    if(n%2 == 0) L = n/2-1 , R = L + 1;
    else L = n/2-1 , R = n/2+1;
    rep(i,0,n-1) rep(j,0,n-1) if((L <= i && i < R) || (L <= j && j < R)){
        vector<pii> block , v;rep(ii,0,2) rep(jj,0,2) v.pb(mp(i+ii,j+jj));
        rep(d,0,4){
            vector<pii> nv;
            for(pii t : v) nv.pb(mp(t.se , n-1-t.fi));
            v = nv;block.insert(block.end(),all(v));
        }
        sort(all(block));block.erase(unique(all(block)) , block.end());
        if(block.size() == 16 || (n % 2 == 0 && i == j && i == (n/2-1))) e.pb(block);
    }
    sort(all(e));e.erase(unique(all(e)) , e.end());
    int rm = n / 2 - 1 , up = (1<<(rm+rm+1))-1;
    int c = 0;fill(f[c] , f[c] + up + 1 , 0);
    dfs(0 , 2);
    rep(i,0,rm){
        rep(j,0,rm){
            c ^= 1;fill(f[c] , f[c] + up + 1 , 0);
            rep(k,0,up+1) if(f[c^1][k]){
                int pos = rm - i + j;
                pp(f[c][k & (up ^ (1<<pos))] , f[c^1][k]);
                if(!(k>>(pos-1)&7)) pp(f[c][k | (7<<(pos-1))] , f[c^1][k]);
            }
        }
    }
    int ret = 0;
    rep(i,0,up+1) pp(ret , f[c][i]);
    return ret;
}


int rot180(){
    e.clear();int up = 0;
    if(n == 1) return 1;
    else up = n % 2 == 0 ? 2 : 3;
    rep(i,0,up-1) rep(j,0,n-1){
        vector<pii> block , v;rep(ii,0,2) rep(jj,0,2) v.pb(mp(i+ii,j+jj));
        rep(d,0,2){
            vector<pii> nv;
            for(pii t : v) nv.pb(mp(up - 1 - t.fi , n - 1 - t.se));
            v = nv; block.insert(block.end(),all(v));
        }
        sort(all(block));block.erase(unique(all(block)) , block.end());
        if(block.size() == 8 || (n%2 == 0 && j == (n/2-1))) e.pb(block);
    }
    sort(all(e));e.erase(unique(all(e)) , e.end());
    int rm = n / 2 - 1;
    up = (1<<(n+1)) - 1;
    int c = 0;fill(f[c] , f[c] + up + 1 , 0);
    dfs(0 , 1);
    rep(i,0,rm){
        rep(j,0,n){
            c ^= 1;fill(f[c] , f[c] + up + 1, 0);
            rep(k,0,up+1) if(f[c^1][k]){
                pp(f[c][k & (up ^ (1<<j))] , f[c^1][k]);
                if(j && !(k>>(j-1)&7))
                    pp(f[c][k | (7<<(j-1))] , f[c^1][k]);
            }
        }
        c ^= 1;fill(f[c] , f[c] + up + 1 , 0);
        rep(k,0,up+1) pp(f[c][(k<<1|1) & up] , f[c^1][k]);
    }
    int ret = 0;
    rep(i,0,up+1) pp(ret , f[c][i]);
    return ret;
}
int out[21];
int main(){
    double t1 = clock();
    for(n=1;n<=20;++n){
        cerr << n << endl;
        int ans = 0;
        pp(ans , rot0());
        pp(ans , rot90() * 2 % P);
        pp(ans , rot180());
        ans = (ll)ans * Pow(4 , P - 2) % P;
        out[n] = ans;
    }
    rep(i,1,21) printf("%d,",out[i]);
    cerr << (clock()-t1) / CLOCKS_PER_SEC << endl;
    return 0;
}
