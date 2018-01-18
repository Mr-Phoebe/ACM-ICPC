#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <stack>
#include <bitset>
#define INF 0x3f3f3f3f
#define eps 1e-8
#define lid id<<1
#define rid id<<1|1
#pragma comment (linker,"/STACK:102400000,102400000") 
using namespace std;
typedef long long LL;
const int maxn=4e5+5;
struct Sam
{
    Sam *next[26],*par;
    int step,id;
}pool[maxn],*root,*last;
int tot;

inline Sam* newnode(int step)
{
    Sam *t=pool+tot;
    t->id=tot++;
    memset(t->next,0,sizeof(t->next));
    t->par=0;
    t->step=step;
    return t;
}

inline void init()
{
    tot=0;
    last=root=newnode(0);
}

int End[maxn];
inline void Extend(int pos,int w)
{
    Sam *p=last;
    Sam *newv=newnode(p->step+1);
    End[pos]=newv->id;
    for(;p&&!p->next[w];p=p->par) p->next[w]=newv;
    if(!p) newv->par=root;
    else
    {
        Sam *q=p->next[w];
        if(q->step==p->step+1) newv->par=q;
        else
        {
            Sam *nq=newnode(p->step+1);
            memcpy(nq->next,q->next,sizeof(q->next));
            nq->par=q->par;
            q->par=nq;
            newv->par=nq;
            for(;p&&p->next[w]==q;p=p->par) p->next[w]=nq;
        }
    }
    last=newv;
}

vector <int> G[maxn];
int L[maxn],R[maxn];
int fa[maxn][20],label;
struct Segtree
{
    int l,r,root;
}tr[maxn*4];

void dfs(int u,int father)
{
    L[u]=++label;
    fa[u][0]=father;
    for(int i=1;i<20;++i) fa[u][i]=fa[fa[u][i-1]][i-1];
    for(int i=0;i<(int)G[u].size();++i)
    {
        int v=G[u][i];
        dfs(v,u);
    }
    R[u]=label;
}

inline void get_tree()
{
    for(int i=0;i<tot;++i) G[i].clear();
    for(int i=0;i<tot;++i) if(pool[i].par) G[pool[i].par->id].push_back(i);
    label=0;
    dfs(0,0);
}

struct SBT
{
    int lc,rc,sz,key;
    void init(int k)
    {
        lc=rc=0;
        sz=1;
        key=k;
    }
}T[maxn*20];
int total;

inline void L_rotate(int &x)
{
    int k=T[x].rc;
    T[x].rc=T[k].lc;
    T[k].lc=x;
    T[k].sz=T[x].sz;
    T[x].sz=T[T[x].lc].sz+T[T[x].rc].sz+1;
    x=k;
}

inline void R_rotate(int &x)
{
    int k=T[x].lc;
    T[x].lc=T[k].rc;
    T[k].rc=x;
    T[k].sz=T[x].sz;
    T[x].sz=T[T[x].lc].sz+T[T[x].rc].sz+1;
    x=k;
}

void Maintain(int &x,bool flag)
{
    if(flag)
    {
        if(T[T[T[x].rc].rc].sz>T[T[x].lc].sz) L_rotate(x);
        else if(T[T[T[x].rc].lc].sz>T[T[x].lc].sz)
        {
            R_rotate(T[x].rc);
            L_rotate(x);
        }
        else return;
    }
    else
    {
        if(T[T[T[x].lc].lc].sz>T[T[x].rc].sz) R_rotate(x);
        else if(T[T[T[x].lc].rc].sz>T[T[x].rc].sz)
        {
            L_rotate(T[x].lc);
            R_rotate(x);
        }
        else return;
    }
    Maintain(T[x].lc,0);
    Maintain(T[x].rc,1);
    Maintain(x,0);
    Maintain(x,1);
}

void Insert(int &x,int k)
{
    if(!x)
    {
        x=++total;
        T[x].init(k);
    }
    else
    {
        T[x].sz++;
        if(k<T[x].key) Insert(T[x].lc,k);
        else Insert(T[x].rc,k);
        Maintain(x,k>=T[x].key);
    }
}

