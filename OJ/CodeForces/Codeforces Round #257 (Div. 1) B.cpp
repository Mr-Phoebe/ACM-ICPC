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
#define d first.first
#define idx first.second
#define mp(a,b) make_pair(a,b)
#define eps 1e-9
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef complex<ld> point;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<pair<ll, int>, int> plii;
typedef pair<long long int,int> pli;

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

const int MAXN=100010;

vector <pii> graph[MAXN];
vector <pii> trains;
int n,m,k;
ll dist[MAXN];
bool used[MAXN];

void dijsktra()
{
    priority_queue <plii,vector<plii> , greater<plii> > pq;
    pq.push(mp(mp(0,1),0));
    int i,j,u,v;
    plii now;pii next;
    CLR(dist,-1);CLR(used,false);
    while (!pq.empty())
    {
        now=pq.top();
        pq.pop();
        if (dist[now.idx]!=-1) continue;
        dist[now.idx]=now.d;
        if (now.second !=0)
            used[now.second]=true;
        for (i=0; i<graph[now.idx].size(); i++)
        {
            next=graph[now.idx][i];
            pq.push(mp(mp(next.first+now.d,next.second),0));
        }
        if (now.idx==1)
        {
            for (i=0; i<trains.size(); i++)
            {
                next=trains[i];
                pq.push(mp(mp(next.first+now.d,next.second),i+1));
            }
        }
    }
}

int main()
{
    read(n),read(m),read(k);
    int i,u,v;
    ll w,ans=0;
    for (i=0; i<m; i++)
    {
        read(u),read(v),read(w);
        graph[u].push_back(mp(w,v));
        graph[v].push_back(mp(w,u));
    }
    for (i=0; i<k; i++)
    {
        read(u),read(w);
        trains.push_back(mp(w,u));
    }
    dijsktra();
    for (i=1; i<=k; i++)
        if (used[i]==false)
                ans++;
    write(ans),putchar('\n');
    return 0;
}
