#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef __int64 INT;

int main()
{
    double c,e;
    INT n;
    while(scanf("%lf%lf",&c,&e)!=EOF)
    {
        scanf("%I64d",&n);
        c *= 10000.0;
        e *= 10000.0;
        c += 0.000001;
        e += 0.000001;
        INT a = (INT)c;
        INT d = (INT)e;
        for(int i = 1;i <= n;++i)
        {
            INT race = i * d;
            race %= (4*a);
            double x,y;
            if(race >= 0 && race <= a)
            {
                x = (double)race / 10000.0;
                y = 0;
            }
            else if(race > a && race <= 2*a)
            {
                race -= a;
                x = (double)a / 10000.0;
                y = (double)race / 10000.0;
            }
            else if(race > 2*a && race <= 3*a)
            {
                race  -= (2*a);
                race = a - race;
                x = (double)race / 10000.0;
                y = (double)a / 10000.0;
            }
            else if(race > 3*a && race <4*a)
            {
                race -= (3*a);
                race = a - race;
                x = 0;
                y = (double)race / 10000.0;
            }
            printf("%.10lf %.10lf\n",x,y);
        }

    }
    return 0;
}