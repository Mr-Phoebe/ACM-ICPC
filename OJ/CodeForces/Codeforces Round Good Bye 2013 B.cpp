#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;  

const int maxn = 300 + 10;
int vis[maxn], a[maxn];

int main()
{
    int n, i, cnt, tcnt;
    while (scanf("%d", &n) != EOF)
    {
        memset(vis, 0, sizeof(vis));
        cnt = 0;
        for (i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            if (a[i] == 0)    // 统计不需要投入钱币的钱包数
            {
                vis[i] = 1;
                cnt++;
            }
        }
        int flag = 1;       // 1: 向右移动，0：向左移动
        while (cnt < n)  
        {
            tcnt = 1;    // 标记当前所处的位置
            while (flag)   
            {
                if (a[tcnt] && tcnt < n)
                {
                    printf("P");   // 投入一枚钱币
                    a[tcnt]--;     // 当前钱包需要的钱币减一枚
                }
                if (!a[tcnt] && !vis[tcnt])    // 当前钱包投入一枚钱币之后刚好不再需要再投入钱币
                {
                    vis[tcnt] = 1;
                    cnt++;   
                }
                if (cnt == n)      // 所有钱包都不需要投入钱币
                    break;
                tcnt++;
                if (tcnt <= n)     // 向右移动
                    printf("R");
                else
                    flag = 0;    // 设为向左移动的标志
            } 
            if (cnt == n)
                break;
            tcnt = n;
            while (!flag)
            {
                if (a[tcnt] && tcnt > 1)
                {
                    printf("P");
                    a[tcnt]--;
                }
                if (!a[tcnt] && !vis[tcnt])
                {
                    vis[tcnt] = 1;
                    cnt++;
                }
                if (cnt == n)
                    break;   
                tcnt--;
                if (tcnt >= 1)   
                    printf("L");
                else
                    flag = 1;
            }    
        } 
        printf("\n");
    }
    return 0;
}