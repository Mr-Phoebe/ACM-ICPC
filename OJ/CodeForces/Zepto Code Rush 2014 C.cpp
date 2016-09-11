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

using namespace std;
#define N 2007
#define Mod 1e10

char mp[1006][12][12];
int G[1006][1005],from[1006];
int n,m,res,id,k,w;
int vis[1005],len[1005];

struct Ans
{
    int ind,pre;
}ans[1007];

int min(int ka,int kb)
{
    if(ka < kb)
        return ka;
    return kb;
}

int dif(char a[12][12],char b[12][12])
{
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j] != b[i][j])
                cnt++;
        }
    }
    return cnt;
}

void Prim()
{
    int i,j,tag,mini;
    res = 0;
    id = 0;
    memset(vis,0,sizeof(vis));
    memset(from,0,sizeof(from));
    for(i=1;i<=k;i++)
        len[i] = n*m;   //×î´óÎªn*m
    for(i=1;i<=k;i++)
    {
        mini = Mod;
        for(j=1;j<=k;j++)
        {
            if(!vis[j] && len[j] < mini)
            {
                mini = len[j];
                tag = j;
            }
        }
        if(mini == Mod)
            return;
        res += len[tag];
        if(len[tag] == n*m)
            ans[id].ind = tag,ans[id++].pre = 0;
        else
            ans[id].ind = tag,ans[id++].pre = from[tag];
        vis[tag] = 1;
        for(j=1;j<=k;j++)
        {
            if(!vis[j] && len[j] > G[tag][j])
            {
                len[j] = G[tag][j];
                from[j] = tag;
            }
        }
    }
}

int main()
{
    int i,j;
    while(scanf("%d%d%d%d",&n,&m,&k,&w)!=EOF)
    {
        id = 0;
        for(i=1;i<=k;i++)
        {
            for(j=0;j<n;j++)
                scanf("%s",mp[i][j]);
        }
        int T = n*m;
        for(i=1;i<=k;i++)
        {
            for(j=i+1;j<=k;j++)
                G[j][i] = G[i][j] = min(dif(mp[i],mp[j])*w,T);
            G[i][i] = 0;
        }
        Prim();
        printf("%d\n",res);
        for(i=0;i<id;i++)
            printf("%d %d\n",ans[i].ind,ans[i].pre);
    }
    return 0;
}
