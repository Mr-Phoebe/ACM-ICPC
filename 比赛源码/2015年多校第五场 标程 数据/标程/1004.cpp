#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
typedef double db;
const int P=258280327;
inline int Pow(int a,int b){
    int c=1;
    for(;b;b>>=1,a=a*1ll*a%P)if(b&1)c=c*1ll*a%P;
    return c;
}
int pro;
const int N=2005;
int powpow[N];
int f[N][N];
int main(){
    int T;scanf("%d",&T);
    rep(Cas,1,T){
        int n,_x,_y;
        scanf("%d%d%d",&n,&_x,&_y);
        pro=_x*1ll*Pow(_y,P-2)%P;
        powpow[0]=1;
        rep(i,1,n)powpow[i]=powpow[i-1]*1ll*(P+1-pro)%P;
        rep(i,0,n)rep(j,0,n)f[i][j]=0;
        f[0][0]=1;
        rep(i,0,n)rep(j,0,n){
            f[i+1][j+1]=(f[i+1][j+1]+f[i][j]*1ll*powpow[j])%P;
            f[i+1][j]=(f[i+1][j]+f[i][j]*1ll*(P+1-powpow[j]))%P;
        }
        rep(k,0,n-1){
            int ans=0;
            rep(i,0,n-1)ans=(ans+f[i][k]*1ll*powpow[k])%P;
            ans=ans*1ll*Pow(n,P-2)%P;
            printf("%d%c",ans,k==n-1?'\n':' ');
        }
    }
    return 0;
}



