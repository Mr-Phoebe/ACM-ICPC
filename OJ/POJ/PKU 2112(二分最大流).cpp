#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <cmath>
#define CLR(x,y) memset(x,y,sizeof(x))
#define mp(x,y) make_pair(x,y)
#define eps 1e-9
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

template<class T>
inline bool read(T &n)
{
    T x = 0, tmp = 1; char c = getchar();
    while((c < '0' || c > '9') && c != '-' && c != EOF) c = getchar();
    if(c == EOF) return false;
    if(c == '-') c = getchar(), tmp = -1;
    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c = getchar();
    n = x*tmp;
    return true;
}
template <class T>
inline void write(T n)
{
    if(n < 0)
    {
        putchar('-');
        n = -n;
    }
    int len = 0,data[20];
    while(n)
    {
        data[len++] = n%10;
        n /= 10;
    }
    if(!len) data[len++] = 0;
    while(len--) putchar(data[len]+48);
}
//-----------------------------------

const int M=60000;
const int N=400;

struct ISAP
{
    struct nedge
    {
        int u,v,next;
        ll c;
    } e[M*2];
    int head[N],tot,n;
    int ss,tt;

    void Resize(int n)
    {
        this->n=n;
    }

    void Clearall()
    {
        tot=1;
        CLR(head,0);
    }

    void Addedge(int u,int v,ll w)
    {
        e[++tot].v=v;
        e[tot].u=u;
        e[tot].c=w;
        e[tot].next=head[u];
        head[u]=tot;
        e[++tot].v=u;
        e[tot].u=v;
        e[tot].c=0;
        e[tot].next=head[v];
        head[v]=tot;
    }

    int dep[N],gap[N];

    void bfs()
    {
        CLR(dep,-1);
        CLR(gap,0);
        queue<int> que;
        gap[0]=1;
        dep[tt]=0;
        que.push(tt);
        while(!que.empty())
        {
            int u=que.front();
            que.pop();
            for(int i=head[u]; i; i=e[i].next)
                if(dep[e[i].v]==-1)
                {
                    que.push(e[i].v);
                    dep[e[i].v]=dep[u]+1;
                    ++gap[dep[e[i].v]];
                }
        }
    }

    int res,cur[N],num[N];
    int top;
    int MaxFlow(int s,int t)
    {
        this->ss=s;
        this->tt=t;
        bfs();
        top=res=0;
        memcpy(cur,head,sizeof(head));
        int u=ss,i;
        while(dep[ss]<n)
        {
            if(u==tt)
            {
                int temp=INF;
                int inser;
                for(i=0; i<top; i++)
                    if(temp>e[num[i]].c)
                    {
                        temp=e[num[i]].c;
                        inser=i;
                    }
                for(i=0; i<top; i++)
                {
                    e[num[i]].c-=temp;
                    e[num[i]^1].c+=temp;
                }
                res+=temp;
                top=inser;
                u=e[num[top]].u;
            }
            if(u!=tt && gap[dep[u]-1]==0)
                break;
            for(i=cur[u]; i; i=e[i].next)
                if(e[i].c != 0 && dep[u]==dep[e[i].v]+1)
                    break;
            if(i)
            {
                cur[u]=i;
                num[top++]=i;
                u=e[i].v;
            }
            else
            {
                int mi=n;
                for(i=head[u]; i; i=e[i].next)
                    if(e[i].c>0 && mi>dep[e[i].v])
                    {
                        mi=dep[e[i].v];
                        cur[u]=i;
                    }
                --gap[dep[u]];
                dep[u]=mi+1;
                ++gap[dep[u]];
                if(u!=ss)
                    u=e[num[--top]].u;
            }
        }
        return res;
    }

    void print()
    {
        puts("GRAPH:");
        for(int i=0; i<=n; i++)
        {
            if(!head[i])
                continue;
            printf("%d ->",i);
            for(int j=head[i]; j; j=e[j].next)
                printf("%d(%I64d) ",e[j].v,e[j].c);
            putchar('\n');
        }
    }
};

int k,c,m,s,t;
int g[N][N],max_dis=-1;
ISAP a;

bool build(int mid)
{
    a.Clearall();
    for(int i=1;i<=k;i++)
        a.Addedge(s,i,m);
    for(int i=1;i<=c;i++)
        a.Addedge(k+i,t,1);
    for(int i=1;i<=k;i++)
        for(int j=1+k;j<t;j++)
            if(g[i][j]<=mid)
                a.Addedge(i,j,1);
    if(a.MaxFlow(s,t)>=c)
        return true;
    return false;
}

void floyd()
{
    for(int k=1;k<t;k++)
        for(int i=1;i<t;i++)
            for(int j=1;j<t;j++)
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
}

int solve()
{
    int l=0,r=max_dis,mid,ans;
    while(l<=r)
    {
        mid=(l+r)>>1;
        if(build(mid))
            ans=mid,r=mid-1;
        else
            l=mid+1;
    }
    return ans;
}


int main()
{
//    freopen("data.txt","r",stdin);
	read(k),read(c),read(m);
	s=0,t=k+c+1;
	a.Resize(t+1);

	for(int i=1;i<t;i++)
        for(int j=1;j<t;j++)
        {
            read(g[i][j]);
            if(!g[i][j])
                g[i][j]=INF;
        }
    floyd();
    for(int i=1;i<t;i++)
        for(int j=1;j<t;j++)
            if(g[i][j]!=INF)
                max_dis=max(max_dis,g[i][j]);
    write(solve());
    putchar('\n');
    return 0;
}

