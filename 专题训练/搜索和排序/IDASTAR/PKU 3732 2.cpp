#include <iostream>
#include <stack>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <bitset>
using namespace std;

#define DEBUG 0

#define my_abs(x)   ((x)>0?(x):-(x))

int dx[4] = {1, 0, 0, -1}; // d r l u
int dy[4] = {0, 1, -1, 0};

typedef struct sdfkllsdjf
{
    int x[10000],y[10000],c[10000];
    int top;
}My_Path;

My_Path path;

typedef struct sdfl
{
    int d[5][5];
	int color[20];
}MAP;

MAP maze;

int ans_flag = 0;
int r,c;

void My_Path_Push(int a,int b,int x)
{
    int t = path.top;
    path.x[t] = a;
    path.y[t] = b;
    path.c[t] = x;
    path.top++;
}

void output()
{
    int t = path.top;
    printf("%d\n",path.top);
    for(int i = 0;i< t;i++)
    {
        printf("%d %d %d\n",path.x[i]+1,path.y[i]+1,path.c[i]);
    }
}

bool Judge(int x,int y)
{
    if(x>=0&&x<r&&y>=0&&y<c)
        return true;
    return false;
}

bool neigbor(MAP m,int x,int y,int k) //判断x y位置的邻居是否有颜色K
{
    for(int i = 0;i<4;i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(!Judge(nx,ny))continue;
        if(m.d[nx][ny] == k)
            return true;
    }
    return false;
}

void FillMap(MAP * m,int x,int y ,int color,int pre_color,int flag)
{
	int i;
    m->d[x][y] = color;
    for( i = 0;i<4;i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(!Judge(nx,ny))continue;
        if(m->d[nx][ny] != pre_color)continue;
        FillMap(m,nx,ny,color,pre_color,0);
    }

    if(!flag)return ;

	memset(m->color,0,sizeof(m->color));
    for( i = 0;i< r;i++)
    {
        for (int j= 0;j<c;j++)
        {
            if(m->d[i][j] != 0)
             m->color[m->d[i][j]] = 1;
        }
    }
}
//hash 从TLE 到 3200+ms
bitset<1000024> vst[25];
int hash(MAP m)
{
    unsigned __int64 sum = 0;
    for(int i = 0;i<r;i++)
    {
        for (int j = 0;j<c;j++)
          sum = m.d[i][j] + sum*131;
    }
    return (sum % 1000007);
}

int H(int color[])
{
    int sum = 0;
    for(int i = 0;i<20;i++)
    {
        if(color[i])
         sum++;
    }
    return sum;
}

void dfs(MAP m,int Ndp,int Maxdp)
{
    int h = H(m.color);
    if(Ndp + h >Maxdp || ans_flag == 1)return ;
    if(h == 0)
    {
        output();
        ans_flag = 1;
        return ;
    }
    for(int i = 0;i< r;i++)
    {
        for(int j= 0;j< c;j++)
        {
            for(int k = 0;k< 20;k++)
            {
                if( k!=0 && !m.color[k])continue;   //如果地图中不存在那种颜色，那么没必要涂
                if(k ==m.d[i][j])continue;   //如果将要涂的颜色个本来的颜色相同。那么没必要涂

                if(k!= 0 && !neigbor(m,i,j,k))continue; //重要剪枝 从3200+ms 减到 250+ms。x,y位置的颜色要么变成0，要么变成邻居的颜色，其他的都是没有意义的

                MAP tmp_map = m;
                FillMap(&tmp_map,i,j,k,tmp_map.d[i][j],1);
                int t = hash(tmp_map);
                if(vst[Ndp+1][t])continue;
                vst[Ndp+1][t] = 1;
                My_Path_Push(i,j,k);
                dfs(tmp_map,Ndp+1,Maxdp);
                if(ans_flag == 1)return ;
                path.top--;
            }
        }
    }
}

void IDA()
{
    int maxdp = H(maze.color);
    ans_flag = 0;
    while(ans_flag ==0)
    {
        for(int i=0;i<=maxdp;i++)
			vst[i].reset();
        path.top = 0;
        dfs(maze,0,maxdp);
        maxdp++;
    }
}

int main()
{
    while(scanf("%d %d",&r,&c) == 2)
    {
        memset(maze.color,0,sizeof(maze.color));
        for(int i = 0;i<r;i++)
        {
            for(int j= 0;j< c;j++)
            {
                scanf("%d",&maze.d[i][j]);
                if(maze.d[i][j])
                   maze.color[maze.d[i][j]] = 1;
            }
        }
        IDA();
    }
    return 0;
}
