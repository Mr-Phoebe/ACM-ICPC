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
    T x = 0, tmp = 1;
    char c = getchar();
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


const int N=2000;   	// 点的个数
const int M=12000;	// 单向边的个数


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


int num[2000],b[2000];
ISAP g;

int main()
{
    freopen("data.txt","r",stdin);
    int temp,n,m;;
    for(int i=0; i<=12; i++)
        b[i]=1<<i;
    while(read(n)&&read(m))
    {
        CLR(num,0);
        g.Clearall();
        g.Resize(1+(1<<m)+m+2);  // 源 人 星球 汇 多放一个点
        for(int i=0; i<n; i++)
        {
            int sta=0;
            for(int j=0; j<m; j++)
            {
                read(temp);
                if(temp)
                    sta|=b[j];
            }
            num[sta]++;
        }
        int k=1<<m;     //更新人的状态数
        for(int i=0; i<m; i++)
        {
            read(temp);
            g.Addedge(i+k+2,k+m+2,temp);       // 将星球和汇连接
        }
        for(int i=0; i<k; i++)
        {
            if(!num[i]) continue;
            g.Addedge(1,i+2,num[i]);
            for(int j=0; j<m; j++)
                if(i&b[j])
                    g.Addedge(i+2,j+k+2,INF);
        }
        int flow=g.MaxFlow(1,k+m+2);
        if(flow>=n)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
