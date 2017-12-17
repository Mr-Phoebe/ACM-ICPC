#include <iostream>
#include <cstdio>

using namespace std;

int n;
int a[1005];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int ave = 0;

    for(int i=1;i<=n;i++)
        ave += a[i];

    ave /= n;

    int ans = 0;
    for(int i=1;i<=n;i++)
    if(a[i] > ave) ans++;

    printf("%d\n",ans);
}
