#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#define MAXN 501
using namespace std;
bool map[MAXN][MAXN] = {0};
const int fx[4] = {0, 1, 0, -1},
          fy[4] = {1, 0, -1, 0};
int m, n, sum = 0;
bool vis[MAXN][MAXN] = {0};
queue<int>q;

int bfs(int x, int y)
{
   int i, j;
   q.push(x); q.push(y);
   while (!q.empty())
   {
      i = q.front();q.pop();
      j = q.front();q.pop();
      for (int k = 0; k < 4; k++)
      if (map[i+fx[k]][j+fy[k]] && !vis[i+fx[k]][j+fy[k]]){
         q.push(i+fx[k]);q.push(j+fy[k]);
         vis[i+fx[k]][j+fy[k]] = 1;
      }
   }
   return 1;
}
int dfs(int x, int y)
{
   if (!map[x][y])
	   return 1;
   vis[x][y]=1;
   for (int k = 0; k < 4; k++)
      if (!vis[x+fx[k]][y+fy[k]] && map[x+fx[k]][y+fy[k]])
      dfs(x+fx[k], y+fy[k]);
   return 1;
}
void init()
{
   int i, j;
   char ch;
   cin >> n >> m;
   getchar();
   for (i = 1; i <= n; i++)
   {
      for (j = 1; j <= m; j++)
      {
         scanf("%c", &ch);
         if (ch != '0') map[i][j] = 1;
      }
      getchar();
   }
}
void debug()
{
   for (int i = 1; i <= n; i++)
   {
      for (int j = 1; j <= m; j++)
         cout << map[i][j] << ' ';
      cout << endl;
   }
}
int main()
{
   init();
   //debug();
   for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
		if (map[i][j] && !vis[i][j])
			 sum+=dfs(i, j); //sum+=bfs(i, j);
   cout << sum << endl;
   return 0;
}
