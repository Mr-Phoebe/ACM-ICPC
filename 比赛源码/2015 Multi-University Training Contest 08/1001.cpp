#include<bits/stdc++.h>
#define int64 long long
#define mk make_pair
#define pb push_back
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define sqr(x) (x)*(x)
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define VI vector<int>
#define VS vector<string>
#define PII pair<int,int>
#define PDD pair<double,double>
#define VPII vector< PII >
#define N 1200000
using namespace std;
const double pi=acos(-1);
int n,C,buy[N],sell[N],a[N],total,Q1[N*2],Q2[N*2],l,r;
int64 ans;
void Max(int v){
    int num=0;
    while(l<=r && Q1[l]<v){
        num+=Q2[l];
        l++;
    }
    if(num){
        Q1[--l]=v;
        Q2[l]=num;
    }
}
void Min(int v){
    while(l<=r && Q1[r]>v){
        ans-=1ll*Q1[r]*Q2[r];
        total+=Q2[r];
        r--;
    }
}
void Del(int num){
    while(num){
        int v=min(num,Q2[l]);
        Q2[l]-=v;
        num-=v;
        if(Q2[l]==0)l++;
    }
}
int main(){
    int T,totaln=0;
    for(scanf("%d",&T);T--;){
        scanf("%d%d",&n,&C);
        totaln+=n;
        rep(i,1,n)scanf("%d",&a[i]);
        rep(i,0,n)scanf("%d%d",&buy[i],&sell[i]);
        ans=0;
        l=r=N; r--;
        rep(i,0,n-1){
            Max(sell[i]);
            total=(i==0?C:(a[i]-a[i-1]));
            Min(buy[i]);
            Q1[++r]=buy[i];
            Q2[r]=total;
            ans+=1ll*buy[i]*total;
            Del(a[i+1]-a[i]);
        }
        Max(sell[n]);
        rep(i,l,r)ans-=1ll*Q1[i]*Q2[i];
        printf("%I64d\n",ans);
    }
}