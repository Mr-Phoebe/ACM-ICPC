#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<ctime>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
const int
    N=100005,
    S=10000005;
int n,m,sn[N],nx[N],x,v[N],dpt,cur,tn,tmpv[N];
int dfsl[N],dfsr[N],ind,aim,aimv,ans[N],tcase;

struct trie{
    trie *p[2];
    int sz;
}pool[S],*rt[N<<1];

inline trie *newnode(){
    trie *x=pool+(++cur);
    x->p[0]=x->p[1]=NULL;
    x->sz=0;
    return x;
}

struct inque{
    int opt,x,y;
    void read(){
        scanf("%d",&opt);
        if(opt==0) scanf("%d%d",&x,&y);
        else scanf("%d",&x);
    }
}q[N];

void dfsT(int x){
    dfsl[x]=++ind;
    for(int j=sn[x];j;j=nx[j])
        dfsT(j);
    dfsr[x]=ind;
}

void insert(trie *&x,int w){
    if(!x) x=newnode();
    x->sz+=aim;
    if(w<0) return;
    int z=aimv>>w&1;
    insert(x->p[z],w-1);
    if(x->p[z]->sz==0) x->p[z]=NULL;
}

void modify(int l,int r,int a,int b){
    bool flag=(r-l+1)==1<<dpt;
    if(l==a && b==r){
        if(flag) insert(rt[r>>dpt],30);
        return;
    }
    if(flag) return;
    int mid=l+r>>1;
    if(b<=mid) modify(l,mid,a,b);
    else if(a>mid) modify(mid+1,r,a,b);
    else modify(l,mid,a,mid),modify(mid+1,r,mid+1,b);
}

int qmax(trie *x,int w){
    if(!x || w<0) return 0;
    int z=aimv>>w&1;
    if(x->p[z^1]) return qmax(x->p[z^1],w-1)+(1<<w);
    return qmax(x->p[z],w-1);
}

int query(int l,int r,int k){
    bool flag=(r-l+1)==1<<dpt;
    if(flag) return qmax(rt[r>>dpt],30);
    if(l==r) return 0;
    int mid=l+r>>1;
    if(k<=mid) return query(l,mid,k);
    return query(mid+1,r,k);
}

int main(){
    scanf("%d",&tcase);
    while(tcase--){
        scanf("%d%d",&n,&m);
        memset(sn,0,sizeof(sn));
        memset(ans,0,sizeof(ans));
        ind=0;
        rep(i,2,n){
            scanf("%d",&x);
            nx[i]=sn[x],sn[x]=i;
        }
        dfsT(1);
        rep(i,1,n) scanf("%d",tmpv+i);
        rep(i,1,m) q[i].read();
        for(tn=dpt=1;tn<n;tn<<=1,dpt++);
        while(dpt--){
            cur=0;
            rep(i,1,tn) rt[i]=NULL;
            memcpy(v,tmpv,sizeof(v));
            aim=1;
            rep(i,1,n){
                aimv=v[i];
                modify(1,tn,dfsl[i],dfsr[i]);
            }
            rep(i,1,m)
                if(q[i].opt==0){
                    aimv=v[q[i].x];
                    aim=-1;
                    modify(1,tn,dfsl[q[i].x],dfsr[q[i].x]);
                    aimv=v[q[i].x]=q[i].y;
                    aim=1;
                    modify(1,tn,dfsl[q[i].x],dfsr[q[i].x]);
                }else{
                    aimv=v[q[i].x];
                    ans[i]=max(ans[i],query(1,tn,dfsl[q[i].x]));
                }
        }
        rep(i,1,m) if(q[i].opt==1) printf("%d\n",ans[i]);
    }
}