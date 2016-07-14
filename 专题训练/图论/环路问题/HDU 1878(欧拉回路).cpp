#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

typedef long long ll;

ll into[1001];
bool hash[1001][1001],bo,bk;
ll n,m,num;
void dfs(ll k)
{
    num++;
    if (num==n) //能遍历所有的顶点说明是连通图
    {
        bo=false;
        return;
    }
    for (int i=1; i<=n; i++)
        if (hash[k][i])
        {
            hash[k][i]=hash[i][k]=false;
            dfs(i);
            if (!bo) return;
        }
}
int main()
{
    while (scanf("%lld %lld",&n,&m)!=EOF)
    {
        if (n==0) break;
        long x,y,i,j;
        memset(hash,0,sizeof(hash));
        memset(into,0,sizeof(into));
        for (i=1; i<=m; i++)
        {
            scanf("%lld%lld",&x,&y);
            hash[x][y]=hash[y][x]=true;
            into[x]++;
            into[y]++;
        }
        bk=true;
        for (i=1; i<=n; i++)
            if (into[i]%2==1)
            {
                bk=false;
                break;
            }
        if (!bk) puts("0");
        else
        {
            bo=true;
            num=0;
            dfs(1);
            if (!bo) puts("1");
            else puts("0");
        }
    }
    return 0;
}
