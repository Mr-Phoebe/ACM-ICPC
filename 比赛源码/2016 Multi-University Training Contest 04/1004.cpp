#include <cstdio>
int a[]={0,1,2,2,12,84,1641,50788,3183091,338785462,429880385,948920428,392930107,842384602,36468923,534250025,693507546,311288183,320259213,232751393,866290697};

int main(){
   // freopen("in", "r", stdin);
  //  freopen("out", "w", stdout);
    int T,x;scanf("%d",&T);
    for(int i=1;i<=T;++i) scanf("%d",&x),printf("Case #%d: %d\n",i,a[x]);
    return 0;
}
