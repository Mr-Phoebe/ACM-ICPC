#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
#define MAX 8
const int INF = (1<<20);
int dirKing[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
int dirKnight[8][2] = {{-2,-1},{-2,1},{2,-1},{2,1},{-1,-2},{1,-2},{-1,2},{1,2}};

char str[MAX*MAX*2+5];
int king[MAX*MAX][MAX*MAX], knight[MAX*MAX][MAX*MAX];
int step[MAX*MAX], num;

inline int min(int a,int b)
{
    return a < b ? a : b;
}

void init()
{
    for(int i = 0; i < MAX*MAX; ++i)
        for(int j = 0; j < MAX*MAX; ++j)
            king[i][j] = knight[i][j] = (i == j ? 0 : INF);
    for(int i = 0; i < MAX*MAX; ++i)
    {
        int x = i/8;
        int y = i%8;
        for(int j = 0; j < 8; ++j)
        {
            int xx = x+dirKing[j][0];
            int yy = y+dirKing[j][1];
            if(xx >= 0 && xx < MAX && yy >= 0 && yy < MAX)
                king[i][8*xx+yy] = 1;
        }
        
        for(int j = 0; j < 8; ++j)
        {
            int xx = x+dirKnight[j][0];
            int yy = y+dirKnight[j][1];
            if(xx >= 0 && xx < MAX && yy >= 0 && yy < MAX)
                knight[i][8*xx+yy] = 1;
        }
    }
}

void floyd(int a[][MAX*MAX])
{
    for(int k = 0; k < MAX*MAX; ++k)
    {
        for(int i = 0; i < MAX*MAX; ++i)
        {
            for(int j = 0; j < MAX*MAX; ++j)
            {
                if(a[i][j] > a[i][k]+a[k][j])
                    a[i][j] = a[i][k]+a[k][j];
            }
        }
    }
}

int main()
{
//    freopen("input.txt","r",stdin);
    init();
    floyd(king);
    floyd(knight);
    
    while(scanf("%s",str) != EOF)
    {
        int start = (str[0]-'A') + (str[1]-'1')*8;
        int num = (strlen(str)-2)/2;
        if(num == 0)
        {
            printf("0\n");
            continue;
        }
        
        for(int i = 0, j = 2; i < num; ++i, j+=2)
            step[i] = (str[j]-'A') + (str[j+1]-'1')*8;
        int result = INF;
        int t1, t2;
        int sum;
        for(int i = 0; i < MAX*MAX; ++i)
        {
            sum = 0;
            for(int k = 0; k < num; ++k)
                sum += knight[ step[k] ][i];
            for(int j = 0; j < MAX*MAX; ++j)
            {
                t1 = king[start][j];
                t2 = INF;
                for(int kk = 0; kk < num; ++kk)
                {
                    t2 = min(t2,knight[ step[kk] ][j] + knight[j][i] - knight[ step[kk] ][i]); // 骑士从起始点到达j点接国王, 骑士和国王一起到达枚举的终点, 其中要减去sum已经加上的即可.
                }
                result = min(result,sum+t1+t2);
            }
        }
        printf("%d\n",result);
    }
    return 0;
}