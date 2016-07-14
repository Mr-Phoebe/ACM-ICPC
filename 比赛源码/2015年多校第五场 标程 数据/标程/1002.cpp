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
int main(){
    int T;scanf("%d",&T);
    while(T--){
        int ans=0;
        int pre=0;int m,n,z,l;
        scanf("%d%d%d%d",&n,&m,&z,&l);
        rep(i,2,n){
            pre=(pre*1ll*m+z)%l;
            ans^=pre;
        }
        printf("%d\n",ans<<1);
    }
    return 0;
}



