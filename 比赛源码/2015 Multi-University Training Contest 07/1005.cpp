#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int q[2],w[2];
int main()
{
    int t,n;
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    int T=0;
    while (~scanf("%d%d",&n,&t)){
        if (n==-1 && t==-1) break;
        T++;
        printf("Case #%d: ",T);
        q[0]=q[1]=0;
        int he=0;
        int ha=0;
        while (n>0){
            q[ha]+=n%10;
            he=he+n%10;
            n/=10;
            ha^=1;
        }
        while (t--){
            int shabi=he;
            int now=0;
            w[1]=w[0]=0;
            while (shabi>0){
                w[now]+=shabi%10;
                shabi/=10;
                now^=1;
            }
            if (now) swap(q[0],q[1]);
            q[0]+=w[0];q[1]+=w[1];
            he+=w[0]+w[1];
        }
        if ((q[0]-q[1])%11==0)
            printf("Yes\n");else printf("No\n");
    }
    return 0;
}
