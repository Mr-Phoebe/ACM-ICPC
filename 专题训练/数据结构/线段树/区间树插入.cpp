#include<iostream>
#include<cstdio>
using namespace std;

int n,m,l,r;//����n���߶���m
struct line{
    int left,right;
    int n;
}a[30000];

void buildt(int l,int r,int step){
    a[step].left=l;
    a[step].right=r;
    a[step].n=0;
    if(l==r) return;
    buildt(l,(l+r)/2,step*2);
    buildt((l+r)/2+1,r,step*2+1);
}

void dfs(int step){
    cout<<step<<"    "<<a[step].left<<"    "<<a[step].right<<"    "<<a[step].n<<endl;
    if(a[step].left==a[step].right) return;
    dfs(step*2);
    dfs(step*2+1);
}

void insert(int s,int t,int step){
    if(s==a[step].left&&t==a[step].right){
        a[step].n++;
        return;
    }
    if(a[step].left==a[step].right) return;
    int mid=(a[step].left+a[step].right)/2;
    if(mid>=t) insert(s,t,step*2);
    else if(mid<s) insert(s,t,step*2+1);
    else{
        insert(s,mid,step*2);
        insert(mid+1,t,step*2+1);
    }
}

int main(){
    cin>>n>>m;
    buildt(0,n,1);
    //dfs(1);
    for(int i=0;i<m;i++){
        cin>>l>>r;
        insert(l,r,1);
    }
    dfs(1);
    return 0;
}
