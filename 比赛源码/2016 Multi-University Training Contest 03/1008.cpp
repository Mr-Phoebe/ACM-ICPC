// by ¦Î
// program sky  :)

#include <vector>
#include <stdio.h>
#include <cstring>
#include <algorithm>

#define Rin register int
#define oo (c=getchar())
#define clr(a) memset(a,0,sizeof a)
#define For(i,l,r) for(int _r=r,i=l;i<=_r;++i)
#define rep(i,l,r) for(int _r=r,i=l;i<_r;++i)
#define dto(i,r,l) for(int _l=l,i=r;i>=_l;--i)
#define ALL(V) V.begin(),V.end()
#define pb push_back
#define x first
#define y second

using namespace std;

typedef double db;
typedef long long LL;
typedef pair<int ,int> PII;
typedef pair<db ,db> cpx;
typedef vector<int> VI;
typedef vector<PII> VII;

inline int IN(){
	char c;Rin x=0;
	for(;oo<48 && c^'-' || c>57;);bool f=c=='-';if(f)oo;
	for(;c>47 && c<58;oo)x=(x<<3)+(x<<1)+c-48;if(f)x=-x;return x;
}

void print(unsigned int x){
	if(x>9)print(x/10);
	putchar(x%10+48);
}

typedef int Arr[300010];

int n,Q,L,R,x,ty,idx;
Arr lzz,rzz,st,St,en,En,sz,sm,an,he,nxt,g,top,fa,key,hvy,con,son1,son2,id;

struct tpl{int a[3];}t[1200010];

void dfs(int u){
	lzz[u]=idx++;
	sm[u]=key[u];sz[u]=1;
	for(int v=he[u];v;v=nxt[v]){
		dfs(v);
		sz[u]+=sz[v];
		sm[u]+=sm[v];
		++son1[u];
		son2[u]+=son1[v]+1;
		an[u]-=sz[v]*sm[v];
		if(sz[v]>sz[hvy[u]])hvy[u]=v;
		con[u]-=sz[v]*son1[v];
	}
	an[u]+=sz[u]*sm[u]+key[u];
	con[u]+=2+sz[u]*son2[u];
	rzz[u]=idx-1;
}

void DFS(int u){
	if(!top[u])top[u]=u;
	if(hvy[u])top[hvy[u]]=top[u];
	for(int v=he[u];v;v=nxt[v])DFS(v);
}

inline void init(){
	clr(lzz);clr(rzz);clr(st);clr(St);clr(en);clr(En);clr(sz);clr(sm);clr(an);clr(he);clr(nxt);clr(g);clr(top);clr(fa);clr(key);clr(hvy);clr(con);clr(son1);clr(son2);clr(id);clr(t);
	n=Q=L=R=x=ty=idx=0;
	if(scanf("%d%d",&n,&Q)==-1)exit(0);
	For(v,2,n){
		int u=IN();
		nxt[v]=he[u];he[u]=v;fa[v]=u;
	}
	For(i,1,n)key[i]=IN();
	dfs(1);
	DFS(1);
	int l=0,r=1;
	for(g[l]=1;l<r;){
		int u=g[l++];
		id[u]=l-1;
		st[u]=r;
		for(int v=he[u];v;v=nxt[v])g[r++]=v;
		en[u]=r;
	}
	st[g[r]=n+1]=en[n+1]=r;
	for(;l--;){
		int u=g[l];
		St[u]=st[g[st[u]]];
		En[u]=en[g[en[u]-1]];
	}
}

void djia(int u,int ll,int rr){
	if(ll==rr)return (void)(t[u].a[2]+=x);
	int mm=ll+rr>>1;
	if(L<=mm)djia(u<<1,ll,mm);
	else djia(u<<1|1,mm+1,rr);
	t[u].a[2]=t[u<<1].a[2]+t[u<<1|1].a[2];
}

void bjia(int u,int ll,int rr){
	if(L<=ll && rr<=R)return (void)(t[u].a[ty]+=x);
	int mm=ll+rr>>1;
	if(L<=mm)bjia(u<<1,ll,mm);
	if(R>mm)bjia(u<<1|1,mm+1,rr);
}

int dqs(int u,int ll,int rr){
	if(L<=ll && rr<=R)return t[u].a[2];
	int mm=ll+rr>>1,res=0;
	if(L<=mm)res=dqs(u<<1,ll,mm);
	if(R>mm)res+=dqs(u<<1|1,mm+1,rr);
	return res;
}

PII bqs(int u,int ll,int rr){
	if(ll==rr)return PII(t[u].a[0],t[u].a[1]);
	int mm=ll+rr>>1;PII _;
	if(L<=mm){
		_=bqs(u<<1,ll,mm);
		return PII(t[u].a[0]+_.x,t[u].a[1]+_.y);
	}
	_=bqs(u<<1|1,mm+1,rr);
	return PII(t[u].a[0]+_.x,t[u].a[1]+_.y);
}

int main(){
// say hello
	for(;;){
		init();
		for(;Q--;){
			if(IN()==1){
				int u=IN();x=IN();
				L=St[u];R=En[u]-1;
				if(L<=R)ty=0,bjia(1,0,n-1);
				L=st[u];R=en[u]-1;
				if(L<=R)ty=1,bjia(1,0,n-1);
				an[u]+=x*con[u];
				x*=son2[u]+1;
				L=lzz[u];
				djia(1,0,n-1);
				for(;fa[top[u]];u=fa[u]){
					u=top[u];
					an[fa[u]]+=(sz[fa[u]]-sz[u])*x;
				}
			}else{
				int u=IN(),_=0;
				if(hvy[u])L=lzz[hvy[u]],R=rzz[hvy[u]],_=dqs(1,0,n-1);
				L=id[u];
				PII res=bqs(1,0,n-1);
				print(an[u]+res.x*(sz[u]+1)+res.y*(2+sz[u]*son1[u])+_*(sz[u]-sz[hvy[u]]));
				putchar('\n');
			}
		}
		fprintf(stderr,"done.\n");
	}
// never say goodbye
}
