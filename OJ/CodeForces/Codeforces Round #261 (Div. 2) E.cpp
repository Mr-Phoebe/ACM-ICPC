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
typedef pair<int, pii> piii;

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

vector<piii> road;

int dp(int n)
{
    vector<int> level,dist;
    dist.resize(n,0);
    int result=0;
    sort(road.begin(),road.end());
    for (int i=0;i<road.size();)
    {
        int x=i;
        vector<pii> temp;
        for (;i<road.size() && road[x].first == road[i].first;i++)
            if (dist[road[i].second.second] <= dist[road[i].second.first])
            {
                result=max(result,dist[road[i].second.first]+1);
                temp.push_back(make_pair(road[i].second.second, dist[road[i].second.first]+1));
            }
        for (int j = 0; j < temp.size(); j++)
            dist[temp[j].first]=max(dist[temp[j].first], temp[j].second);

    }
    return result;
}


int main()
{
    int n, m, from, to, cost;
    read(n), read(m);
    for(int i=0;i<m;i++)
    {
        read(from), read(to), read(cost);
        road.push_back(make_pair(cost,make_pair(from-1,to-1)));
    }
    printf("%d\n", dp(n));
}

