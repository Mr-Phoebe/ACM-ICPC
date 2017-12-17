#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int sol(){
  int n,m;
  scanf("%d%d",&n,&m);
  if(((n+1ll)*n>>1)%m!=0 || m * 2 -1 > n) return puts("NO");
  
  const int c=(n+1-m*2)%(m*2)+m*2-1,
    s=c*(c+1)/(m*2),
    d=(n-c)/(m*2);
  puts("YES");
  set<int> v;
  for(int i=1;i<=c;++i)v.insert(i);
  for(int j=0,l=c+1;j<m;++j,putchar('\n')){
    static int o[32],c,r;
    for(c=r=0;r<s;){
      auto it = v.upper_bound(s-r);
      r+=o[c++]=*--it;
      v.erase(it);
    }
    printf("%d",c+d*2);
    for(int i=0;i<c;++i)printf(" %d",o[i]);
    for(int i=0;i<d;++i)printf(" %d %d",l++,n--);
  }
}
int main(){
  int T;
  for(scanf("%d",&T);T--;sol());
}