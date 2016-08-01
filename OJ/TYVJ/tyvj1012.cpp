#include<cstdio>  
using namespace std;  
int need[]={6,2,5,5,4,5,6,3,7,6};  
int ans;  
  
int cnt(int cur){  
    int ans=0,ret;  
    if(cur==0) return 6;  
    while(cur>0){  
        ret=cur%10;  
        ans+= need[ret];  
        cur/=10;  
    }  
    return ans;  
}  
int main(){  
//    freopen("matches.in","r",stdin);  
//    freopen("matches.out","w",stdout);  
    int n;  
    scanf("%d",&n);  
    for(int i=0;i<=1000;i++){  
       for(int j=0;j<=1000;j++){  
           int a=cnt(i);  int b=cnt(j);  
           int d=cnt(i+j);  
           int c=n-4-a-b;  
           if(d==c){  
                ans++;  
           }  
       }  
    }  
    printf("%d\n",ans);  
    return 0;  
}  