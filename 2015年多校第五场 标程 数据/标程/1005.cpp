#include <cstdio>
#include <cstring>
#include <algorithm>
#define mk make_pair
#define fi first
#define se second
#define PA pair<int,int>
using namespace std;

int x,y;

PA get(int x){
    if(x<=2){
        if(x==1) return mk(1,1);
        if(x==2) return mk(1,18);
    }
    if(x<=10){
        int k=x-2;
        if(k<=2) return mk(2,k);
        else return mk(2,18-(8-k));
    }
    if(x<=18){
        int k=x-10;
        if(k<=2) return mk(3,k);
        else return mk(3,k+10);
    }
    int k=x-18;
    return mk(4+k/18,(k-1)%18+1);
}

int main(){
    while(scanf("%d%d",&x,&y)!=EOF){
        PA A=get(x);
        PA B=get(y);
        if(A.fi==B.fi){
            if(x==4 && y==5){
                puts("FIRST BIGGER");
                continue;
            }
            if(x==5 && y==4){
                puts("SECOND BIGGER");
                continue;
            }
            if(x==12 && y==13){
                puts("FIRST BIGGER");
                continue;
            }
            if(x==13 && y==12){
                puts("SECOND BIGGER");
                continue;
            }
            if(x==7 && y==8){
                puts("FIRST BIGGER");
                continue;
            }
            if(x==8 && y==7){
                puts("SECOND BIGGER");
                continue;
            }
            if(x==15 && y==16){
                puts("FIRST BIGGER");
                continue;
            }
            if(x==16 && y==15){
                puts("SECOND BIGGER");
                continue;
            }
            if(A.se>B.se) puts("FIRST BIGGER");else puts("SECOND BIGGER");
        }else{
            if(A.fi<B.fi) puts("FIRST BIGGER");
            else puts("SECOND BIGGER");
        }
    }
    return 0;
}

