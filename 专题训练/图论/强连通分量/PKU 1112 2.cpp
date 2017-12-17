#include<iostream>  
#include<cmath>  
#include<cstdio>  
#include<cstdlib>  
#include<string>  
#include<cstring>  
#include<algorithm>  
#include<vector>  
#include<map>  
#include<set>  
#include<stack>  
#include<list>  
#include<queue>  
#define eps 1e-6  
#define INF 0x1f1f1f1f  
#define PI acos(-1.0)  
#define ll __int64  
#define lson l,m,(rt<<1)  
#define rson m+1,r,(rt<<1)|1  
//#pragma comment(linker, "/STACK:1024000000,1024000000")  
using namespace std;  
  
  
//本题关键是建反图，将相互认识的情况，转化成相互不认识的情况  
//思维逆向，这样便于处理，因为不同的连通区一定相互认识，同一连通区内可以分层处理，相邻的一定不相互认识  
#define Maxn 110  
struct Node  
{  
   int cnt[2];  
   int sa[2][Maxn]; //存每个连通区间的两类人数  
}node[Maxn];  
bool kn[Maxn][Maxn],nn[Maxn][Maxn];  
bool vis[Maxn];  
int n,num;  
bool dp[Maxn][Maxn]; //dp[i]表示第一个team的人数  
int ans[Maxn][Maxn]; //记录到达第i个连通区且状态为j时第一个队的选择  
int aa[Maxn],bb[Maxn];//aa表示第一个队的组成成员，  
  
  
void dfs(int v,int p)  
{  
   node[num].cnt[p]++; //该连通区该颜色的人数  
   node[num].sa[p][node[num].cnt[p]]=v;//标号  
   for(int i=1;i<=n;i++)  
   {  
      if(!nn[v][i]||vis[i])  
         continue;  
      vis[i]=true;  
      dfs(i,p^1);  
   }  
}  
  
bool ok() //对每一个区间扫描是否有矛盾的  
{  
   for(int i=1;i<=num;i++)  
   {  
      for(int p=0;p<2;p++)  
      {  
         for(int k=1;k<=node[i].cnt[p];k++)  
            for(int m=k+1;m<=node[i].cnt[p];m++)  
            {  
               int a=node[i].sa[p][k],b=node[i].sa[p][m];  
               if(nn[a][b]) //同一联通快内，同颜色不认识的话有矛盾  
                  return false;  
            }  
      }  
   }  
   return true;  
}  
  
int main()  
{  
   int a;  
  
   while(~scanf("%d",&n))  
   {  
      memset(kn,false,sizeof(kn));  
      memset(nn,false,sizeof(nn));  
      for(int i=1;i<=n;i++)  
         while(scanf("%d",&a)&&a)  
            kn[i][a]=true;  
      for(int i=1;i<=n;i++)  
         for(int j=1;j<=n;j++)  
            if(!kn[i][j]||!kn[j][i])  
               nn[i][j]=nn[j][i]=true; //建无向反图  
      memset(vis,false,sizeof(vis));  
      num=0; //num表示连通区的个数  
      for(int i=1;i<=n;i++) //对每一个连通区间 染色  
         if(!vis[i])  
         {  
            num++;  
            vis[i]=true;  
            node[num].cnt[0]=node[num].cnt[1]=0;  
            dfs(i,0);  
         }  
      if(!ok())  
      {  
         printf("No solution\n");  
         continue;  
      }  
      memset(dp,false,sizeof(dp));  
      memset(ans,0,sizeof(ans));  
      dp[0][0]=true;  
      for(int i=1;i<=num;i++) //简单背包，每个连通分量每种颜色必须进一个小队  
      {  
         for(int j=n;j>=min(node[i].cnt[0],node[i].cnt[1]);j--) //第一个背包  
         {  
            if(!dp[i][j]&&j>=node[i].cnt[0]&&dp[i-1][j-node[i].cnt[0]])  
               dp[i][j]=true,ans[i][j]=0;  
            if(!dp[i][j]&&j>=node[i].cnt[1]&&dp[i-1][j-node[i].cnt[1]])  
               dp[i][j]=true,ans[i][j]=1;  
         }  
      }  
      int gap=n,temp1=0,temp2=0;  
      for(int i=1;i<=n;i++) //求出 差值最小的 两支队伍数  
         if(dp[num][i]&&abs(i-(n-i))<gap)  
            gap=abs(i-(n-i)),temp1=i;  
      temp2=n-temp1;  
      if(!temp1||!temp2)  
         printf("No solution\n");  
      else  
      {  
         //printf("%d %d\n",temp1,temp2);  
         int p=0,q=0;  
         for(int i=num;i>=1;i--)  
         {  
            //printf(":::%d\n",ans[i][temp1]);  
            if(ans[i][temp1]) //逆向输出,说明达到该状态第一队选择了第1种  
            {  
               for(int j=1;j<=node[i].cnt[1];j++)  
                  aa[++p]=node[i].sa[1][j];  
               for(int j=1;j<=node[i].cnt[0];j++)  
                  bb[++q]=node[i].sa[0][j];  
               temp1-=node[i].cnt[1]; //注意第一队要减去选择了的人数 每个连通分量必须有人选，  
            } //第一队选择了第0种  
            else  
            {  
               for(int j=1;j<=node[i].cnt[0];j++)  
                  aa[++p]=node[i].sa[0][j];  
               for(int j=1;j<=node[i].cnt[1];j++)  
                  bb[++q]=node[i].sa[1][j];  
               temp1-=node[i].cnt[0];  
            }  
         }  
         printf("%d",q);  
         for(int i=1;i<=q;i++)  
            printf(" %d",bb[i]);  
         putchar('\n');  
         printf("%d",p);  
         for(int i=1;i<=p;i++)  
            printf(" %d",aa[i]);  
         putchar('\n');  
  
      }  
  
   }  
   return 0;  
}  