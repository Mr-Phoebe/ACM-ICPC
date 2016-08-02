#include  <cstdio>
#include <cstring>
using namespace std;

int t,n;
int num[1005];

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(num,0,sizeof(num));
        for(int i=1;i<=n;i++)
        {
            int tmp;
            scanf("%d",&tmp);
            num[tmp]++;
        }

        int maxnum = -1,maxid;
        for(int i=1;i<=1000;i++)
        {
            if(num[i] > maxnum)
            {
                maxnum = num[i];
                maxid = i;
            }
        }

        int total = 0;
        for(int i=1;i<=1000;i++)
        {
            if(num[i] == maxnum)  total++;
        }

        if(total > 1) printf("Nobody\n");
        else printf("%d\n",maxid);
    }
    return 0;
}
