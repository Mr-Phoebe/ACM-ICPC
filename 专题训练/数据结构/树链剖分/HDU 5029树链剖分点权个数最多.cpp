
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int MAXN = 100010;
struct Edge
{
    int to,next;
} edge[MAXN*2];
int head[MAXN],tot;
int top[MAXN];
int fa[MAXN];
int deep[MAXN];
int num[MAXN];
int p[MAXN];
int fp[MAXN];
int son[MAXN];
int pos;
void init()
{
    tot = 0;
    memset(head,-1,sizeof(head));
    pos = 1;
    memset(son,-1,sizeof(son));
}
void addedge(int u,int v)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}
void dfs1(int u,int pre,int d)
{
    deep[u] = d;    //  深度
    fa[u] = pre;    //  父亲
    num[u] = 1;     //  子孙数
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].to;
        if(v != pre)
        {
            dfs1(v,u,d+1);
            num[u] += num[v];
            if(son[u] == -1 || num[v] > num[son[u]])
                son[u] = v;         //  重儿子
        }
    }
}
void getpos(int u,int sp)
{
    top[u] = sp;
    p[u] = pos++;   //  在线段树中的位置
    fp[p[u]] = u;
    if(son[u] == -1)return;     //  没有重儿子则为轻链，则为叶子
    getpos(son[u],sp);          //  访问重链
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].to;
        if(v != son[u] && v != fa[u])   //  访问轻链，父亲挂在重链上
            getpos(v,v);
    }
}
vector<int>avec[MAXN],dvec[MAXN];
void change(int u,int v,int z)
{
    int f1 = top[u],f2 = top[v];
    int tmp = 0;
    while(f1 != f2)
    {
        if(deep[f1] < deep[f2])
        {
            swap(f1,f2);
            swap(u,v);
        }
        avec[p[f1]].push_back(z);
        dvec[p[u]+1].push_back(z);
        u = fa[f1];
        f1 = top[u];
    }
    if(deep[u] > deep[v])swap(u,v);
    avec[p[u]].push_back(z);
    dvec[p[v]+1].push_back(z);
}
struct Node
{
    int l,r;
    int Max,id;
    void output()
    {
        printf("l %d r %d Max %d id %d\n",l,r,Max,id);
    }
} segTree[MAXN<<2];
void debug(int i)
{
    segTree[i].output();
    if(segTree[i].l == segTree[i].r)return;
    debug(i<<1);
    debug((i<<1)|1);
}
void push_up(int i)
{
    if(segTree[i<<1].Max < segTree[(i<<1)|1].Max)
    {
        segTree[i].Max = segTree[(i<<1)|1].Max;
        segTree[i].id = segTree[(i<<1)|1].id;
    }
    else
    {
        segTree[i].Max = segTree[i<<1].Max;
        segTree[i].id = segTree[i<<1].id;
    }
}
void build(int i,int l,int r)
{
    segTree[i].l = l;
    segTree[i].r = r;
    if(l == r)
    {
        segTree[i].id = l;
        segTree[i].Max = 0;
        return;
    }
    int mid = (l+r)/2;
    build(i<<1,l,mid);
    build((i<<1)|1,mid+1,r);
    push_up(i);
}
void update(int i,int k,int val)
{
    if(segTree[i].l == k && segTree[i].r == k)
    {
        segTree[i].Max += val;
        return;
    }
    int mid = (segTree[i].l+segTree[i].r)/2;
    if(k <= mid)update(i<<1,k,val);
    else update((i<<1)|1,k,val);
    push_up(i);
}
int ans[MAXN];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m;
    while(scanf("%d%d",&n,&m) == 2)
    {
        if(n == 0 && m == 0)break;
        init();
        int u,v;
        for(int i = 1; i < n; i++)
        {
            scanf("%d%d",&u,&v);
            addedge(u,v);
            addedge(v,u);
        }
        dfs1(1,0,0);
        getpos(1,1);
        for(int i = 1; i <= 100000; i++)
        {
            avec[i].clear();
            dvec[i].clear();
        }
        int z;
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&z);
            change(u,v,z);
        }
        build(1,1,100000);
        for(int i = 1; i <= n; i++)
        {
            //debug(1);
            //printf("%d %d\n",avec[i].size(),dvec[i].size());
            for(int j = 0; j < avec[i].size(); j++)
            {
                update(1,avec[i][j],1);
                //printf("%d *\n",avec[i][j]);
            }
            for(int j = 0; j < dvec[i].size(); j++)
            {
                update(1,dvec[i][j],-1);
                //printf("%d **\n",dvec[i][j]);
            }
            u = fp[i];
            //printf("i  %d  %d\n",i,fp[i]);
            if(segTree[1].Max == 0)ans[u] = 0;
            else ans[u] = segTree[1].id;
        }
        for(int i = 1; i <= n; i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}
