#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
#include<stack>
#define maxn 100100
using namespace std;

 struct yyy
 {
     int x,y,id;

     bool operator < (const yyy k) const
     {
         return  ((y<k.y) || (y==k.y && x<k.x));
     }

 };

int a[maxn];
yyy q[maxn];
int ans[maxn];
int pre[maxn];
int nxt[maxn];
vector<int> Pre[maxn];
int sum[maxn];

stack<int> st;

 int lowbit(int x) { return x&(-x) ;}

 void add(int x,int v)
 {
     if (x==0) return;
     while (x<maxn)
     {
         sum[x]+=v;
         x+=lowbit(x);
     }

 }

 int getsum(int x)
 {
     int Sum=0;
     while (x>0)
     {
         Sum+=sum[x];
         x-=lowbit(x);
     }
     return Sum;
 }



int main()
{
     int T;
     int i,j,k,p,x,y,r;
     int n,m;
     freopen("in.txt","r",stdin);
     scanf("%d",&T);
     for (k=1;k<=T;k++)
     {
         memset(sum,0,sizeof(sum));
         memset(pre,0,sizeof(pre));
         memset(nxt,0,sizeof(nxt));
         memset(q,0,sizeof(q));
         memset(ans,0,sizeof(ans));
         memset(a,0,sizeof(a));

         scanf("%d",&n);
         printf("Case %d:\n",k);
         for (i=1;i<=n;i++)
            scanf("%d",&a[i]),Pre[i].clear();

         scanf("%d",&m);
         for (i=1;i<=m;i++)
         {
             scanf("%d%d",&q[i].x,&q[i].y);q[i].id=i;
            if (q[i].y<=q[i].x) swap(q[i].x,q[i].y);           //查询区间
         }
          sort(q+1,q+m+1);                                     //按照r的大小
          while (!st.empty()) st.pop();
          for (i=1;i<=n;i++)                                   //单调队列，一增一减
          {
              while ( !st.empty() && a[i]<=a[st.top()]  ) st.pop();
              if (st.empty()) pre[i]=0;
              else pre[i]=st.top();                             //更新前驱点
              st.push(i);
          }
          while (!st.empty()) st.pop();
          for (i=n;i>=1;i--)
          {
              while ( !st.empty() && a[i]>=a[st.top()]  ) st.pop();
              if (st.empty()) nxt[i]=0;
              else nxt[i]=st.top();
              st.push(i);
          }
          for (i=1;i<=n;i++)
            Pre[nxt[i]].push_back(i);

           /* for (i=1;i<=n;i++)
            {
                cout<<i<<' ';
            for (j=0;j<Pre[i].size();j++)
                cout<<Pre[i][j]<<' ';

                cout<<endl;
            }*/

            /*for (i=1;i<=m;i++)
                cout<<q[i].x<<' '<<q[i].y<<endl;*/

          r=0;
            for (i=1;i<=m;i++)
            {
               while (r<q[i].y)
               {
                   r++;
                   //cout<<r<<' ';
                   for (j=0;j<Pre[r].size();j++)
                    add(pre[Pre[r][j]],1);                    //前驱结点的前缀的位置是否在里面
               }
//cout<<"xx"<<' '<<i<<endl;
               ans[ q[i].id ]=getsum(q[i].y) - getsum(q[i].x-1);
            }
          for (i=1;i<=m;i++)
             printf("%d\n",ans[i]);
     }
     return 0;
}
