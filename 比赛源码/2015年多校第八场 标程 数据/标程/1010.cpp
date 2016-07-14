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
const int N=110000;
const int P=258280327;
int a[N],T,n,A,B;
int g[2][10];
inline void add(int &x,int y){x+=y;if(x>=P)x-=P;}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        scanf("%d%d",&A,&B);A%=9;B%=9;
        rep(i,1,n)scanf("%d",&a[i]);
        
        int gg=0;
        rep(i,1,n)gg=(gg+a[i])%9;
        memset(g,0,sizeof g);
        int now=0;
        g[now][0]=1;
        rep(i,1,n){
            now^=1;
            rep(k,0,8)g[now][k]=0;
            rep(k,0,8){
                add(g[now][(k+a[i])%9],g[now^1][k]);
                add(g[now][k],g[now^1][k]);
            }
        }
        
        int ans=g[now][A]*(((A+B)%9)==gg);
        if(gg==A&&B!=0)ans=(ans+1)%P;
        if(gg==B&&A!=0)ans=(ans+1)%P;
        printf("%d\n",ans);
    }
    return 0;
}