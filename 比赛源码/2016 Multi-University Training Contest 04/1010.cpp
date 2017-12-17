#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[100005],f[300005];
int n,m;
int main()
{
    int Tcase;
    cin >> Tcase;
    for (int ii = 1;ii <= Tcase;ii ++)
    {
        scanf("%d",&n);
        for (int i = 1;i <= n;i ++)
            scanf("%d",&a[i]);
        int l = 1,r = 0;
        int num = 0,ans = 1;
        for (int i = 1;i <= n;i ++)
        {
            if (l > r)
            {
                f[++r] = a[i] - num;
                if (!a[i]) num ++,r --;
                ans = max(ans,num + r - l + 1);
                continue;
            }
            a[i] -= num;
            if (a[i] + num== 0) num ++;
            else {
                if (a[i] > f[r]) f[++r] = a[i];
                else{
                    int k = lower_bound(f + l,f + r,a[i]) - f;
                    f[k] = a[i];
                }
            }
            ans = max(ans,num + r - l + 1);
        }
        printf("Case #%d: %d\n",ii,ans);
    }
}
