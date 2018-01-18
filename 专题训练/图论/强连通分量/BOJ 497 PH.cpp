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

const int MAXN=2014;

struct Edge
{
    int to,next;
}e[2*MAXN];
int head[MAXN];
int out[MAXN],dfn[MAXN],low[MAXN],instack[MAXN],stackk[MAXN],n,m,k,belong[MAXN];
int tot=0,cnt=1,idx=0,top=0;
int dis[MAXN],vis[MAXN];
queue<int> q;

void add_edge(int u,int v)
{
    e[tot].to=v;
    e[tot].next=head[u];
    head[u]=tot++;
}

void tarjan(int u)
{
    int temp;
    dfn[u]=low[u]=cnt++;
    instack[u]=1;
    stackk[++top]=u;
    for(int i=head[u];i!=-1;i=e[i].next)
    {
        int v=e[i].to;
        if(dfn[v]==-1)
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(instack[v])
            low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u])
    {
        idx++;
        do
        {
            temp=stackk[top--];
            instack[temp]=0;
            belong[temp]=idx;
        }
         while(top && temp!=u);
    }
}

void spfa(int src)
{
    CLR(dis,INF);
    dis[src]=0;
    vis[src]=1;
    q.push(src);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=head[u];i!=-1;i=e[i].next)
        {
            int v=e[i].to;
            if(belong[u]==belong[v])
            {
                if(dis[v]>dis[u])
                {
                    dis[v]=dis[u];
                    if(!vis[v])
                    {
                        q.push(v);vis[v]=1;
                    }
                }
            }
            else if(dis[v]>dis[u]+1)
            {
                dis[v]=dis[u]+1;
                if(!vis[v])
                {
                    q.push(v);vis[v]=1;
                }

            }
        }
        vis[u]=0;
    }
}

int main()
{
//    freopen("data.txt","r",stdin);
    int T;
    read(T);
    while(T--)
    {
        CLR(dfn,-1);
        CLR(low,-1);
        CLR(head,-1);
        CLR(instack,0);
        CLR(belong,0);
        CLR(out,0);
        idx=0;cnt=1;top=0;tot=0;
        int u,v;
        read(n),read(m),read(k);
        for(int i=0;i<m;i++)
        {
            read(u),read(v);
            add_edge(u,v);
        }
/*
        for(int i=1;i<=n;i++)
        {
            cout<<i<<":";
            for(int j=head[i];j!=-1;j=e[j].next)
                cout<<e[j].to<<" ";
            cout<<endl;
        }
        */
        for(int i=1;i<=n;i++)
            if(dfn[i]==-1)
                tarjan(i);
/*
        for(int i=1;i<=n;i++)
            printf("%d ", belong[i]);
        cout<<endl;
        */
        int s,t;
        read(s),read(t);
        if(belong[s]==belong[t])
            puts("Input Error");
        else
        {
            spfa(s);
/*
            for(int i=1;i<=n;i++)
                cout<<dis[i]<<" ";
            cout<<endl;
            */
            if(dis[t]<=k)
                puts("Good Job");
            else
                puts("Sad");
        }
    }
    return 0;
}
