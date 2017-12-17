#include <stdio.h>
#include <string.h>
#define M 1550

int dp[M][2],tree[M][15];   //dp[i][1] Ϊ��i��һ�� �ܿ�����������������
//dp[i][0] Ϊi���� �ܿ�����������������
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
        if (vis[leaf])            //����ý���ѷ��ʹ����Ͳ����ٷ��ʣ���Ȼ�ͻ���ѭ����
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
˼·����������ȷ��ʾ Ϊһ�����������뵽������״DP��״̬���̣�
dp[root][1] += dp[leaf][0];     //������һ���Ļ������� ������Ҷ����������ٱ��ĺ�
dp[root][0] += dp[leaf][1];     //����㲻�� ������Ҷ��㶼��
dp[root][0] = min (dp[root][1],dp[root][0]);      //���dp[root][0] ��ʾ Ҫ������������������ٱ�
*/ 