#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;
#define rep(i,a,b) for(int i=a;i<(b);++i)
const int N = 22;
int T , n , m , u[N*N] , v[N*N] , go[1<<N] , can[1<<N] , q[1<<N] , sum[1<<N];
#define lb(x) (x)&(-(x))
int main(){
  //  freopen("in", "r", stdin);
  //  freopen("out", "w", stdout);
    scanf("%d",&T);
    rep(re,0,T){
 //       double __ = clock();
        scanf("%d%d",&n,&m);
        fill(go , go + (1<<n) , 0);
        fill(can , can + (1<<n) , 0);
        fill(sum , sum + (1<<n) , 0);
        rep(i,0,m){
            scanf("%d%d",u + i , v + i);
            go[1<<u[i]] |= 1<<v[i];
            go[1<<v[i]] |= 1<<u[i];
        }
        rep(i,1,1<<n) go[i] |= go[i^(lb(i))] | go[lb(i)];
        int l = 0 , r = 0;
        rep(i,0,n) can[q[r++] = 1<<i] = true;
        while(l < r){
            int c = q[l++];
            int gg = go[c] ^ (go[c] & c);
            for(int i=gg;i;i^=lb(i)){
                int nc = lb(i) ^ c;
                if(!can[nc]) can[q[r++] = nc] = true;
            }
        }
        int all = 0;
        rep(i,0,1<<n){
            int j = (1<<n)-1;j^=i;
            if(can[i] && can[j]) sum[i]++ , all++;
        }
        all >>= 1;
        rep(j,0,n) for(int i=(1<<n)-1;i>=0;--i) if(!(i>>j&1))
            sum[i] += sum[i^(1<<j)];
        printf("Case #%d: ",re + 1);
        rep(i,0,m) printf("%d%c",all - sum[(1<<u[i]) | (1<<v[i])] , " \n"[i+1==m]);
 //       cerr << re << " " << (double)(clock() - __) / CLOCKS_PER_SEC << endl;
    }
    return 0;
}