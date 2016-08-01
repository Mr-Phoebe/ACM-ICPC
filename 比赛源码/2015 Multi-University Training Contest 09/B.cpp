#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define SZ(x) (int(x.size()))
typedef long long ll;
typedef long double LD;
const ll mod=1000000007;
const int N=10100;

ll p,q,r,base,pw[N],w[N];
vector<pair<int,int> > e[N];
set<pair<ll,int> > st;
int _,sgn[N];
ll mul(ll a,ll b,ll mod=r) {
	ll c=a*b-mod*ll((LD)a*b/mod);
	while (c<0) c+=mod;
	while (c>=mod) c-=mod;
	return c;
}
typedef set<pair<ll,int> >::iterator ite;
void add(int id,ite p,ite q) {
	e[id].pb(mp(p->se,1));
	e[id].pb(mp(q->se,-1));
	w[id]=p->fi-q->fi;
//	printf("%lld\n",w[id]);
	st.erase(p); st.erase(q);
	st.insert(mp(w[id],id));
}
void dfs(int x,int w) {
	sgn[x]=w;
//	if (x<2500) printf("%d %d\n",x,w);
	for (auto p:e[x]) dfs(p.fi,w*p.se);
}
const int L=2500;
int main() {
	while (scanf("%lld%lld%lld%lld",&p,&q,&r,&base)!=EOF) {
		pw[0]=1; p%=r; q%=r; base%=r;
		rep(i,1,4*L+1) pw[i]=mul(pw[i-1],base);
		st.clear();
		rep(i,0,L) {
			w[i]=(mul(q,pw[4*i+2])-mul(p,pw[4*i+2])+mul(p,pw[4*i+1])-mul(q,pw[4*i+1]))%r;
			if (w[i]<0) w[i]+=r;
//			fprintf(stderr,"%lld\n",w[i]);
			sgn[i]=0;
			st.insert(mp(w[i],i));
		}
		int tot=L;
		rep(i,0,2*L) e[i].clear();
		bool sol=0;
		while (SZ(st)>=2) {
			ite q=(--st.end());
			ite p=q--;
			add(tot++,p,q);
			q=st.lower_bound(mp(w[tot-1],-1));
			p=q++;
			if (q!=st.end()&&p->fi==q->fi) {
				add(tot++,p,q);
				sol=1;
				dfs(tot-1,1);
				break;
			}
		}
		assert(sol);
		ll rr=0;
		rep(i,0,L) rr+=sgn[i]*w[i];
		assert(rr==0);
		rep(i,0,L) if (sgn[i]>=0) printf("()()"); else printf("(())"); puts("");
		rep(i,0,L) if (sgn[i]<=0) printf("()()"); else printf("(())"); puts("");
	}
}