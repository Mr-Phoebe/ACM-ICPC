#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn = 5100;
int v[maxn], u[maxn], w[maxn];         //u,线段起始点。v,线段终点。w,权值。 
int r[maxn];        //保存边序号，便于间接排序 
int p[maxn];                           //并查集 

int cmp(const int i, const int j)   //间接排序 
{
    return w[i] < w[j];
}

int find(int x)
{
    return p[x] == x? x : p[x] = find(p[x]);
}//find


int Kruskal(int n, int m)
{
    int ans = 0;
    for(int i = 0 ; i < n; i++) p[i] = i;     //初始化并查集 
    for(int i = 0 ; i < m; i++) r[i] = i;     //初始化边序号 
    sort(r, r+m, cmp);
    for(int i = 0; i < m ; i++)
    {
        int e = r[i]; int x = find(v[e]); int y = find(u[e]);
        if(x!=y)
        {
            ans += w[e];
            p[x] = y;        
        } //如在不同集合，合并。 
    }
    return ans;
}

void init()
{
    memset(v, 0, sizeof(v));
    memset(u, 0, sizeof(u));
    memset(w, 0, sizeof(w));
    memset(r, 0, sizeof(r));
}//init


int main()
{
    int i;
    int n, m;
    while(~scanf("%d", &n), n)
    {
        init();      //预处理 
        m = n*(n-1)/2; 
        for(i = 0 ; i < m ; i++)
        {
            scanf("%d%d%d", &u[i], &v[i], &w[i]);
            u[i]--;
            v[i]--;            //注意序号要减1，因为我是从零开始标号的 
        }
        printf("%d\n", Kruskal(n, m));
    }
    return 0;
}