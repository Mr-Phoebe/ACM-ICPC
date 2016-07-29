#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<map>
#include<cstring>
#define ll long long
#define N 100

using namespace std;

int l1,l2,i,j,k,Maxa,Maxb;
map<char,int>pat;
string a,b;
int p1[N],p2[N];
int Comba[N],Combb[N];//记录下连牌时的最大牌的数字
void re(int* q){for(i=0;i<N;i++)q[i]=0;}
void solve(){
    re(Comba);re(Combb);
    for(i=3;i<=17;i++){
        if(p1[i])Comba[p1[i]]=i;
        if(p2[i])Combb[p2[i]]=i;
    }
    if(p1[16]&&p1[17])Comba[4]=17;//双王MAX
    if(p2[16]&&p2[17])Combb[4]=17;
    if(Comba[4]>=Combb[4]&&Comba[4]){printf("Yes\n");return;}//火箭和炸弹

    else if(Comba[4]&&l1==4){printf("Yes\n");return;}
    else if(Comba[4]&&l1==6){printf("Yes\n");return;}

    else if(l1==1){printf("Yes\n");return;}
    else if(Comba[2]&&l1==2){printf("Yes\n");return;}
    else if(Comba[3]&&l1==3){printf("Yes\n");return;}

    else if(Comba[2]&&Comba[3]&&l1==5){printf("Yes\n");return ;}
    else if(Comba[1]&&Comba[3]&&l1==4){printf("Yes\n");return ;}

    else if(Comba[4]<Combb[4]){printf("No\n");return;}

    else if(Maxa>=Maxb){printf("Yes\n");return;}//单牌


    else if(Comba[2]>=Combb[2]&&Comba[2]){printf("Yes\n");return;}//对牌


    else if(Comba[3]>=Combb[3]&&Comba[3]){printf("Yes\n");return;}//三张牌

    printf("No\n");
}
int main(){
    int t;
    ios_base::sync_with_stdio(false);
    pat['3']=3;pat['4']=4;pat['5']=5;pat['6']=6;
    pat['7']=7;pat['8']=8;pat['9']=9;pat['T']=10;
    pat['J']=11;pat['Q']=12;pat['K']=13;pat['A']=14;
    pat['2']=15;pat['X']=16;pat['Y']=17;
    cin>>t;
    while(t--){
        cin>>a>>b;
        Maxa=Maxb=0;
        l1=a.size();
        l2=b.size();
        for(i=0;i<l1;i++){
            p1[pat[a[i]]]++;
            if(pat[a[i]]>Maxa)Maxa=pat[a[i]];
        }
        for(i=0;i<l2;i++){
            p2[pat[b[i]]]++;
            if(pat[b[i]]>Maxb)Maxb=pat[b[i]];
        }
        solve();
        re(p1);re(p2);
    }
    return 0;
}