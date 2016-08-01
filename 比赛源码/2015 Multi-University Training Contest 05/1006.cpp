#include<cstdio>
#include<algorithm>
#include<cstring>
#include <iostream>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
const int N=100005;
const int M=300005;

int T,n,m,sn[N],nx[M<<1],ed[M<<1],del[M<<1],cur,x,y;
int se[N],ne[N<<1],en[N<<1],id[N<<1],cr;
bool inst[N],ans[M],ve[N];
int stp[N],sts[N],len;

inline int get(int &x){
    while(del[x]) x=nx[x];
    //del[x]=del[x^1]=1;
    return x;
}

void dfs(int l,int x){
    stp[len]=x;
    inst[x]=1;
    int &j=sn[x];
    for(j=get(j);j;j=get(j)){
        del[j]=del[j^1]=1;
        if(inst[ed[j]]){
            ans[j>>1]=j&1;
            while(stp[len]^ed[j]){
                ans[sts[len]>>1]=sts[len]&1;
                inst[stp[len]]=0;
                --len;
            }
        }
        else{
            sts[++len]=j;
            dfs(l+1,ed[j]);
        }
        if(len<l) return;
    }
    if(l){
        ne[++cr]=se[stp[l-1]],se[stp[l-1]]=cr,en[cr]=x,id[cr]=sts[len];
        ne[++cr]=se[x],se[x]=cr,en[cr]=stp[l-1],id[cr]=sts[len]^1;
        //printf("%d %d\n",stp[l-1],x);
    }
    inst[x]=0;
    --len;
}

void work(int x,int fa){
    inst[x]=1;
    int v=ve[x];
    for(int j=se[x];j;j=ne[j])
        if(en[j]!=fa){
            ve[en[j]]=v;
            ans[id[j]>>1]=(id[j]&1)^v;
            work(en[j],x);
            v^=1;
        }
}

void Main(){
    rep(i,1,n)inst[i]=sn[i]=se[i]=ve[i]=0;
    rep(i,1,m+m+1)del[i]=0;
    cur=cr=1;
    
    scanf("%d%d",&n,&m);
    rep(i,1,m){
        scanf("%d%d",&x,&y);
        nx[++cur]=sn[x],sn[x]=cur,ed[cur]=y;
        nx[++cur]=sn[y],sn[y]=cur,ed[cur]=x;
    }
    rep(i,1,n) len=0,dfs(0,i);
    rep(i,1,n) if(!inst[i]) work(i,0);
    rep(i,1,m) printf("%d\n",ans[i]^1);
}

int main(){
    scanf("%d",&T);
    while(T--) Main();
}
 

