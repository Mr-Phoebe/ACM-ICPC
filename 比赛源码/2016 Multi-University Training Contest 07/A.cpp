#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
// =============== MemoryPool ===============
template<class T>struct Pool{
    T *a,**q; int pa,pq;
    Pool(int MAXN){a=new T[MAXN];q=new T*[MAXN];pa=pq=0;}
//  ~Pool(){delete[] a; delete[] q;}
    void clear(){pa=pq=0;}
    T* NEW(){return pq ? q[--pq] : &a[pa++];}
    void DELETE(T* x){q[pq++]=x; return;}
    int IDX(T*x){return x-a;}
};

typedef long long LL;
const LL INF=0x3f3f3f3f3f3f3f3fLL;
#define REP(i,n) for(int i=0;i<n;++i)

// =============== KD-Tree ===============
#define rangeCalc
template<class T>inline bool updmx(T& A,const T& B){return A<B?A=B,1:0;}
template<class T>inline bool updmn(T& A,const T& B){return A>B?A=B,1:0;}
LL dcmp(const LL& x){return x==0 ? 0 : (x<0 ? -1 : 1);}
//please KDT::clear() before use
namespace KDT{
    const int MAXN=1500010;
    const double SGTA=0.8;// Scapegoat Tree Const
    struct Point{
        int x[2];int i;
        int& operator[](int i){return x[i];}
        const int& operator[](int i)const{return x[i];}
        bool operator<(const Point& B){return x[0]<B.x[0]||(x[0]==B.x[0]&&x[1]<B.x[1]);}
    };
    struct ct{
        int sz;
        int mxD[2],mnD[2];
        ct(){sz=0;}
        explicit ct(const Point& P):sz(1){REP(i,2)mxD[i]=mnD[i]=P[i];}
        bool empty()const{return sz==0;}
    }ct0;
    ct& operator +=(ct& A, const ct& B){
        if(A.empty())return A=B;
        if(!B.empty()){
            A.sz+=B.sz;
            REP(i,2)updmx(A.mxD[i],B.mxD[i]),updmn(A.mnD[i],B.mnD[i]);
        }
        return A;
    }
    struct node{
        node *l,*r;Point v;ct c;
        node(){}
        explicit node(const Point& v):v(v),c(ct(v)){}
    };
    Pool<node>pool(MAXN);
    void clear(){pool.clear();}
    struct cmp{
        int D;cmp(int D):D(D){}
        bool operator()(const Point& A,const Point& B)const{return A[D]<B[D];}
    };
    node* build(int d,Point* A,int l,int r){
        if(l>r) return 0;
        int M=(l+r)>>1;
        nth_element(A+l,A+M,A+r+1,cmp(d));
        node *o=new(pool.NEW())node(A[M]);
        o->l=build(!d,A,l,M-1); o->r=build(!d,A,M+1,r);
        if(o->l)o->c+=o->l->c;
        if(o->r)o->c+=o->r->c;
        return o;
    }
    Point A[MAXN];int AN;
    void eraseAll(node* o){if(!o)return;A[++AN]=o->v;eraseAll(o->l);eraseAll(o->r);pool.DELETE(o);}
    void rebuild(node*& o,int d){AN=0;eraseAll(o);o=build(d,A,1,AN);}
    void insert(node*& rt,const Point& iP){
        node *np=new(pool.NEW())node(iP);
        if(!rt){rt=np;return;}
        static node* sk[MAXN];static int tp;tp=0;
        node *o=rt;
        for(int d=0;;d=!d){
            sk[tp++]=o;
            o->c+=np->c;
            if(iP[d]<o->v[d]){
                if(!o->l){o->l=np;break;}
                o=o->l;
            }else{
                if(!o->r){o->r=np;break;}
                o=o->r;
            }
        }
        sk[tp++]=o;
        if(tp<log(rt->c.sz)/log(1/SGTA))return;
        for(o=sk[--tp];(o->l?o->l->c.sz:0)<SGTA*o->c.sz
                &&(o->r?o->r->c.sz:0)<SGTA*o->c.sz;o=sk[--tp]);
        if(o==rt){rebuild(rt,0);return;}
        node* p=sk[--tp];
        rebuild(p->l==o?p->l:p->r,tp&1);
    }
    LL sqr(int x){return (LL)x*x;}
    Point qP;
    LL getdis(node* o){
        LL res=0;
        REP(d,2){
            if(qP[d]<o->c.mnD[d])res+=sqr(o->c.mnD[d]-qP[d]);
            if(o->c.mxD[d]<qP[d])res+=sqr(qP[d]-o->c.mxD[d]);
        }
        return res;
    }
    LL res; Point resP;
    LL res2; Point resP2;
    void query(int d, node* o){
        LL d0=0; REP(i,2)d0+=sqr(o->v[i]-qP[i]);
        if(d0<res||(d0==res&&o->v<resP))res2=res,resP2=resP,res=d0,resP=o->v;
        else if(d0<res2||(d0==res2&&o->v<resP2))res2=d0,resP2=o->v;
        LL dl=o->l?getdis(o->l):INF;
        LL dr=o->r?getdis(o->r):INF;
        if(dl<dr){
            if(dl<=res2)query(!d,o->l);
            if(dr<=res2)query(!d,o->r);
        }else{
            if(dr<=res2)query(!d,o->r);
            if(dl<=res2)query(!d,o->l);
        }
    }
    Point query(node*& rt, const Point& p){
        qP=p;res=INF;res2=INF;query(0,rt);return resP2;
    }
}

const int maxn=100010;

int n,q;
KDT::Point a[maxn];

int pa[maxn];
int findset(int x){return pa[x]==x ? x : pa[x]=findset(pa[x]);}

void solve(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;++i){
        scanf("%d%d",&a[i][0],&a[i][1]);
        a[i].i=i;
    }
    KDT::node *rt=KDT::build(0,a,1,n);
    for(int i=1;i<=n;++i)pa[i]=i;
    for(int _i=1;_i<=n;++_i){
        int i=a[_i].i,j=query(rt,a[_i]).i;
        int p=findset(i),q=findset(j);
        pa[p]=q;
    }
    while(q--){
        int x,y;scanf("%d%d",&x,&y);
        puts(findset(x)==findset(y) ? "YES" : "NO");
    }
}
int main(){
    int kase,i=0;scanf("%d",&kase);
    while(kase--){
        printf("Case #%d:\n",++i);
        solve();
    }
    return 0;
}