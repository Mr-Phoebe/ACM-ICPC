#include<iostream>
#include <cstring>
#include<string>
#include<vector>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define N 50003
using namespace std;
vector <int> adj[4*N];
int node[N],temp[14],flag[4*N],mi,p,xx,x;
int main()
{
	freopen("data.txt","r",stdin);
 //   freopen("out.txt","w",stdout);
    int t,n,m,i,j,ha,l,r;
    int findll(int r);
    int findrr(int l);
    cin>>t;
    while(t--)
    {
        memset(adj,0,sizeof(adj));
        memset(node,0,sizeof(node));
        for(i=0;i<4*N;i++) adj[i].clear();
        cin>>n>>m;
        for (i=0;i<n;i++)
        {
            scanf("%d",&ha);
           // cin>>ha;
         //   cout<<ha;
            node[i]=ha;//写成了n。。。。
            memset(temp,0,sizeof(temp));
            j=13;
            while(ha!=0) { temp[j--]=ha%2; ha=ha/2;}
            p=1;
            for(j=0;j<14;j++)
            {
            //   cout<<temp[j];
               if(temp[j]==0) p=p*2;//temp[j]写成了temp[i]!!!
               else p=p*2+1;
               adj[p].push_back(i);//居然写成了n！！！
          //     cout<<"p:"<<p<<endl;
            }
           // cout<<endl;
        }
        for (i=0;i<m;i++)
        {
            scanf("%d%d%d",&l,&r,&xx);
          //  cin>>l>>r>>xx;
            l=l-1;r=r-1;      //所有下标都从0开始的。。
            memset(temp,0,sizeof(temp));
            j=13;
            x=xx;
            while(x!=0) { temp[j--]=x%2; x=x/2;}
            p=1;
           // int mid;
            for(j=0;j<14;j++)
            {
            if (temp[j]==0)
              {
                  p=p*2+1;
               //  cout<<"ll:"<<findll(l)<<"  rr:"<<findrr(r)<<endl;
                  if(findll(l)<=findrr(r)){}
                  else
                  {
                     p--;
                     findll(l);
                  }
              }
            else
              {
                  p=p*2;
            //      cout<<"ll:"<<findll(l)<<"  rr:"<<findrr(r)<<endl;
                 if(findll(l)<=findrr(r)){}
                 else
                 {                       //p改动之后没有更新Mi值
                   p++;
                   findll(l);
                 }
               }
             //  cout<<"p:"<<p<<endl;
            }
        //    cout<<adj[16386][0]<<"  &size"<<adj[16386].size()<<endl;
       //     cout<<xx<<"x  node"<<node[adj[p][mi]]<<endl;
            printf("%d\n",node[adj[p][mi]] ^xx);//答案是求异或值

        }

    }
  //   system("pause");
     return 0;
     }

int findrr(int r)
{
    int s=adj[p].size();
    int low=-1,high=s-1;
    mi=(low+high+1)/2;
    if(low==high) mi=-1;      ///无点的情况
    while(high!=low)
    {
    if(adj[p][mi]<=r)   low=mi;
    else high=mi-1;
    mi=(low+high+1)/2;
    }
    if(high<mi) mi=high;     ///单点的情况
    return mi;
}
int findll(int l)
{
     int s=adj[p].size();
     int low=0,high=s;
     mi=(low+high)/2;
     while(low!=high)
     {
     if(adj[p][mi]>=l)   high=mi;
     else low=mi+1;
     mi=(low+high)/2;
     }
     return mi;
}

/*
3
100 10
3934  6758  8641  524  2093  3662  5231  6800  8369  9937  1507  2762  4331  5586  6841  8410  9665  921  2490  4059  5314  6569  8138  9393  963  2218  3787  5042  6611  7866  9435  691  1946  3515  4770  6339  7594  8849  418  1674  2929  4497  5753  7321  8576  9832  1401  2656  4225  5480  7049  8618  9873  1443  2698  4267  5522  7091  8973  543  2112  3367  4936  6505  8074  9329  899  2154  3722  5291  6860  8429  9684  1254  2509  4078  5333  6902  8471  40  1295  2864  4433  5688  7257  8512  82  1651  2906  4475  6044  7612  8867  437  1692  3261  4830  6085  7654  8909   
12 25 8951
15 31 2090
42 68 3972
61 95 5541
36 62 7110
11 47 8679
54 98 249
42 62 2131
41 99 3386
13 82 4955
100 7
8937  2076  3959  5528  7096  8665  235  2118  3373  5255  6510  8079  9648  1218  2787  4042  5611  6866  8435  4  1573  2828  4397  5966  7221  8790  46  1615  3184  4753  6008  7576  8832  401  1970  3225  4794  6049  7618  8873  443  2012  3267  4836  6091  7660  8915  484  1740  3308  4877  6132  7701  8956  526  1781  3350  4919  6174  7743  8998  568  2764  4333  6529  7784  9981  1551  3433  5316  6885  9708  1278  2533  3788  5357  6612  7867  9123  692  1947  3516  4771  6026  7282  8850  106  1361  2930  4185  5440  6696  8264  9519  776  2031  3599  4855  6110  7365   
2 3 0
13 31 8649
15 43 2848
46 95 7868
1 100 9437
5 91 1007
2 44 133
10 5
85 117 125 127 4156 1446 1648 7964 4961 1648
1 4 42
2 4 42
3 4 42
1 10 2341
1 10 5431
1 10 8384


*/