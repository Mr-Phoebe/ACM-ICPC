#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int abs(int x)
{
    return x<=0? -x : x;
}

int n,m,k;
struct node
{
    int x,y,id,ra;
    bool operator < (const node x) const
    {
        if(id!=x.id)
        return id>x.id;
        else
        return ra<x.ra;
    }
}arr[3000];

priority_queue<node> q;

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            q.push((node){i,j,i+j-1,abs(i-j)});
        }
    }
    int cnt=0,sum=0;
    for(int i=0;i<k;i++)
    {
        node u=q.top();
        arr[cnt++]=u;
        sum+=arr[cnt-1].id;
        q.pop();
    }
    cout<<sum<<endl;
    for(int i=cnt-1;i>=0;i--)
    {
        int x=arr[i].x;int y=arr[i].y;
        for(int j=1;j<=x;j++)
        {
            printf("(%d,%d)",j,1);
            if(j!=x) putchar(32);
        }
        if(2<=y) putchar(32);
        for(int j=2;j<=y;j++)
        {
            printf("(%d,%d)",x,j);
            if(j!=y) putchar(32);
        }
        if(i!=0) putchar(10);
    }

    return 0;
}