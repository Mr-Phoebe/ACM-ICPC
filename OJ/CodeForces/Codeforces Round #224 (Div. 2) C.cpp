#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int maxn = 1e5 + 5;
int a[maxn];

int main()
{
    int i, cnt, n, d, ans, td, td1, c1, c2;
    while (scanf("%d", &n) != EOF)
    {
        for (i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        sort(a+1, a+n+1);
        d = a[2]-a[1];
        if (n == 1)     // ���Բ������޸�����ֻҪ����a[1]����
            printf("-1\n");
        else if (a[1] == a[n] && n >= 2)  // ������
            printf("1\n%d\n", a[1]);
        else if (n == 2)
        {
            if ((a[1] + a[2]) % 2)  // �ж�������֮���Ƿ�Ҳ���Բ���
                printf("2\n%d %d\n", a[1]-d, a[2]+d);
            else
                printf("3\n%d %d %d\n", a[1]-d, (a[1]+a[2])/2,  a[2]+d);
        }
        else
        {
            if (n >= 3)
            {
                c2 = c1 = 1;
                td1 = a[3]-a[2];
                if (td1 != d)
                {
                    for (i = 4; i <= n; i++)
                    {
                        int td = a[i] - a[i-1];
    // ���ִ���>=2�ĲΪ�������еĹ���                    
						if (td == td1)
                            c2++;
                        else
                            c1++;
                        if (c1 >= 2 || c2 >= 2)
                            break;
                    }
                }
                if (c2 >= c1 && n >= 3 && d > td1)    // ����ȷ������
                    d = td1;            
            }
            cnt = 0;
            for (i = 2; i <= n; i++)
            {
                td = a[i] - a[i-1];
                if (d != td)
                {
                    cnt++;
                    if ((a[i-1]+a[i]) % 2 || a[i-1]+2*d != a[i])
                    {
                        cnt++;
                        break;
                    }
                    else
                        ans = a[i-1] + d;
                } 
            }
            if (!cnt)
                printf("2\n%d %d\n", a[1]-d, a[n]+d);
            else if (cnt == 1)
                printf("1\n%d\n", ans);
            else 
                printf("0\n");
        }
    }
    return 0;
}