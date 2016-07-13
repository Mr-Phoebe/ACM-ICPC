#include <stdio.h>
#include <string.h>
#define M 1550

int dp[M][2],tree[M][15];   //dp[i][1] 为在i放一兵 能看守这棵子树所须的人
//dp[i][0] 为i不放 能看守这棵子树所须的人
bool vis[M];
int min (int a,int b)
{
    return a > b ? b : a;
}
void dfs (int root)
{
    int sum = tree[root][0];
    vis[root] = true;
    for (int i = 1; i <= sum ; i ++)
    {
        int leaf = tree[root][i];
        if (vis[leaf])            //如果该结点已访问过，就不用再访问（不然就会死循环）
            continue;
        dfs (leaf);
        dp[root][1] += dp[leaf][0];
        dp[root][0] += dp[leaf][1];
        dp[root][0] = min (dp[root][1],dp[root][0]);
    }
}
int main ()
{
    int n,i,m,node,root;
    char str[10];
    while (~scanf ("%d",&n))
    {
        memset (tree,0,sizeof(tree));
        memset (dp,0,sizeof(dp));
        memset (vis,false,sizeof(vis));
        for (i = 1; i <= n; i ++)
            dp[i][1] = 1;
        for (i = 0; i < n; i ++)
        {
            scanf ("%s",str);
            sscanf (str,"%d:(%d)",&root,&m);
            ++root;
            while (m --)
            {
                scanf ("%d",&node);
                ++node;
                tree[root][++tree[root][0]] = node;
                tree[node][++tree[node][0]] = root;
            }
        }
            dfs(1);
            printf ("%d\n",dp[1][0]);
    }
    return 0;
}


/*
思路：题中已明确表示 为一棵树，所以想到了用树状DP，状态方程：
dp[root][1] += dp[leaf][0];     //根结点放一兵的话，等于 它所有叶结点所须最少兵的和
dp[root][0] += dp[leaf][1];     //根结点不放 那它的叶结点都放
dp[root][0] = min (dp[root][1],dp[root][0]);      //最后，dp[root][0] 表示 要看守这个结点所须的最少兵
*/ 