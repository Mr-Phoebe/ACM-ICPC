// by ¦Î
// program sky  :)

#include <vector>
#include <stdio.h>
#include <algorithm>

#define Rin register int
#define oo (c=getchar())
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

const int mo=1e9+7,_=5005;

inline void inc(int &x,int y){if((x+=y)>=mo)x-=mo;}
inline void dec(int &x,int y){if((x-=y)<0)x+=mo;}

inline bool cmp(const int*i,const int*j){return *i<*j;}

int n,LS,a[_],*ls[_],pre[_][_],nxt[_][_];
PII dp[_][_];

int main(){
// say hello
	for(;~scanf("%d",&n);){
		LS=0;For(i,1,n)nxt[n+1][i]=0;
		For(i,1,n)a[i]=IN(),ls[++LS]=a+i;
		sort(ls+1,ls+LS+1,cmp);
		for(int i=1,la,tp;i<=LS;++i)tp=*ls[i],*ls[i]=i==1?1:*ls[i-1]+(la!=tp),la=tp;
		For(i,1,n+1)For(j,1,n)pre[i][j]=j^a[i-1]?pre[i-1][j]:i-1;
		dto(i,n,0)	For(j,1,n)nxt[i][j]=j^a[i+1]?nxt[i+1][j]:i+1;
		dto(i,n,1){
			dp[i][i]=PII(1,1);
			PII ans=PII(0,1);
			For(j,i+1,n){
				if(a[j-1]<=a[i]){
					PII tmp=dp[nxt[i][a[j-1]]][pre[j-1][a[j-1]]];
					if(tmp.x==ans.x)dec(ans.y,tmp.y);
					tmp=dp[nxt[i][a[j-1]]][j-1];
					if(tmp.x>ans.x)ans=tmp;else if(tmp.x==ans.x)inc(ans.y,tmp.y);
				}
				dp[i][j]=a[j]==a[i]?PII(ans.x+2,ans.y):dp[i][j]=PII();
			}
		}
		PII ans=PII(1,0);
		For(i,1,n){
			PII tmp=dp[nxt[0][i]][pre[n+1][i]];
			if(tmp.x>ans.x)ans=tmp;
			else if(tmp.x==ans.x)inc(ans.y,tmp.y);
		}
		printf("%d %d\n",ans.x,ans.y);
	}
// never say goodbye
}
