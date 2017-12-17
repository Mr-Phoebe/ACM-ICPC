#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int t,n;
int a[100005];
int pre[100005][33];

bool cmp(int aa,int bb)
{return aa > bb;}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);

        sort(a+1,a+1+n,cmp);

        for(int i=0;i<32;i++) pre[0][i] = 0;

        for(int i=1;i<=n;i++)
        {
            for(int p=0;p<32;p++)
            {
                if((a[i] & (1 << p)) == 0) pre[i][p] = pre[i-1][p] + 1;
                else pre[i][p] = pre[i-1][p];
            }
        }


        long long ans = 0;

        for(int i=1;i<=n;i++)
        {
            int highpos;
            for(int p=0;p<32;p++)
            if(a[i] & (1 << p)) highpos = p;

            ans += pre[i-1][highpos];
        }

        printf("%lld\n",ans);
    }
}
