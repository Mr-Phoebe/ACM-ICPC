#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>

#pragma comment(linker, "/STACK:1024000000");
#define LL long long int

using namespace std;

char Map[5010][5010];

int ans[5010][5010];

int mark[5010][5010];

int main()
{
    int n,m,i,j;

    scanf("%d %d",&n,&m);

    for(i = 0;i < n; ++i)
    {
       memset(mark[i],0,sizeof(int)*(m+2));
    }

    for(i = 0;i < n; ++i)
    {
        scanf("%*c%s",Map[i]);
        Map[i][0] -= '0';
        ans[i][0] = Map[i][0];
        mark[0][ans[i][0]] ++;
        for(j = 1;j < m; ++j)
        {
            Map[i][j] -= '0';
            ans[i][j] = (Map[i][j] == 1 ? ans[i][j-1]+1 : 0);
            mark[j][ans[i][j]] ++;
        }
    }

    int Max = -1,temp,sum;

    for(j = 0;j < m; ++j)
    {
        sum = 0;
        for(i = m;i >= 1; --i)
        {
            if( (temp = (sum += mark[j][i])*i) > Max)
                Max = temp;
        }
    }

    if(Max == -1)
        Max = 0;
    cout<<Max<<endl;

    return 0;
}