int d_key;
void Delete(int &x,int k)
{
    T[x].sz--;
    if(T[x].key==k||(k<T[x].key&&T[x].lc==0)||(k>T[x].key&&T[x].rc==0))
    {
        if(!T[x].lc||!T[x].rc)
        {
            d_key=T[x].key;
            x=T[x].lc+T[x].rc;
        }
        else
        {
            Delete(T[x].lc,k+1);
            T[x].key=d_key;
        }
    }
    else Delete(k<T[x].key?T[x].lc:T[x].rc,k);
}

void build(int id,int l,int r)
{
    tr[id].l=l;
    tr[id].r=r;
    tr[id].root=0;
    if(l==r) return;
    int mid=(l+r)>>1;
    build(lid,l,mid);
    build(rid,mid+1,r);
}

void updata(int id,int x,int v,int flag)
{
    while(1)
    {
        if(flag) Insert(tr[id].root,v);
        else Delete(tr[id].root,v);
        if(tr[id].l==tr[id].r) break;
        int mid=(tr[id].l+tr[id].r)>>1;
        if(x<=mid) id=lid;
        else id=rid;
    }
}

inline int Find_node(int u,int len)
{
    for(int i=19;i>=0;--i)
    {
        int t=fa[u][i];
        if(pool[t].step>=len) u=t;
    }
    return u;
}

inline int get_cnt(int x,int v)
{
    int res=0;
    while(x)
    {
        if(T[x].key<=v)
        {
            res+=T[T[x].lc].sz+1;
            x=T[x].rc;
        }
        else x=T[x].lc;
    }
    return res;
}

inline int get_kth(int id,int ll,int rr,int k)
{
    while(tr[id].l!=tr[id].r)
    {
        int cnt=get_cnt(tr[lid].root,rr)-get_cnt(tr[lid].root,ll-1);
        if(cnt>=k) id=lid;
        else
        {
            k-=cnt;
            id=rid;
        }
    }
    int cnt=get_cnt(tr[id].root,rr)-get_cnt(tr[id].root,ll-1);
    if(cnt>=k) return tr[id].l;
    else return -1;
}

inline int get_smaller(int x,int v)
{
    int res=0;
    while(x)
    {
        if(T[x].key<v)
        {
            res+=T[T[x].lc].sz+1;
            x=T[x].rc;
        }
        else x=T[x].lc;
    }
    return res;
}

inline bool Find(int x,int v)
{
    while(x)
    {
        if(T[x].key==v) return 1;
        if(T[x].key<v) x=T[x].rc;
        else x=T[x].lc;
    }
    return 0;
}

char str[maxn];
int rt[maxn];
int main()
{
    int T;
    scanf("%d",&T);
    for(int ca=1;ca<=T;++ca)
    {
        printf("Case #%d:\n",ca);
        init();
        scanf("%s",str);
        int len=strlen(str);
        for(int i=0;str[i];++i) Extend(i,str[i]-'a');
        get_tree();
        total=0;
        build(1,1,len);
        int q;
        scanf("%d",&q);
        memset(rt,0,sizeof(rt));
        while(q--)
        {
            int t;
            scanf("%d",&t);
            if(t==1)
            {
                int x,p;
                scanf("%d%d",&x,&p);
                int u=Find_node(End[p],x);
                if(Find(rt[u],x)) continue;
                updata(1,x,L[u],1);
                Insert(rt[u],x);
            }
            else if(t==2)
            {
                int x,p;
                scanf("%d%d",&x,&p);
                int u=Find_node(End[p],x);
                if(!Find(rt[u],x)) continue;
                updata(1,x,L[u],0);
                Delete(rt[u],x);
            }
            else
            {
                int x,p,k;
                scanf("%d%d%d",&x,&p,&k);
                int u=Find_node(End[p],x);
                k+=get_smaller(rt[u],x);
                printf("%d\n",get_kth(1,L[u],R[u],k));
            }
        }
    }
}
