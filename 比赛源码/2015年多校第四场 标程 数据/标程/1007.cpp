#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct bian{
    int next,point;
}b[410000];
struct ask{
    int l,r,where;
}q[110000];
struct atom{
    int where,size;
}s[110000];
long long d[110000];
int lim=700,R[800],len,n,m,p[110000],f[110000],size[110000],K,where[110000],an[110000],ans;
void ade(int k1,int k2){
    d[k1]++; b[++len]=(bian){p[k1],k2}; p[k1]=len;
}
void add(int k1,int k2){
    ade(k1,k2); ade(k2,k1);
}
int compare(ask k1,ask k2){
    return where[k1.l-1]<where[k2.l-1]||(where[k1.l-1]==where[k2.l-1]&&k1.r<k2.r);
}
int findfather(int k1){
    while (f[k1]!=k1) k1=f[k1]; return k1;
}
void addin(int l,int r,int lim){
    int head=0;
//    cout<<"solve "<<l<<" "<<r<<" "<<lim<<endl;
//    for (int i=1;i<=n;i++) cout<<f[i]<<" "; cout<<endl;
//    for (int i=1;i<=n;i++) cout<<size[i]<<" "; cout<<endl;
    for (int k=l;k<=r;k++){
        int k1=findfather(k);
        for (int i=p[k];i;i=b[i].next){
            int j=b[i].point;
            if (j>k&&j<=lim){
                int k2=findfather(j);
                if (k1!=k2){
                    ans--;
                    if (size[k1]>size[k2]){
                        f[k2]=k1; s[++head]=(atom){k2,size[k2]};
                    } else {
                        s[++head]=(atom){k1,size[k1]}; f[k1]=k2;
                        if (size[k1]==size[k2]){
                            s[++head]=(atom){k2,size[k2]}; size[k2]++;
                        }
                        k1=k2;
                    }
                }
            }
        }
    }
    while (head){
        size[s[head].where]=s[head].size; f[s[head].where]=s[head].where; head--;
    }
//    cout<<"end"<<endl;
}
int getint(){
	char ch=getchar(); while (ch<'0'||ch>'9') ch=getchar();
	int x=0; while (ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x;
}
void solve(){
    for (int i=1;i<=n;i++){
        d[i]=0; p[i]=0;
    }
    memset(R,0x00,sizeof R);
    len=0;
    
    for (int i=1;i<=m;i++){
        int k1=getint(),k2=getint();
        add(k1,k2);
    }
    for (int i=1;i<=n;i++) d[i]+=d[i-1];
    len=0; if (n<=1000&&m<=1000) lim=30; else lim=800;
    while (R[len]!=n){
        len++; R[len]=R[len-1]+1; 
        while (R[len]<=n&&d[R[len]]-d[R[len-1]]<=lim&&R[len]-R[len-1]<=lim) R[len]++;
        R[len]=max(R[len]-1,R[len-1]+1);
    }
    for (int i=1;i<=K;i++){
        q[i].l=getint(); q[i].r=getint();
        q[i].where=i;
    }
    for (int i=1;i<=len;i++)
        for (int j=R[i-1]+1;j<=R[i];j++) where[j]=i;
//    for (int i=1;i<=n;i++) cout<<where[i]<<" "; cout<<endl;
    sort(q+1,q+K+1,compare);
    int now=1; where[n+1]=len+1;
    for (int num=1;num<=len+1;num++){
    //    cout<<where[q[now].l-1]+1<<endl;
        if (now>K||where[q[now].l-1]+1!=num) continue;
        for (int i=1;i<=n;i++){
            f[i]=i; size[i]=1;
        }
        ans=n;
        while (now<=K&&where[q[now].l-1]==where[q[now].r]){
            addin(q[now].l,q[now].r,q[now].r); an[q[now].where]=ans; ans=n; now++;
        }
//        cout<<"asd"<<endl;
        for (int k=R[num-1]+1;k<=n;k++){
            int k1=findfather(k);
            for (int i=p[k];i;i=b[i].next){
                int j=b[i].point;
                if (j<k&&j>=R[num-1]+1){
                    int k2=findfather(j);
                    if (k1!=k2){
                        ans--;
                        if (size[k1]>size[k2]) f[k2]=k1; 
                        else {
                            f[k1]=k2; if (size[k1]==size[k2]) size[k2]++;
                            k1=k2;
                        }
                    }
                }
            }
            int preans=ans;
            while (now<=K&&where[q[now].l-1]+1==num&&q[now].r==k){
        //        cout<<"solve "<<q[now].l<<" "<<q[now].r<<" "<<R[num-1]+1<<" "<<q[now].where<<endl;
        //        for (int i=1;i<=n;i++) cout<<f[i]<<" "; cout<<endl;
        //        for (int i=1;i<=n;i++) cout<<size[i]<<" "; cout<<endl;
                addin(q[now].l,R[num-1],q[now].r); an[q[now].where]=ans; ans=preans; now++;
            }
            if (where[q[now].l-1]+1!=num) break;
        }
    }
    //cout<<now<<endl;
    for (int i=1;i<=K;i++) printf("%d\n",an[i]);
}
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
    while (scanf("%d%d%d",&n,&m,&K)!=EOF) solve();
    return 0;
}
