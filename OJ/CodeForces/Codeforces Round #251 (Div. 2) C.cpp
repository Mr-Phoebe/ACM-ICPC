#include <cstdio>
#include <iostream>
using namespace std;
int odd[100005],even[100005];
int main(){
    int n,k,p,u,ocnt = 0,ecnt = 0,v;
    scanf("%d %d %d",&n,&k,&p);
    u = k - p;
    for(int i = 0; i < n; ++i){
        scanf("%d",&v);
        if(v & 1)
            odd[ocnt++] = v;
        else
            even[ecnt++] = v;
    }
    if(ocnt < u || (ocnt - u) & 1 || ecnt + ((ocnt - u)>>1) < p){
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    for(int i = 0; i < u - 1; ++i)
        printf("1 %d\n",odd[--ocnt]);
    for(int i = 0; i < p - 1; ++i){
        if(ecnt)
            printf("1 %d\n",even[--ecnt]);
        else{
            printf("2 %d %d\n",odd[ocnt - 1],odd[ocnt - 2]);
            ocnt -= 2;
        }
    }
    if(u && p)
        printf("1 %d\n",odd[--ocnt]);
    printf("%d",ocnt + ecnt);
    while(ocnt)
        printf(" %d",odd[--ocnt]);
    while(ecnt)
        printf(" %d",even[--ecnt]);
    puts("");
    return 0;
}