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
typedef multiset<int>::iterator it;
multiset<int> now;
void Main(){
    int n;scanf("%d",&n);
    now.clear();LL ans=0;
    rep(i,1,n){
        int x;scanf("%d",&x);now.insert(x);
    }
    rep(i,1,n-1){
        int tmp=0;
        tmp+=(*now.begin());
        now.erase(now.begin());
        tmp+=(*now.begin());
        now.erase(now.begin());
        ans+=1ll*tmp;
        now.insert(tmp);
    }
    printf("%I64d\n",ans);
}
int main(){
    int T;scanf("%d",&T);
    while(T--)Main();
    return 0;
}



