#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<assert.h>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
const int N=210000;
struct node{
	LL dis;int x;
	inline node(LL _dis=0,int _x=0){x=_x;dis=_dis;}
};
inline bool operator <(const node &a,const node &b){return a.dis<b.dis;}
multiset<node> heap;
vector<int>p[N];
int u[N],v[N],w[N];
int n,m;
LL dis[N];
bool vis[N];
FILE	*Finn;
vector<int>theout;
int	main(int args, char** argv){
	Finn = fopen(argv[1], "r");
	int T;fscanf(Finn,"%d",&T);
	while(T--){
	fscanf(Finn,"%d%d",&n,&m);
	rep(i,1,n)p[i].clear();
	rep(i,1,m){fscanf(Finn,"%d%d",&u[i],&v[i]);p[u[i]].pb(i);}
	
	rep(i,1,m){
		scanf("%d",&w[i]);
	}
	rep(i,1,m)if(w[i]>n||w[i]<1){printf("WA\n");continue;}
	
	heap.clear();rep(i,1,n)vis[i]=0;
	rep(i,1,n)dis[i]=(LL)1e16;
	dis[1]=0;
	heap.insert(node(0,1));
	while(heap.size()){
		node now=*heap.begin();
		heap.erase(heap.begin());
		if(vis[now.x])continue;
		vis[now.x]=1;
		rep(i,0,p[now.x].size()-1){
			int _V=v[p[now.x][i]];
			int _W=w[p[now.x][i]];
			if(dis[_V]>dis[now.x]+_W){
				dis[_V]=dis[now.x]+_W;
				heap.insert(node(dis[_V],_V));
			}
		}
	}
	int now=1;
	while(dis[now+1]>dis[now]&&now!=n)now++;
	while(dis[now+1]<dis[now]&&now!=n)now++;
	if(now==n)printf("AC\n");
	else printf("WA\n");
	}
	return 0;
}

