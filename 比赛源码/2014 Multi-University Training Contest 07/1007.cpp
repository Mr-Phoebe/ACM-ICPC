#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

struct Node
{
    int x;
    int y;
    int c;
}l[100000];

map <int, map<int, int> > fmap;
map <int ,int>hashx,hashy;
int T,n,m,k,mapx,mapy,t,cas,lianx[100010],liany[100010],Q,A,B,X,Y;

bool cmpx(Node a,Node b)
{
    return a.x<b.x;
}
bool cmpy(Node a,Node b)
{
    return a.y<b.y;
}

int main()
{
    int CAS;
    scanf("%d", &CAS);
    for(int cas=1;cas<=CAS;cas++)
    {
      scanf("%d%d%d",&n,&m,&k);
      printf("Case #%d:\n",cas);
      for(int i=0;i<k;i++)scanf("%d%d%d",&l[i].x,&l[i].y,&l[i].c);
      fmap.clear();hashx.clear();hashy.clear();mapx=mapy=0;
      sort(l,l+k,cmpx);
      for(int i=0;i<k;i++)if(!hashx[l[i].x])hashx[l[i].x]=++mapx;
      sort(l,l+k,cmpy);
      for(int i=0;i<k;i++)
      {
        if(!hashy[l[i].y])hashy[l[i].y]=++mapy;
        fmap[hashx[l[i].x]][hashy[l[i].y]]=l[i].c;
      }
      for(int i=1;i<=mapx;i++)lianx[i]=i;
      for(int i=1;i<=mapy;i++)liany[i]=i;
      scanf("%d",&t);
      for(int i=0;i<t;i++)
      {
        scanf("%d%d%d",&Q,&A,&B);
        if(Q==1)
        {
          X=hashx[A];Y=hashx[B];
          if(X && Y)swap(lianx[X],lianx[Y]);
        }
        else if(Q==2)
        {
          X=hashy[A];Y=hashy[B];
          if(X && Y)swap(liany[X],liany[Y]);
        }
        else if(Q==3)
        {
          X=hashx[A];Y=hashy[B];
          if(X && Y)printf("%d\n",fmap[lianx[X]][liany[Y]]);
          else printf("0\n");
        }
      }
    }
    return 0;
}
