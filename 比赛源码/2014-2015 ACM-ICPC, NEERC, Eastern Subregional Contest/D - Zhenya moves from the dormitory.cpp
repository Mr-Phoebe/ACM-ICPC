#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int sum,a1,a2;
int n,m;

int sf[300],af[300];

int bp[300],sp[300],ap[300];

int main()
{
    scanf("%d%d%d",&sum,&a1,&a2);

    scanf("%d",&n);

    for(int i=1;i<=n;i++)
        scanf("%d%d",&sf[i],&af[i]);

    scanf("%d",&m);

    for(int i=1;i<=m;i++)
        scanf("%d%d%d",&bp[i],&sp[i],&ap[i]);

    int ans = -1,ansf,ansp;

    for(int i=1;i<=m;i++)
    {
        if(bp[i] == 1)
        {
            if(sp[i] <= sum){if(ans < a1 + ap[i]){ans = a1 + ap[i];ansf = -1;ansp = i;}}
        }
        else
        {
            if(sp[i] <= sum) if(ans < a2 + ap[i]){ans = a2 + ap[i];ansf = -1;ansp = i;}

            for(int j=1;j<=n;j++)
                if(sp[i] <= sf[j] * 2 && sp[i] <= sum * 2)
                    if(ans < ap[i] + af[j]){ans = ap[i] + af[j];ansf = j;ansp = i;}
        }
    }
    if(ans == -1) {printf("Forget about apartments. Live in the dormitory.");return 0;}

    if(ansf == -1) printf("You should rent the apartment #%d alone.",ansp);
    else printf("You should rent the apartment #%d with the friend #%d.",ansp,ansf);

    return 0;
}
