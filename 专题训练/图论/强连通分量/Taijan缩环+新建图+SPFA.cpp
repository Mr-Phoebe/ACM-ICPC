#include <bits/stdc++.h>

#define MAXN 4005
#define eps 1e-14
#define MOD 1000000009
#define INF 0x3f3f3f3f

#define test

#define For(i,m,n) for(int i=(m);i<(n);i++)
#define vecfor(iter,a) for(vector<int>::iterator iter=a.begin();iter!=a.end();iter++)
#define rep(i,m,n) for(int i=(m);i<=(n);i++)
#define LL long long

/*author birdstorm*/
using namespace std;
const double pi=acos(-1.0);

template<class T>
inline bool read(T &n)
{
    T x=0, tmp=1;
    char c=getchar();
    while((c < '0' || c > '9') && c != '-' && c != EOF) c=getchar();
    if(c == EOF) return false;
    if(c == '-') c=getchar(), tmp=-1;
    while(c >= '0' && c <= '9') x *= 10, x += (c - '0'),c=getchar();
    n=x*tmp;
    return true;
}

template <class T>
inline void write(T n)
{
    if(n < 0)
    {
        putchar('-');
        n=-n;
    }
    int len=0,data[20];
    while(n)
    {
        data[len++]=n%10;
        n /= 10;
    }
    if(!len) data[len++]=0;
    while(len--) putchar(data[len]+48);
}

struct strongly_connected_components
{
    vector<int> &color;
    vector<int> Stack;
    int colorcnt, curr, *instack, *dfn, *low, *info, *next, *to;
    void dfs(int x)
    {
        dfn[x]=low[x]=++curr;
        Stack.push_back(x);
        instack[x]=1;
        for(int j=info[x]; j; j=next[j])
        {
            int idx=to[j];
            if(!instack[idx])
            {
                dfs(idx);
                low[x]=min(low[x],low[idx]);
            }
            else if(instack[idx]==1)
            {
                low[x]=min(low[x],dfn[idx]);
            }
        }
        if(low[x]==dfn[x])
        {
            while(Stack.back()!=x)
            {
                color[Stack.back()]=colorcnt;
                instack[Stack.back()]=2;
                Stack.pop_back();
            }
            color[Stack.back()]=colorcnt++;
            instack[Stack.back()]=2;
            Stack.pop_back();
        }
    }
    strongly_connected_components(const vector<pair<int, int> > &edgelist, int n, vector<int> &ans):color(ans)
    {
        color.resize(n+2);
        instack = new int[n+2];
        dfn = new int[n+2];
        low = new int[n+2];
        info = new int [n+2];
        next = new int[(int)edgelist.size()+5];
        to = new int[(int)edgelist.size()+5];
        fill_n(info,n+2,0);
        int sz=edgelist.size();
        For(i,0,sz)
        {
            to[i+1]=edgelist[i].second;
            next[i+1]=info[edgelist[i].first];
            info[edgelist[i].first]=i+1;
        }
        fill_n(instack,n+2,0);
        colorcnt=curr=0;
        rep(i,1,n)
        {
            if(!instack[i]) dfs(i);
        }
        delete[] instack;
        delete[] dfn;
        delete[] low;
        delete[] info;
        delete[] next;
        delete[] to;
    }
};
vector<pair<int,int> > e;
vector<int> ans, ne[MAXN];
int x[MAXN], y[MAXN];
bool inque[MAXN];
int dist[MAXN];
queue<int> que;
bool spfa(int r, int en, int k)
{
    memset(dist,0x3f,sizeof dist);
    dist[r]=0;
    while(!que.empty()) que.pop();
    que.push(r);
    inque[r]=true;
    while(!que.empty())
    {
        int u=que.front();
        que.pop();
        int sz=ne[u].size();
        For(i,0,sz)
        {
            int idx=ne[u][i];
            if(dist[u]+1<dist[idx])
            {
                dist[idx]=dist[u]+1;
                if(!inque[idx])
                {
                    inque[idx]=true;
                    que.push(idx);
                }
            }
        }
        inque[u]=false;
    }
    if(dist[en]>k) return false;
    else return true;
}

inline void addedge(int x, int y)
{
    ne[x].push_back(y);
}
int main()
{
    int t;
    int n, m, k;
    int st, en;
    read(t);
    while(t--)
    {
        e.clear();
        ans.clear();
        read(n), read(m), read(k);
        rep(i,0,n)
            ne[i].clear();
        For(i,0,m)
        {
            read(x[i]), read(y[i]);
            e.push_back(make_pair(x[i],y[i]));
        }
        read(st), read(en);
        strongly_connected_components D(e,n,ans);
        if(ans[st]==ans[en])
        {
            printf("Input Error\n");
            continue;
        }
        For(i,0,m)
            if(ans[x[i]]!=ans[y[i]])
            {
                addedge(ans[x[i]],ans[y[i]]);
            }
        if(spfa(ans[st],ans[en],k)) printf("Good Job\n");
        else printf("Sad\n");
    }
    return 0;
}
