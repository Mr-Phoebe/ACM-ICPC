#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int cas,n;
char a[200];
int ans;

int main()
{
    cas = 0;
    while(~scanf("%d",&n))
    {
        cas++;
        ans = 0;
        for(int i=1;i<=n;i++)
        {
            scanf("%s",a);
            int tmp = 0;
            for(int j=0;j<strlen(a);j++)
                tmp += a[j];

            ans = max(ans,tmp);
        }
        printf("Case %d: %d\n",cas,ans);
    }
    return 0;
}