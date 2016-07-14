#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std ;
struct ma
{
    int b,p;
};
int cmp(const ma &a,const ma &b)
{
    return a.p < b.p;
}
int main()
{
    int t;
    int c[110];
    scanf("%d",&t);
    while(t--)
	{
        int n;
        double dp = 0;
        ma s[110][110];
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
		{
            scanf("%d",&c[i]);
            for(int j = 0; j < c[i]; j++)
                scanf("%d%d",&s[i][j].b,&s[i][j].p);
            sort(&s[i][0],c[i]+&s[i][0],cmp);//                         (1)
        }
        for(int i = 0; i < n; i++)
		{         //枚举所有设备
            for(int j = 0; j < c[i]; j++)
			{
                int mb = s[i][j].b,k;       //假设当前的设备是最优解    (2)
                int sp = s[i][j].p;
                for(k = 0; k < n; k++)
				{
                    if(k==i) continue;
                    int q = 0;
                     //(1)处排序不对的话，这里就不能找到正确的最优元，
                     //结果是B/P，B能通过的最大流量，由这组设备组合中最小流量决定，
                     //P是总花费，(2)的假设成立必须满足s[k][q].b>=mb，在所有满足s[k][q].b>=mb的项里，
                     //要使B/P最大，s[k][q].p就必须最小（知道为怎么要排序了吧）。
                    while(q<c[k]&&s[k][q].b<mb) q++;
                    if(q>=c[k]) break;
                    sp += s[k][q].p;
                }
                //组够n个设备时，检验当前组合是否最优的，如果是，那么保存最优值
                //枚举过所有设备之后，最优解就确定了
                if(k>=n&&(mb/double(sp)>dp)) dp = mb*1.0/sp*1.0; 
            }
        }
        printf("%0.3f\n",dp);
    }
    return 0;
}