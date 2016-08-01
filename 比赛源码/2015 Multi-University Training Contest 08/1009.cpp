//AC
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
#define rep(i,n) for (int i=0;i<n;++i)
const int N=888888;
double b[4][4]; char s[15];
int n,m,l,r; double k,c[N],ans[N];
struct node{
    double a[4][4];
    node(){rep(i,4) rep(j,4) a[i][j]=i==j;}
    node(double x,double y,double z,double ang){
        double Cos=cos(ang),Sin=sin(ang); rep(i,4) rep(j,4) a[i][j]=i==j;
        a[0][0]=x*x*(1-Cos)+Cos,a[0][1]=x*y*(1-Cos)+z*Sin,a[0][2]=x*z*(1-Cos)-y*Sin;
        a[1][0]=x*y*(1-Cos)-z*Sin,a[1][1]=y*y*(1-Cos)+Cos,a[1][2]=y*z*(1-Cos)+x*Sin;
        a[2][0]=x*z*(1-Cos)+y*Sin,a[2][1]=y*z*(1-Cos)-x*Sin,a[2][2]=z*z*(1-Cos)+Cos;
    }
    void operator *=(const node &A){
        memset(b,0,sizeof(b));
        rep(k,4) rep(i,4) rep(j,4) b[i][j]+=a[i][k]*A.a[k][j];
        memcpy(a,b,sizeof(a));
    }
    node operator -=(const node &A){
        rep(i,4) rep(j,4) a[i][j]-=A.a[i][j]; return *this;
    }
    bool operator !=(const node &A){
        rep(i,4) rep(j,4) if (fabs(a[i][j]-A.a[i][j])>1e-9) return 1;
        return 0;
    }
    double dist(){
        double d=0; rep(i,3) d+=a[3][i]*a[3][i]; return sqrt(d);
    }
    void read(){
        rep(i,4) rep(j,4) a[i][j]=0;
        rep(i,3) scanf("%lf",&a[3][i]); a[3][3]=1;
    }
    void prt(){rep(i,3) printf("%.5lf%s",a[3][i],i<2?" ":"\n");}
}I,U1,U,V,a[N];
#define tree int t,int l,int r
#define left t*2,l,mid
#define right t*2+1,mid+1,r
#define M int mid=l+r>>1
void build(tree)
{
    c[t]=1; if (l==r){a[t].read(); return;} M;
    build(left),build(right);
}
inline void downA(int t){if (a[t]!=I) a[t*2]*=a[t],a[t*2+1]*=a[t],a[t]=I;}
node query(tree,int x)
{
    if (l==r) return a[t]; M; downA(t);
    if (x<=mid) return query(left,x); else return query(right,x);
}
void modify(tree,int ll,int rr,node &U)
{
    if (l==ll && r==rr){a[t]*=U; return;} M; downA(t);
    if (rr<=mid) modify(left,ll,rr,U);
    else if (ll>mid) modify(right,ll,rr,U);
    else modify(left,ll,mid,U),modify(right,mid+1,rr,U);
}
inline void downC(int t)
{if (c[t]!=1) ans[t*2]*=c[t],c[t*2]*=c[t],ans[t*2+1]*=c[t],c[t*2+1]*=c[t],c[t]=1;}
void change(tree,int x,double y)
{
    if (l==r){ans[t]=y; return;} M; downC(t);
    if (x<=mid) change(left,x,y); else change(right,x,y);
    ans[t]=ans[t*2]+ans[t*2+1];
}
double sum(tree,int ll,int rr)
{
    if (l==ll && r==rr) return ans[t]; M; downC(t);
    if (rr<=mid) return sum(left,ll,rr);
    if (ll>mid) return sum(right,ll,rr);
    return sum(left,ll,mid)+sum(right,mid+1,rr);
}
void mul(tree,int ll,int rr,double k)
{
    if (l==ll && r==rr){c[t]*=k,ans[t]*=k; return;} M; downC(t);
    if (rr<=mid) mul(left,ll,rr,k);
    else if (ll>mid) mul(right,ll,rr,k);
    else mul(left,ll,mid,k),mul(right,mid+1,rr,k);
    ans[t]=ans[t*2]+ans[t*2+1];
}
int main()
{
    for (int bg=1; scanf("%d%d",&n,&m),n&&m; bg++)
    {
        printf("Case #%d:\n",bg);
        //memset(a,0,sizeof(a));
        for (int i=0; i<n*4; i++) a[i]=node();
        build(1,1,n);
        for (int i=1;i<n;++i) change(1,1,n,i,(query(1,1,n,i)-=query(1,1,n,i+1)).dist());
        while (m--){
            scanf("%s%d",s,&l);
            if (*s=='C') query(1,1,n,l).prt();
            else{
                scanf("%d",&r);
                if (*s=='L') printf("%.5lf\n",l<r?sum(1,1,n,l,r-1):0);
                else{
                    U.read(); rep(i,3) U.a[i][i]=1;
                    if (*s=='T') modify(1,1,n,l,r,U);
                    else if (*s=='S'){
                        scanf("%lf",&k);
                        rep(i,3) U.a[i][i]=k,U.a[3][i]-=U.a[3][i]*k;
                        modify(1,1,n,l,r,U); if (l<r) mul(1,1,n,l,r-1,k);
                    }else{
                        double x,y,z,ang; scanf("%lf%lf%lf%lf",&x,&y,&z,&ang);
                        rep(i,3) U.a[i][i]=1; U1=U; rep(i,3) U.a[3][i]*=-1;
                        double d=sqrt(x*x+y*y+z*z); x/=d,y/=d,z/=d,d=sqrt(y*y+z*z);
                        U*=node(x,y,z,ang),U*=U1,modify(1,1,n,l,r,U);
                    }
                    if (l>1) change(1,1,n,l-1,(query(1,1,n,l-1)-=query(1,1,n,l)).dist());
                    if (r<n) change(1,1,n,r,(query(1,1,n,r)-=query(1,1,n,r+1)).dist());    
                }
            }
        }
    }
    return 0;
}