#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

struct Edge
{
    int u,v,w;    
};
int father[111];
Edge a[5010];
int n,sum=0;

bool cmp(const Edge a,const Edge b)
{
    return a.w<b.w;    
}

int findfather(int x)
{
    if(father[x]!=x)
        return father[x]=findfather(father[x]);
    else
        return father[x];
}

void Merge(int x,int y)
{
    int xx=findfather(x);
    int yy=findfather(y);
    if(xx!=yy)
        father[xx]=yy;
}

void Kruskal(int maxn)
{
    sum=0;
    sort(a+1,a+maxn,cmp);
    for(int i=1;i<maxn;i++)
        if(findfather(a[i].u)!=findfather(a[i].v))
        {
            sum+=a[i].w;
            Merge(a[i].u,a[i].v);
        }
}


int main()
{
//	freopen("data.txt","r",stdin);
    int i;
    while(scanf("%d",&n)&&n!=0)
    {
		for(int i=1;i<=n;i++)
			father[i]=i;
        for(i=1;i<=n*(n-1)/2;i++)
            scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
        Kruskal(i);
        printf("%d\n",sum);
    }
    return 0;
} 