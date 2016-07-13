#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#define For(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
const int N=400005;

struct node{
    int l,r,v;
}ed[N]; int nx[N],sn[N],cnt;
int be[N<<2],sz[N<<2],ans[N<<2],cov[N<<2];
int ww[N],n,W,L,anssz,reans;

void Add(int x,int l,int r,int v){
    ++cnt;
    ed[cnt]=(node){l,r,v};
    nx[cnt]=sn[x];
    sn[x]=cnt;
    ww[++*ww]=l;
    ww[++*ww]=r+1;
}

int suan(int x,int y){
    if(x>y) return 0;
    int ans=0;
    for(int i=1;i<=y;i<<=1){
        int u,v;
        u=(y-i)/(2*i)+1;
        if(x-1<i) v=0;else v=(x-1-i)/(2*i)+1;
        if((u-v)&1) ans+=i;
    }
    return ans;
}

void build(int x,int L,int R){
    if(L==R){
        be[x]=suan(ww[L],ww[L+1]-1);
        return;
    }
    int md=(L+R)>>1;
    build(x*2,L,md);
    build(x*2+1,md+1,R);
    be[x]=be[x*2]^be[x*2+1];
}

inline int IN(){
    char ch=getchar(); int x=0;
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0' && ch<='9') (x*=10)+=ch-'0',ch=getchar();
    return x;
}

void cover(int x,int L,int R,int ll,int rr,int v){
    if(ll>rr) return;
    if(ll<=L && R<=rr){
        cov[x]+=v;
        if(cov[x]){
            sz[x]=ww[R+1]-ww[L];
            ans[x]=be[x];
        }else{
            if(L==R) sz[x]=ans[x]=0;
            else sz[x]=sz[x*2]+sz[x*2+1],ans[x]=ans[x*2]^ans[x*2+1];
        }
        return;
    }
    int md=(L+R)>>1;
    if(ll<=md) cover(x*2,L,md,ll,rr,v);
    if(md<rr)  cover(x*2+1,md+1,R,ll,rr,v);
    if(!cov[x]){
        sz[x]=sz[x*2]+sz[x*2+1];
        ans[x]=ans[x*2]^ans[x*2+1];
    }
}

int Now,nowx;
int szask(int x,int L,int R){
    if(cov[x]){
        reans^=suan(nowx,ww[R+1]-1);
        return min(nowx,ww[R+1])-ww[L];
    }
    if(L==R) return 0;
    int md=(L+R)>>1;
    return sz[x*2]+szask(x*2+1,md+1,R);
}

void Ask(int x,int L,int R,int ll,int rr){
    if(ll>rr) return;
    Now+=cov[x];
    if(ll<=L && R<=rr){
        if(R<rr){
            if(Now) anssz+=ww[R+1]-ww[L];
            else anssz+=sz[x];
        }else{
            if(Now && R==rr) reans^=suan(nowx,ww[R+1]-1);
            if(Now) anssz+=min(nowx,ww[R+1])-ww[L];
            else{
                if(L==R)return;
                int md=(L+R)>>1;
                anssz+=sz[x*2]+szask(x*2+1,md+1,R);
            }
        }
        return;
    }
    int md=(L+R)>>1; int cnow=Now;
    if(ll<=md) Ask(x*2,L,md,ll,rr); Now=cnow;
    if(md<rr)  Ask(x*2+1,md+1,R,ll,rr);
}

void ask(int x,int L,int R,int ll,int rr){
    if(ll>rr) return;
    Now+=cov[x];
    if(ll<=L && R<=rr){
        if(Now) reans^=be[x];else reans^=ans[x];
        return;
    }
    int md=(L+R)>>1; int cnow=Now;
    if(ll<=md) ask(x*2,L,md,ll,rr); Now=cnow;
    if(md<rr)  ask(x*2+1,md+1,R,ll,rr);
}

int main(){
    while(scanf("%d%d%d",&n,&W,&L)!=EOF){
        
        memset(ed,0,sizeof ed);
        memset(nx,0,sizeof nx);
        memset(sn,0,sizeof sn);
        memset(be,0,sizeof be);
        memset(sz,0,sizeof sz);
        memset(ans,0,sizeof ans);
        memset(cov,0,sizeof cov);
        memset(ww,0,sizeof ww);
        anssz=reans=cnt=0;
        
        For(i,1,n){
            int x1=IN(),y1=IN(),x2=IN(),y2=IN();
            Add(x1,y1,y2,1);
            Add(x2+1,y1,y2,-1);
           }
            sort(ww+1,ww+*ww+1);
        *ww=unique(ww+1,ww+*ww+1)-(ww+1);
        build(1,1,*ww-1);
        int now=1;
        For(i,1,W){
            for(int j=sn[i];j;j=nx[j]){
                ed[j].l=lower_bound(ww+1,ww+*ww+1,ed[j].l)-ww;
                ed[j].r=lower_bound(ww+1,ww+*ww+1,ed[j].r+1)-ww;
                cover(1,1,*ww-1,ed[j].l,ed[j].r-1,ed[j].v);
            }
            for(;ww[now]<i && now<*ww;++now);
            anssz=0; nowx=i;
            Now=0; Ask(1,1,*ww-1,1,now-1);
            Now=0; ask(1,1,*ww-1,now,*ww-1);
            if(anssz&1) reans^=i&(-i);
        }    
        if(reans) printf("GTW wins\n");else printf("DSY wins\n");
    }
    return 0;
}

