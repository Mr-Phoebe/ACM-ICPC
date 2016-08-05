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
#include<complex>
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
const int N = 105 , M = 10;
int n , cost[N][N] , a[M] , b[M] , has[M];
char s[N];

template<class T>
struct Dinic{
    const static int N = 40101 , M = N * 10;
    int s , t , n , h[N] , cur[N] , level[N] , q[N] , e , ne[M] , to[M];
    T cap[M] , flow;
    void liu(int u,int v,T w){ to[e] = v;ne[e] = h[u];cap[e] = w;h[u] = e++;}
    void link(int u,int v,T w){ liu(u , v , w);liu(v , u , 0);}
    void ini(int _n = N) { fill(h , h + _n , -1);e = 0;}
    bool bfs(){
        int L = 0 , R = 0;
        fill(level , level + n , -1);
        level[q[R++] = s] = 0;
        while(L < R && level[t] == -1){
            int c = q[L++];
            for(int k=h[c];~k;k=ne[k])
                if(cap[k] > 0 && level[to[k]] == -1)
                    level[q[R++] = to[k]] = level[c] + 1;
        }
        return ~level[t];
    }
    T dfs(int c,T mx){
        if(c == t) return mx;
        T ret = 0;
        for(int &k = cur[c];~k;k = ne[k]){
            if(level[to[k]] == level[c] + 1 && cap[k] > 0){
                T flow = dfs(to[k] , min(mx , cap[k]));
                ret += flow;cap[k] -= flow , cap[k^1] += flow;mx -= flow;
                if(!mx) return ret;
            }
        }
        level[c] = -1;
        return ret;
    }
    T run(int _s,int _t,int _n){
        s = _s , t = _t , n = _n;
        flow = 0;
        while(bfs()){
            copy(h , h + n , cur);
            flow += dfs(s,~0U>>1);
        }
        return flow;
    }
};
Dinic<int> f;

int main2(){
    scanf("%d",&n);
    scanf("%s",s);
    fill(has,has+10,0);
    rep(i,0,n) has[s[i] - '0'] = true;
    rep(i,0,10) scanf("%d%d",a + i , b + i);
    rep(i,0,n) rep(j,0,n) scanf("%d",&cost[i][j]);
    int ans = 0;
    f.ini(n * n + n + 10 + 2);
    int S = n*n + n + 10 , T = S + 1;
    rep(i,0,n) rep(j,0,n) if(i!=j) ans += cost[i][j] , f.link(S , n*i+j , cost[i][j]),
        f.link(n*i+j,n*n+i,~0U>>1) , f.link(n*i+j,n*n+j,~0U>>1);
    rep(i,0,n) f.link(n*n+i , n*n+n+s[i]-'0',~0U>>1) , f.link(n*n+i , T , a[s[i]-'0']);
    rep(i,0,10) f.link(n*n+n+i,T,b[i] - a[i]);
    return ans - f.run(S,T,T+1);
}

int main(){
//	freopen("stringv3.in","r",stdin);
    int T;scanf("%d",&T);
    rep(i,1,T+1) printf("Case #%d: %d\n",i,main2());
    return 0;
}