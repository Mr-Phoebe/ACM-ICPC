#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
#define MAXN 1000005

using namespace std;

int t,cas;
int n;
int a[105];

int main()
{
    scanf("%d",&t);
    for(cas = 1;cas <= t;cas++)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        printf("Case #%d: ",cas);
        for(int i=1;i<=n;i++)
        if(a[i] % 3 != 0) {printf("No\n");goto mark;}
        printf("Yes\n");
        mark:;
    }
    return 0;
}
