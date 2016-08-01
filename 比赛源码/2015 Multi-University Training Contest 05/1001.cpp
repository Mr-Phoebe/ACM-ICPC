#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
typedef double db;
const int N=190000;
struct SAM{
    int go[N][26];
    int fail[N],step[N],tot,last;
    int rt[N];
    void init(){
        tot=last=1;
        memset(go,0,sizeof go);
        memset(fail,0,sizeof fail);
        memset(step,0,sizeof step);
        memset(rt,-1,sizeof rt);
        step[0]=-1;
    }
    void expended(int p){
        ++tot;step[tot]=step[last]+1;
        rt[tot]=p;int g;
        for(g=last;(!go[g][p])&&g;g=fail[g])go[g][p]=tot;
        last=tot;
        if(!g){
            fail[tot]=1;
        }
        else{
            int gt=go[g][p];
            if(step[gt]==step[g]+1){
                fail[tot]=gt;
            }
            else{
                int r=++tot;
                fail[r]=fail[gt];
                rep(i,0,25)go[r][i]=go[gt][i];
                step[r]=step[g]+1;fail[gt]=fail[tot-1]=r;
                for(;g&&go[g][p]==gt;g=fail[g])go[g][p]=r;
            }
        }
    }
    int topxu[N];
    int sum[N];
    void topsort(){
        memset(sum,0,sizeof sum);
        rep(i,1,tot)sum[step[i]]++;
        rep(i,1,tot)sum[i]+=sum[i-1];
        rep(i,1,tot)topxu[sum[step[i]]--]=i;
        per(i,tot,1){
            if(rt[fail[topxu[i]]]==-1)rt[fail[topxu[i]]]=rt[topxu[i]];
        }
    }
}A,B;
char a[N],b[N];
int lena,lenb;
unsigned long long be[27];
void Main(){
    scanf("%s",a+1);lena=strlen(a+1);
    scanf("%s",b+1);lenb=strlen(b+1);
    A.init();
    B.init();
    rep(i,1,lena)A.expended(a[i]-'a');
    per(i,lenb,1)B.expended(b[i]-'a');
    B.topsort();
    memset(be,0,sizeof be);
    rep(i,2,B.tot){
        be[B.rt[i]]+=1ll*(B.step[i]-B.step[B.fail[i]]);
    }
    //rep(j,0,4)printf("%I64u\n",be[j]);
    unsigned long long ans=0;
    rep(i,1,A.tot){
        unsigned long long num=A.step[i]-A.step[A.fail[i]];
        ans+=num;
        rep(j,0,25)if(!A.go[i][j]){
            ans+=num*1ll*be[j];
            //printf("%I64u %d\n",num,j);
        }
    }
    printf("%I64u\n",ans);
}
int main(){
    int T;scanf("%d",&T);
    while(T--)Main();
    return 0;
}


