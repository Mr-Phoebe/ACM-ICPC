#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int a[100005],b[100005],len;

int main()
{
    int maxn,sum;
    int i,n;
    freopen("data.txt","r",stdin);
    while(~scanf("%d",&n))
    {
        sum = 0;
        for(i = 0; i<n; i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        if(sum == 0)
        {
            printf("%d\n",n);
            continue;
        }
        if(n == 1)
        {
            printf("1\n");
            continue;
        }
        if(n == 2)
        {
            printf("2\n");
            continue;
        }
        len = 0;
        int l,r,flag = 1;
        for(i = 2; i<n; i++)
        {
            if(a[i-1]+a[i-2] == a[i])
                b[len++] = 1;
            else
                b[len++] = 0;
        }
        maxn = 0;
        l = 0;
        r = 0;
        for(i = 0; i<len; i++)
        {
            if(b[i] == 1)
            {
                if(flag)
                {
                    l = i;
                    flag = 0;
                }
                else
                    r = i;
            }
            else
            {
                if(r-l+1>maxn && r!=l)
                    maxn = r-l+1;
                flag = 1;
                l = 0;
                r = 0;
            }
        }
        if(r-l+1>maxn && r!=l)
            maxn = r-l+1;
        printf("%d\n",maxn+2);
    }

    return 0;
}
