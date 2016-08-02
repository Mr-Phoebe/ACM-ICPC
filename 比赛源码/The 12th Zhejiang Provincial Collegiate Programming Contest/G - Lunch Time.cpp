#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int t;
int s,m,d;
struct dish
{
    char name[55];
    int price;
    bool operator <(const dish &d) const
    {
        return price < d.price;
    }
}dishes1[105],dishes2[105],dishes3[105];

int ans;
int ans1,ans2,ans3;

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&s,&m,&d);

        ans = 0;

        for(int i=1;i<=s;i++)
        {
            scanf("%s",dishes1[i].name);
            scanf("%d",&dishes1[i].price);
        }
        sort(dishes1+1,dishes1+1+s);
        ans += dishes1[s/2+1].price;

        for(int i=1;i<=m;i++)
        {
            scanf("%s",dishes2[i].name);
            scanf("%d",&dishes2[i].price);
        }
        sort(dishes2+1,dishes2+1+m);
        ans += dishes2[m/2+1].price;

        for(int i=1;i<=d;i++)
        {
            scanf("%s",dishes3[i].name);
            scanf("%d",&dishes3[i].price);
        }
        sort(dishes3+1,dishes3+1+d);
        ans += dishes3[d/2+1].price;

        printf("%d %s %s %s\n",ans,dishes1[s/2+1].name,dishes2[m/2+1].name,dishes3[d/2+1].name);
    }
}
