#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<int,int>> e[2048];
vector<ll> seq;
int mul;

int d[2048];
bool mark[2048];
void dfs(int u,int f=-1){
  d[u]=0;
  int to=0;
  for(const auto&p:e[u]){
    const int v=p.first;
    if(v==f)continue;
    dfs(v,u);
    d[v]+=p.second;
    if(d[v] > d[u]){
      d[u] = d[v];
      to=v;
    }
  }
  mark[to]=true;
}
ll sol(){
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;++i)e[i].clear();
  for(int i=1,a,b,c;i<n;++i){
    scanf("%d%d%d",&a,&b,&c);
    e[a].push_back({b,c});
    e[b].push_back({a,c});
  }
  seq.clear();
  for(int i=1;i<=n;++i){
    scanf("%d",&mul);
    fill(mark+1,mark+n+1,false);
    dfs(i);
    for(int j=1;j<=n;++j)if(!mark[j])
      seq.push_back(d[j] * (ll) mul);
  }
  m=min<int>(seq.size(),m);
  nth_element(seq.begin(),seq.end()-m,seq.end());
  return accumulate(seq.end()-m,seq.end(),0LL);
}
int main(){
  int T;for(scanf("%d",&T);T--;printf("%lld\n",sol()));
}