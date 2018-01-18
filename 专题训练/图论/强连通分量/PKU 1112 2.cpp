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
  
  
//����ؼ��ǽ���ͼ�����໥��ʶ�������ת�����໥����ʶ�����  
//˼ά�����������ڴ�����Ϊ��ͬ����ͨ��һ���໥��ʶ��ͬһ��ͨ���ڿ��Էֲ㴦�����ڵ�һ�����໥��ʶ  
#define Maxn 110  
struct Node  
{  
   int cnt[2];  
   int sa[2][Maxn]; //��ÿ����ͨ�������������  
}node[Maxn];  
bool kn[Maxn][Maxn],nn[Maxn][Maxn];  
bool vis[Maxn];  
int n,num;  
bool dp[Maxn][Maxn]; //dp[i]��ʾ��һ��team������  
int ans[Maxn][Maxn]; //��¼�����i����ͨ����״̬Ϊjʱ��һ���ӵ�ѡ��  
int aa[Maxn],bb[Maxn];//aa��ʾ��һ���ӵ���ɳ�Ա��  
  
  
void dfs(int v,int p)  
{  
   node[num].cnt[p]++; //����ͨ������ɫ������  
   node[num].sa[p][node[num].cnt[p]]=v;//���  
   for(int i=1;i<=n;i++)  
   {  
      if(!nn[v][i]||vis[i])  
         continue;  
      vis[i]=true;  
      dfs(i,p^1);  
   }  
}  
  
bool ok() //��ÿһ������ɨ���Ƿ���ì�ܵ�  
{  
   for(int i=1;i<=num;i++)  
   {  
      for(int p=0;p<2;p++)  
      {  
         for(int k=1;k<=node[i].cnt[p];k++)  
            for(int m=k+1;m<=node[i].cnt[p];m++)  
            {  
               int a=node[i].sa[p][k],b=node[i].sa[p][m];  
               if(nn[a][b]) //ͬһ��ͨ���ڣ�ͬ��ɫ����ʶ�Ļ���ì��  
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
               nn[i][j]=nn[j][i]=true; //������ͼ  
      memset(vis,false,sizeof(vis));  
      num=0; //num��ʾ��ͨ���ĸ���  
      for(int i=1;i<=n;i++) //��ÿһ����ͨ���� Ⱦɫ  
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
      for(int i=1;i<=num;i++) //�򵥱�����ÿ����ͨ����ÿ����ɫ�����һ��С��  
      {  
         for(int j=n;j>=min(node[i].cnt[0],node[i].cnt[1]);j--) //��һ������  
         {  
            if(!dp[i][j]&&j>=node[i].cnt[0]&&dp[i-1][j-node[i].cnt[0]])  
               dp[i][j]=true,ans[i][j]=0;  
            if(!dp[i][j]&&j>=node[i].cnt[1]&&dp[i-1][j-node[i].cnt[1]])  
               dp[i][j]=true,ans[i][j]=1;  
         }  
      }  
      int gap=n,temp1=0,temp2=0;  
      for(int i=1;i<=n;i++) //��� ��ֵ��С�� ��֧������  
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
            if(ans[i][temp1]) //�������,˵���ﵽ��״̬��һ��ѡ���˵�1��  
            {  
               for(int j=1;j<=node[i].cnt[1];j++)  
                  aa[++p]=node[i].sa[1][j];  
               for(int j=1;j<=node[i].cnt[0];j++)  
                  bb[++q]=node[i].sa[0][j];  
               temp1-=node[i].cnt[1]; //ע���һ��Ҫ��ȥѡ���˵����� ÿ����ͨ������������ѡ��  
            } //��һ��ѡ���˵�0��  
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