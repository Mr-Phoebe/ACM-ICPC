#include <cstdio>
#include <algorithm>
struct point{
   int coo;
   int num;
}p[110];

bool cmp(point x, point y){
    return  x.coo < y.coo;
}

int main(){
    int n, m, l, r, ans[110];
    scanf("%d %d ", &n, &m);
    for(int i = 0; i < n; i ++){
        scanf("%d", &p[i].coo);
        p[i].num = i;
    }
   while(m--) { scanf("%d %d", &l, &r); }  
   std::sort(p, p + n, cmp);
   for(int i = 0; i < n; i++)
        ans[p[i].num] = i%2==0 ? 1 : 0;
   for(int i = 0; i < n-1; i++)
         printf("%d ", ans[i]);
   printf("%d\n", ans[n-1]);
   return 0;
}