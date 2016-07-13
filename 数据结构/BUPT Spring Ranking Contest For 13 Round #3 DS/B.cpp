#include<iostream>
#include<cstdio>
using namespace std;

const int MAXN=1000010;

struct node
{
    int num;
    int i;
}q1[MAXN],q2[MAXN];

int maxn[MAXN],minn[MAXN];

int main()
{
    int n,k,i;
    while(scanf("%d %d",&n,&k)!=EOF)
    {
        int top1,top2,tail1,tail2;
        top1=top2=tail1=tail2=0;
        int p;
        for(i=0;i<n;i++)
        {
            scanf("%d",&p);
            while(top1<tail1&&q1[tail1-1].num<p) tail1--;//递减队列
            q1[tail1].i=i,q1[tail1++].num=p;
            while(i-q1[top1].i>=k) top1++;
            while(top2<tail2&&q2[tail2-1].num>p) tail2--;//递增队列
            q2[tail2].i=i,q2[tail2++].num=p;
            while(i-q2[top2].i>=k) top2++;
            if(i>=k-1) maxn[i-k+1]=q1[top1].num,minn[i-k+1]=q2[top2].num;
        }

        printf("%d",minn[0]);
        for(i=1;i<=n-k;i++)
            printf(" %d",minn[i]);
        printf("\n%d",maxn[0]);
        for(i=1;i<=n-k;i++)
            printf(" %d",maxn[i]);
        printf("\n");
    }
    return 0;
}
