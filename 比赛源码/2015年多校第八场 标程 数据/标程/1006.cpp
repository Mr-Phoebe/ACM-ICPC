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
vector<int>go[N];
int n,m;
int u[N],v[N];
bool ok[N];
int dis[N];
int fa[N];
void relax(int x){
    rep(i,0,go[x].size()-1)if(!fa[v[go[x][i]]]&&!ok[v[go[x][i]]]){
        fa[v[go[x][i]]]=x;
    }
}
int main(){
    int T;scanf("%d",&T);
    while(T--){
    scanf("%d%d",&n,&m);
    rep(i,1,n)go[i].clear();
    rep(i,1,n)fa[i]=ok[i]=dis[i]=0;
    rep(i,1,m){
        scanf("%d%d",&u[i],&v[i]);
        go[u[i]].pb(i);
    }
    
    ok[1]=1;
    dis[1]=0;
    relax(1);
    int last=n;int pre=2;int now=1;
    while(pre<=last){
        if(fa[pre]){
            ok[pre]=1;
            relax(pre);
            dis[pre]=now++;
            pre++;
            continue;
        }
        
        if(fa[last]){
            ok[last]=1;
            relax(last);
            dis[last]=now++;
            last--;
            continue;
        }
        
    }
    rep(i,1,m)if(u[i]!=fa[v[i]])printf("%d\n",n);else printf("%d\n",dis[v[i]]-dis[u[i]]);
    }
    return 0;
}