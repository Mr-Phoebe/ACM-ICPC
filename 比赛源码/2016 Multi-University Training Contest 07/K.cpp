#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
const int MODD=1000000007;
const int maxn=1005;
int f[2][maxn];
int twoi,cas=0;
int power(int p)
{
    if (p==0) return 1;
    int ret=power(p/2);
    ret=1LL*ret*ret%MODD;
    if (p%2==1) ret=ret*2%MODD;
    return ret;
}
void work()
{
    twoi=power(MODD-2);
    int n;
    scanf("%d",&n);
    int can=0;
    f[can][0]=1;
    for (int i=1; i<=n; i++)
    {
        memset(f[1-can],0,sizeof(f[1-can]));
        int dir;
        scanf("%d",&dir);
        if (i==n) dir=0;
        if (i==1) dir=1;
        if (dir==1)
        {
            for (int j=i-1; j>=0; j--)
                f[1-can][j+1]=f[can][j];
        }
        else
        {
            for (int j=i-1; j>=1; j--)
                f[1-can][j]=f[can][j];

            for (int j=i-1; j>=2; j--)
            {
                f[1-can][j-1]+=1LL*f[1-can][j]*twoi%MODD;
                f[1-can][j-1]%=MODD;
                f[1-can][j]=1LL*f[1-can][j]*twoi%MODD;

            }
        }

        can=1-can;
    }
    int ans=1LL*f[can][1]*twoi%MODD;
    printf("Case #%d: %d\n",++cas,ans);

}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--) work();
}
