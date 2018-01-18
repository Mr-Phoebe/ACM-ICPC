#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <cmath>

using namespace std;

const int MAXN=1010;
int c[MAXN][MAXN];

inline int lowbit(int x)
{
    return x&(-x);
}
int getsum(int x,int y)
{
    int s=0;
    for(int i=x;i<MAXN;i+=lowbit(i))
        for(int j=y;j<MAXN;j+=lowbit(j))
            s+=c[i][j];
    return s%2;

}
void update(int x,int y)
{
    for(int i=x;i>0;i-=lowbit(i))
        for(int j=y;j>0;j-=lowbit(j))
            c[i][j]^=1;
}
int main(void)
{
    int t,n,m;
    char op;
    int x1,x2,y1,y2;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%*c",&n,&m);
        memset(c,0,sizeof(c));
        while(m--)
        {
            scanf("%c",&op);
            if(op=='Q')
            {
                scanf("%d%d%*c",&x1,&y1);
                printf("%d\n",getsum(x1,y1));
            }
            else
            {
                scanf("%d%d%d%d%*c",&x1,&y1,&x2,&y2);
                update(x1-1,y1-1);
                update(x1-1,y2);
                update(x2,y1-1);
                update(x2,y2);
            }
        }
        printf("\n");
    }
    return 0;
}
