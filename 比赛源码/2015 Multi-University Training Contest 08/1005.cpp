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
const int N=210000;
char a[N],b[N];
int go[N][26],tot,fail[N],num[N];
int q[N];
int st[N];
void Main(){
    rep(i,1,tot){
        num[i]=0;fail[i]=0;
        rep(j,0,25)go[i][j]=0;
    }
    tot=1;
    int n,m;scanf("%d%d",&n,&m);
    int be=1;
    rep(i,1,n){
        scanf("%s",a+be);
        st[i]=be;
        be+=strlen(a+be);
    }
    st[n+1]=be;
    rep(i,1,m){
        scanf("%s",b+1);
        int len=strlen(b+1);
        int now=1;
        rep(j,1,len){
            if(!go[now][b[j]-'a'])go[now][b[j]-'a']=++tot;
            now=go[now][b[j]-'a'];
        }
        num[now]++;
    }
    
    q[q[0]=1]=1;
    fail[1]=1;
    rep(i,1,q[0]){
        int x=q[i];
        rep(j,0,25)if(go[x][j]){
            q[++q[0]]=go[x][j];
            int y=go[x][j];
            int p=fail[x];
            while((!go[p][j])&&p!=1){
                p=fail[p];
            }
            if(go[p][j]==y||(!go[p][j]))fail[y]=1;
            else fail[y]=go[p][j];
        }
    }
    //printf("_____%d %d\n",n,m);
    
    rep(i,1,q[0])num[q[i]]+=num[fail[q[i]]];

    //printf("__%d %d\n",n,m);
    rep(i,1,n){
        //printf("?\n");
        LL ans=0;
        int x=1;
        rep(j,st[i],st[i+1]-1){
            while((!go[x][a[j]-'a'])&&(x!=1))x=fail[x];
            if(go[x][a[j]-'a'])x=go[x][a[j]-'a'];
            ans+=1ll*num[x];
        }
        printf("%I64d\n",ans);
    }
}
int main(){
    int T;scanf("%d",&T);
    while(T--)Main();
    return 0;
}