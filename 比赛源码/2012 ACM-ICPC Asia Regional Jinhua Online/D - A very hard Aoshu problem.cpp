#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

const int INF = 9999999;

int len, ans;
char a[20];

int main()
{
    while (1)
    {
        scanf("%s", a);
        if (a[0] == 'E') break;
        len = strlen(a);
        ans = 0;
        for (int i = 1; i < len; i++)
        {
            int llen = i, rlen = len-llen;
            for (int j = 0; j <= (1<<(llen-1))-1; j++)
            {
                int sum1 = 0, tmp1 = 0;
                for (int k = 0; k < llen; k++)
                if ((j&(1<<k)) == 0)
                {
                    tmp1 = tmp1*10+a[k]-'0';
                    if (tmp1 > INF) break;
                }
                else
                {
                    tmp1 = tmp1*10+a[k]-'0';
                    if (tmp1 > INF) break;
                    sum1 += tmp1; tmp1 = 0;
                    if (sum1 > INF) break;
                }
                sum1 += tmp1;
                if (sum1 > INF || tmp1 > INF) continue;
                for (int k = 0; k <= (1<<(rlen-1))-1; k++)
                {
                    int sum2 = 0, tmp2 = 0;
                    for (int l = 0; l < rlen; l++)
                    if ((k&(1<<l)) == 0)
                    {
                        tmp2 = tmp2*10+a[llen+l]-'0';
                        if (tmp2 > sum1) break;
                    }
                    else
                    {
                        tmp2 = tmp2*10+a[llen+l]-'0';
                        if (tmp2 > sum1) break;
                        sum2 += tmp2; tmp2 = 0;
                        if (sum2 > sum1) break;
                    }
                    sum2 += tmp2;
                    if (sum2 > sum1 || tmp2 > sum1) continue;
                    if (sum2 == sum1) ans++;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
