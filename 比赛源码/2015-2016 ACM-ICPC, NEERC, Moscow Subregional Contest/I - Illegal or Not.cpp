#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n;

bool vis[2000];

int main()
{
    scanf("%d",&n);

    memset(vis,false,sizeof(vis));

    for(int i=1;i<=n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        for(int j=a;j<=b;j++) vis[j] = true;
    }

    int num = 0;

    for(int i=1;i<=180;i++)
        if(vis[i]) num++;

    if(num > 90) {printf("No");return 0;}

    for(int i=181;i<=1826;i++)
    {
        if(vis[i]) num++;
        if(vis[i - 180]) num--;
        if(num > 90) {printf("No");return 0;}
    }
    printf("Yes");
    return 0;
}
