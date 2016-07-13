#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<iostream>
#include<assert.h>
#define int64 long long
#define sqr(x) (x)*(x)
#define mk make_pair
#define pb push_back
#define fi first
#define se second
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define VI vector<int>
#define VI64 vector<int64>
#define VS vector<string>
#define PII pair<int,int>
#define PDD pair<double,double>
#define VPII vector< PII >
#define SZ(x) ((int)(x).size())
using namespace std;
const double pi=acos(-1);
int n;
int main(){
    //freopen("IN","r",stdin);
    //freopen("ANS","w",stdout);
    scanf("%d",&n);
    int size=0,maxx=-2e9;
    rep(i,1,n){
        int type,x;
        scanf("%d",&type);
        if(type==1){
            scanf("%d",&x);
            assert(abs(x)<=1e9);
            size++;
            maxx=max(maxx,x);
        }else if(type==2){
            size=max(0,size-1);
            if(!size)maxx=-2e9;
        }else{
            if(!size)printf("0\n");
            else printf("%d\n",maxx);
        }
    }
    return 0;
}


