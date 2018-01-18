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
            if (a[i] == 0)    // ͳ�Ʋ���ҪͶ��Ǯ�ҵ�Ǯ����
            {
                vis[i] = 1;
                cnt++;
            }
        }
        int flag = 1;       // 1: �����ƶ���0�������ƶ�
        while (cnt < n)  
        {
            tcnt = 1;    // ��ǵ�ǰ������λ��
            while (flag)   
            {
                if (a[tcnt] && tcnt < n)
                {
                    printf("P");   // Ͷ��һöǮ��
                    a[tcnt]--;     // ��ǰǮ����Ҫ��Ǯ�Ҽ�һö
                }
                if (!a[tcnt] && !vis[tcnt])    // ��ǰǮ��Ͷ��һöǮ��֮��պò�����Ҫ��Ͷ��Ǯ��
                {
                    vis[tcnt] = 1;
                    cnt++;   
                }
                if (cnt == n)      // ����Ǯ��������ҪͶ��Ǯ��
                    break;
                tcnt++;
                if (tcnt <= n)     // �����ƶ�
                    printf("R");
                else
                    flag = 0;    // ��Ϊ�����ƶ��ı�־
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