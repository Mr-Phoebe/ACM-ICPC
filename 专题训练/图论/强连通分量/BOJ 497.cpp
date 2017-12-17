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

#define up(i, lower, upper) for(int i = lower; i < upper; i++)
#define down(i, lower, upper) for(int i = upper-1; i >= lower; i--)

using namespace std;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef long long ll;
typedef unsigned long long ull;

const double pi = acos(-1.0);

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

///---------------------------------------------------------
vector<int> v[2010];
int out[2010], dfn[2010], low[2010], instack[2010], stackk[2010], n, m, belong[2010];
int indexx, cnt, top, head[2010];
int dis[2010];
queue<int> q;
void tarjan(int u)
{
    int tmp, sz;
    dfn[u] = low[u] = cnt++;
    instack[u] = 1;
    stackk[++top] = u;
    sz = v[u].size();
    up(i, 0, sz)
    {
        if(dfn[v[u][i]] == -1)
        {
            tarjan(v[u][i]);
            low[u] = min(low[u], low[v[u][i]]);
        }
        else if(instack[v[u][i]]) low[u] = min(low[u], dfn[v[u][i]]);
    }
    if(low[u] == dfn[u])
    {
        indexx++;
        do
        {
            tmp = stackk[top--];
            instack[tmp] = 0;
            belong[tmp] = indexx;
        }
        while(top != 0 && tmp != u);
    }
}

void spfa(int src)
{
    //printf("%d----\n", src);
    memset(dis, 0x3f, sizeof dis);
    dis[src] = 0;
    q.push(src);
    while(!q.empty())
    {
        int tmp = q.front();
        q.pop();
        int sz = v[tmp].size();
        up(i, 0, sz)
        {
            if(belong[tmp] == belong[v[tmp][i]])
            {
                if(dis[tmp] < dis[v[tmp][i]])
                    dis[v[tmp][i]] = dis[tmp], q.push(v[tmp][i]);
            }
            else if(dis[tmp]+1 < dis[v[tmp][i]])
                dis[v[tmp][i]] = dis[tmp]+1, q.push(v[tmp][i]);
            //printf("from %d to %d\n", dis[tmp], dis[v[tmp][i]]);
        }
    }
}

int main()
{
	freopen("data.txt","r",stdin); 
    int nn;
    read(nn);
    while(nn--)
    {
        memset(dfn, -1, sizeof(dfn));
        memset(low, -1, sizeof(low));
        memset(head, -1, sizeof(head));
        memset(instack, 0, sizeof(instack));
        memset(belong, 0, sizeof(belong));
        memset(out, 0, sizeof(out));
        indexx = 0, cnt = 1;
        top = 0;
        int from, to, k;
        read(n), read(m), read(k);
        up(i, 0, m)
        {
            read(from), read(to);
            v[from].push_back(to);
        }
/*
        up(i, 1, n+1)
        {
        	up(j, 0, v[i].size())
				cout<<v[i][j]<<" "; 
			cout<<endl;
        }
*/			
        up(i, 1, n+1) if(dfn[i] == -1) tarjan(i);
//        up(i, 1, n+1) printf("%d ", belong[i]); puts("");
        int src, des;
        read(src), read(des);
        if(belong[src] == belong[des]) puts("Input Error");
        else
        {
            //printf("%d---\n", src);
            spfa(src);
//          for(int i=1;i<=n;i++)
//            	cout<<dis[i]<<" ";
            if(dis[des] <= k) puts("Good Job");
            else puts("Sad");
        }
        up(i, 1, n+1) v[i].clear();
    }
    return 0;
}
